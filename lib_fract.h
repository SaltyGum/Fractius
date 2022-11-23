/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fract.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:40:49 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/11/23 16:41:24 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FRACT_H
# define LIB_FRACT_H

// Screen size and mx iterations
# define WIDTH 800.0
# define HEIGHT 800.0
# define MAX_IT 255

// Starting point Fractal
# define R_BEG -2.5
# define R_END 1.5
# define I_BEG -2.0
# define I_END 2.0

// Buttons setup mac

// ARROWS
# define A_UP 126
# define A_DOWN 125
# define A_LEFT 123
# define A_RIGHT 124
// SCROLLING
# define SCRL_UP 3
# define SCRL_DOWN 4
// COLOR CHANGE HELP PANEL AND RESET
# define C_BUT 8
# define H_BUT 4
# define R_BUT 15
// WINDOW CLOSE
# define ESC_BUT 53

//Includes
# include <stdlib.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_variables {
	double	z;
	double	y;
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	double	ci;
	double	cr;
}				t_vars;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_win;

typedef struct s_structs {
	t_data	img;
	t_win	mlx;
	t_vars	vars;
}				t_all;

#endif
