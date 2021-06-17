#include "ft_printf.h"

void    fmt_init(t_format *fmt)
{
    fmt->minus = 0;
    fmt->zero = 0;
    fmt->width = 0;
    fmt->prec_dot = 0;
    fmt->prec_value = 0;
    fmt->type = '\0';
    fmt->c = '\0';
    fmt->str = NULL;
    fmt->neg = 0;
}

int	check_flags(char *c, t_format *fmt, int i)
{
	if (c[i] == '-') 
	{
		fmt->minus = 1;
		i++;
	}
	if (c[i] == '0')
	{
		fmt->zero = 1;
		i++;
	}
	return (i);
}

int check_width(char *str, t_format *fmt, int i) 
{
	if (str[i] == '*')
	{
		fmt->width = va_arg(fmt->arg_list, int);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
        fmt->width = fmt->width * 10 + (str[i] - '0');
	    i++;
    }
    if (fmt->width < 0)
    {
        fmt->width *= -1;
        fmt->minus = 1;
    }
    return (i);
}

int check_precision(char *str, t_format *fmt, int i)
{
    if (str[i] == '.')
    {
    	fmt->prec_dot = 1;
        i++;
        if (str[i] == '*')
        {
            fmt->prec_value = va_arg(fmt->arg_list, int);
            i++;
        }
        if (fmt->prec_value < 0)
        {
            fmt->prec_dot = 0;
            fmt->prec_value = 0;
        }
        while (ft_isdigit(str[i]))
        {
        	fmt->prec_value = fmt->prec_value * 10 + (str[i] - '0'); 
    	    i++;
        }
    }
    if (fmt->prec_value < 0)
        fmt->prec_dot = 0;
    return (i);
}

/*
int check_type(char c, t_format *fmt, int i, char **str, char *w)
{
	fmt->type = c;
    i++;
    if (c == 's')
        *str = ft_strdup(va_arg(fmt->arg_list, char *));
    if (c == 'c' || c == '%')
        *w = (char)va_arg(fmt->arg_list, int);
 //   if (c == 'i' || c == 'd')
//if (c=='i') || (c=='d') *str = ft_itoa(va_arg(fmt->arg_list, int));//leaks !!!
    return(i);
}
*/
int check_type(char c, t_format *fmt, int i, char **str, char *w)
{
	fmt->type = c;
    int nbr;

    i++;
    if (c == 's')
        *str = ft_strdup(va_arg(fmt->arg_list, char *));
    if (c == 'c')
        *w = (char)va_arg(fmt->arg_list, int);
    if (c == 'i' || c == 'd')
    {
        nbr = va_arg(fmt->arg_list, int);
        if (nbr < 0)
        {
            nbr = nbr * -1;
            fmt->neg = 1;
        }
        *str = ft_itoa(nbr);
    }
    return(i);
}