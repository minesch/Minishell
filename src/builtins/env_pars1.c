/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_pars1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:48:19 by azakarya          #+#    #+#             */
/*   Updated: 2023/03/22 20:48:20 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_env	*pars_env(char **env)
{
	t_env	*list_env;
	t_env	*env_start;
	int		index;

	list_env = ft_calloc(sizeof(t_env), 1);
	env_start = list_env;
	index = 0;
	while (env[index] != NULL)
	{
		list_env->val_name = get_val_name(env[index]);
		list_env->val_value = get_val(env[index]);
		if (env[index + 1] == NULL)
		{
			list_env->next = NULL;
			break ;
		}
		list_env->next = malloc(sizeof(t_env));
		if (!list_env->next)
			return (NULL);
		list_env->next->prev = list_env;
		list_env = list_env->next;
		index++;
	}
	add_hidden_values(&env_start);
	return (env_start);
}

char	*get_val_name(char *env_line)
{
	int		i;
	char	*value;

	i = 0;
	while (env_line[i] != '=' && env_line[i] != '\0')
		i++;
	value = malloc(i + 1);
	if (!value)
		return (NULL);
	value[i] = '\0';
	i--;
	while (i >= 0)
	{
		value[i] = env_line[i];
		i--;
	}
	return (value);
}

char	*get_val(char *env_line)
{
	int		i;
	int		tmp;
	char	*value;

	i = 0;
	while (env_line[i] != '=')
		i++;
	tmp = i;
	i++;
	while (env_line[i] != '\0')
		i++;
	value = malloc(i - tmp);
	if (!value)
		return (NULL);
	while (i > tmp)
	{
		value[i - tmp - 1] = env_line[i];
		i--;
	}
	return (value);
}
