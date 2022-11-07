/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:13:27 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/11/07 19:46:25 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fract.h"

void	my_mlx_pp(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	mandelb(double *zr, double *zi, double y, double x)
{
	double	zr2;
	double	zi2;
	double	i;

	i = 0;
	zr2 = *zr * *zr;
	zi2 = *zi * *zi;
	while ((i < MAX_IT) && ((zr2 + zi2) < 4))
	{
		*zi = 2.0 * *zr * *zi + (0.3842);
		*zr = zr2 - zi2 + (- 0.70176);
		zr2 = *zr * *zr;
		zi2 = *zi * *zi;
		i++;
	}
	if (i == MAX_IT)
		return (MAX_IT);
	//i = i + 1 - log(log2(fabs(zr2 + zi2)));
	return (i);
}

void	ft_mb(t_data img, double x, double y, double color)
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
			zr = 2.0 * 2.0 * (x - WIDTH / 2.0) / WIDTH;
			zi = 2.0 * 2.0 * (y - HEIGHT / 2.0) / HEIGHT;
			color = mandelb(&zr, &zi, y, x);
			if (color == MAX_IT)
				my_mlx_pp(&img, x, y, create_trgb(0, 0, 0, 0));
			else
			{
				color = (color * 255 / MAX_IT) * 84 * 42;
				my_mlx_pp(&img, x, y, create_trgb(0, color, 0, 255));
			}
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

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract-oil");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_mb(img, 0.0, 0.0, 0.0);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
