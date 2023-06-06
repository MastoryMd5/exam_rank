#include <unistd.h>

int main(int argc, char **argv)
{
	int	i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	char	*str1;
	char	*str2;
	char	dup[255];

	if (argc != 3)
		return(write(0, "\n", 1));
	dup[0] = '\0';
	str1 = argv[1];
	str2 = argv[2];

	while(str1[i])
	{
		j = 0;
		k = 0;
		while(str1[i] != str2[j] && str2[j])
			j++;
		while(str1[i] != dup[k] && dup[k])
			k++;
		if (str1[i] == str2[j] && str1[i] != dup[k])
		{
			write(0, &str1[i], 1);
			dup[l] = str1[i];
			l++;
		}
		i++;
	}
	write(0, "\n", 1);
}
