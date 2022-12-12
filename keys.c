/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:22:31 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/12 12:39:14 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fract.h"

void	key_maker(t_data *blk, int key)
{
	double	mid_r;
	double	mid_i;

	mid_i = blk->i_end - blk->i_beg;
	mid_r = blk->r_end - blk->r_beg;
	if (key == 2)
	{
		blk->i_end += mid_i * 0.15;
		blk->i_beg += mid_i * 0.15;
	}
	else if (key == 1)
	{
		blk->i_end -= mid_i * 0.15;
		blk->i_beg -= mid_i * 0.15;
	}
	else if (key == 4)
	{
		blk->r_end -= mid_r * 0.15;
		blk->r_beg -= mid_r * 0.15;
	}
	else if (key == 3)
	{
		blk->r_end += mid_r * 0.15;
		blk->r_beg += mid_r * 0.15;
	}
}

double	ft_translate(double start, double end, double trans)
{
	return (start + ((end - start) * trans));
}

int	clk_act(int key, int x, int y, t_data *blk)
{
	double	r;
	double	i;
	double	zoom;

	zoom = 1.0;
	r = 0.0;
	i = 0.0;
	r = (double)x / (WIDTH / (blk->r_end - blk->r_beg)) + blk->r_beg;
	i = (double)y / (HEIGHT / (blk->i_end - blk->i_beg)) * -1 + blk->i_end;
	if (key == SCRL_UP)
		zoom = 0.90;
	else if (key == SCRL_DOWN)
		zoom = 1.10;
	blk->i_end = ft_translate(i, blk->i_end, (1.0 * zoom));
	blk->r_end = ft_translate(r, blk->r_end, (1.0 * zoom));
	blk->i_beg = ft_translate(i, blk->i_beg, (1.0 * zoom));
	blk->r_beg = ft_translate(r, blk->r_beg, (1.0 * zoom));
	ft_render(blk);
	return (0);
}

int	ch_ose(int key, t_data *blk)
{
	if (key == ESC_BUT)
		ft_close(blk);
	else if (key == A_UP)
		key_maker(blk, 1);
	else if (key == A_DOWN)
		key_maker(blk, 2);
	else if (key == A_LEFT)
		key_maker(blk, 3);
	else if (key == A_RIGHT)
		key_maker(blk, 4);
	else if (key == C_BUT)
		ft_palet(blk);
	else if (key == R_BUT)
		ft_reset(blk, R_BUT);
	ft_render(blk);
	return (0);
}
