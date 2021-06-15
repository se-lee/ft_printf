#include "ft_printf.h"

int	type_char(t_format fmt)
{
	char	pad;
	int		i;

	i = 0;
	if (fmt.width > 1)
	{
		pad = set_zero_or_space(fmt);
		if (fmt.minus == 0)
		{
			while (i < fmt.width - 1)
			{
				ft_putchar_fd(pad, 1);
				i++;
			}
		}
	}
	ft_putchar_fd(fmt.c, 1);
	if (fmt.minus == 1)
	{
		i++;
		while (i < fmt.width)
		{
			ft_putchar_fd(pad, 1);
			i++;
		}
	}
	i++;
	fmt.printf_len = i;
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
		if (fmt.minus == 1)
			result_str = ft_strjoin(fmt.str, temp); 
		else if (fmt.minus == 0)
			result_str = ft_strjoin(temp, fmt.str); 
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

int	type_int(t_format *fmt)
{
	//int		arg_int;
	char	*result_int;
	char	*int_char;
	char	*sign;
	if (!(fmt->str))
		return (0);
	if ((fmt->prec_value < ft_strlen(fmt->str)) && (fmt->prec_dot == 1))
	{

	}
	// if ((int)fmt->arg_list < 0)
	// {
	// 	arg_int = arg_int * -1;
	// 	sign = ft_strdup("-");
	// }

	// if (fmt.prec_value > ft_strlen(fmt.str))
	// {
	//     //fill zeros
	// }
	// if (sign != 0)
	// {

	// }
	result_int = ft_strdup(fmt->str);
	ft_putstr_fd(result_int, 1);
	free(fmt->str);
	free(result_int);
	return (ft_strlen(result_int));
}


//int	type_uint
//int	type_hexa
//int	type_ptr