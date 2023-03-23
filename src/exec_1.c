/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:11:28 by ergrigor          #+#    #+#             */
/*   Updated: 2023/02/03 09:23:35 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/main.h"

char	**get_paths(void)
{
	t_env	*ptr;

	ptr = g_lobal->env;
	while (ptr)
	{
		if (ft_strcmp(ptr->val_name, "PATH") == 0 && ptr->val_value)
			return (ft_split(ptr->val_value, ':'));
		ptr = ptr->next;
	}
	return (NULL);
}

int	is_directory(char *cmd)
{
	int			i;
	struct stat	_path;

	i = 0;
	if (!cmd || cmd[0] == '\0')
		return (set_status(127));
	stat(cmd, &_path);
	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			if (S_ISDIR(_path.st_mode) == 1 && access(cmd, F_OK | X_OK) == 0)
				return (set_status(126));
			else if (S_ISDIR(_path.st_mode) != 1 && i != 0 && cmd[i - 1] != '.')
				return (set_status(126), 125);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

char	*get_abs_path(char **paths, char *cmd)
{
	int			i;
	char		*temp;
	struct stat	_path;

	stat(cmd, &_path);
	i = 0;
	if (access(cmd, F_OK | X_OK | R_OK) == 0 && S_ISDIR(_path.st_mode) != 1)
		return (cmd);
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		temp = ft_strjoin(temp, cmd);
		if (access(temp, X_OK | R_OK) == 0)
			break ;
		free (temp);
		i++;
	}
	if (access(temp, X_OK | R_OK) == 0)
		return (temp);
	else
	{
		print_error(cmd, "command not found");
	}
	return (NULL);
}

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (0);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (0);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (0);
	else if (ft_strcmp(cmd, "export") == 0)
		return (0);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (0);
	else if (ft_strcmp(cmd, "env") == 0)
		return (0);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (0);
	else
		return (1);
}

void	print_error(char *cmd, char *error)
{
	ft_putstr_fd(get_val_value("PS1"), 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
}
