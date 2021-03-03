NAME		=	libft.a

INC_PATH	=	includes/

SRC_PATH	=	srcs/

OBJ_PATH	=	srcs/obj/

SRC_NAME	=	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
				ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
				ft_strrchr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
				ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
				ft_strstr.c ft_memset.c ft_bzero.c ft_memcpy.c \
				ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
				ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_atoi.c \
				ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
				ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
				ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
				ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
				ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_count_char.c \
				ft_strclr.c ft_strlenc.c ft_arraydel.c ft_strlen2.c \
				get_next_line.c ft_itoa_base.c str_filled.c rev_uint32.c \
				rev_uint64.c rotr32.c rotl32.c

OBJ_NAME	=	$(SRC_NAME:.c=.o)
INC_NAME	=	libft.h

SRC			=	$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC			=	$(addprefix $(INC_PATH), $(INC_NAME))

.PHONY:			all clean fclean re

all:			$(NAME)

$(NAME):		$(OBJ)
				@ar rc $(NAME) $(OBJ)
				@ranlib $(NAME)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(INC)
				@mkdir -p $(OBJ_PATH)
				@gcc -Wall -Wextra -Werror -I $(INC_PATH) -o $@ -c $<

clean:
				@rm -f $(OBJ)
				@rm -rf $(OBJ_PATH)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all
