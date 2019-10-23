/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:04:01 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/23 18:37:19 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		recursive_ls(char *path)
{
	DIR				*dirp;
	struct dirent	*dp;
	char			*full_name;

	ft_printf("path:%s\n", path);
	if (!(dirp = opendir(path)))
		return (-1);
	while ((dp = readdir(dirp)))
	{
		if (dp->d_type == DT_DIR)
		{
			if (ft_strequ(dp->d_name, ".") || ft_strequ(dp->d_name, ".."))
				continue ;
			full_name = ft_strjoin(path, "/"); // leaks
			full_name = ft_strjoin(full_name, dp->d_name);
			recursive_ls(full_name);
			ft_printf("%s/\n", dp->d_name);
		}
		else
			ft_printf("%s\n", dp->d_name);
	}
	closedir(dirp);
}

int		ft_ls(t_flags *flags, int argc, char **argv, int start)
{
	recursive_ls(argv[start]);
	return (0);
}
