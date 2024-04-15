#include "../includes/cub3d.h"

void error(t_game *game, char *msg){
	(void)game;
	ft_printf("❌ Error\n    %s\n", msg);
	//! FREE
	exit(1);
}

