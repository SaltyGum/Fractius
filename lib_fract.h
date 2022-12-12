/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fract.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:40:49 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/12 12:38:54 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FRACT_H
# define LIB_FRACT_H

// Screen size and mx iterations
# define WIDTH 800.0
# define HEIGHT 800.0
# define MAX_IT 200

// Buttons setup

// ARROWS
# define A_UP 65362
# define A_DOWN 65364
# define A_LEFT 65361
# define A_RIGHT 65363
// SCROLLING
# define SCRL_UP 4
# define SCRL_DOWN 5
// COLOR CHANGE HELP PANEL AND RESET
# define C_BUT 99
# define H_BUT 104
# define R_BUT 114
// WINDOW CLOSE
# define ESC_BUT 65307
# define WIN_X 17

//Includes
# include <stdlib.h>
# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>

//Structs
typedef struct s_data
{
	int		palet;
	double	r;
	double	g;
	double	b;
	double	r_beg;
	double	r_end;
	double	i_beg;
	double	i_end;
	char	*type;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	x;
	double	y;
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	double	ci;
	double	cr;
	double	color;
}				t_data;

//Functions
double	dove(t_data *blk, double cr, double ci);
double	julia(t_data *blk, double zr, double zi);
double	mandelb(t_data *blk, double cr, double ci);
double	burn_ship(t_data *blk, double cr, double ci);
double	tri_fact(t_data *blk, double cr, double ci);
void	ft_render(t_data *blk);
int		ft_close(t_data *blk);
void	key_maker(t_data *blk, int key);
void	blk_init(t_data *blk, char **argv, int argc);
double	ft_translate(double start, double end, double trans);
int		clk_act(int key, int x, int y, t_data *blk);
int		ch_ose(int key, t_data *blk);
int		ft_tolower(int c);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	ft_putstr(char *str);
int		ft_strcmp(char	*s1, char *s2);
void	ft_palet(t_data *blk);
void	ft_reset(t_data *blk, int key);
#endif
