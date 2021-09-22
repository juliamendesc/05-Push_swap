#include "../push_swap.h"

int	check_string_duplicates(char *str)
{
	size_t i;
	size_t j;
	int count;

	i = 0;
	while (i < ft_strlen(str))
	{
		count = 1;
		j = i + 1;
		while (j < ft_strlen(str))
		{
			if (str[i] == str[j] && str[i] != ' ')
			{
				count++;
				str[j] = '\0';
			}
			j++;
		}
		i++;
	}
	if (count > 1 && str[i] != '\0')
		return (1);
	return (0);
}

int	are_there_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (*argv)
	{
		if (ft_strcmp(argv[i], "0") == 0 || ft_strcmp(argv[i], "-0") == 0)
		{
			if (ft_strcmp(argv[j], "0") == 0 || ft_strcmp(argv[j], "-0") == 0)
				return (1);
		}
		if (check_string_duplicates(*argv) == 1)
				return (1);
		j++;
		i++;
	}
	return (0);
}

int	digit_bigger_than_min_max_int(char **argv)
{
	int	i;

	i = 1;
	while (*argv[i])
	{
		if (ft_strlen(argv[i]) > 2)
		{
			if (ft_atoi(argv[i]) == 0 || ft_atoi(argv[i]) == -1)
				return (1);
		}
		i++;
	}
	return (0);
}

/*
** Check for errors:
** minimum of 2 arguments;
** numbers should be in the min_int - max_int range;
** there cannot be a single - or +;
** all arguments must be numbers written with digits;
*/

int	error_handling(int argc, char **argv)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	if (argc < 2)
		ft_exit_ps("Wrong number of arguments.\nPlease use: ./push_swap \"list of numbers\"\n", -1);
	if (ft_isstringalpha(argv[i]) == 1)
		ft_exit_ps("Numbers have to be a digit\n", -1);
	while (argv[i] != NULL)
	{
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && !ft_isdigit(argv[i][++j]))
				return (-1);
			if (ft_isstringdigit(argv[i]) == 1)
				{
					if (are_there_duplicates(argv) == 1)
						ft_exit_ps("There cannot be duplicate numbers\n", -1);
					return (0);
				}
			j++;
		}
		i++;
	}
	if (digit_bigger_than_min_max_int(argv) == 1)
		ft_exit_ps("Numbers out of integer range\n", -1);
	return (0);
}
