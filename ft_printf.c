#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list args;
    t_format fmt;
    int i;

    va_start(args, str);
    i = 0;
    if (!str)
        return (0);
    while(str[i] != '\0')
    {
        if(str[i] != '%')
            ft_putchar_fd(str[i], 1);
        else
        {
            read_format(str[++i], fmt); //? or str[i++] ?
            // call apply_type(fmt, ars);
        }
        i++;
    }

}

void    fmt_init(t_format fmt)
{
    fmt->minus = 0;
    fmt->zero = 0;
    fmt->width = 0;
    fmt->prec_dot = 0;
    fmt->prec_value = 0;
    fmt->type = 0;
    fmt->return_len = 0;
}

t_format read_format(char *str, t_format fmt)
{
    int i;

    i = 0;
    fmt_init(fmt);
    while (str[i] != '\0')
    {
        if (str[i] == '-')
        {
            fmt->minus = 1;

        }
        if (str[i]) == '0')
            fmt->zero = 1;
        
        if (str[i] == '*' || ft_isdigit(str[i]))
            fmt->width = //read_number function
        if (str[i] == '.')
        {
            fmt->prec_dot = 1;
            fmt->prec_value = //read_number;
        }
        i++;
    }   
    fmt->type = str[i];

    return (fmt);
}

/*
int read_number(str, fmt, args);

return (nbr);
*/

char *apply_padding(t_format fmt)
{
    char *padding;

    padding = calloc(fmt->width, sizeof(char));
    if (fmt->zero == 1)
    {
        padding = ft_memset(padding, '0', fmt->width); //or fmt->prec_value?
    }
    else
        padding = ft_memset(padding, ' '. fmt->width);
    return (padding);
}

int apply_type(t_format fmt, va_list args)
{
    if (fmt->type == 'c' || fmt->type == '%')
        return (type_char(fmt, args));
    else if (fmt->type == 's')
        return (type_str(fmt, args));
    else if (fmt->type == 'i' || fmt->type == 'd')
        return (type_int(fmt, args));
    else if (fmt->type == 'u')
        return (type_uint(fmt, args));
    else if (fmt->type == 'x' || fmt->type == 'X')
        return (type_hexa(fmt, args));
    else if (fmt->type == 'p')
        return (type_ptr(fmt, args));
    else   
        return (-1); //error 
}

int type_char(t_format fmt, va_list args)
{
    char *result_c;

    if (fmt->width > 0)
    {
        //call apply_padding(fmt);
    }
    if (fmt->minus == 1) //
    {
        result_c = ft_memcpy(result_c, args) 
    }
    else if (fmt->minus == 0)
    {
        result_c = ft_memcpy(args, result_c);
    }
    ft_putstr_fd(result_c, 1);

    return (ft_strlen(result_c));
}

int type_str(t_format fmt, va_list args)
{
    char *result_str;
    char *arg_str;

    if (fmt->width > 0 && fmt->width > ft_strlen(args))
        result_str = apply_padding(fmt);
    if (fmt->prec_value < ft_strlen(args))
    {
        //cut args
    }
    if (fmt->minus == 1) //
    {
        result_str = ft_memcpy(result_str, args);
    }
    else if (fmt->minus == 0)
    {
        result_str = ft_mempy(args, result_str);
    }
    ft_putstr_fd(result_str, 1);
    return (ft_strlen(result_str));
}

int type_int(t_format fmt, va_list args)
{
    char *result_int;
    char *args_int;
    char *sign;

    if (args < 0)
    {
        args = args * -1;
        sign = ft_strdup('-');
    }
    args_int = itoa(args);
    if (fmt->prec_value > ft_strlen(args_int))
    {
        //fill zeros
    }
    if (sign != 0)
    {

    }
}