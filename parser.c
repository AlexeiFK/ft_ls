#include "libft.h"
#include <stdio.h>


/*
**==================================HEADER======================================
*/

# ifndef ERROR
# define ERROR			(-1)
# endif
# define PARSE_FLAG		0
# define PARSE_FILE		1
# define FLAGS_STR		"ARalr"

# define FLAG_A			0x1
# define FLAG_R			0x2
# define FLAG_A_SMALL	0x4	
# define FLAG_L_SMALL	0x8
# define FLAG_R_SMALL	0x10

typedef struct		s_options
{
	int				flags;
	t_dlist			*files;
}					t_options;

typedef int			(*t_parser)(char *str, t_options *s_options);

/*
**=============================END_OF_HEADER====================================
*/

/*
**--------------------------------FLAG_STATE------------------------------------
*/

int					has_sflag_a(int flags)
{
	return (flags & FLAG_A);
}

int					has_flag_r(int flags)
{
	return (flags & FLAG_R);
}

int					has_flag_a_small(int flags)
{
	return (flags & FLAG_A_SMALL);
}

int					has_flag_l_small(int flags)
{
	return (flags & FLAG_R_SMALL);
}

int					has_sflag_r_small(int flags)
{
	return (flags & FLAG_R_SMALL);
}

/*
**----------------------------------PARSER--------------------------------------
*/

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
	options->flags |= (1 << (flag - flag_bucket));
	while (*(++str))
	{
		if (!(flag = ft_strchr(FLAGS_STR, *str)))
			return (PARSE_FILE);
		options->flags |= (1 << (flag - flag_bucket));
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

/*
**-----------------------PRINT_RESULT_PARSING_RESULT----------------------------
*/

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

/*
**--------------------------------MAIN------------------------------------------
*/

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