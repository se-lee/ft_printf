#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_option
{
	int	minus;
	int	zero;
	int	width;
	int	precision;

}	t_option;

int	ft_printf(const char *str, ...);

#endif