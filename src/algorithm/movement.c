/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:10:49 by dinoguei          #+#    #+#             */
/*   Updated: 2024/04/15 23:39:07 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	esc_key(t_game *game)
{
	ft_printf(YELLOW " ░▒███████\n");
	ft_printf("░██▓▒░░▒▓██\n");
	ft_printf("██▓▒░__░▒▓██___██████\n");
	ft_printf("██▓▒░____░▓███▓__░▒▓██\n");
	ft_printf("██▓▒░___░▓██▓_____░▒▓██\n");
	ft_printf("██▓▒░_______________░▒▓██\n");
	ft_printf(" ██▓▒░______________░▒▓██\n");
	ft_printf("  ██▓▒░____________░▒▓██\n");
	ft_printf("   ██▓▒░__________░▒▓██\n");
	ft_printf("    ██▓▒░________░▒▓██\n");
	ft_printf("     ██▓▒░_____░▒▓██\n");
	ft_printf("      ██▓▒░__░▒▓██\n");
	ft_printf("       █▓▒░░▒▓██\n");
	ft_printf("         ░▒▓██\n");
	ft_printf("       ░▒▓██\n");
	ft_printf("     ░▒▓██" RESET "\tThanks for playing <3\n");
	free_exit(game);
}

void	moviment_key(t_game *game, double new_x, double new_y)
{
	if (game->map.map_a[(int)new_y][(int)new_x] != '\0'
		&& ft_strchr("NSWE0", game->map.map_a[(int)new_y][(int)new_x]))
	{
		game->pos.row = new_x;
		game->pos.col = new_y;
		game->ray.screen_pixel = 0;
	}
}

void	direction_key(t_game *game, double val)
{
	t_vector	olddir;
	t_vector	oldplane;

	assign_vector_values(&olddir, game->map.dir.y, game->map.dir.x);
	assign_vector_values(&oldplane, game->map.plane.y, game->map.plane.x);
	game->map.dir.y = game->map.dir.y * cos(val) - game->map.dir.x * sin(val);
	game->map.dir.x = olddir.y * sin(val) + game->map.dir.x * cos(val);
	game->map.plane.y = game->map.plane.y * cos(val)
		- game->map.plane.x * sin(val);
	game->map.plane.x = oldplane.y * sin(val)
		+ game->map.plane.x * cos(val);
	game->ray.screen_pixel = 0;
}
