#include "ft_printf.h"

char    set_zero_or_space(t_format fmt)
{
    char    pad;

    pad = '\0';
    if (fmt.zero == 1)
        pad = '0';
    else if (fmt.zero == 0)
        pad = ' ';
    return (pad);
}

char *apply_padding(t_format fmt, int len)
{
    char *padding;

    padding = ft_calloc(len, sizeof(char));
    if (fmt.zero == 1)
    {
        padding = ft_memset(padding, '0', len);
    }
    else
        padding = ft_memset(padding, ' ', len);
    return (padding);
}
