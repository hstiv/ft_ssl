NAME	=	ft_ssl

SRCS	=	srcs/ft_ssl.c \
			srcs/error_handlers.c \
			srcs/message_digest/message_digest.c \
			srcs/message_digest/sha256.c \
			srcs/message_digest/md5.c \
			srcs/message_digest/md_print.c \
			$(LFT)

HEADER	=	include/

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