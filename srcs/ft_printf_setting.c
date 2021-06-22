#include "ft_printf.h"

char	*apply_padding(t_format *fmt, int len)
{
	char	*padding;

	padding = ft_calloc(len + 1, sizeof(char));
	if (padding == NULL)
		return (NULL);
	if (fmt->zero == 1)
		padding = ft_memset(padding, '0', len);
	else
		padding = ft_memset(padding, ' ', len);
	return (padding);
}

void	ft_append(char **a, char *str)
{
	char	*result;

	result = ft_strjoin(str, *a);
	free(*a);
	*a = result;
}

void	apply_padding_free(t_format *fmt, char **str, int len)
{
	char	*padding;
	char	*result;

	result = NULL;
	padding = apply_padding(fmt, len);
	if (fmt->minus == 1)
		result = ft_strjoin(*str, padding);
	else if (fmt->minus == 0)
		result = ft_strjoin(padding, *str);
	free(*str);
	*str = result;
	free(padding);
}

void	apply_precision_free(t_format *fmt, char **str, int len)
{
	char	*fill_zero;
	char	*result;
	int		was_zero;

	result = NULL;
	was_zero = fmt->zero;
	fmt->zero = 1;
	fill_zero = apply_padding(fmt, len);
	fmt->zero = was_zero;
	result = ft_strjoin(fill_zero, *str);
	free(*str);
	*str = result;
	free(fill_zero);
}

void	apply_zero(t_format *fmt, int *nbr, char **str)
{
	if (fmt->zero == 0)
	{
		if (*nbr < 0)
			ft_append(str, "-");
		if (ft_strlen(*str) < fmt->width)
			apply_padding_free(fmt, str, fmt->width - ft_strlen(*str));
	}
	else
	{
		if (ft_strlen(*str) < fmt->width)
			apply_padding_free(fmt, str,
				fmt->width - ft_strlen(*str) - (*nbr < 0));
		if (*nbr < 0)
			ft_append(str, "-");
	}
}
