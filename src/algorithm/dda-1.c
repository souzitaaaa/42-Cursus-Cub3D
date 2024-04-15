/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda-1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:34:59 by dinoguei          #+#    #+#             */
/*   Updated: 2024/04/15 19:50:08 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//! NORMINETTADO

/**
 * @brief			Function to assign the initial values on a vector
 *
 * @param vector	Vector struct that will be the one beeing initializated
 * @param y 		Value of y that will be initializated on the vector
 * @param x 		Value of x that will be initializated on the vector
 */
void	assign_vector_values(t_vector *vector, double y, double x)
{
	vector->y = y;
	vector->x = x;
}

/**
 * @brief 		This function will initializate the distTo X and
 * 					Y aswell as the stepX
 * 				The @param distTo variables are going to be store
 * 					the value of the first deltaDist, because if the
 * 					player position is on themiddle of a grid, the value
 * 					of the deltaDistdon't work because it's a fractionary
 * 					value, in between thosedeltaDist values, so these distTo
 * 					calculate the first value untill a grid
 * 				The @param step variables are going to be used to know the
 * 					direction of the ray
 *
 * @param game	Struct that contains every information on the program
 */
void	get_distto(t_game *game)
{
	if (game->ray.rayDir.x < 0)
	{
		game->ray.distTo.x = (game->pos.row - game->ray.mapPos.x)
			* game->ray.deltaDist.x;
		game->ray.step.x = -1;
	}
	else
	{
		game->ray.distTo.x = (game->ray.mapPos.x + 1.0 - game->pos.row)
			* game->ray.deltaDist.x;
		game->ray.step.x = 1;
	}
	if (game->ray.rayDir.y < 0)
	{
		game->ray.distTo.y = (game->pos.col - game->ray.mapPos.y)
			* game->ray.deltaDist.y;
		game->ray.step.y = -1;
	}
	else
	{
		game->ray.distTo.y = (game->ray.mapPos.y + 1.0 - game->pos.col)
			* game->ray.deltaDist.y;
		game->ray.step.y = 1;
	}
}

void	loop_assignment(t_game *game, double *multiplier)
{
	*multiplier = 2 * game->ray.screen_pixel / (double)SCREEN_X - 1;
	assign_vector_values(&game->ray.rayDir, game->map.dir.y + game->map.plane.y
		* *multiplier, game->map.dir.x + game->map.plane.x * *multiplier);
	assign_vector_values(&game->ray.deltaDist,
		sqrt(1 + (game->ray.rayDir.x * game->ray.rayDir.x)
			/ (game->ray.rayDir.y * game->ray.rayDir.y)),
		sqrt(1 + (game->ray.rayDir.y * game->ray.rayDir.y)
			/ (game->ray.rayDir.x * game->ray.rayDir.x)));
	assign_vector_values(&game->ray.mapPos, floor(game->pos.col),
		floor(game->pos.row));
	if (game->ray.rayDir.x == 0)
		game->ray.deltaDist.x = 1e30;
	else
		game->ray.deltaDist.x = fabs(1 / game->ray.rayDir.x);
	if (game->ray.rayDir.y == 0)
		game->ray.deltaDist.y = 1e30;
	else
		game->ray.deltaDist.y = fabs(1 / game->ray.rayDir.y);
}

void	restart_structs(t_game *game)
{
	game->ray.dda.hit = false;
	game->ray.dda.hitSide = 0;
	game->ray.dda.perpendicularDist = 0;
	game->ray.dda.wallX = 0;
	game->ray.line.y = 0;
	assign_ivector_values(&game->ray.line.texture, 0, 0);
	game->ray.line.step = 0;
	game->ray.line.texturePos = 0;
	game->ray.line.color = 0;
}

/**
 * @brief       Initial function for the dda algorithm, it's
 * 					the function directly connected to the
 * 					mlx_loop_hook, so this mean that this function
					will execute in loop.
				It iterates from 0 until the SCREEN_X (screen width) in order
					to coverall the window.
				From there it stars to assign values in order to
					calculate the rays.
				The @param multiplier is used to instead of
					using, 0px to SCREEN_Wit uses a value that ranges
					from -1 to 1, as the extremities of the screen
					and 0 beeing the middle
				The @param camera is used to help calculate another
					vector later on, it's a vector with the value of a
					vector that starts on the plane and goes and ends on
					the multiplier value, to calculate the point on the
					camera we are currently in
				The @param rayDir is a vector that contains the direction
					of the ray starting on the player position (dir) and
					ending on the camera (vector calculated above)
				The @param deltaDist is the distance on X and Y between the grids
				The @param mapPos will be used to keep track on the player
					position, for the calculations ahead, at this part we
					set them as the initial player position
 *
 * @param game  Struct that contains every information on the program
 * @return int  The function on the mlx_loop_hook must return a int type
 */
int	loop(t_game *game)
{
	double	multiplier;

	multiplier = 0;
	while (game->ray.screen_pixel < SCREEN_X)
	{
		loop_assignment(game, &multiplier);
		get_distto(game);
		dda(game);
		game->ray.screen_pixel++;
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->data.img, 0, 0);
		restart_structs(game);
	}
	return (1);
}
