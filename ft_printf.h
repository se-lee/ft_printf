#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_format
{
	va_list	arg_list; // all the "unused' parameters after the main str
	int	minus; // 0 if minus doesnt exist, 1 if exists
	int	zero; // 0 or 1
	int	width; //-1 if not existent
	int	prec_dot; //dot, 0 is not existent
	int prec_value; //the actual value of prec
	char	type; //csiduxX
	int	printf_len; //length of final result (str after all flags applied)
}				t_format;

int	ft_printf(const char *str, ...); //__attribute__(format(printf, 1, 2)); //attribute -> 



#endif