
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	if(!str)
		return (0);
	while (*str != '\0')
	{
		if(*str != '%')
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
	}
	va_end(args);
	return (0);
}

int	main()
{
	ft_printf("hello thank you byebye");
	
	return (0);
}