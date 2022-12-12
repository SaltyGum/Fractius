/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:06:13 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/12 12:40:21 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fract.h"

void	ch_color(t_data *blk, double r, double g, double b)
{
		blk->r = r;
		blk->g = g;
		blk->b = b;
		blk->palet++;
}

void	ft_palet(t_data *blk)
{
	if (blk->palet == 0)
		ch_color(blk, 2, 0, 13);
	else if (blk->palet == 1)
		ch_color(blk, 2, 13, 0);
	else if (blk->palet == 2)
		ch_color(blk, 0, 13, 2);
	else if (blk->palet == 3)
		ch_color(blk, 0, 2, 13);
	else if (blk->palet == 4)
		ch_color(blk, 13, 2, 0);
	else if (blk->palet == 5)
	{
		ch_color(blk, 13, 0, 2);
		blk->palet = 0;
	}
}

void	ft_reset(t_data *blk, int key)
{
	if (key == R_BUT)
	{
		blk->i_end = 2.1;
		blk->i_beg = -1.9;
		blk->r_end = 2.1;
		blk->r_beg = -1.9;
		blk->palet = 0;
		ft_palet(blk);
		ft_render(blk);
	}
}
