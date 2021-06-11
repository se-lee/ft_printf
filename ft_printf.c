#include "ft_printf.h"

void    fmt_init(t_format *fmt)
{
    fmt->minus = 0;
    fmt->zero = 0;
    fmt->width = 0;
    fmt->prec_dot = 0;
    fmt->prec_value = 0;
    fmt->type = 'a';
    fmt->printf_len = 0;
}

int	check_flags(char *c, t_format *fmt, int i)
{
	//printf("in check falg i = %d\n", i);//
	if (c[i] == '-')
	{
		fmt->minus = 1;
		i++;
	}
	else if (c[i] == '0')
	{
	//	printf("here\n");//
		fmt->zero = 1;
		i++;
	}
	return (i);
}

//!! Width and Precision !! not working correctly 
int check_width(char *str, t_format *fmt, int i) 
{
	if (str[i] == '*')
	{
		fmt->width = (int)fmt->arg_list;
		i++;
	}
	else if (ft_isdigit(str[i]))
	{
		fmt->width = fmt->width * 10 + (str[i] - '0'); //??
		i++;
	}
    return (i);
}

int check_precision(char *str, t_format *fmt, int i)
{
	if (str[i] == '.')
	{
		fmt->prec_dot = 1;
		fmt->prec_value = fmt->prec_value * 10 + (str[i] - '0'); //??
		i++;
	}
    return (i);
}

//!! Type not working correctly
int check_type(char c, t_format *fmt, int i)
{
	fmt->type = c;
    i++;
    return(i);
}

int read_format(char *str, t_format *fmt, int i)
{
    fmt_init(fmt);
	i = check_flags(str, fmt, i);
	i = check_width(str, fmt, i);
	i = check_precision(str, fmt, i);
	// printf("i = %d\n", i);//
	// printf("str = %s\n", &str[i]);//
	i = check_type(str[i], fmt, i);//in check type you have your displaying fct
	printf("minus = %d, zero = %d, width = %d, prec_dot = %d, prec_value = %d, type = %c, len = %d\n", fmt->minus, fmt->zero, fmt->width, fmt->prec_dot, fmt->prec_value, fmt->type, fmt->printf_len);//
	return (i);
}

char *apply_padding(t_format fmt)
{
    char *padding;

    padding = calloc(fmt.width, sizeof(char));
    if (fmt.zero == 1)
    {
        padding = ft_memset(padding, '0', fmt.width); //or fmt->prec_value?
    }
    else
        padding = ft_memset(padding, ' ', fmt.width);
    return (padding);
}

int type_char(t_format fmt)
{
    char *result_c;
	char arg_char;

	arg_char = (char)va_arg(fmt.arg_list, int);
    if (fmt.width > 0)
    {
        result_c = apply_padding(fmt);
    }
    if (fmt.minus == 1)
    {
        result_c = ft_memcpy(result_c, fmt.arg_list, sizeof(char));
    }
    else if (fmt.minus == 0)//check if there's zero
    {
	printf("here\n");//!!
        result_c = ft_memcpy(fmt.arg_list, result_c, sizeof(char));
    }
	else
	{
		ft_putchar_fd(arg_char, 1);
		return (1);
	}
    return (ft_strlen(result_c));
}

int type_str(t_format fmt)
{
    char *result_str;
    char *arg_str;

	arg_str = NULL;
    if (fmt.width > 0 && fmt.width > ft_strlen((char*)fmt.arg_list))
        result_str = apply_padding(fmt);
    if (fmt.prec_value < ft_strlen((char*)fmt.arg_list))
    {
        arg_str = ft_memcpy(arg_str, fmt.arg_list, fmt.prec_value);
    }
    if (fmt.minus == 1) //
    {
        result_str = ft_memcpy(result_str, arg_str, fmt.width);
    }
    else if (fmt.minus == 0)
    {
        result_str = ft_memcpy(arg_str, result_str, fmt.width);
    }
    ft_putstr_fd(result_str, 1);
    return (ft_strlen(result_str));
}


/*
int type_int(t_format fmt)
{
    char *result_int;
    char *args_int;
    char *sign;

    if (fmt.arg_list < 0)
    {
        fmt.arg_list = fmt.arg_list * -1;
        sign = ft_strdup('-');
    }
    args_int = itoa(args);
    if (fmt.prec_value > ft_strlen(args_int))
    {
        //fill zeros
    }
    if (sign != 0)
    {

    }
}
*/

int apply_type(t_format fmt)
{
    if (fmt.type == 'c' || fmt.type == '%')
        return (type_char(fmt));
    else if (fmt.type == 's')
        return (type_str(fmt));
    // else if (fmt.type == 'i' || fmt.type == 'd')
    //     return (type_int(fmt));
    // else if (fmt.type == 'u')
    //     return (type_uint(fmt));
    // else if (fmt.type == 'x' || fmt.type == 'X')
    //     return (type_hexa(fmt));
    // else if (fmt.type == 'p')
    //     return (type_ptr(fmt));
    return (-1); //error 
}

int ft_printf(const char *str, ...)
{
    t_format fmt;
    int i;

    va_start(fmt.arg_list, str);
    i = 0;
    if (!str)
        return (0);
    while(str[i] != '\0')
    {
        if(str[i] != '%')
		{
            ft_putchar_fd(str[i], 1);
			i++;
		}
		else
        {
			i++;
            i += read_format((char*)str, &fmt, i);
			fmt.printf_len = apply_type(fmt);
        }
    }

// printf("(fmt %c)\n", fmt.type);
    return (fmt.printf_len);
}

int	main()
{
	ft_printf("%c\n", 'A');
	// printf("printf= %c\n", 'A');
	return (0);
}
