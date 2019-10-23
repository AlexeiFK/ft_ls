/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:49:25 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/23 21:13:10 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			read_flags(int argc, char **argv, t_flags *flags)
{
	//todo
	flags->l = 0;
	flags->t = 0;
	flags->a = 1;
	flags->r = 1;
	flags->r_cap = 1;
	return (0);
}

int			main(int argc, char **argv)
{
	int		number_of_flags;
	t_flags flags;
	int		start_index;

	number_of_flags = read_flags(argc, argv, &flags);
	start_index = 1 + number_of_flags;
	ft_ls(&flags, argc, argv, start_index);
	return (0);
}
