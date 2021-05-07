#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_format
{
	int	minus; // 0 if minus doesnt exist, 1 if exists
	int	zero; // 0 or 1
	int	width;
	int	precision; //dot
	int	length;
	char	type; //csiduxX
}				t_format;

int	ft_printf(const char *str, ...);



#endif