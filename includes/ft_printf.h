#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_format
{
	va_list	arg_list;
	int	minus;
	int	zero;
	int	width;
	int	prec_dot;
	int prec_value;
	char	type;
	int	printf_len;
}				t_format;

void    fmt_init(t_format *fmt);
char	*apply_padding(t_format *fmt, int len);
int		check_flags(char *c, t_format *fmt, int i);
int 	check_width(char *str, t_format *fmt, int i); 
int 	check_precision(char *str, t_format *fmt, int i);
int 	check_type(char *str, t_format *fmt, int i);
int		type_char(char c, t_format *fmt);
int 	type_str(char *str, t_format *fmt);
int		type_int(int nbr, t_format *fmt);
int		type_uint(unsigned int nbr, t_format *fmt);
int		type_hexa(unsigned int	nbr, t_format *fmt);
int		type_ptr(unsigned long int nbr, t_format *fmt);
void    ft_append(char **a, char *str);
void    apply_padding_free(t_format *fmt, char **str, int len);
void    apply_precision_free(t_format *fmt, char **str, int len);
void	apply_zero(t_format *fmt, int *nbr, char **str);
int		ft_printf(const char *str, ...);

#endif