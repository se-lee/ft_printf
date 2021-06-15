BIN			= objs
SRC			= srcs
LIBFT		= libft
INC			= includes
SRCS		=	ft_printf.c \
				ft_printf_checks.c \
				ft_printf_types.c \
				ft_printf_setting.c \

OBJS		= $(addprefix $(BIN)/, $(SRCS:.c=.o))
NAME		= libftprintf.a
LIBFT_FILE	= $(LIBFT)/libft.a
CC			= gcc
RM			= rm -rf
CFLAGS		= -g -Wall -Wextra -Werror #-fsanitize=address
HEADERS		= $(addprefix $(INC)/, ft_printf.h)

all:		init $(NAME)

$(BIN)/%.o:		$(SRC)/%.c $(HEADERS) $(LIBFT)/libft.h
			$(CC) $(CFLAGS) -c $< -Iincludes -Ilibft -o $@

$(NAME):	$(OBJS)
			cp $(LIBFT_FILE) $(NAME)
			ar rc $(NAME) $(OBJS)

init:
			@ mkdir -p objs
			$(MAKE) -C $(LIBFT)

re_lib:
			$(MAKE) -C $(LIBFT) re

clean:		
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT) clean
			@ $(RM) objs

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT) fclean

re:			fclean all

.PHONY:		all clean fclean re init re_lib