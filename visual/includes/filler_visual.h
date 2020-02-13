/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_visual.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:35:46 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/12 17:13:27 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISUAL_H
# define FILLER_VISUAL_H

# include "../../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"

# define HOW    	1000
# define WOW    	1500
# define HOI    	1000
# define WOI    	1000
# define COB    	0xFFBA00
# define KVK_ESCAPE	0x35
# define SPACE		49
# define AR_RIGHT	124

typedef	struct	s_color
{
	int8_t			channel[4];
}				t_color;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct	s_map
{
	t_point		ini_s;
	char		*line;
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*img_data;
	int			bpp;
	int			sl;
	int			endian;
	char		name1[100];
	char		name2[100];
	int			hight;
	int			width;
	t_point		s;
	t_point		f;
	int			param;
	int			bug;
	int			p1_res;
	int			p2_res;
	int			i;
	int			step_flag;
	int			space_flag;
}				t_map;

typedef struct	s_draw
{
	int		dx;
	int		dy;
	int		err[2];
	int		sign_dx;
	int		sign_dy;
}				t_draw;

typedef struct	s_boarder
{
	t_point p[4];
}				t_boarder;

int				main(int argc, char *argv[]);
void			ft_solution(t_map *map);
void			ft_init_map(t_map *m);
void			draw_line(t_map *map, t_point s, t_point f, int color);
void			ft_error(char *str);
void			ft_init_and_print_board(t_map *map);
void			ft_print_lines(t_map *m);
void			ft_read_map_and_print(t_map *m, char **line);
void			print_menu_sup2(t_map *map, int *i, void *m, void *w);
void			ft_draw_sq_x(t_map *m, int i, int j, int col);
void			ft_draw_sq_o(t_map *m, int i, int j, int col);
void			print_menu(t_map *map);
int				closee(t_map *m);
void			readprint_sup(t_map *m, char **l, int param);
int				ft_catch_num(char **l);
void			ft_catch_players_sup(char **line, int fd, int i, int fin);
#endif
