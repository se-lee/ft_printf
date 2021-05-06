
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	//t_format	format;
	int	i;
	int	c;
	char type;

	va_start(args, str);
	i = 0;
	if(!str)
		return (0);
	while (str[i] != '\0')
	{
		if(str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i += 1;
		}

		/* else   (when str[i] == '%')
			find format [flags][width][.precision][length]csiduxX%


			- need buffer? to store temporary data?
			how to print?
		*/
		else
		{
			i += 1;
			type = str[i];
			if (type == 'c')
				c = ft_type_char(va_arg(args, int));
			else if (type == '%')
				ft_type_char('%');
			else if (type == 'd' || type == 'i')
				ft_putnbr_fd(va_arg(args, int), 0);
			i += 1;
		}
	}
	va_end(args);
	return (0);
}

/*
function : ft_error_case -- handles error/exceptions

function : ft_find_format -- checks options and type (t_format format)

function : ft_type_char -- handles c (if format.type equals c)
function : ft_type_str -- handles s
function : ft_type_int -- handles i, d
function : ft_type_uint -- handles u
function : ft_type_hexa -- handles x, X

ft_output_type

option functions ---
minus :
zero :
width :
precision :
length :
*/

int	ft_type_char(int chr)
{
	ft_putchar_fd((char)chr, 1);
	return (0);
}

int	main()
{
	char a;
	a = 'a';
	ft_printf("%c number=%d %% %c %c\n", a, 42, 'b', 'c');
	//printf("%c %c %c\n", a, 'b', 'c');
	return (0);
}
