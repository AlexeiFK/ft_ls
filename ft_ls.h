/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:53:30 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/23 21:20:44 by rjeor-mo         ###   ########.fr       */
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
void				ft_lstsort(t_list *lst);
void				ft_lstrev(t_list *lst);

#endif
