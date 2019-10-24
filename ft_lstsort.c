/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:35:12 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/24 16:54:53 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsort(t_list *lst, int (*cmp)(t_list *e1, t_list *e2))
{
	t_list		*tmp_i;
	t_list		*tmp_j;
	void		*tmp_data;

	tmp_i = lst;
	while (tmp_i)
	{
		tmp_j = lst;
		while (tmp_j->next)
		{
			if (cmp(tmp_j, tmp_j->next))
			{
				tmp_data = tmp_j->content;
				tmp_j->content = tmp_j->next->content;
				tmp_j->next->content = tmp_data;
			}
			tmp_j = tmp_j->next;
		}
		tmp_i = tmp_i->next;
	}
}
