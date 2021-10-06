#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

# define	FLOOR 	"s/desert-32.xpm"
# define	WALL 	"s/wall-32.xpm"
# define	PLAYER 	"s/player_1.xpm"

typedef struct s_map
{
	char	**map_pars;
	int		map_size_l;
	int		map_size_h;
	char	*img_path_floor;
	char	*ing_pach_wall;
	void	*img;
}				t_map;

typedef struct s_player
{
	int		x;
	int		y;
	void	*img;
}		t_player;

// typedef struct s_enemy
// {
// 	int	x;
// 	int	y;
// }				t_enemy;

// typedef struct s_coins
// {
// 	int	x;
// 	int	y;
// }				t_coins;

// typedef struct s_exit
// {
// 	int	x;
// 	int	y;
// }				t_exit;

typedef struct s_data
{
	t_map		map;
	t_player	player;
	// t_enemy		*enmy;
	// t_exit		*exit;
	// t_coins		*coins;
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
}				t_data;


int	get_next_line(int fd, char **line);

#endif
