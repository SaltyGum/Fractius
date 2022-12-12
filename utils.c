/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:57:57 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/12 01:05:35 by jeluiz4          ###   ########.fr       */
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

double	ft_trigger(t_data *blk)
{
	if (ft_strcmp(blk->type, "mandelbrot") == 0)
		return (mandelb(blk));
	if (ft_strcmp(blk->type, "tricorn") == 0)
		return (tri_fact(blk));
	if (ft_strcmp(blk->type, "burningship") == 0)
		return (burn_ship(blk));
	if (ft_strcmp(blk->type, "dove") == 0)
		return (dove(blk));
	if (ft_strcmp(blk->type, "julia") == 0)
		return (julia(blk));
	ft_close(blk);
	return (0.0);
}

void	ft_render(t_data *blk)
{
	blk->y = 0.0;
	while (blk->y < HEIGHT)
	{
		blk->x = 0.0;
		while (blk->x < WIDTH)
		{
			blk->color = ft_trigger(blk);
			if (blk->color == MAX_IT)
				my_mlx_pp(blk, blk->x, blk->y, create_trgb(0, 0, 0, 0));
			else
			{
				blk->color = (blk->color * 255 / MAX_IT);
				my_mlx_pp(blk, blk->x, blk->y,
					create_trgb(0, blk->color * blk->r,
						blk->color * blk->g,
						blk->color * blk->b));
			}
			blk->x++;
		}
		blk->y++;
	}
	mlx_put_image_to_window(blk->mlx, blk->win, blk->img, 0, 0);
}

int	ft_close(t_data *blk)
{
	if (blk->img)
		mlx_destroy_image(blk->mlx, blk->img);
	if (blk->mlx && blk->win)
	{
		mlx_destroy_window(blk->mlx, blk->win);
		free(blk->mlx);
	}
	ft_putstr("END\n");
	exit(200);
}
