#include "ft_printf.h"

void	fmt_init(t_format fmt)
{
	fmt.minus = 0;
	fmt.zero = 0;
	fmt.width = -1;
	fmt.precision_dot = 0;
	fmt.precision_value = 0;
	fmt.type = 0;
	fmt.return_printf = 0;
}
void read_format(char *str) 
{
	t_format	fmt;
	int	i;

	i = 0;
	fmt_init(fmt);
	
	while (str) //REVISE condition: Start after '%', but end where?  
	{
		if (str[i] == '-')
			fmt.minus = 1;
		else if (str[i] == '0')
			fmt.zero = 1;
		else if (str[i] == '.')
		{
			fmt.precision_dot = 1; 
		}
		else if (str[i] == '*' || ft_isdigit(str[i]))
		{
			fmt.width = 0;
		}
//		else if (str[i] == <the specifier character>)
// 			fmt.type = <the specifier>
	}
}

void	set_width(t_format fmt, char **str) //store the value of width to fmt.width
{
	int	num;
	c = &str[i];
	va_list args;

	if (fmt.width == 1)
	{
	//add a loop to cover if the number has more than 1 digit?
		while (ft_isdigit((int)c))
		{
			fmt.width *= 10 + (c - '0'); //convert char to int;
			(c)++;
		}
	}
	else if (c == '*')
	{
		fmt.width = va_arg(args, int); //not sure
	}
}
char	*apply_padding(t_format fmt) 
{
	char *padding;

	padding = ft_calloc(fmt.width, sizeof(char));
	if (fmt.zero == 0)	
		ft_memset(padding, ' ', fmt.width);
	return (padding);
}

void	apply_precision(t_format fmt, char c)
{
	if (fmt.precision_dot == 1)
		fmt.precision_value = c - '0'; //REVISE
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
int ft_type_ptr(int ptr)
{
//	return pointer address
}

char	*display_final(va_list args, t_format fmt)
{
	char	*rtn;
	int		i;
	
	i = 0;
//	fmt.return_printf ----- store the entire length of final display

//	rtn[i] = 
}


int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_format	fmt;
	int	i;
	char type;
	int	str_len;

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
			i += 1;
		read_format((char *)str);
			i += 1;
		}
	}
	va_end(args);
	return (str_len);
}

int	main()
{
	t_format fmt;
	char a;
	a = 'a';
	char *str;
	str = "hello %15d";
	read_format(str);
	printf("minus: %d", fmt.width);

/*
	ft_printf("%c number=%d %% %c %c %s %s %s\n", a, '*', 'b', 65, "hello", "good", "bye");
	printf("%c number=%d %% %4c %c %s %s %s\n", a, '*', 'b', 65, "hello", "good", "bye");
*/
	return (0);
}
