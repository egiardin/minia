NAME = minia

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRCS = $(shell find $(SRC_DIR) -name '*.c')

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -I $(INC_DIR)

GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)🔧 Édition des liens...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation terminée !$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE) Compilation de $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED) Suppression des fichiers objets...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED) Suppression de l'exécutable...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re