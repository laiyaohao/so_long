#include "so_long.h"

int	find_item(char **map, char item, char axis)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == item)
			{
				if (axis == 'x')
					found = j;
				if (axis == 'y')
					found = i;
			}
			j++;
		}
		i++;
	}
	return (found);
}
