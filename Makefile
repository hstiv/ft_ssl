NAME				=	ft_ssl

SRC					=	srcs/ft_ssl.c \
						srcs/error_handlers.c \
						srcs/tools.c \
						srcs/message_digest/message_digest.c \
						srcs/message_digest/md_print.c \
						srcs/message_digest/md5/md5.c \
						srcs/message_digest/md5/main_cycle_funcs.c \
						srcs/message_digest/sha224/sha224.c \
						srcs/message_digest/sha224/main_cycle_funcs.c \
						srcs/message_digest/sha224/additional_funcs.c \
						srcs/message_digest/sha256/sha256.c \
						srcs/message_digest/sha256/main_cycle_funcs.c \
						srcs/message_digest/sha256/additional_funcs.c \
						srcs/message_digest/sha512/sha512.c \
						srcs/message_digest/sha512/main_cycle_funcs.c \
						srcs/message_digest/sha512/additional_funcs.c \
						srcs/cipher/base64/base64_parser.c \
						srcs/cipher/base64/base64_print.c \
						srcs/cipher/base64/base64.c \
						$(LFT)


INC					=	includes/

INC_MD				=	includes/message_digest/

INC_CP				=	includes/cipher/

LIB_NAME			=	libft.a

LIB_PATH			=	libft/

LFT					=	libft/libft.a

LIB_INC_PATH		=	libft/includes/


all: 				$(LFT) $(NAME)

$(LFT):
						@make -C $(LIB_PATH)

$(NAME):
						@gcc -o $(NAME) -Wall -Wextra -Werror \
						$(SRC) -I $(INC) -I $(INC_MD) -I $(INC_CP) -I $(LIB_INC_PATH)
						@echo "(•̀ᴗ•́)و $(NAME) generated!"

clean:
						@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ $(NAME) is deleting... Wait a sec."
						@make -C $(LIB_PATH) fclean

fclean:				clean
						@rm -rf $(NAME)

re:					fclean all
