# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 16:33:12 by carloga2          #+#    #+#              #
#    Updated: 2025/05/21 16:34:57 by carloga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Source files
SRCS = get_next_line.c \
	   get_next_line_utils.c \
		

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADER = fget_next_line.h

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

# Compile source files
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@$(RM) $(OBJS)

# Clean object files and library
fclean: clean
	@$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Non-file targets
.PHONY: all clean fclean re