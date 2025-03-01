CFLAGS = -Wall -Wextra -Werror

NAME = hangman

SRC = src/main.c src/ft_randomizer.c src/ft_check.c src/ft_printables.c src/ft_utils.c src/ft_word.c

OBJETS = $(SRC:.c=.o)

RED=\033[0;31m

GREEN=\033[0;32m

YELLOW=\033[0;33m

WHITE=\033[0m

BLUE = \033[0;36m

$(NAME) : $(OBJETS)
	@printf "$(YELLOW)TRYING TO COMPILE $(NAME)...$(WHITE)\n"
	@cc $(CFLAGS) -o $(NAME) $(OBJETS)
	@printf "\r$(GREEN)$(NAME) READY TO USE$(WHITE)\n"

all : $(NAME)
	
.c.o:
	@cc $(CFLAGS) -c -o $@ $< -g

clean :
	@printf "$(YELLOW)CLEANING ".o" FILES...$(WHITE)\n"
	@rm -f $(OBJETS)
	@printf "\r$(GREEN)".o" FILES ARE CLEANED$(WHITE)\n"

fclean : clean
	@rm -f ${NAME}
	@printf "\r$(GREEN)FCLEANED WITH SUCCESS$(WHITE)\n"

re : fclean all

test : re
	@norminette src
	@valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./$(NAME) maps/map0.ber

.PHONY : all clean fclean re