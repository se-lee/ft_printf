#include "ft_printf.h"

int	type_char(t_format fmt)
{
	char	*padding;
	
	padding = ft_strdup("");
	if (fmt.width > 1)
	{
		free(padding);
		padding = apply_padding(fmt, (fmt.width - 1));
	}
	if (fmt.minus == 1)
	{
	    ft_putchar_fd(fmt.c, 1);
        ft_putstr_fd(padding, 1);
    }
    else if (fmt.minus == 0)
    {
        ft_putstr_fd(padding, 1);
        ft_putchar_fd(fmt.c, 1);
    }
	fmt.printf_len = ft_strlen(padding) + 1;
	free(padding);
	return (fmt.printf_len);
}

int	type_str(t_format fmt)
{
	char	*result_str;
	char	*temp;
	int	i;

	i = 0;
	result_str = NULL;
	temp = NULL;
	if (!(fmt.str))
		return (0);
	if ((fmt.prec_value < ft_strlen(fmt.str)) && (fmt.prec_dot == 1))
	{
		temp = fmt.str;
		fmt.str = ft_substr(temp, 0, fmt.prec_value); 
		free(temp);
	}
	if (fmt.width > ft_strlen(fmt.str))
	{
		temp = apply_padding(fmt, (fmt.width - ft_strlen(fmt.str)));
		result_str = sort_left_right(fmt, fmt.str, temp);
		free(temp);
	}
	else
		result_str = ft_strdup(fmt.str);
	ft_putstr_fd(result_str, 1);
	fmt.printf_len = ft_strlen(result_str);
	free(result_str);
	free(fmt.str);
	return (fmt.printf_len);
}

/*
int	type_int(int nbr, t_format fmt) //(t_format *fmt)
{
	char	*result_int;
	char	*temp; 
 	char	*width_pad;
	char	*sign;

	width_pad = NULL;
	sign = ft_strdup("");
	temp = NULL;
	result_int = NULL;
	if (fmt.prec_dot == 1 && nbr == 0)
		result_int = ft_strdup(""); 
	if (nbr < 0)
	{
		sign = ft_strjoin(sign, ft_strdup("-"));
		fmt.str = ft_itoa(nbr * -1); //malloc
	}
	else
		fmt.str = ft_itoa(nbr);
printf("nb: %d", nbr);
printf("str:%s ", fmt.str);
	// if (ft_strlen(fmt.str) < fmt.prec_value)
	// {
	// 	fmt.zero = 1;
	// 	temp = apply_padding(fmt, (fmt.prec_value - ft_strlen(fmt.str)));
	// 	result_int = ft_strjoin(temp, fmt.str);
	// 	free(temp);
	// }
	// if (ft_strlen(result_int) < fmt.width)
	// {
	// 	fmt.zero = 0;
	// 	width_pad = apply_padding(fmt, fmt.width - ft_strlen(result_int)); //malloc
	// }
	// else if (fmt.width <= ft_strlen(result_int))
	// 	width_pad = ft_strdup("");
//	result_int = sort_left_right(fmt, result_int, width_pad); //malloc
	ft_putstr_fd(result_int, 1);
	fmt.printf_len = ft_strlen(result_int);
	free(sign);
	free(width_pad);
	free(fmt.str);
	free(result_int);
	return (fmt.printf_len);
}*/

int	type_int(t_format *fmt)
{
	char	*result_int; //final output
	char	*sign;
	char	*temp; 
 	char	*width_pad; 
	char	*prec_zero; 
	int		nbr;

	result_int = NULL;
	temp = NULL;
	prec_zero = NULL; 
	width_pad = NULL;; 
	sign = ft_strdup("");
printf("nb:%d ", nbr);

	if (!(fmt->str))
		return (0);
	if (fmt->prec_value < ft_strlen(fmt->str))
		prec_zero = ft_strdup(fmt->str);
	else if (ft_strlen(fmt->str) < fmt->prec_value)
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
	free(prec_zero);
	free(width_pad);
	free(fmt->str);
	free(result_int);
	return (fmt->printf_len);
}
