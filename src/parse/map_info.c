#include "../../includes/cub3d.h"

void	ft_isprint_error(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_isprint(line[i]))
		{
            ft_printf("Error\n Invalid map!!!\n");
            exit(EXIT_FAILURE);
		}
		i++;
	}
}

void    parse_map(t_game *game, int *y)
{
    int i;

    //Aloca memoria e preenche o map_a
    game->map.map_a = (char **)malloc(sizeof(char *) * (game->map.area_y + 1));
    i = 0;
    while (*y < game->map.area_y  && game->map.area[*y][0] != '\0' 
            && is_not_texture(game->map.area[*y]))
    {
        game->map.map_a[i] = special_strtrim(ft_strdup(game->map.area[*y]));
        i++;
        (*y)++;
    }
    game->map.map_a[i] = NULL;
    game->map.mapa_y = i;
    //Depois do mapa estar preenchido,
    //Se ainda n tivermos chegado ao fim do ficheiro
    //Verifica que nao tem mais nada 
    if (*y < game->map.area_y)
    {
        while (*y < game->map.area_y)
            ft_isprint_error(game->map.area[(*y)++]);
    }
}

bool    textures_finish(bool ceiling, bool floor, t_game *game)
{
	if (ceiling == false || floor == false)
        return (false);
	if (!game->map.no_texture || !game->map.so_texture 
        || !game->map.we_texture || !game->map.ea_texture)
            return (false);
    return (true);
}

bool    check_beggin_map(bool ceiling, bool floor, t_game *game, int *y)
{
    //Serve para checkar linhas vazias entre texturas
    if(textures_finish(ceiling, floor, game) == false)
        ft_isprint_error(game->map.area[*y]);
    if(textures_finish(ceiling, floor, game) == true)
    {
        //Se encontra um '1' vai fazer parsing do mapa
        if (ft_strchr(game->map.area[*y], '1') != NULL) //beg map
        {
            parse_map(game, y);
            return(true);
        }
        //Se nao encontra o 1 tem que ser linha vazia,
        //Checkar linhas vazias entre o fim das texturas e o mapa
        ft_isprint_error(game->map.area[*y]);
    }
    return(false);

}

void	map_info(t_game *game)
{
	int	y;
	char	*line;
	bool	ceiling;
	bool	floor;

    y = 0;
    ceiling = false;
    floor = false;
	while (y < game->map.area_y)
	{
		line = ft_strtrim(game->map.area[y], " \t");
		parse_textures(game, line, &ceiling, &floor);
		if (is_not_texture(line))
        {
            //Se encontrar o inicio do mapa, faz parsing do mapa e da break
            if (check_beggin_map(ceiling, floor, game, &y) == true)
                break;
        }
		y++;
		free(line);
	}
    //No final de verificar o mapa area todo, 
    //se nao tiver todas as cores e texturas da erro
    verify_textures(ceiling, floor, game);
}
