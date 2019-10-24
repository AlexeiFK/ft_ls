/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:53:30 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/24 18:47:12 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include "libft.h"
# include <stdlib.h>

# define COLUMN_MAX 5

typedef struct		s_file
{
	char			*name;
	char			*full_name;
	int				is_dir;
}					t_file;

typedef struct		s_flags
{
	int				l;
	int				r_cap;
	int				r;
	int				a;
	int				t;
}					t_flags;

int					ft_ls(t_flags *f,
					int argc, char **argv,
					int start_index);

void				print_file(t_list *lst);
void				print_hidden_files();

t_file				*new_t_file(char *name, char *full_name, int is_dir);
t_list				*create_list_of_files(char *path);

void				delete_file(void *file, size_t size);

void				ft_lstsort(t_list *lst,
					int (*cmp)(t_list *e1, t_list *e2));

void				ft_lstrev(t_list **lst);

#endif
