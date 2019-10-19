#include "libft.h"
#include <stdio.h>

# ifndef ERROR
# define ERROR		(-1)
# endif
# define PARSE_FLAG	0
# define PARSE_FILE	1
# define FLAGS_STR		"ARalr"

typedef struct		s_options
{
	int				flags;
	t_dlist			*files;
}					t_options;

typedef int			(*t_parser)(char *str, t_options *s_options);

int					usage()
{
	ft_putendl("usage: ft_ls [-larRA] [file ...]");
	return (0);
}

int					parse_fnames(char *str, t_options *options)
{
	char			*fname;
	t_dlist			*new;		

	if (!str || !*str || !(fname = ft_strdup(str)) ||
			!(new = ft_dlstnew_ptr((void *)fname)))
	{
		ft_dlstdel(&options->files, ft_dlstcontentdel);
		return (ERROR);
	}
	ft_dlstpush_back(&options->files, new);
	return (PARSE_FILE);
}

int					parse_flags(char *str, t_options *options)
{
	char			*flag;
	char			*flag_bucket;

	if (!str || !*str || *str != '-')
		return (!str || !*str ? ERROR : parse_fnames(str, options));
	++str;
	flag_bucket = FLAGS_STR;
	if (!*str || !(flag = ft_strchr(flag_bucket, *str)))
		return (ERROR);
	options->flags |= ft_power(2, flag - flag_bucket);
	while (*(++str))
	{
		if (!(flag = ft_strchr(FLAGS_STR, *str)))
			return (PARSE_FILE);
		options->flags |= ft_power(2, flag - FLAGS_STR);
	}
	return (PARSE_FLAG);
}

int					parse(char **argv, t_options *options)
{
	char			*str;
	int				state;
	static t_parser	parsers[2] = {parse_flags, parse_fnames};

	state = PARSE_FLAG;
	while ((str = *argv) && state != ERROR)
	{
		if ((state = (parsers[state])(str, options)) == ERROR)
			break ;
		++argv;
	}
	return (state == ERROR ? FAILURE : SUCCESS);
}

void				print_fnames(void *str)
{
	char			*s;
	static int		i;
	static char		nbr_ar[64 + 1];

	s = (char *)str;
	ft_imaxtostr(nbr_ar, i, 10, 0);
	printf("%i-th file: \"%s\"\n", i++, str);
	return ;
}

void				print_flags(int flags)
{
	static char		nbr_ar[64 + 1];
	
	ft_imaxtostr(nbr_ar, flags, 2, 0);
	ft_strrev(nbr_ar);
	printf("FLAGS:\n%s\n%-s\n\n", FLAGS_STR, nbr_ar);
	return ;
}

int					main(int argc, char **argv)
{
	t_options		options;

	ft_bzero((void *)&options, sizeof(options));
	if (argc < 2)
		return (usage());
	if (parse(++argv, &options) == FAILURE)
		return (FAILURE);
	print_flags(options.flags);
	ft_dlstforeach(options.files, print_fnames);
	return (0);
}