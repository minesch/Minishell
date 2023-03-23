/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:48:06 by azakarya          #+#    #+#             */
/*   Updated: 2023/03/22 20:48:08 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/main.h"

void	print_cd_err(char *path)
{
	ft_putstr_fd(get_val_value("PS1"), 2);
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	set_status(1);
}

void	many_arg(void)
{
	ft_putstr_fd(get_val_value("PS1"), 2);
	ft_putstr_fd("cd: too many arguments\n", 2);
	set_status(1);
}
