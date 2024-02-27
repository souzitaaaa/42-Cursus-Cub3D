#include "../../includes/cub3d.h"

bool	count_commas(char *str)
{
	int	c = 0;
	int	i = 0;

	while (str[i])
	{
		if (str[i] == ',')
			c++;
		i++;
	}
	return (c == 2);
}