NAME		:=	hangman

CC			:=	clang

SRC			:=	src/main.c \
				src/ft_randomizer.c \
				src/ft_check.c \
				src/ft_printables.c \
				src/ft_utils.c \
				src/ft_word.c

INCLUDES	:= include/
OBJETS		:=	$(SRC:.c=.o)
DEPS		:=	$(OBJETS:%.o=%.d)

CFLAGS		:=	-Wall -Wextra -Werror  -I$(INCLUDES) -MMD -MP

RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
MAGENTA		:=	\033[1;35m
CYAN		:=	\033[1;36m
WHITE		:=	\033[1;37m
ERASE		:=	\033[K

all : $(NAME)

$(NAME) : $(OBJETS)
	@printf "\r$(ERASE)🟡 $(YELLOW)[HANGMAN] Compiling $(NAME)...$(WHITE)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJETS)
	@printf "\r$(ERASE)✅ $(GREEN)[HANGMAN] Compiled !$(WHITE)\n"

.c.o:
	@printf "\r🟡 $(MAGENTA)[COMPILING📦] $<$(WHITE)"
	@$(CC) $(CFLAGS) -c -o $@ $< -g

-include $(DEPS)

clean :
	@printf "🟡 $(MAGENTA)[CLEANING🧹] .o files...$(WHITE)\n"
	@rm -f $(OBJETS)
	@printf "✅ $(GREEN)[CLEANED🧹]$(WHITE)\n"

fclean : clean
	@printf "🟡 $(MAGENTA)[CLEANING🧹] Cleaning hangman files...$(WHITE)\n"
	@rm -f $(NAME)
	@printf "✅ $(GREEN)[CLEANED🧹]$(WHITE)\n"

re : fclean all

test : re
	@norminette src
	@valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./$(NAME) maps/map0.ber

.PHONY : all clean fclean re test