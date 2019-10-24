/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:58:55 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/24 17:59:41 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	delete_file(void *file, size_t size)
{
	t_file *f;
	size = 0;

	f = (t_file*)file;
	free(f->name);
	free(f->full_name);
	free(f);
}
