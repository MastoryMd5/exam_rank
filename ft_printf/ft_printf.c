#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_putnbrbase(int n, int base)
{
	char *words;
	int out = 0;
	words = "0123456789abcdef";

	if (n > base)
		out += ft_putnbrbase(n / base, base);
	out += write(0, &words[n%base], 1);
	return (out);
}

int ft_putstr(char *str)
{
	int out = 0;
	int i = 0;

	while(str[i])
	{
		out += write(0, &str[i], 1);
		i++;
	}
	return(out);
}

int ft_putdec(int i)
{
	int out = 0;

	if (i < 0)
	{
		i * -1;
		write(0, "-", 1);
	}
	ft_putnbrbase(i, 10);
	return(out);
}

int ft_printf(const char *str, ...)
{
	int i = 0;
	int j = 0;
	va_list args;
	int out = 0;

	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				out += ft_putstr(va_arg(args, char *));
			if (str[i] == 'd')
				out += ft_putdec(va_arg(args, int));
			if (str[i] == 'x')
				out += ft_putnbrbase(va_arg(args, unsigned int), 16);
		}
		else
			out += write(0, &str[i], 1);
		i++;
	}
	va_end(args);
	return(out);
}


int main ()
{
    	int i;

    	i=14314;
    	printf("--- Il mio printf --- \n");

   	printf("COUNT: %d\n", ft_printf("T%s\n", "ciao"));
   	printf("COUNT: %d\n", ft_printf("Il numero è: %d\n", i));
    	printf("COUNT: %d\n", ft_printf("HEX %x\n", i));

        printf("--- Il printf standard --- \n");

	printf("COUNT: %d\n", printf("T%s\n", "ciao"));
	printf("COUNT: %d\n", printf("Il numero è: %d\n", i));
	printf("COUNT: %d\n", printf("HEX %x\n", i));

   	printf("L'output dei due printf devono essere identici\n");
	return(0);
}



