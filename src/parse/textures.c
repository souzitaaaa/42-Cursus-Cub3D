#include "../../includes/cub3d.h"

int	textures_validations(t_game *game)
{
	int pos_no;
	int pos_so;
	int pos_we;
	int pos_ea;

	pos_no = ft_strlen(game->map.no_texture) - 4;
	pos_so = ft_strlen(game->map.so_texture) - 4;
	pos_we = ft_strlen(game->map.we_texture) - 4;
	pos_ea = ft_strlen(game->map.ea_texture) - 4;
	if (ft_strncmp(".xpm", &game->map.no_texture[pos_no], 4) != 0 || ft_strncmp(".xpm", &game->map.so_texture[pos_so], 4) != 0 || ft_strncmp(".xpm", &game->map.we_texture[pos_we], 4) != 0 || ft_strncmp(".xpm", &game->map.ea_texture[pos_ea], 4) != 0)
	{
		ft_printf("Error\n The texture you provided isn't .xpm\n");
		return (0);
	}
	return (1);
}
