NAME 	= philo
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror# -g -fsanitize=thread
SOURCE 	= $(wildcard $(SRC_DIR)*.c)
OBJS	= $(patsubst %.c, %.o, $(SOURCE))

all:$(NAME)

$(NAME) : $(OBJS)
	$(CC)  $(CFLAGS) -pthread $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) -I $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

PHONY: all re clean fclean