#include "ft_printf.h"

int read_format(char *str, t_format *fmt, int i)
{
//  i++; 
    fmt_init(fmt);
	i = check_flags(str, fmt, i);
	i = check_width(str, fmt, i);
	i = check_precision(str, fmt, i);
	i = check_type(str[i], fmt, i, &(fmt->str), &(fmt->c));
	return (i);
}


int apply_type(t_format fmt)
{
    if (fmt.type == 'c' || fmt.type == '%')
        return (type_char(fmt));
    else if (fmt.type == 's')
        return (type_str(fmt));
    else if (fmt.type == 'i' || fmt.type == 'd')
        return (type_int(va_arg(fmt.arg_list, int), fmt));
    // else if (fmt.type == 'u')
    //     return (type_uint(fmt));
    // else if (fmt.type == 'x' || fmt.type == 'X')
    //     return (type_hexa(fmt));
    // else if (fmt.type == 'p')
    //     return (type_ptr(fmt));
    return (-1); //error 
}

/*
int apply_type(t_format fmt)
{
    if (fmt.type == 'c' || fmt.type == '%')
        return (type_char(fmt));
    else if (fmt.type == 's')
        return (type_str(fmt));
    else if (fmt.type == 'i' || fmt.type == 'd')
        return (type_int(&fmt));
    // else if (fmt.type == 'u')
    //     return (type_uint(fmt));
    // else if (fmt.type == 'x' || fmt.type == 'X')
    //     return (type_hexa(fmt));
    // else if (fmt.type == 'p')
    //     return (type_ptr(fmt));
    return (-1); //error 
}
*/
int ft_printf(const char *str, ...)
{
    t_format fmt;
    int i;

    va_start(fmt.arg_list, str);
    fmt.printf_len = 0;
    i = 0;
    if (!str)
        return (0);
    while(str[i] != '\0')
    {
        if(str[i] != '%')
		{
            ft_putchar_fd(str[i], 1);
			i++;
            fmt.printf_len++;
		}
		else
        {
			i++;
            i = read_format((char*)str, &fmt, i);
			fmt.printf_len += apply_type(fmt);
        }
    }

    return (fmt.printf_len);
}
