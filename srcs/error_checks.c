#include "../push_swap.h"

int	is_duplicate(int *array, int size)
{
	int	i;
	int	j;

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

int	duplicate_validation(char **args, int size)
{
	int	*array;
	int	i;
	int	f;

	array = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		array[i] = ft_atoi(args[i]);
	f = 0;
	if (is_duplicate(array, size))
		f = 1;
	free (array);
	return (f);
}

int	digit_bigger_than_min_max_int(char *argv)
{
	if (argv[0] == '-' && (ft_strlen(argv) > 11 || (ft_strlen(argv) == 11
				&& ft_memcmp(argv, "-2147483648", 11) > 0)))
		return (1);
	if (argv[0] != '-' && ((ft_strlen(argv) == 10
				&& ft_memcmp(argv, "2147483647", 11) > 0) || ft_strlen(argv) > 10))
		return (1);
	return (0);
}

/*
** Check for errors:
** minimum of 2 arguments;
** numbers should be in the min_int - max_int range;
** there cannot be a single - or +;
** all arguments must be numbers written with digits;
*/

int	error_handling(int size, char **argv)
{
	int	i;

	i = -1;
	if (size < 1)
		ft_exit_ps("Wrong number of arguments.\nPlease use: ./push_swap \"list of numbers\"\n", -1);
	while (++i < size)
	{
		if (ft_isstringdigit(argv[i]) == 0)
			ft_exit_ps("Numbers have to be a digit\n", -1);
		if (digit_bigger_than_min_max_int(argv[i]) == 1)
			ft_exit_ps("Numbers out of integer range\n", -1);
	}
	if (duplicate_validation(argv, size) != 0)
			ft_exit_ps("There cannot be duplicate numbers\n", -1);
	return (0);
}
