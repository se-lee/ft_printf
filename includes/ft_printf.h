#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

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
	char c;
	char *str;
	int	neg;
}				t_format;

void    fmt_init(t_format *fmt);
char	*apply_padding(t_format fmt, int len);
int		check_flags(char *c, t_format *fmt, int i);
int 	check_width(char *str, t_format *fmt, int i); 
int 	check_precision(char *str, t_format *fmt, int i);
int 	check_type(char c, t_format *fmt, int i, char **str, char *w);
int 	type_char(t_format fmt);
int 	type_str(t_format fmt);
int		type_int(int nbr, t_format fmt);
//int	type_int(t_format *fmt);
char  *sort_left_right(t_format fmt, char *str, char *padding);
char    *apply_precision(t_format fmt);
char    *apply_width(t_format fmt);


int		ft_printf(const char *str, ...); //__attribute__(format(printf, 1, 2)); //attribute -> 


#endif