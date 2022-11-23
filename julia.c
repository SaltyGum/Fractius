/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:13:27 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/11/23 16:42:50 by jeluiz4          ###   ########.fr       */
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
		*zi = 2.0 * *zr * *zi + (0.8);
		*zr = zr2 - zi2 + (0);
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
				color = (color * 255 / MAX_IT);
				my_mlx_pp(&img, x, y, create_trgb(0, color, color, color));
			}
			x++;
		}
		y++;
	}
}

int	ft_close(int keycode, t_win *vars)
{
	if (keycode == ESC_BUT)
	{
		//mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit (13);
	}
	return (0);
}

int	ch_ose(int key, t_win *vars)
{
	if (key == A_UP)
		printf("KEYPRESSED A_UP == %d\n", A_UP);
	if (key == A_DOWN)
		printf("KEYPRESSED A_DOWN == %d\n", A_DOWN);
	if (key == A_RIGHT)
		printf("KEYPRESSED A_RIGHT == %d\n", A_RIGHT);
	if (key == A_LEFT)
		printf("KEYPRESSED A_LEFT == %d\n", A_LEFT);
	if (key == C_BUT)
		printf("KEYPRESSED C_BUT == %d\n", C_BUT);
	if (key == H_BUT)
		printf("KEYPRESSED H_BUT == %d\n", H_BUT);
	if (key == R_BUT)
		printf("KEYPRESSED R_BUT == %d\n", R_BUT);
	if (key == ESC_BUT)
	{
		printf("KEYPRESSED ESC_BUT == %d\n", ESC_BUT);
		ft_close(key, vars);
	}
}

int	main(void)
{
	t_win	mlx;
	t_data	img;
	t_all	bgm;

	bgm.vars.z = 5.5;
	printf("Será ? %.2f\n", bgm.vars.z);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Fract-oil");
	img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_mb(img, 0.0, 0.0, 0.0);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, &ch_ose, &mlx);
	mlx_loop(mlx.mlx);
}
