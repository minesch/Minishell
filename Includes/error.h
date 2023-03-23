/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:27:31 by azakarya          #+#    #+#             */
/*   Updated: 2023/03/23 22:27:35 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define QUOTE_ERR "minishell: unexpected EOF while looking for matching \"'\"\n"
# define DB_QUOTE_ERR "minishell: unexpected EOF while\
		looking for matching `\"`\n"
# define L_SCOPE_ERR "minishell: unexpected EOF while looking for matching \"(\"\n"
# define R_SCOPE_ERR "minishell: unexpected EOF while looking for matching \")\"\n"

#endif
