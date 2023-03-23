/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:48:12 by azakarya          #+#    #+#             */
/*   Updated: 2023/03/22 20:50:18 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (!fd || !s)
		return ;
	while (s[++i] != '\0')
		write(fd, &s[i], 1);
}

int	flag_checking(char *command)
{
	int	j;

	j = 1;
	while (command[j] == 'n')
		j++;
	if (command[j] == '\0')
		return (1);
	return (0);
}

int	echo_built(t_element *elem)
{
	char	**command;
	int		flag;
	int		i;

	i = 1;
	command = elem->command->args;
	flag = 0;
	while ((command[i]) && (command[i][0] == '-')
		&& flag_checking(command[i]) == 1)
	{
			flag = 1;
			i++;
	}
	while (command[i])
	{
		ft_putstr_fd(command[i], 1);
		if (command[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (flag == 0)
		ft_putstr_fd("\n", 1);
	return (set_status(0));
}
