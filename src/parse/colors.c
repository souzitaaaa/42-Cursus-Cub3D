#include "../../includes/cub3d.h"

void	parse_color(char *color_str, int *color_values)
{
	char	*ptr = color_str;
	int	count = 0;
	int	comma = 0;

	while (*ptr != '\0')
	{
		if (*ptr == ',')
			comma++;
		ptr++;
	}
	if (comma != 2)
	{
		ft_printf("Error\n Invalid color format. Must contain 3 values separated by commas.\n");
		exit(EXIT_FAILURE);
	}
	ptr = color_str;
	while (*ptr != '\0' && count < 3)
	{
		while (*ptr == ' ' || *ptr == '\t')
			ptr++;
		if (!ft_isdigit(*ptr))
		{
			ft_printf("Error\n Invalid color format.\n");
			exit(EXIT_FAILURE);
		}
		color_values[count++] = ft_atoi(ptr);
		while (ft_isdigit(*ptr))
			ptr++;
		if (*ptr == ',')
			ptr++;
	}
	if (count != 3)
	{
		printf("Error\n Invalid color format. Must contain exactly 3 values.\n");
		exit(EXIT_FAILURE);
    }
}

void	floor_colors(t_game *game)
{
	char	*color_str;
	int i = 0;
	int color_values[3];

	while (i < game->map.mapa_y)
	{
		if (ft_strncmp(game->map.map_a[i], "F ", 2) == 0)
		{
			color_str = game->map.map_a[i] + 2;
			parse_color(color_str, color_values);
			game->map.f_range[0] = color_values[0];
			game->map.f_range[1] = color_values[1];
			game->map.f_range[2] = color_values[2];
			if (color_values[0] < 0 || color_values[0] > 255 || color_values[1] < 0
                || color_values[1] > 255 || color_values[2] < 0 || color_values[2] > 255)
            {
                ft_printf("Error\nColor range is out.");
                exit(EXIT_FAILURE);
            }
		}
		i++;
	}
}

void	ceiling_colors(t_game *game)
{
	char	*color_str;
	int	i = 0;
	int color_values[3];

	while (i < game->map.mapa_y)
	{
		if (ft_strncmp(game->map.map_a[i], "C ", 2) == 0)
		{
			color_str = game->map.map_a[i] + 2;
			parse_color(color_str, color_values);
			game->map.c_range[0] = color_values[0];
			game->map.c_range[1] = color_values[1];
			game->map.c_range[2] = color_values[2];
			if (color_values[0] < 0 || color_values[0] > 255 || color_values[1] < 0
                || color_values[1] > 255 || color_values[2] < 0 || color_values[2] > 255)
            {
                ft_printf("Error\nColor range is out.");
                exit(EXIT_FAILURE);
            }
		}
		i++;
	}
}
