NAME 	= philo_bonus
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
SOURCE 	= all_ings.c errors.c init_bonus.c philo_bonus.c utils_bonus.c
OBJS	= $(patsubst %.c, %.o, $(SOURCE))

all:$(NAME)

bonus:$(NAME)

$(NAME) : $(OBJS)
	$(CC)  $(CFLAGS) -pthread $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) -I $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

PHONY: all re clean fclean bonus