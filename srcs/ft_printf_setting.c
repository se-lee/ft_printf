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
