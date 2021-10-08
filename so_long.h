#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

# define	FLOOR 	"s/grass.xpm"
# define	WALL 	"s/wall.xpm"
# define	PLAYER 	"s/player_1.xpm"
# define	COIN_1	"s/coins/Coin1.xpm"
# define	COIN_2	"s/coins/Coin2.xpm"
# define	COIN_3	"s/coins/Coin3.xpm"
# define	COIN_4	"s/coins/Coin4.xpm"
# define	COIN_5	"s/coins/Coin5.xpm"
# define	COIN_6	"s/coins/Coin6.xpm"
# define	COIN_7	"s/coins/Coin7.xpm"
# define	COIN_8	"s/coins/Coin8.xpm"
# define	COIN_9	"s/coins/Coin9.xpm"
# define	EXIT	"s/exit.xpm"
// # define	ENEMY	"s/enemies/Enemies2.xpm"
// # define	ENEMY	"s/enemies/Enemies3.xpm"

typedef struct s_map
{
	char	**map_pars;
	int		map_size_l;
	int		map_size_h;
	char	*img_path_floor;
	char	*ing_pach_wall;
	void	*img_wall;
	void	*img_floor;
}				t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		steps;
	void	*img;
}		t_player;

typedef struct s_enemy
{
	void	*img_1;
	void	*img_2;
	void	*img;
	int		x;
	int		y;
}				t_enemy;

typedef struct s_coins
{
	int		count;
	void	*img;
	void	*img_1;
	void	*img_2;
	void	*img_3;
	void	*img_4;
	void	*img_5;
	void	*img_6;
	void	*img_7;
	void	*img_8;
	void	*img_9;	
}				t_coins;

typedef struct s_exit
{
	int		x;
	int		y;
	void	*img_exit;
}				t_exit;

typedef struct s_data
{
	t_map		map;
	t_player	player;
	t_enemy		enmy;
	t_exit		exit;
	t_coins		coins;
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
	}			t_data;

int		get_next_line(int fd, char **line);
void	ft_map_volidation(int argc, char **argv, t_data *data);
void	ft_pars_map(char **argv, t_data *data);
void	ft_img_inint(t_data *data);

void	ft_coin_animation(t_data *data);
void	ft_enemy_animation(t_data *data);
int		ft_render(t_data *data);

int		press_key(int key, t_data *data);
int		mouse_clik(t_data *data);

#endif
