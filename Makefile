CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
SRCS_NAME = mandatory/main/main.c \
	mandatory/main/setup.c \
	mandatory/global/map.c \
	mandatory/global/img.c \
	mandatory/global/ceiling.c \
	mandatory/global/flooring.c \
	mandatory/raycasting/calculate.c \
	mandatory/raycasting/raycasting.c \
	mandatory/setting/mk_map.c \
	mandatory/setting/mk_img.c \
	mandatory/setting/setting.c \
	mandatory/setting/set_human.c \
	mandatory/setting/set_imgs.c \
	mandatory/plot/plot.c \
	mandatory/plot/pixel_put.c
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
	$(MAKE) -C ./mlx-linux
	$(CC) $(OBJS) libft/libft.a $(LDFLAGS) mlx-linux/libmlx_Darwin.a -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJDIR)
	$(MAKE) clean -C ./mlx-linux
	$(MAKE) fclean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all
