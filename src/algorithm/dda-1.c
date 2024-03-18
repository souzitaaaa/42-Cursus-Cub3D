#include "../includes/cub3d.h"

/**
 * @brief			Function to assign the initial values on a vector
 * 
 * @param vector	Vector struct that will be the one beeing initializated
 * @param y 		Value of y that will be initializated on the vector
 * @param x 		Value of x that will be initializated on the vector
 */
void assign_vector_values(t_vector *vector, double y, double x)
{
        vector->y = y;
        vector->x = x;
}

/**
 * @brief 			Function to calculate the magnitude of a vector
 * 				@param Magnitude is the lenght of a vector
 *
 * @param vector 	Vector that will be used to measure the magnitude
 * @return double 	The return value of this function will be the magnitude of
 * 				the vector
 */
double magnitude(t_vector vector)
{
        double result;

        result = sqrt(vector.y * vector.y + vector.x * vector.x);
        return result;
}

/**
 * @brief 		This function will initializate the distTo X and Y aswell as the stepX
 * 				The @param distTo variables are going to be store the value of the first
 * 			deltaDist, because if the player position is on the middle of a grid, the value
 * 			of the deltaDist don't work because it's a fractionary value, in between those
 * 			deltaDist values, so these distTo calculate the first value untill a grid
 * 				The @param step variables are going to be used to know the direction of
 * 			the ray
 * 
 * @param game	Struct that contains every information on the program
 */
void get_distToSides(t_game *game)
{
        if (game->ray.rayDir.x < 0)
        {
                game->ray.distTo.x = (game->pos.row - game->ray.mapPos.x) * game->ray.deltaDistX;
                game->ray.step.x = -1;
        }
        else
        {
                game->ray.distTo.x = (game->ray.mapPos.x + 1 - game->pos.row) * game->ray.deltaDistX;
                game->ray.step.x = 1;
        }
        if (game->ray.rayDir.y < 0)
        {
                game->ray.distTo.y = (game->pos.col - game->ray.mapPos.y) * game->ray.deltaDistY;
                game->ray.step.y = -1;
        }
        else
        {
                game->ray.distTo.y = (game->ray.mapPos.y + 1 - game->pos.col) * game->ray.deltaDistY;
                game->ray.step.y = 1;
        }
}

/**
 * @brief 			Get the max value between two numbers
 * 
 * @param dif_x 	First value to be compared
 * @param dif_y 	Second value to be compared
 * @return double 	This function return the biggest number between those two
 */
double  get_max(double dif_x, double dif_y) {
        if (dif_x > dif_y)
                return (dif_x);
        return (dif_y);
}

/**
 * @brief       Initial function for the dda algorithm, it's the function
 *			directly connected to the mlx_loop_hook, so this mean that this function
			will execute in loop.
				It iterates from 0 until the SCREEN_X (screen width) in order to cover
			all the window.
				From there it stars to assign values in order to calculate the rays.
				The @param multiplier is used to instead of using, 0px to SCREEN_W
			it uses a value that ranges from -1 to 1, as the extremities of the screen
			and 0 beeing the middle
				The @param camera is used to help calculate another vector later on,
			it's a vector with the value of a vector that starts on the plane and goes
			and ends on the multiplier value, to calculate the point on the camera we
			are currently in
				The @param rayDir is a vector that contains the direction of the ray
			starting on the player position (dir) and ending on the camera (vector
			calculated above)
				The @param deltaDist is the distance on X and Y between the grids
				The @param mapPos will be used to keep track on the player position,
			for the calculations ahead, at this part we set them as the initial player
			position
 *
 * @param game  Struct that contains every information on the program
 * @return int  The function on the mlx_loop_hook must return a int type
 */
int loop(t_game *game)
{
        double multiplier;

        multiplier = 0;

        game->ray.screen_pixel = 0;
        //draw_ceiling_walls(game);
        //! Não tenho a certeza quanto ao <=, mas se ele não tiver para no 0.998047
        while (game->ray.screen_pixel < SCREEN_X)
        {
                //* ASSIGNMENT PART
                multiplier = 2 * (game->ray.screen_pixel / SCREEN_X) - 1;
                //printf(YELLOW "Multiplier\t| %f\t\t|\n" RESET, multiplier);
                assign_vector_values(&game->ray.camera, game->map.plane.y * multiplier, game->map.plane.x * multiplier);
                //printf("Camera vector\t| col(y): %f\t| row(x): %f\t|\n", game->ray.camera.y, game->ray.camera.x);
                assign_vector_values(&game->ray.rayDir, game->map.dir.y + game->ray.camera.y, game->map.dir.x + game->ray.camera.x);
                //printf("RayDir vector\t| col(y): %f\t| row(x): %f\t|\n", game->ray.rayDir.y, game->ray.rayDir.x);
                
                //! Treating raydir 0
                if (game->ray.rayDir.x == 0) {
                        game->ray.deltaDistX = 1;
                        game->ray.deltaDistY = 0;
                }
                else {
                        if (game->ray.rayDir.y) {
                                game->ray.deltaDistX = fabs(magnitude(game->ray.rayDir) / game->ray.rayDir.x);
                        }
                }
                //printf("DeltaDistX\t| %f\t\t|\n", game->ray.deltaDistX);
                if (game->ray.rayDir.y == 0) {
                        game->ray.deltaDistX = 0;
                        game->ray.deltaDistY = 1;
                }
                else {
                        if (game->ray.rayDir.x) {
                                game->ray.deltaDistY = fabs(magnitude(game->ray.rayDir) / game->ray.rayDir.y);
                        }
                }
                //printf("DeltaDistY\t| %f\t\t|\n", game->ray.deltaDistY);
                assign_vector_values(&game->ray.mapPos, floor(game->pos.col), floor(game->pos.row));
                //printf("MapPos vector\t| col(y): %f\t| row(x): %f\t|\n", game->ray.mapPos.y, game->ray.mapPos.x);
                get_distToSides(game);
                //printf("DistToSide\t| col(y): %f\t| row(x): %f\t|\n", game->ray.distTo.y, game->ray.distTo.x);
                //* END
                //*DDA
                dda(game);
                game->ray.screen_pixel++;
                mlx_put_image_to_window(game->data.mlx, game->data.win, game->data.img, 0, 0);
        }
        //printf("Player Info | col(y): %f | row(x): %f | orientation: %c |\n", game->pos.col, game->pos.row, game->pos.orientation);
        return 1;
}