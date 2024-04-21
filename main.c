/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:30:06 by dinoguei          #+#    #+#             */
/*   Updated: 2024/04/20 16:50:29 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"
#include "./minilibx-linux/mlx.h"

bool	check_args(int ac, char **av)
{
	int			i;

	i = 0;
	if (ac != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (false);
	}
	if (av[1][0] == '\0')
	{
		ft_printf("Error\nNo map inserted\n");
		return (false);
	}
	while (av[1][i] == ' ' || av[1][i] == '\t')
	{
		if (av[1][i + 1] == '\0')
		{
			ft_printf("Error\nNo map inserted\n");
			return (false);
		}
		i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_game		game;
	t_playerPos	player;

	if (!check_args(ac, av))
		return (1);
	game.map.map_folder = av[1];
	init_struct(&game);
	map_validations(&game);
	player = get_position(&game, game.map.map_a);
	game.pos = player;
	set_direction(&game, player);
	game.pos.col += 0.5;
	game.pos.row += 0.5;
	init_game(&game);
}
