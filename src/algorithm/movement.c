#include "../includes/cub3d.h"

int esc_key(t_game *game) {
    (void)game;
    printf(YELLOW " ░▒███████\n");
    printf("░██▓▒░░▒▓██\n");
    printf("██▓▒░__░▒▓██___██████\n");
    printf("██▓▒░____░▓███▓__░▒▓██\n");
    printf("██▓▒░___░▓██▓_____░▒▓██\n");
    printf("██▓▒░_______________░▒▓██\n");
    printf(" ██▓▒░______________░▒▓██\n");
    printf("  ██▓▒░____________░▒▓██\n");
    printf("   ██▓▒░__________░▒▓██\n");
    printf("    ██▓▒░________░▒▓██\n");
    printf("     ██▓▒░_____░▒▓██\n");
    printf("      ██▓▒░__░▒▓██\n");
    printf("       █▓▒░░▒▓██\n");
    printf("         ░▒▓██\n");
    printf("       ░▒▓██\n");
    printf("     ░▒▓██" RESET "\tThanks for playing <3\n");
    //! FUNCAO PARA DAR FREE AS COISAS
    exit(1);
}

void    moviment_key(t_game *game, double new_x, double new_y) {
    if (game->map.map_a[(int)new_y][(int)new_x] != '\0' && ft_strchr("NSWE0", game->map.map_a[(int)new_y][(int)new_x])) {
        game->pos.row = new_x;
        game->pos.col = new_y;
        game->ray.screen_pixel = 0;
    }
}

void    direction_key(t_game *game, double val) {
    t_vector	oldDir;
    t_vector	oldPlane;

    assign_vector_values(&oldDir, game->map.dir.y, game->map.dir.x);
    assign_vector_values(&oldPlane, game->map.plane.y, game->map.plane.x);
    game->map.dir.y = game->map.dir.y * cos(val) - game->map.dir.x * sin(val);
    game->map.dir.x = oldDir.y * sin(val) + game->map.dir.x * cos(val);
    game->map.plane.y = game->map.plane.y * cos(val) - game->map.plane.x * sin(val);
    game->map.plane.x = oldPlane.y * sin(val) + game->map.plane.x * cos(val);
    game->ray.screen_pixel = 0;
}