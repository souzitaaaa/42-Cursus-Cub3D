#include "../includes/cub3d.h"

/*Essa função e para saber a posição do jogador porque os calculos dos raios começam nessa posição*/
t_playerPos	get_position(t_map *map)
{
	t_playerPos	pos = {-1, -1, ' '};

	char	**area = map->area;
	int		rows = map->map_y;
	int		cols = map->map_x;

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (area[row][col] == 'N' || area[row][col] == 'S' || area[row][col] == 'E' || area[row][col] == 'W')
			{
				pos.row = row;
				pos.col = col;
				pos.orientation = area[row][col];
				return (pos);
			}
		}
	}
	return (pos);
}

/*Essa função é para setar a direção de visão do jogador levando em consideração a orientação, o plano
do jogador é ajustado para ser perpendicular à direção, ou seja, formando um plano horizontal que corta
a direção do jogador em um ângulo de 90 graus*/
void	set_direction(t_game *game, t_playerPos pos)
{
	t_map	*map = &(game->map);

	/*dir_x = 0 e dir_y = -1 - o jogador está olhando p/ cima, não tem movimento na direção horizontal x,
	mas ele está indo p/ cima na direção vertical y. Plane_x = 1 e plane_y = 0 - o plano do jogador é perpendicular
	à direção de visão, então ele precisa estar em ângulo reto com a direção, ou seja,  o plano está se movendo
	para a direita horizontalmente x = 1 e não tem movimento vertical y = 0*/
	if (pos.orientation == 'N')
	{
		map->dir_x = 0;
		map->dir_y = -1;
		map->plane_x = 1;
		map->plane_y = 0;
	}
	/*dir_x = 0 e mdir_y = 1 - o jogador está olhando p/ baixo na grade do mapa, não tem movimento na direção horizontal x,
	mas ele está indo p/ baixo na direção vertical y. Plane_x = -1 e plane_y = 0 - o plano precisa estar em ângulo reto com
	a direção, então agora o plano está se movendo p/ a esquerda horizontalmente x = -1 e não tem movimento vertical y = 0*/
	else if (pos.orientation == 'S')
	{
		map->dir_x = 0;
		map->dir_y = 1;
		map->plane_x = -1;
		map->plane_y = 0;
	}
	/*dir_x = -1 e dir_y = 0 - o jogador está olhando p/ a esquerda na grade do mapa, tem movimento p/ a esquerda na direção horizontal x,
	mas não tem movimento vertical y. Plane_x = 0 e plane_y = -1 - o plano está em ângulo reto com a direção, então está se movendo p/
	cima verticalmente y = -1 e não tem movimento horizontal x = 0*/
	else if (pos.orientation == 'W')
	{
		map->dir_x = -1;
		map->dir_y = 0;
		map->plane_x = 0;
		map->plane_y = -1;
	}
	/*dir_x = 1 e dir_y = 0 - o jogador está olhando p/ a direita na grade do mapa, tem movimento p/ a direita na direção horizontal x,
	mas não há movimento vertical y. Plane_x = 0 e plane_y = 1- o plano está em ângulo reto com a direção, então está se movendo p/
	baixo verticalmente y = 1 e não tem movimento horizontal x = 0*/
	else if (pos.orientation == 'E')
	{
		map->dir_x = 1;
		map->dir_y = 0;
		map->plane_x = 0;
		map->plane_y = 1;
	}
}
