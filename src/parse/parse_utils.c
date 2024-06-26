/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:01:32 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/18 16:44:05 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	encode_rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return (r << 16 | g << 8 | b);
}

void	get_mapa_x(t_game *game)
{
	int	i;
	int	len;
	int	x;

	i = 1;
	x = ft_strlen(game->map.map_a[0]);
	len = 0;
	while (i < game->map.mapa_y)
	{
		len = ft_strlen(game->map.map_a[i]);
		if (len > x)
			x = len;
		i++;
	}
	game->map.mapa_x = x;
}
