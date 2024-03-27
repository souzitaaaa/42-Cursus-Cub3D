#-------------------------------------  COLORS  --------------------------------
RESET			= \033[0m
BLACK 			= \033[1;30m
RED 			= \033[1;31m
GREEN 			= \033[1;32m
YELLOW		 	= \033[1;33m
BLUE			= \033[1;34m
PURPLE 			= \033[1;35m
CYAN 			= \033[1;36m
WHITE 			= \033[1;37m

#----------------------------------- COMMANDS ----------------------------------
CC				= cc
RM 				= rm -rf

#-----------------------------------  FLAGS  -----------------------------------
CFLAGS 			= -Wall -Wextra -Werror -g
NPD				= --no-print-directory
MINILIBX 		= ./minilibx
MLXFLAGS 		= -L ./minilibx -lmlx -Ilmlx -lXext -lX11

#----------------------------------  FOLDERS ------------------------------------

LIBFTDIR 		= libft
LIBFT 			= $(LIBFTDIR)/libft.a
INCLUDE			= includes
SRCS			= src
_SUBFOLDERS		= parse algorithm
VPATH			= $(SRCS) $(addprefix $(SRCS)/, $(_SUBFOLDERS))
OBJDIR			= obj

#--------------------------------- FILES  ---------------------------------------
NAME 			= cub3d

_FILES 			= position utils colors parse_utils textures map walls_utils movement map_validations dda-1 dda-2
OBJ				= $(_FILES:%=%.o)
TARGET			= $(addprefix $(OBJDIR)/, $(OBJ))
_HEADERS		= cub3d.h
HDR				= $(addprefix $(INCLUDE)/, $(_HEADERS))

#---------------------------------  RULES  --------------------------------------

ifeq ($(shell uname), Linux)
	MINILIBX 	= ./minilibx-linux
	MLXFLAGS 	= -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
	OS          = 1
else ifeq ($(shell uname), Darwin)
	MINILIBX 	= ./minilibx
	MLXFLAGS	= -L ./minilibx -lmlx -framework OpenGL -framework Appkit -lm
	CP_CMD 		= cp ./minilibx/libmlx.dylib ./
	OS          = 2
endif

all: $(NAME)

$(NAME): $(OBJDIR) $(TARGET) $(LIBFT) main.c
	echo "[$(CYAN)Compiling minilibx$(RESET)] $(CFLAGS) $<$(RESET)"
	$(MAKE) --no-print-directory -C $(MINILIBX)
	echo "[$(GREEN)Success$(RESET)] Compiling minilibx$(BOLD)$(RESET)"
	$(CC) $(CFLAGS) main.c $(TARGET) $(MLXFLAGS) -I $(INCLUDE) $(LIBFT) -o $(NAME) -lm
	echo "[$(GREEN)Success$(RESET)] cub3d created$(BOLD)$(RESET)"

$(OBJDIR)/%.o : %.c $(HDR)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $<$(RESET)"
	$(CC) $(CFLAGS) -D OS=$(OS) -c $< -o $@ -I $(INCLUDE)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	echo "[$(CYAN)Compiling$(RESET)] libft$(RESET)"
	$(MAKE) $(NPD) -C $(LIBFTDIR)
	echo "[$(GREEN)Success$(RESET)] Libft compilation compleated!$(BOLD)$(RESET)"

clean:
	$(RM) $(OBJDIR)
	$(MAKE) clean $(NPD) -C  $(LIBFTDIR)
	echo "[$(RED)Deleting$(RESET)]  object files deleted$(BOLD)$(RESET)"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean $(NPD) -C  $(LIBFTDIR)
	echo "[$(RED)Deleting$(RESET)]  .a deleted$(BOLD)"

re: fclean all

.SILENT:

.PHONY: all clean fclean re