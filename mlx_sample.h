#ifndef SAMPLE_LIB_H
# define SAMPLE_LIB_H

# include <mlx.h>
# include <stdio.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
// ----------------------------------
// MACROS

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

# define IMG_SIZE 48
# define TITRE "toto"

# define PLAYER "assets/player.xpm"
# define LOCKED "assets/chest_locked.xpm"
# define WALL "assets/wall.xpm"
# define GROUND "assets/ground.xpm"
# define COIN1 "assets/coin/coin1.xpm"



// ----------------------------------
// STRUCTS
typedef struct s_map
{
	int		line_count;
	char	**map;
	char	*path;
	int		fd;
}		t_map;

typedef struct t_img
{
	int		width;
	int		height;
	void	*wall;
	void	*exit_l;
	void	*ground;
	void	*player;
	void	*coin1;

}		t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		win_height;
	int		win_width;
}		t_data;

// ---------------------------------
// FUNCTIONS

void	create_map(char *path, t_data *data);
void	init_map(t_data *data);
int		render(t_data *data);
void	parse_chars(t_data *data, int width, int i, int j);
void	init_images(t_data *data);



#endif
