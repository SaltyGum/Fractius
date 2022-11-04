/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fract.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:40:49 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/11/04 16:37:45 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FRACT_H
# define LIB_FRACT_H
# define WIDTH 1000
# define HEIGHT 1000
# define MAX_IT 200

# define R_BEG -2.5
# define R_END 1.5
# define I_BEG -2.0
# define I_END 2.0

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
