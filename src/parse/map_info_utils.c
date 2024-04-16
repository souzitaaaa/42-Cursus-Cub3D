#include "../../includes/cub3d.h"

void     check_texture(char *line, char *compare, char **texture)
{
    if (ft_strncmp(line, compare, 3) == 0)
    {
        if (*texture)
        {
            ft_printf("Error\nDuplicate texture");
            exit(EXIT_FAILURE);
        }
        *texture = ft_strdup(line + 3);
    }
}

void    check_color(char *line, char *compare, bool *color, t_game *game)
{
    if (ft_strncmp(line, compare, 2) == 0)
    {
        if (*color == true)
        {
            ft_printf("Error\nDuplicate floor color");
            exit(EXIT_FAILURE);
        }
        *color = true;
        if(ft_strncmp(compare, "F ", 2) == 0)
            floor_colors(game);
        if(ft_strncmp(compare, "C ", 2) == 0)
            floor_colors(game);
    }
}

void	parse_textures(t_game *game, char *line, bool *ceiling, bool *floor)
{
	if (line[0] != '\0')
	{
        check_texture(line, "NO ", &game->map.no_texture);
		check_texture(line, "SO ", &game->map.so_texture);
        check_texture(line, "WE ", &game->map.we_texture);
        check_texture(line, "EA ", &game->map.ea_texture);
        check_color(line, "C ", ceiling, game);
        check_color(line, "F ", floor, game);
	}
}

bool	is_not_texture(char *line)
{
	if (ft_strncmp(line, "NO ", 3) != 0
		&& ft_strncmp(line, "SO ", 3) != 0
		&& ft_strncmp(line, "WE ", 3) != 0 
		&& ft_strncmp(line, "EA ", 3) != 0
		&& ft_strncmp(line, "F ", 2) != 0
		&& ft_strncmp(line, "C ", 2) != 0)
		return (true);
	return (false);
}

void    verify_textures(bool ceiling, bool floor, t_game *game)
{
	if (ceiling == false || floor == false)
	{
		ft_printf("Error\n Not all required colors are specified.");
		exit(EXIT_FAILURE);
	}
	if (!game->map.no_texture || !game->map.so_texture 
        || !game->map.we_texture || !game->map.ea_texture)
	{
		ft_printf("Error\n Not all required textures are specified.");
		exit(EXIT_FAILURE);
	}
}