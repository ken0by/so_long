/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:27:51 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/15 20:55:27 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ---------- LIBRERIAS ---------- */
# include "../libft/include/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include "../libft/gnl/include/get_next_line.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/* ---------- TECLAS ---------- */
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_LEFT		123
# define ARROW_RIGHT	124

# define DESTROY 17
# define XPM_PATH	"./xpm/"

/* ---------- STRUCTS ---------- */
typedef struct s_player
{
	int		steps;
	int		steps_flag;
	int		pos;
	void	*player_front;
	void	*player_back;
	void	*player_right;
	void	*player_left;
}	t_player;

typedef struct s_map
{
	int		height;
	int		width;
	int		all_potions;
	int		n_potions;
	char	*line;
	char	**cpy;
	void	*wall;
	void	*floor;
	void	*portal;
	void	*potion;
}	t_map;

typedef struct s_game
{
	int			img_height;
	int			img_width;
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
}	t_game;

/* ---------- FUNCIONES ---------- */

/* ----- SRC ----- */
/* SO_LONG.C */
int	ft_close(t_game *game);

/* READ_MAP.C */
void	ft_read_map(t_game *game, char *file);

/* FT_MESSEG.C */
void	ft_error(char *s);
void	ft_win(t_game *game);
void	ft_lose(t_game *game);

/* CHECK_MAP.C */
void	ft_check_map(t_game *game);

/* CHECK_PATH.C */
int		check_path(t_game *game);

/* START_XPM.C */
void	all_xpm(t_game *game);
void	print_img(t_game *game, void *img, int i, int j);

/* PRINT_MAP.C */
void	print_map(t_game *game, char c);

/* PRINT_STEPS.C */
void	print_steps(t_game *game);

/* CONTROLS.C */
int		ft_key(int key, t_game *game);

/* FT_FREE.C */
void	ft_free_close(char *line, int fd);
void	ft_free_matrix(t_game *game);

/* ----- UTILS ----- */
/* FT_NO_NL.C */
char	*ft_strdup_no_nl(const char *s1);
char	*ft_strjoin_no_nl(char *s1, char *s2);

/* FT_SLEN.C */
int		ft_slen(char *s);

/* ---------- COLOR FONT ---------- */
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define RESET   "\x1b[0m"


#endif
