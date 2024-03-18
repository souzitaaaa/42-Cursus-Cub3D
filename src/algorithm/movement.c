#include "../includes/cub3d.h"

void stopWalking(t_game *game) {
    game->ray.velocity.y *= 0;
    game->ray.velocity.x *= 0;
}

void walkUp(t_game *game) {
    game->ray.velocity.y = game->map.dir.y * game->ray.speed;
    game->ray.velocity.x = game->map.dir.x * game->ray.speed;
}

void walkDown(t_game *game) {
    game->ray.velocity.y = (game->map.dir.y * -1) * game->ray.speed;
    game->ray.velocity.x = (game->map.dir.x * -1) * game->ray.speed;
}

void    updateInput(t_game *game) {
    game->ray.velocity
}