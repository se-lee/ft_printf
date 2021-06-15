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
	int	i;

	i = 0;
	result_str = NULL;
	if (!(fmt.str))
		return (0);
	if ((fmt.prec_value < ft_strlen(fmt.str)) && (fmt.prec_value != 0))
		fmt.str = ft_substr(fmt.str, 0, fmt.prec_value); //substr does malloc
	if (fmt.width > ft_strlen(fmt.str))
	{
		result_str = apply_padding(fmt, fmt.width - ft_strlen(fmt.str)); //malloc 
		/* i need free previous result_str in order to do the following (fmt.minus) */
		if (fmt.minus == 1)
			result_str = ft_strjoin(fmt.str, result_str); //strjoin does malloc
		else if (fmt.minus == 0)
			result_str = ft_strjoin(result_str, fmt.str); //strjoin does malloc
	}
	else
		result_str = ft_strdup(fmt.str); //does malloc
	ft_putstr_fd(result_str, 1);
	fmt.printf_len = ft_strlen(result_str);
	free(result_str);
	if ((fmt.prec_value < ft_strlen(fmt.str)) && (fmt.prec_value != 0))
		free(fmt.str);
	return (fmt.printf_len);
}

int	type_int(t_format *fmt)//leaks !
{
	int		arg_int;
	char	*result_int;
	char	*int_char;
	char	*sign;

	arg_int = (int)fmt->arg_list;
	if ((int)fmt->arg_list < 0)
	{
		arg_int = arg_int * -1;
		sign = ft_strdup("-");
	}
	int_char = ft_itoa(arg_int);
	// if (fmt.prec_value > ft_strlen(args_int))
	// {
	//     //fill zeros
	// }
	// if (sign != 0)
	// {

	// }
//    result_int = ft_strdup(int_char);
	ft_putstr_fd(int_char, 1);
	free(fmt->str);
	return (ft_strlen(result_int));
}
