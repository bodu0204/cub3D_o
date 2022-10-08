CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Wshadow -Imlx
SRCS_NAME = srcs/mandatory/main/main.c
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
	$(MAKE) -C ./minilibx_mms_20200219
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) libft/libft.a minilibx_mms_20200219/libmlx.dylib -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJDIR)
	$(MAKE) clean -C ./minilibx_mms_20200219
	$(MAKE) fclean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all
