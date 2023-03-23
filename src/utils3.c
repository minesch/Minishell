/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:43:58 by ergrigor          #+#    #+#             */
/*   Updated: 2023/01/31 00:33:45 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*remake_var_line(char *line, int len)
{
	int		i;
	int		j;
	char	*result;
	char	*bari;

	i = 0;
	result = ft_strdup("");
	while (line[i] && i < len)
	{
		if (line[i] != '$' && i < len)
		{
			j = i;
			while (line[i] && line[i] != '$' && i < len)
				i++;
			result = append_to_result(result, line, j, i);
		}
		else if (line[i] == '$' && i < len)
		{
			bari = resolve_var_line(line, &i);
			result = ft_free_strjoin(result, bari);
			free(bari);
		}
	}
	return (result);
}

int	check_next_token(t_token *ptr)
{
	int	flag;

	if (!ptr)
		return (0);
	else if (ptr->type == WORD)
		return (1);
	else if (ptr->type == DOUBLE_QUOTES || ptr->type == SINGLE_QUOTES)
	{
		flag = ptr->type;
		ptr = ptr->next;
		while (ptr && ptr->type != flag)
			ptr = ptr->next;
		if (!ptr)
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

int	hd_count_check(t_token *token)
{
	int		count;
	t_token	*ptr;

	count = 0;
	ptr = token;
	while (ptr)
	{
		if (ptr && ptr->type == HERE_DOC)
		{
			if (ptr->next && ptr->next->type == SPACE_TK)
				ptr = ptr->next->next;
			else
				ptr = ptr->next;
			count += check_next_token(ptr);
			if (ptr)
				ptr = ptr->next;
			else
				ptr = NULL;
		}
		else
			ptr = ptr->next;
	}
	return (count);
}
