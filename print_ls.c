/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:00:03 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/24 18:00:47 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file(t_list *lst)
{
	t_file *f;

	f = (t_file*)lst->content;
	ft_printf("%-20s\n", f->name);
	//ft_printf("_____________\nfullname:%s\nname:%s\nis_dir:%d\n", f->full_name, f->name, f->is_dir);
}

void	print_hidden_files();
