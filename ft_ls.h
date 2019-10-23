/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:53:30 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/23 17:51:10 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <dirent.h>
#include "libft.h"

typedef struct		s_flags
{
	int				fl_a;
}					t_flags;

int					ft_ls(t_flags *f,
					int argc, char **argv,
					int start_index);

#endif
