#include <unistd.h>
#include <stdio.h>

int	ft_strlcat(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while(s1[i])
		i++;
	while(s2[j])
	{
		s1[i] = s2[j];
		j++;
	}
}


int	main(int argc, char **argv)
{
	char	dup[255];
	int		i = 0;
	int		j = 0;
	int		k = 0;

	if (argc != 3)
		return (write(0, "\n", 1));
	ft_strlcat(argv[1], argv[2]);
	dup[j] = '\0';
	while (argv[1][i])
	{
		j = 0;
		while(argv[1][i] != dup[j] && dup[j])
			j++;
		if (argv[1][i] != dup[j])
			{
				write(0, &argv[1][i], 1);
				dup[k] = argv[1][i];
				k++;
			}
		i++;
	}
	write(0, "\n", 1);
}
