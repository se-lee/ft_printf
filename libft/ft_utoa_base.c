#include "libft.h"

static int	ft_len_nbr(unsigned int n, int base_len)
{
	unsigned int	i;
	long long int	nbr;

	nbr = (long long int)n;
	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr >= base_len)
	{
		nbr /= base_len;
		i++;
	}
	return (i);
}

char	*ft_utoa_base(unsigned int n, const char *base)
{
	int				i;
	char			*str;
	int				len;
	long long int	nbr;
	int				base_len;

	nbr = (long long int)n;
    base_len = ft_strlen(base);
	len = ft_len_nbr(n, base_len);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	i = len - 1;
	while (nbr >= base_len)
	{
		str[i] = base[nbr % base_len];
		nbr /= base_len;
		i--;
	}
	str[i] = base[nbr % base_len];
	return (str);
}
