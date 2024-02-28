#include "../../includes/cub3d.h"

void	map_info(t_game *game)
{
	int	i = 0;
	char	*line;

	while (i < game->map.map_y + 1)
	{
		line = ft_strtrim(game->map.area[i], " \t");
		if (ft_strncmp(line, "NO ", 3) == 0){
			game->map.no_texture = ft_strdup(line + 3);
			ft_printf("noth texture: %s\n", game->map.no_texture);
		}
		else if (ft_strncmp(line, "SO ", 3) == 0){
			game->map.so_texture = ft_strdup(line + 3);
			ft_printf("south texture: %s\n", game->map.so_texture);
		}
		else if (ft_strncmp(line, "WE ", 3) == 0){
			game->map.we_texture = ft_strdup(line + 3);
			ft_printf("west texture: %s\n\n", game->map.we_texture);
		}
		else if (ft_strncmp(line, "EA ", 3) == 0)
		{
			game->map.ea_texture = ft_strdup(line + 3);
			ft_printf("east texture: %s\n\n", game->map.ea_texture);
		}
		else if (line[0] != '\0'){
			//ft_printf("Error\n Invalid texture path.\n");
			break ;
		}
		i++;
		}
}//será que precisa fazer uma validação da ordem das texturas? 