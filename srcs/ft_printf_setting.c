#include "ft_printf.h"

char *apply_padding(t_format fmt, int len)
{
    char *padding;

    padding = ft_calloc(len + 1, sizeof(char)); //malloc
    if (fmt.zero == 1)
        padding = ft_memset(padding, '0', len); //no malloc
    else
        padding = ft_memset(padding, ' ', len);
    return (padding);
}

char  *sort_left_right(t_format fmt, char *str, char *padding)
{
    char    *result;

    result = NULL;
    if (fmt.minus == 1)
        result = ft_strjoin(str, padding);       
    else if (fmt.minus == 0 )
        result = ft_strjoin(padding, str);
    return (result);
}

char    *apply_precision(t_format fmt)
{
    char    *pad_zero = NULL;
    char    *result = NULL;
    if (ft_strlen(fmt.str) < fmt.prec_value)
    {
        fmt.zero = 1;
        pad_zero = apply_padding(fmt, fmt.prec_value - ft_strlen(fmt.str));
    }
    else if (fmt.prec_value < ft_strlen(fmt.str))
        pad_zero = ft_strdup("");
 //printf("padzero: %s ", pad_zero);
    result = ft_strjoin(pad_zero, fmt.str);
 //printf("res: %s ", result);
    free(pad_zero);
    return (result);
}

char    *apply_width(t_format fmt)
{
    char    *pad_width = NULL;
    char    *result = NULL;

    if (ft_strlen(fmt.str) < fmt.width)
	{
		fmt.zero = 0;
		pad_width = apply_padding(fmt, fmt.width - ft_strlen(fmt.str)); //malloc
	}
	else if (fmt.width <= ft_strlen(fmt.str))
		pad_width = ft_strdup("");
    result = sort_left_right(fmt, fmt.str, pad_width);
    free(pad_width);
    return (result);
}