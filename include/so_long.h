/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:27:51 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/05 16:05:13 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ---------- LIBRERIAS ---------- */
# include "../libft/ft_printf/include/ft_printf.h"
# include "../libft/gnl/include/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
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

/* ---------- STRUCTS ---------- */
typedef struct s_player
{
	int		steps;
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
	int		all_positions;
	int		n_position;
	char	*line;
	char	**cpy;
	void	*wall;
	void	*portal;
	void	*position;
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

/* READ_MAP.C */
void	ft_read_map(t_game *game, char *file);

/* FT_MESSEG.C */
void	ft_error(char *s);

/* CHECK_MAP.C */
void	ft_check_map(t_game *game);

/* CHECK_PATH.C */
int	check_path(t_game *game);

/* FT_NO_NL.C */
char	*ft_strdup_no_nl(const char *s1);
char	*ft_strjoin_no_nl(char const *s1, char const *s2);

/* FT_SLEN.C */
int	ft_slen(char *s);

/* ---------- COLOR FONT ---------- */
# define BLACK   "\x1B[30m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1B[37m"
# define ORANGE  "\x1B[38;2;255;128;0m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LBLUE   "\x1B[38;2;53;149;240m"
# define LGREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
# define RESET   "\x1b[0m"

/* ---------- COLOR BACKGROUND ---------- */
# define BG_BLACK   "\x1B[40m"
# define BG_RED     "\x1B[41m"
# define BG_GREEN   "\x1B[42m"
# define BG_YELLOW  "\x1B[43m"
# define BG_BLUE    "\x1B[44m"
# define BG_MAGENTA "\x1B[45m"
# define BG_CYAN    "\x1B[46m"
# define BG_WHITE   "\x1B[47m"
# define BG_ORANGE  "\x1B[48;2;255;128;0m"
# define BG_LBLUE   "\x1B[48;2;53;149;240m"
# define BG_LGREEN  "\x1B[48;2;17;245;120m"
# define BG_GRAY    "\x1B[48;2;176;174;174m"
# define BG_ROSE    "\x1B[48;2;255;151;203m"

#endif
