#include "ft_printf.h"

int	type_char(t_format *fmt, char c)
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


int	type_str(t_format *fmt)
{
	char	*result_str;
	char	*temp;
	int	i;

	i = 0;
	result_str = NULL;
	temp = NULL;
	if (!(fmt->str))
		return (0);
	if ((fmt->prec_value < ft_strlen(fmt->str)) && (fmt->prec_dot == 1))
	{
		temp = fmt->str;
		fmt->str = ft_substr(temp, 0, fmt->prec_value); 
		free(temp);
	}
	if (fmt->width > ft_strlen(fmt->str))
	{
		temp = apply_padding(fmt, (fmt->width - ft_strlen(fmt->str)));
		result_str = sort_left_right(fmt, fmt->str, temp);
		free(temp);
	}
	else
		result_str = ft_strdup(fmt->str);
	ft_putstr_fd(result_str, 1);
	fmt->printf_len = ft_strlen(result_str);
	free(result_str);
	free(fmt->str);
	return (fmt->printf_len);
}


int	type_int(int nbr, t_format *fmt) 
{
	char	*result_int;

	result_int = NULL;
	if (fmt->prec_dot == 1 && nbr == 0)
		result_int = ft_strdup(""); 
	else if (nbr < 0)
		result_int = ft_itoa(nbr * -1);
	else
		result_int = ft_itoa(nbr); 
	if (ft_strlen(result_int) < fmt->prec_value)
	{
		fmt->zero = 1;
		apply_precision_free(fmt, &result_int, fmt->prec_value - ft_strlen(result_int));
	}
	if (nbr < 0)
		ft_append(&result_int, "-");
	if (ft_strlen(result_int) < fmt->width)
	{
		fmt->zero = 0;
		apply_padding_free(fmt, &result_int, fmt->width - ft_strlen(result_int));
	}
	ft_putstr_fd(result_int, 1);
	fmt->printf_len = ft_strlen(result_int);
	free(result_int);
	return (fmt->printf_len);
}

/*

int	type_int(t_format *fmt)
{
	char	*result_int; //final output
	char	*sign;
	char	*temp; 
 	char	*width_pad; 
	char	*prec_zero; 
//	int		nbr;

	result_int = NULL;
	temp = NULL;
	prec_zero = NULL; 
	width_pad = NULL;; 
	sign = ft_strdup("");
// nbr =va_arg(fmt->arg_list, int);
// printf("nb:%d ", nbr);

	if (!(fmt->str))
		return (0);
	if (fmt->prec_dot == 1 && fmt->str == '0')
		result_int = ft_strdup(""); 
	if (ft_strlen(fmt->str) < fmt->prec_value)
	{
		fmt->zero = 1;
		temp = apply_padding(*fmt, (fmt->prec_value - ft_strlen(fmt->str)));
		prec_zero = ft_strjoin(temp, fmt->str); 
		free(temp);
	}
	if (ft_strlen(prec_zero) < fmt->width)
	{
		fmt->zero = 0;
		width_pad = apply_padding(*fmt, fmt->width - ft_strlen(prec_zero));
	}
	else if (fmt->width <= ft_strlen(prec_zero))
		width_pad = ft_strdup("");
	result_int = sort_left_right(*fmt, prec_zero, width_pad); 
	ft_putstr_fd(result_int, 1);
	fmt->printf_len = ft_strlen(result_int);
	free(sign);
	free(prec_zero);
	free(width_pad);
	free(fmt->str);
	free(result_int);
	return (fmt->printf_len);
}
*/

int	type_uint(unsigned int nbr, t_format *fmt)
{
	char	*result_uint;

	result_uint = NULL;
	if (fmt->prec_dot == 1 && nbr == 0)
		result_uint = ft_strdup(""); 
	else
		result_uint = ft_utoa_base(nbr, "0123456789"); 
	if (ft_strlen(result_uint) < fmt->prec_value)
	{
		fmt->zero = 1;
		apply_precision_free(fmt, &result_uint, fmt->prec_value - ft_strlen(result_uint));
	}
	if (ft_strlen(result_uint) < fmt->width)
	{
		fmt->zero = 0;
		apply_padding_free(fmt, &result_uint, fmt->width - ft_strlen(result_uint));
	}
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
	if (ft_strlen(result_uint) < fmt->prec_value)
	{
		fmt->zero = 1;
		apply_precision_free(fmt, &result_uint, fmt->prec_value - ft_strlen(result_uint));
	}
	if (ft_strlen(result_uint) < fmt->width)
	{
		fmt->zero = 0;
		apply_padding_free(fmt, &result_uint, fmt->width - ft_strlen(result_uint));
	}
	ft_putstr_fd(result_uint, 1);
	fmt->printf_len = ft_strlen(result_uint);
	free(result_uint);
	return (fmt->printf_len);
}