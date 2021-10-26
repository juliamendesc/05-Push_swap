#include "../includes/push_swap.h"

int is_duplicate(int *array, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int duplicate_validation(char **args, int size)
{
	int *array;
	int i;
	int f;

	array = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		array[i] = ft_atoi(args[i]);
	f = 0;
	if (is_duplicate(array, size))
		f = 1;
	free(array);
	return (f);
}

/*
** Check for errors:
** minimum of 2 arguments;
** numbers should be in the min_int - max_int range;
** there cannot be a single - or +;
** all arguments must be numbers written with digits;
*/

int error_handling(int size, char **argv)
{
	int i;

	i = -1;
	if (size < 1)
		ft_exit_ps_simple("", -1);
	while (++i < size)
	{
		if (ft_atoll(argv[i]) > 2147483647 || ft_atoll(argv[i]) < -2147483648)
			ft_exit_ps_simple("Error\n", -1);
		if (ft_isstringdigit(argv[i]) == 0)
			ft_exit_ps_simple("Error\n", -1);
	}
	if (duplicate_validation(argv, size) == 1)
		ft_exit_ps_simple("Error\n", -1);
	return (0);
}
