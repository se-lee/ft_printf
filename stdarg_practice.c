#include <stdio.h>
#include <stdarg.h>

void	print_ints(int num, ...)
{
	va_list	args;
	int		i;
	int		value;

	i = 0;
	va_start(args, num);
	printf("ints:\t");
	while (i < num)
	{
		value = va_arg(args, int);
		printf("%d ",value);
		i++;
	}
	printf("\n");
	va_end(args);
}

void	print_chars(int num, ...)
{
	va_list args;
	int		i;
	char	c;
	
	i = 0;
	va_start(args, num);
	printf("chars:\t");
	while (i < num)
	{
		c = va_arg(args, int);
		printf("%c ", c);
		i++;
	}
	printf("\n");
	va_end(args);
}

void	print_str(int num, ...)
{
	va_list	args;
	int		i;
	char	*str;

	i = 0;
	va_start(args, num);
	printf("str:\t");
	while (i < num)
	{
		str = va_arg(args, char*);
		printf("%s ", str);
		i++;
	}
	printf("\n");
	va_end(args);
}

int main()
{
	print_ints(7, 1, 2, 8, 4, 78, 93055, 468);
	print_chars(7, 'a', 'b', 'd', 'e', 'i', 'y', 'z');
	print_str(7, "hello", "thanks", "bye", "hiiii", "bonjour", " ", "42");
	
	return (0);
}
