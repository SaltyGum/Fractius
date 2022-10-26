/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:13:27 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/10/26 17:16:16 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fract.h"

void	my_mlx_pp(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		y;
	int		x;
	int		aux;

	y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// borda esquerda
	while(y <= 100)
	{
		x = 0;
		while(x <= 600)
		{
			my_mlx_pp(&img, y, x, 0x00FF00);
			x++;
		}
		y++;
	}
	//borda topo
	while(y <= 800)
	{
		x = 0;
		while(x <= 100)
		{
			my_mlx_pp(&img, y, x, 0x00FF00);
			x++;
		}
		y++;
	}
	// borda direita
	y = 700;
	while(y <= 800)
	{
		x = 0;
		while(x <= 600)
		{
			my_mlx_pp(&img, y, x, 0x00FF00);
			x++;
		}
		y++;
	}
	// borda base
	y = 0;
	while(y <= 800)
	{
		x = 400;
		while(x <= 600)
		{
			my_mlx_pp(&img, y, x, 0x00FF00);
			x++;
		}
		y++;
	}
	// retangulo laranja
	y = 100;
	while(y <= 700)
	{
		x = 100;
		while(x <= 400)
		{
			my_mlx_pp(&img, y, x, 0xFF4A05);
			x++;
		}
		y++;
	}
	// triangulo azul
	y = 400;
	x = 100;
	aux = y;
	while (y <= 700)
	{
		aux = 400 - (x - 100);
		while (aux <= y)
		{
			my_mlx_pp(&img, aux, x, 0x0000FF);
			aux++;
		}
		x++;
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
