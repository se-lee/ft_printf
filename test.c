#include <stdio.h>

int	main()
{
	char *s = "hellooooooooo";	

	printf("c: %c %% %c\n", 116, 68);
	printf("s:%s\n", s);
    printf("s:%10s\t\n\t%-10s\n", s, s);
    printf("s:%.5s\t%.*s\n", s, 2, s);

	printf("i & d: %i %d %.6i %i %.0i %+i %i\n", 1, 2, 3, 0 ,0 ,4, -4);
		printf("%-5d\n", 123);
	printf("u: %u %u\n", 4, -2);
	printf("x: %x %x %X %#x\n", 5, 10, 10, 6);
	printf("p: %p\n", s);
	
	return (0);

}
