NAME 	= philo
BNAME	= bonus
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror# -g -fsanitize=thread
SOURCE 	= errors.c init.c lft.c philosophers.c utils.c
OBJS	= $(patsubst %.c, %.o, $(SOURCE))

BSOURCE	= /philo_bonus/philo_bonus.c
BOBJS	= $(patsubst %.c, %.o, $(BSOURCE))

all:$(NAME)

$(NAME) : $(OBJS)
	$(CC)  $(CFLAGS) -pthread $(OBJS) -o $(NAME)

$(BNAME) : $(BOBJS)
	$(CC)  $(CFLAGS) -pthread $(BOBJS) -o $(BNAME)

%.o : %.c
	$(CC) -I ./philo_bonus $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJS) /philo_bonus/$(BOBJS)

fclean: clean
	@rm -f $(NAME) $(BNAME)

bonus:$(BNAME)


PHONY: all re clean fclean $(NAME) bonus