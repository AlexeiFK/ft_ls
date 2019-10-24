/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:04:01 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/24 18:01:14 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		recurs_ls(t_flags *flags, t_list *files_list)
{
	t_list *lst;
	t_file *f;

	while (files_list)
	{
		f = (t_file*)files_list->content;
		if (f->is_dir && f->name[0] != '.')
		{
			ft_printf("\n%s:\n", f->full_name);
			lst = create_list_of_files(f->full_name);
			ft_lstiter(lst, print_file);
			ft_printf("\n");
			recurs_ls(flags, lst);
			ft_lstdel(&lst, delete_file);
		}
		files_list = files_list->next;
	}
	return (0);
}

int		ft_ls(t_flags *flags, int argc, char **argv, int start)
{
	t_list *lst;
	if (start == argc)
	{
		lst = create_list_of_files(".");
		ft_lstrev(&lst);
		ft_lstiter(lst, print_file);
		ft_printf("\n");
//		if (flags->r_cap)
//			recurs_ls(flags, lst);
	}
	while (start < argc)
	{
		lst = create_list_of_files(argv[start]);
		ft_lstiter(lst, print_file);
		ft_printf("\n");
		if (flags->r_cap)
			recurs_ls(flags, lst);
		++start;
	}
	return (0);
}
