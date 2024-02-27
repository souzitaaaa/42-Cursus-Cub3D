#include "../../includes/cub3d.h"

// void	colors_validations(t_game *game, char *color)
// {
// 	int	c1;
// 	int	c2;
// 	int	c3;

// 	if	(!count_commas(color))
// 	{
// 		ft_printf("Error\n The color range is not separated by ",".\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	game->map.colors = ft_split(color, ' ,');
// 	if (!ft_isdigit(game->map.colors[0]) || !ft_isdigit(game->map.colors[1]) || !ft_isdigit(game->map.colors[2]))
// 	{
// 		ft_printf("Error\n The colors is not a number.\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	c1 = ft_atoi(game->map.colors[0]);
// 	c2 = ft_atoi(game->map.colors[1]);
// 	c3 = ft_atoi(game->map.colors[2]);
// 	game->map.colors = NULL;
// 	if (c1 < 0 || c1 > 255 || c2 < 0 || c2 > 255 || c3 < 0 || c3 > 255)
// 	{
// 		ft_printf("Error\n The color range is wrong.\n");
// 		exit(EXIT_FAILURE);
// 	}
// }

// colors_validations(game, FLOOR);
// colors_validations(game, CEILING);