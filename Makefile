NAME	=	ft_ssl

SRCS	=	srcs/ft_ssl.c \
			srcs/error_handlers.c \
			srcs/message_digest/message_digest.c \
			srcs/message_digest/sha256.c \
			srcs/message_digest/md5.c \
			srcs/message_digest/md_print.c \
			srcs/message_digest/sha224.c \
			srcs/message_digest/hash_formatter.c \
			srcs/message_digest/sha512.c \
			$(LFT)

HEADER	=	include/

MD_HEADERS = include/message_digest/

LFTH	=	libft/

LFT		=	libft/libft.a

FL		=	-Wall -Wextra -Werror

all:		$(NAME)


$(NAME):	
			@make -C libft/ re
			@gcc -o $(NAME) $(SRCS) -I $(HEADER) -I $(MD_HEADERS) -I $(LFTH)

clean:		
			@make -C libft/ fclean
			@rm -rf srcs/*.o

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all