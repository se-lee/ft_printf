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
	if (padding == NULL)
		return (-1);
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
	if (!str)
		result_str = ft_strdup("(null)");
	else
		result_str = ft_strdup(str);
	if ((fmt->prec_value < ft_strlen(result_str)) && (fmt->prec_dot == 1))
	{
		temp = result_str;
		result_str = ft_substr(temp, 0, fmt->prec_value);
		free(temp);
	}
	if (fmt->width > ft_strlen(result_str))
		apply_padding_free(fmt, &result_str,
			(fmt->width - ft_strlen(result_str)));
	if (result_str == NULL)
		return (-1);
	ft_putstr_fd(result_str, 1);
	fmt->printf_len = ft_strlen(result_str);
	free(result_str);
	return (fmt->printf_len);
}
