#include "ft_printf.h"

int	read_format(char *str, t_format *fmt, int i)
{
	fmt_init(fmt);
	i = check_flags(str, fmt, i);
	i = check_width(str, fmt, i);
	i = check_precision(str, fmt, i);
	i = check_type(str, fmt, i);
	return (i);
}

int	apply_type(t_format *fmt)
{
	if (fmt->type == 'c')
		return (type_char((char)va_arg(fmt->arg_list, int), fmt));
	if (fmt->type == '%')
		return (type_char('%', fmt));
	else if (fmt->type == 's')
		return (type_str(va_arg(fmt->arg_list, char *), fmt));
	else if (fmt->type == 'i' || fmt->type == 'd')
		return (type_int(va_arg(fmt->arg_list, int), fmt));
	else if (fmt->type == 'u')
		return (type_uint(va_arg(fmt->arg_list, unsigned), fmt));
	else if (fmt->type == 'x' || fmt->type == 'X')
		return (type_hexa(va_arg(fmt->arg_list, unsigned), fmt));
	else if (fmt->type == 'p')
		return (type_ptr(va_arg(fmt->arg_list, long unsigned), fmt));
	return (-1);
}

int	do_format(const char *str, t_format *fmt, int *i)
{
	int	len_save;
	int	result;

	(*i)++;
	result = read_format((char *)str, fmt, *i);
	if (result < 0)
		return (-1);
	*i = result;
	len_save = fmt->printf_len;
	result = apply_type(fmt);
	if (result < 0)
		return (-1);
	fmt->printf_len = len_save + result;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	t_format	fmt;
	int			i;

	va_start(fmt.arg_list, str);
	fmt.printf_len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i++;
			fmt.printf_len++;
		}
		else if (do_format(str, &fmt, &i) < 0)
		{
			va_end(fmt.arg_list);
			return (-1);
		}
	}
	va_end(fmt.arg_list);
	return (fmt.printf_len);
}
