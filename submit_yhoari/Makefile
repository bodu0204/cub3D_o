CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
SRCS_NAME = main/main.c \
	main/setup.c \
	global/map.c \
	global/img.c \
	global/ceiling.c \
	global/flooring.c \
	raycasting/calculate.c \
	raycasting/raycasting.c \
	raycasting/raycasting_utils.c \
	setting/mk_map.c \
	setting/mk_map_utils.c \
	setting/mk_img.c \
	setting/setting.c \
	setting/set_human.c \
	setting/set_imgs.c \
	setting/set_imgs_utils.c \
	plot/plot.c \
	plot/pixel_put.c
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
