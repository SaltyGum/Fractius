/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:13:27 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/10/31 17:41:36 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fract.h"

void	my_mlx_pp(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mandelb(double *zr, double *zi, int y, int x)
{
	double	zr2;
	double	zi2;
	int		i;

	i = 0;
	zr2 = *zr * *zr;
	zi2 = *zi * *zi;
	while ((i < MAX_IT) && ((zr2 + zi2) < 4))
	{
		*zi = 2 * *zr * *zi + (I_BEG + (y * (I_END - I_BEG) / WIDTH));
		*zr = zr2 - zi2 + (R_BEG + (x * ((R_END - R_BEG) / HEIGHT)));
		zr2 = *zr * *zr;
		zi2 = *zi * *zi;
		i++;
	}
	return (i);
}

void	ft_mb(t_data img, int x, int y, int color)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;

	while (y < HEIGHT)
	{
		x = 0;
		//ci = I_BEG + y * ((I_END - I_BEG) / HEIGHT);
		while (x < WIDTH)
		{
			//cr = R_BEG + x *((R_END - R_BEG) / WIDTH);
			zr = 0.0;
			zi = 0.0;
			color = mandelb(&zr, &zi, y, x);
			if (color == MAX_IT)
				my_mlx_pp(&img, x, y, 0x000000);
			else
				my_mlx_pp(&img, x, y, 0x0000FF);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		c;
	int		m;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract-oil");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_mb(img, 0, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
