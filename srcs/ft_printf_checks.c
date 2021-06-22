#include "ft_printf.h"

void	fmt_init(t_format *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->width = 0;
	fmt->prec_dot = 0;
	fmt->prec_value = 0;
	fmt->type = '\0';
}

int	check_flags(char *str, t_format *fmt, int i)
{
	while (str[i] && (str[i] == '0' || str[i] == '-'))
	{
		if (str[i] == '-')
		{
			fmt->minus = 1;
			fmt->zero = 0;
		}
		else if (fmt->minus != 1)
			fmt->zero = 1;
		i++;
	}
	return (i);
}

int	check_width(char *str, t_format *fmt, int i)
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
		fmt->zero = 0;
	}
	return (i);
}

int	check_precision(char *str, t_format *fmt, int i)
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

int	check_type(char *str, t_format *fmt, int i)
{
	char	c;

	c = str[i];
	if (c && (c == 'd' || c == 'i' || c == '%' || c == 's'
			|| c == 'c' || c == 'x' || c == 'X' || c == 'u' || c == 'p'))
		fmt->type = str[i++];
	else
	{
		fmt->printf_len++;
		fmt->type = '\0';
	}
	return (i);
}
