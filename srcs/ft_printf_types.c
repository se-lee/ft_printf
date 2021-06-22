#include "ft_printf.h"

int	type_char(char c, t_format *fmt)
{
	char	*padding;

	padding = ft_strdup("");
	if (fmt->width > 1)
	{
		free(padding);
		padding = apply_padding(fmt, (fmt->width - 1));
	}
	if (fmt->minus == 1)
	{
		ft_putchar_fd(c, 1);
		ft_putstr_fd(padding, 1);
	}
	else if (fmt->minus == 0)
	{
		ft_putstr_fd(padding, 1);
		ft_putchar_fd(c, 1);
	}
	fmt->printf_len = ft_strlen(padding) + 1;
	free(padding);
	return (fmt->printf_len);
}

int	type_str(char *str, t_format *fmt)
{
	char	*result_str;
	char	*temp;
	int		i;

	i = 0;
	result_str = NULL;
	temp = NULL;
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if ((fmt->prec_value < ft_strlen(str)) && (fmt->prec_dot == 1))
	{
//		result_str = ft_substr(str, 0, fmt->prec_value);
		temp = str;
		str = ft_substr(temp, 0, fmt->prec_value);
		free(temp);
	}
	if (fmt->width > ft_strlen(str))
	{
//		apply_padding_free(fmt, &result_str, (fmt->width - ft_strlen(str)));
		temp = apply_padding(fmt, (fmt->width - ft_strlen(str)));
		result_str = sort_left_right(fmt, str, temp);
		free(temp);
	}
	else
		result_str = ft_strdup(str);
	ft_putstr_fd(result_str, 1);
	fmt->printf_len = ft_strlen(result_str);
	free(result_str);
	free(str);
	return (fmt->printf_len);
}

int	type_int(int nbr, t_format *fmt)
{
	char	*result_int;

	result_int = NULL;
	if (fmt->prec_dot == 1 && nbr == 0)
		result_int = ft_strdup("");
	else if (nbr < 0)
		result_int = ft_utoa_base(((long int)nbr) * -1, "0123456789");
	else
		result_int = ft_itoa(nbr);
	if (fmt->prec_dot)
		fmt->zero = 0;
	if (ft_strlen(result_int) < fmt->prec_value)
		apply_precision_free(fmt, &result_int, fmt->prec_value - ft_strlen(result_int));

	apply_zero(fmt, &nbr, &result_int);
	// if (fmt->zero == 0)
	// {
	// 	if (nbr < 0)
	// 		ft_append(&result_int, "-");
	// 	if (ft_strlen(result_int) < fmt->width)
	// 		apply_padding_free(fmt, &result_int, fmt->width - ft_strlen(result_int));
	// }
	// else //if fmt->zero == 1
	// {
	// 	if (ft_strlen(result_int) < fmt->width)
	// 		apply_padding_free(fmt, &result_int, fmt->width - ft_strlen(result_int) - (nbr < 0));
	// 	if (nbr < 0)
	// 		ft_append(&result_int, "-");
	// }

	ft_putstr_fd(result_int, 1);
	fmt->printf_len = ft_strlen(result_int);
	free(result_int);
	return (fmt->printf_len);
}

int	type_uint(unsigned int nbr, t_format *fmt)
{
	char	*result_uint;

	result_uint = NULL;
	if (fmt->prec_dot == 1 && nbr == 0)
		result_uint = ft_strdup("");
	else
		result_uint = ft_utoa_base(nbr, "0123456789");
	if (fmt->prec_dot)
		fmt->zero = 0;
	if (ft_strlen(result_uint) < fmt->prec_value)
		apply_precision_free(fmt, &result_uint,
			fmt->prec_value - ft_strlen(result_uint));
	if (ft_strlen(result_uint) < fmt->width)
		apply_padding_free(fmt, &result_uint,
			fmt->width - ft_strlen(result_uint));
	ft_putstr_fd(result_uint, 1);
	fmt->printf_len = ft_strlen(result_uint);
	free(result_uint);
	return (fmt->printf_len);
}

int	type_hexa(unsigned int	nbr, t_format *fmt)
{
	char	*result_uint;

	result_uint = NULL;
	if (fmt->prec_dot == 1 && nbr == 0)
		result_uint = ft_strdup("");
	else if (fmt->type == 'x')
		result_uint = ft_utoa_base(nbr, "0123456789abcdef");
	else if (fmt->type == 'X')
		result_uint = ft_utoa_base(nbr, "0123456789ABCDEF");
	if (fmt->prec_dot)
		fmt->zero = 0;
	if (ft_strlen(result_uint) < fmt->prec_value)
		apply_precision_free(fmt, &result_uint,
			fmt->prec_value - ft_strlen(result_uint));
	if (ft_strlen(result_uint) < fmt->width)
		apply_padding_free(fmt, &result_uint,
			fmt->width - ft_strlen(result_uint));
	ft_putstr_fd(result_uint, 1);
	fmt->printf_len = ft_strlen(result_uint);
	free(result_uint);
	return (fmt->printf_len);
}

int	type_ptr(unsigned long int nbr, t_format *fmt)
{
	char	*result_ptr;

	result_ptr = NULL;
	if (fmt->prec_dot == 1 && nbr == 0)
		result_ptr = ft_strdup("");
	else
		result_ptr = ft_utoa_base(nbr, "0123456789abcdef");
	if (fmt->prec_dot)
		fmt->zero = 0;
	if (ft_strlen(result_ptr) < fmt->prec_value)
		apply_precision_free(fmt, &result_ptr,
			fmt->prec_value - ft_strlen(result_ptr));
	ft_append(&result_ptr, "0x");
	if (ft_strlen(result_ptr) < fmt->width)
		apply_padding_free(fmt, &result_ptr,
			fmt->width - ft_strlen(result_ptr));
	ft_putstr_fd(result_ptr, 1);
	fmt->printf_len = ft_strlen(result_ptr);
	free(result_ptr);
	return (fmt->printf_len);
}
