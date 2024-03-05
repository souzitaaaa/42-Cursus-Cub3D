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
                game->ray.distToX = (game->pos.row - game->ray.mapPos.x) * game->ray.deltaDistX;
                game->ray.stepX = -1;
        }
        else
        {
                game->ray.distToX = (game->ray.mapPos.x + 1 - game->pos.row) * game->ray.deltaDistX;
                game->ray.stepX = 1;
        }
        if (game->ray.rayDir.y < 0)
        {
                game->ray.distToY = (game->pos.col - game->ray.mapPos.y) * game->ray.deltaDistY;
                game->ray.stepY = -1;
        }
        else
        {
                game->ray.distToY = (game->ray.mapPos.y + 1 - game->pos.col) * game->ray.deltaDistY;
                game->ray.stepY = 1;
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

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->data.addr + (y * game->data.line_len + x * (game->data.bits_per_pixel / 8));
	
        *(unsigned int *)dst = color;
}

void	draw_line(t_game *game, int hitSide)
{
	//t_line	line;
	int		i;
        double dif_x = 0;
	double dif_y = 0;
	int n_step = 0;
	double x_step = 0;
	double y_step = 0;
	double x = 0;
	double y = 0;

	dif_x = game->ray.screen_pixel - game->ray.screen_pixel;
	dif_y = game->ray.lineEndY - game->ray.lineStartY;
	n_step = get_max(fabs(dif_x), fabs(dif_y));
	x_step = dif_x / n_step;
	y_step = dif_y / n_step;
	x = game->ray.screen_pixel;
	y = game->ray.lineStartY;
        printf("dif_y: %f\n", dif_y);
        printf("dif_x: %f\n", dif_x);
        printf("n_step: %i\n", n_step);
        printf("x_step: %f\n", x_step);
        printf("y_step: %f\n", y_step);
        printf("x: %f\n", x);
        printf("y: %f\n", y);
	i = 0;
	while (i <= n_step)
	{
                if (hitSide == 1)
		        my_mlx_pixel_put(game, (int)x, (int)y, COLOR);
                else
                        my_mlx_pixel_put(game, (int)x, (int)y, COLOR2);
		x += x_step;
		y += y_step;
		i++;
	}

}

/**
 * @brief       This function implements the Digital Differential Analyzer(DDA)
 * 			algorithm, which calculates the intersections of rays with the walls
 * 			in the game map
 * 				@brief //? NOT FINISHED BECAUSE I NEED TO SORT IN STRUCTS
 * 
 * @param game  Struct that contains every information on the program
 */
void dda(t_game *game)
{
        bool hit;
        double lineSizeY;
        double lineSizeX;
        int     hitSide;
        double perpendicularDist;
        double x = 0;
        double y = 0;

        x = game->ray.mapPos.x;
        y = game->ray.mapPos.y;
        lineSizeY = game->ray.distToY;
        lineSizeX = game->ray.distToX;
        hit = false;
        hitSide = 0;
        perpendicularDist = 0;
        //! calcula o caminho em que o raio passa até chegar á parede
        while (!hit)
        {
                printf( YELLOW "LineSize\t| col(y): %f\t| row(x): %f\t|\n" RESET, lineSizeY, lineSizeX);
                printf("WallMapPos\t| col(y): %f\t| row(x): %f\t|\n", y, x);
                if (lineSizeX < lineSizeY)
                {
                        x += game->ray.stepX;
                        lineSizeX += game->ray.deltaDistX;
                        hitSide = 0;
                }
                else
                {
                        y += game->ray.stepY;
                        lineSizeY += game->ray.deltaDistY;
                        hitSide = 1;
                }
                if (game->map.area[(int)y][(int)x] == '1') {
                        hit = true;
                }
        }
                printf("hitWall\t\t| col(y): %i\t\t| row(x): %i\t\t|\n", (int)y, (int)x);
                printf("hitSide\t\t| %i\t\t\t|\n", hitSide);
        if (hitSide == 0) {
                perpendicularDist = fabs(x - game->pos.row + ((1 - game->ray.stepX)/2))/game->ray.rayDir.x;
        }
        else {
                perpendicularDist = fabs(y - game->pos.col + ((1 - game->ray.stepY)/2))/game->ray.rayDir.y;
        }
                printf("perpendicularD\t| %f\t\t|\n", perpendicularDist);
        game->ray.wallLineSize = SCREEN_Y/perpendicularDist;
        game->ray.lineStartY = SCREEN_Y/2 - game->ray.wallLineSize/2;
        game->ray.lineEndY = SCREEN_Y/2 + game->ray.wallLineSize/2;
        draw_line(game, hitSide);
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

        //game->ray.screen_pixel = 0;
        //! Não tenho a certeza quanto ao <=, mas se ele não tiver para no 0.998047
        while (game->ray.screen_pixel < SCREEN_X)
        {
                //* ASSIGNMENT PART
                multiplier = 2 * (game->ray.screen_pixel / SCREEN_X) - 1;
                printf(YELLOW "Multiplier\t| %f\t\t|\n" RESET, multiplier);
                assign_vector_values(&game->ray.camera, game->map.plane.y * multiplier, game->map.plane.x * multiplier);
                printf("Camera vector\t| col(y): %f\t| row(x): %f\t|\n", game->ray.camera.y, game->ray.camera.x);
                assign_vector_values(&game->ray.rayDir, game->map.dir.y + game->ray.camera.y, game->map.dir.x + game->ray.camera.x);
                printf("RayDir vector\t| col(y): %f\t| row(x): %f\t|\n", game->ray.rayDir.y, game->ray.rayDir.x);
                
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
                printf("DeltaDistX\t| %f\t\t|\n", game->ray.deltaDistX);
                if (game->ray.rayDir.y == 0) {
                        game->ray.deltaDistX = 0;
                        game->ray.deltaDistY = 1;
                }
                else {
                        if (game->ray.rayDir.x) {
                                game->ray.deltaDistY = fabs(magnitude(game->ray.rayDir) / game->ray.rayDir.y);
                        }
                }
                printf("DeltaDistY\t| %f\t\t|\n", game->ray.deltaDistY);
                assign_vector_values(&game->ray.mapPos, floor(game->pos.col), floor(game->pos.row));
                printf("MapPos vector\t| col(y): %f\t| row(x): %f\t|\n", game->ray.mapPos.y, game->ray.mapPos.x);
                get_distToSides(game);
                printf("DistToSide\t| col(y): %f\t| row(x): %f\t|\n", game->ray.distToY, game->ray.distToX);
                //* END
                //*DDA
                dda(game);
                game->ray.screen_pixel++;
        }
        mlx_clear_window(game->data.mlx, game->data.win);
		mlx_put_image_to_window(game->data.mlx, game->data.win, game->data.img, 0, 0);
        return 1;
}