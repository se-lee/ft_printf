#include "ft_printf.h"

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
		apply_precision_free(fmt, &result_int,
			fmt->prec_value - ft_strlen(result_int));
	apply_zero(fmt, &nbr, &result_int);
	if (result_int == NULL)
		return (-1);
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
	if (result_uint == NULL)
		return (-1);
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
	if (result_uint == NULL)
		return (-1);
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
	if (result_ptr == NULL)
		return (-1);
	ft_putstr_fd(result_ptr, 1);
	fmt->printf_len = ft_strlen(result_ptr);
	free(result_ptr);
	return (fmt->printf_len);
}
