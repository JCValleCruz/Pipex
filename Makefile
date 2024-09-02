#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                            
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME       	:= pipex
CC		:= gcc
FLAGS    	:= -Wall -Wextra -Werror
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      pipex.c \
                          Libft/ft_atoi.c \
                          Libft/ft_bzero.c \
                          Libft/ft_calloc.c \
                          Libft/ft_isalnum.c \
                          Libft/ft_isalpha.c \
                          Libft/ft_isascii.c \
                          Libft/ft_isdigit.c \
                          Libft/ft_isprint.c \
                          Libft/ft_itoa.c \
                          Libft/ft_lstadd_back_bonus.c \
                          Libft/ft_lstadd_front_bonus.c \
                          Libft/ft_lstclear_bonus.c \
                          Libft/ft_lstdelone_bonus.c \
                          Libft/ft_lstiter_bonus.c \
                          Libft/ft_lstlast_bonus.c \
                          Libft/ft_lstmap_bonus.c \
                          Libft/ft_lstnew_bonus.c \
                          Libft/ft_lstsize_bonus.c \
                          Libft/ft_memchr.c \
                          Libft/ft_memcmp.c \
                          Libft/ft_memcpy.c \
                          Libft/ft_memmove.c \
                          Libft/ft_memset.c \
                          Libft/ft_putchar_fd.c \
                          Libft/ft_putendl_fd.c \
                          Libft/ft_putnbr_fd.c \
                          Libft/ft_putstr_fd.c \
                          Libft/ft_split.c \
                          Libft/ft_strchr.c \
                          Libft/ft_strdup.c \
                          Libft/ft_striteri.c \
                          Libft/ft_strjoin.c \
                          Libft/ft_strlcat.c \
                          Libft/ft_strlcpy.c \
                          Libft/ft_strlen.c \
                          Libft/ft_strmapi.c \
                          Libft/ft_strncmp.c \
                          Libft/ft_strnstr.c \
                          Libft/ft_strrchr.c \
                          Libft/ft_strtrim.c \
                          Libft/ft_substr.c \
                          Libft/ft_tolower.c \
                          Libft/ft_toupper.c \
                          utils.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


