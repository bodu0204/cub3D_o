CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
SRCS_NAME = mandatory/main/main.c
SRCDIR = srcs
OBJDIR = objs
SRCS = $(addprefix $(SRCDIR)/, $(SRCS_NAME))
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
NAME = cub3D

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir $(shell find $(SRCDIR) -type d | sed 's/^$(SRCDIR)/$(OBJDIR)/g')

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C ./minilibx-linux
	$(CC) $(OBJS) libft/libft.a $(LDFLAGS) minilibx-linux/libmlx_Darwin.a -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJDIR)
	$(MAKE) clean -C ./minilibx-linux
	$(MAKE) fclean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all
