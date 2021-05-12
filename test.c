
#include "ft_printf.h"
bool	read_number(const char *str, int *i, int *result)
{
	bool success;
	bool negative;

	*result = 0;
	if (str[*i] == '-')
	{
		negative = true;
		*i += 1;
	}
	else
		negative = false;
	success = false;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result = *result * 10 + (str[*i] - '0');
		(*i)++;
		success = true;
	}
	if (negative)
		*result = - *result;
	return (success);
}

// when a number is read --> use the value of "result" to determine the padding size
// set padding using "result" 

int	ft_type_char(int chr)
{
	ft_putchar_fd((char)chr, 1);
	return (0);
}

void	ft_type_str(char *str, int width)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	while (i < width)
	{
		ft_putchar_fd(' ', 1);		
		i++;
	}
}

int	ft_type_int(int num)
{
	ft_putnbr_fd(num, 1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	char type;
	int width;

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
		else //when '%' is found
		{
			i += 1;
			read_number(str, &i, &width);
			type = str[i];
			if (type == 'c')
				ft_type_char(va_arg(args, int));
			else if (type == 's')
				ft_type_str(va_arg(args, char*), width);
			else if (type == '%')
				ft_type_char('%');
			else if (type == 'd' || type == 'i')
				ft_type_int(va_arg(args, int));
			i += 1;
		}
	}
	va_end(args);
	return (0);
}

int	main()
{
	char a;
	
	a = 'a';
	
	int i = 14;
	int result;
	char *input = "number=%d %% %-80   00c %c %s %s 4%s\n";

	if (read_number(input, &i, &result))
		printf("find_number: %d, it ended at %d\n", result, i);
	else
		printf("No number was found !\n");

	
	ft_printf("%c number=%d %% %c %10c %3s %s %s\n", a, '*', 'b', 65, "hello", "good", "bye");
	printf("%c number=%d %% %c %10c %3s %1.2s %s\n", a, '*', 'b', 65, "hello", "good", "bye");
	return (0);
}
