/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fract.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:40:49 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/11/06 19:13:30 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FRACT_H
# define LIB_FRACT_H

// Screen size and mx iterations
# define WIDTH 800
# define HEIGHT 800
# define MAX_IT 200

// Starting point Fractal
# define R_BEG -2.5
# define R_END 1.5
# define I_BEG -2.0
# define I_END 2.0

// Buttons setup

// ARROWS
# define A_UP 62
# define A_DOWN 68
# define A_LEFT 64
# define A_RIGHT 66
// SCROLLING
# define SCRL_UP 3
# define SCRL_DOWN 4
// COLOR CHANGE HELP PANEL AND RESET
# define C_BUT 36
# define H_BUT 28
# define R_BUT 18
// WINDOW CLOSE
# define ESC_BUT 9

//Includes
# include <stdlib.h>
# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif
