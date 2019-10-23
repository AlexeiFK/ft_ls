/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:04:01 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/23 21:29:06 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		recursive_ls(char *path)
{
	DIR				*dirp;
	struct dirent	*dp;
	char			*full_name;
	int				n_column;

	ft_printf("path:%s\n", path);
	n_column = 0;
	if (!(dirp = opendir(path)))
		return (-1);
	while ((dp = readdir(dirp)))
	{
		if (dp->d_type == DT_DIR)
		{
			if (ft_strequ(dp->d_name, ".") || ft_strequ(dp->d_name, ".."))
				continue ;
			if (dp->d_name[0] == '.')
				continue ;
			full_name = ft_strjoin(path, "/"); // leaks
			full_name = ft_strjoin(full_name, dp->d_name);
			recursive_ls(full_name);
			ft_printf("%s ", dp->d_name);
		}
		else
		{
			ft_printf("%s ", dp->d_name);
			if (n_column >= COLUMN_MAX)
			{
				ft_putstr("\n");
				n_column = 0;
			}
		}
		++n_column;
	}
	closedir(dirp);
}

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

void	print_file(t_list *lst)
{
	t_file *f;
	static n_col = 0;

	f = (t_file*)lst->content;
	ft_printf("%-20s", f->name);
	if (n_col >= COLUMN_MAX)
	{
		ft_putstr("\n");
		n_col = 0;
	}
	n_col++;
	//ft_printf("_____________\nfullname:%s\nname:%s\nis_dir:%d\n", f->full_name, f->name, f->is_dir);
}

void	print_hidden_files();

void	delete_file(void *file, size_t size)
{
	t_file *f;
	size = 0;

	f = (t_file*)file;
	free(f->name);
	free(f->full_name);
	free(f);
}

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
		ft_lstiter(lst, print_file);
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
