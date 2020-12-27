NAME	=	ft_ssl

SRCS	=	srcs/ft_ssl srcs/md5.c $(LFT)

HEADER	=	includes/

LFTH	=	libft/

LFT		=	libft/libft.a

FL		=	-Wall -Wextra -Werror

all:		$(NAME)


$(NAME):
			@make -C libft re
			@gcc -o $(NAME) $(SRCS) -I $(HEADER) -I $(LFTH)

clean:
			@rm -rf srcs/*.o
			@make -C libft fclean

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all