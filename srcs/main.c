#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int	a[500];
//	int	b[500];
	int	len_a;
//	int	len_b;
	int	i = 0;
	int j = 1;

	if (argc < 2)
		ft_exit_ps("Wrong number of arguments\n", -1);
	len_a = ft_strlen(argv[1]);
	printf("argc %d\n", argc);
	while (j <= argc)
	{
		printf("len %d\n", len_a);
		printf("str %s\n", argv[1]++);
		j++;
	}
	a[i++] = atoi(argv[1]++);
	i = 0;
	while (j <= argc)
	{
		printf("array i=%d, value= %d\n", i, a[i]);
		i++;
	}
}
