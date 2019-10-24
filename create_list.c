/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:59:22 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/24 18:46:45 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*new_t_file(char *name, char *full_name, int is_dir)
{
	t_file *new;

	new = (t_file *)malloc(sizeof(t_file));
	new->name = ft_strdup(name);
	new->full_name = ft_strdup(full_name);
	new->is_dir = is_dir;
	return (new);
}

t_list	*create_list_of_files(char *path)
{
	t_list			*new_list;
	t_list			*tmp_list;
	t_file			*new_file;
	DIR				*dirp;
	struct dirent	*dp;
	char			*full_name;

	new_list = NULL;
	if (!(dirp = opendir(path)))
		return (NULL);
	while ((dp = readdir(dirp)))
	{
		full_name = ft_strjoin(path, "/"); // leaks
		full_name = ft_strjoin(full_name, dp->d_name); //leaks
		new_file = new_t_file(dp->d_name, full_name, dp->d_type == DT_DIR);
		tmp_list = ft_lstnew(new_file, sizeof(t_file));
		ft_lstadd(&new_list, tmp_list);
	}
	closedir(dirp);
	return (new_list);
}
