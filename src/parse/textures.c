#include "../../includes/cub3d.h"

void	textures_validations(t_game *game)
{
	int pos;

	pos = ft_strlen(game->map.texture_folder) - 4;
	if (ft_strncmp(".xpm", &game->map.texture_folder[pos], 4) != 0)
	{
		ft_printf("Error\n The texture you provided isn't .xpm\n");
		exit(EXIT_FAILURE);
	}
}

int	check_format(char	*ln)
{
	while (*ln == ' ' || (*ln >= 9 && *ln <= 13))
		ln++;
	if ((!ft_strncmp(ln, "NO", 2) || !ft_strncmp(ln, "SO", 2) || !ft_strncmp(ln, "WE", 2) || !ft_strncmp(ln, "EA", 2)) && (ln[2] == 32 || (ln[2] >= 9 && ln[2] <= 13)))
		return (1);
	else if ((!ft_strncmp(ln, "F", 1) || !ft_strncmp(ln, "C", 1)) && (ln[1] == 32 || (ln[1] >= 9 && ln[1] <= 13)))
		return (1);
	return (0);
}

