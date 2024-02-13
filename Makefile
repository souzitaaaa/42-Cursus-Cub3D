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
CFLAGS			= -Wall -Wextra -Werror
NPD				= --no-print-directory
MINILIBX 		= ./minilibx-linux
MLXFLAGS 		= -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

#----------------------------------  FOLDERS ------------------------------------

INCLUDE			= includes
SRCS			= src
_SUBFOLDERS		= 
VPATH			= $(SRCS) $(addprefix $(SRCS)/, $(_SUBFOLDERS))
OBJDIR			= obj

#--------------------------------- FILES  ---------------------------------------
NAME 			= cub3d

_FILES 			= init

OBJ				= $(_FILES:%=%.o)
TARGET			= $(addprefix $(OBJDIR)/, $(OBJ))
_HEADERS		= cub3d.h
HDR				= $(addprefix $(INCLUDE)/, $(_HEADERS))

#---------------------------------  RULES  --------------------------------------

all: $(NAME)

$(NAME): $(OBJDIR) $(TARGET) main.c
	echo "[$(CYAN)Compiling minilibx$(RESET)] $(CFLAGS) $<$(RESET)"
	$(MAKE) --no-print-directory -C $(MINILIBX)
	echo "[$(GREEN)Success$(RESET)] Compiling minilibx$(BOLD)$(RESET)"
	$(CC) $(CFLAGS) -lm main.c $(TARGET) $(MLXFLAGS) -I $(INCLUDE) -o $(NAME)
	echo "[$(GREEN)Success$(RESET)] cub3d created$(BOLD)$(RESET)"

$(OBJDIR)/%.o : %.c $(HDR)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)
	echo "[$(RED)Deleting$(RESET)]  object files deleted$(BOLD)$(RESET)"

fclean: clean
	$(RM) $(NAME)
	echo "[$(RED)Deleting$(RESET)]  .a deleted$(BOLD)"

re: fclean all

.SILENT:

.PHONY: all clean fclean re