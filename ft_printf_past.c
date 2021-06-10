#include "ft_printf.h"

void	fmt_init(t_format *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->width = 0;
	fmt->precision_dot = 0;
	fmt->precision_value = 0;
	fmt->type = 0;
	fmt->return_printf = 0;
}

void	read_format(char *str, va_list args) 
{
	t_format *fmt;
	int	i;

	i = 0;
	while (str)  //&& when type csx... is not found
	{
		if (str[i] == '-')
			fmt->minus = 1;
		else if (str[i] == '0')
			fmt->zero = 1;
		else if (str[i] == '.')
		{
			fmt->precision_dot = 1; 
		}
		else if (str[i] == '*' || ft_isdigit(str[i]))
		{
			set_width_precision(str[i], &fmt, args)
		}
		i++;
	}
}

void	set_width_precision(char c, t_format *fmt, va_list args) 
{//a function to store value to fmt.width or fmt.precision_value
	if (ft_isdigit((int)c))
	{
		if (fmt->precision_dot == 0)
			fmt->width = fmt->width * 10 + (c - '0');
		else // if fmt->precision_dot == 1
			fmt->precision_value = fmt->precision_value * 10 + (c - '0');
	}
	else if (c == '*') //??
	{
		/* how to use va_arg*/
		fmt->width = va_arg(args, int); //not sure
	}
}

char	*apply_padding(t_format *fmt) 
{//a function to fill '0' or ' '
	char *padding;

	padding = ft_calloc(fmt->width, sizeof(char));
	if (fmt->zero == 0)	
		ft_memset(padding, ' ', fmt->width);
	return (padding);
}

int	ft_type_char(int chr, t_format fmt)
{
	int	len;
	

	ft_putchar_fd((char)chr, 1);
	return (0);
}
int	ft_type_str(char *str, t_format fmt)
{
	ft_putstr_fd(str, 1);
	return (0);
}
/*
int	ft_type_int(int num, t_format fmt) // itoa
{
	ft_putnbr_fd(num, 1);
	return (0);
}
int ft_type_unit(int num) // ---- difference between type_int & type_unit??
{
	ft_putnbr_fd(num, 1);
	return (0);
}
char *ft_type_hexa(int deci)
{
	char *hexa;
	//hexadecimal conversion _____ /16
	// 
	return (hexa);
}
*/

char	*display_final(va_list args, t_format fmt)
{
	char	*rtn;
	int		i;
	
	i = 0;
	while ()

//	fmt.return_printf ----- store the entire length of final display
//  apply padding
// 	apply type (conversion)
// 	
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_format	fmt;
	int	i;

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
		else
		{
			fmt_init(fmt);
			read_format((char *)str);
			i += 1;
		}
	}
	va_end(args);
	return (/*fmt.return_printf*/);
}


int	main()
{
	t_format fmt;
	char a;
	a = 'a';
	char *str;
	str = "-5d";
	read_format(str, &fmt);
	printf("minus: %d", fmt.minus);

/*
	ft_printf("%c number=%d %% %c %c %s %s %s\n", a, '*', 'b', 65, "hello", "good", "bye");
	printf("%c number=%d %% %4c %c %s %s %s\n", a, '*', 'b', 65, "hello", "good", "bye");
*/
	return (0);
}
