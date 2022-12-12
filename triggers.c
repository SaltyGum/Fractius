/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:38:11 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/11 22:20:20 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fract.h"

double	dove(t_data *blk)
{
	double	i;

	i = 0;
	blk->zr = 0.0;
	blk->zi = 0.0;
	blk->zr2 = blk->zr * blk->zr;
	blk->zi2 = blk->zi * blk->zi;
	while ((i < MAX_IT) && ((blk->zr2 + blk->zi2) < 4))
	{
		blk->zi = fabs(2.0 * blk->zr * blk->zi)
			+ (blk->i_beg + (blk->y * (blk->i_end - blk->i_beg) / WIDTH));
		blk->zr = sqrt(blk->zr2) - sqrt(blk->zi2)
			+ (blk->r_beg + (blk->x * ((blk->r_end - blk->r_beg) / HEIGHT)));
		blk->zr2 = blk->zr * blk->zr;
		blk->zi2 = blk->zi * blk->zi;
		i++;
	}
	if (i == MAX_IT)
		return (MAX_IT);
	i = i + 1 - log(log2(fabs(blk->zr2 + blk->zi2)));
	return (i);
}

double	julia(t_data *blk)
{
	double	i;

	i = 0;
	blk->zr = 2.0 * 2.0 * (blk->x - WIDTH / 2.0) / WIDTH;
	blk->zi = 2.0 * 2.0 * (blk->y - HEIGHT / 2.0) / HEIGHT;
	blk->zr2 = blk->zr * blk->zr;
	blk->zi2 = blk->zi * blk->zi;
	while ((i < MAX_IT) && ((blk->zr2 + blk->zi2) < 4))
	{
		blk->zi = 2.0 * blk->zr * blk->zi + blk->ci;
		blk->zr = blk->zr2 - blk->zi2 + blk->cr;
		blk->zr2 = blk->zr * blk->zr;
		blk->zi2 = blk->zi * blk->zi;
		i++;
	}
	if (i == MAX_IT)
		return (MAX_IT);
	i = i + 1 - log(log2(fabs(blk->zr2 + blk->zi2)));
	return (i);
}

double	burn_ship(t_data *blk)
{
	double	i;

	i = 0;
	blk->zr = 0.0;
	blk->zi = 0.0;
	blk->zr2 = blk->zr * blk->zr;
	blk->zi2 = blk->zi * blk->zi;
	while ((i < MAX_IT) && ((blk->zr2 + blk->zi2) < 4))
	{
		blk->zi = fabs(2.0 * blk->zr * blk->zi)
			+ (blk->i_beg + (blk->y * (blk->i_end - blk->i_beg) / WIDTH));
		blk->zr = sqrt(blk->zr2) - sqrt(blk->zi2)
			+ (blk->r_beg + (blk->x * ((blk->r_end - blk->r_beg) / HEIGHT)));
		blk->zr2 = blk->zr * blk->zr;
		blk->zi2 = blk->zi * blk->zi;
		i++;
	}
	if (i == MAX_IT)
		return (MAX_IT);
	i = i + 1 - log(log2(fabs(blk->zr2 + blk->zi2)));
	return (i);
}

double	tri_fact(t_data *blk)

{
	double	i;

	i = 0;
	blk->zr = 0.0;
	blk->zi = 0.0;
	blk->zr2 = blk->zr * blk->zr;
	blk->zi2 = blk->zi * blk->zi;
	while ((i < MAX_IT) && ((blk->zr2 + blk->zi2) < 4))
	{
		blk->zi = -(2.0 * blk->zr * blk->zi)
			+ (blk->i_beg + (blk->y * (blk->i_end - blk->i_beg) / WIDTH));
		blk->zr = blk->zr2 - blk->zi2
			+ (blk->r_beg + (blk->x * ((blk->r_end - blk->r_beg) / HEIGHT)));
		blk->zr2 = blk->zr * blk->zr;
		blk->zi2 = blk->zi * blk->zi;
		i++;
	}
	if (i == MAX_IT)
		return (MAX_IT);
	i = i + 1 - log(log2(fabs(blk->zr2 + blk->zi2)));
	return (i);
}

double	mandelb(t_data *blk)
{
	double	i;

	i = 0;
	blk->zr = 0.0;
	blk->zi = 0.0;
	blk->zr2 = blk->zr * blk->zr;
	blk->zi2 = blk->zi * blk->zi;
	while ((i < MAX_IT) && ((blk->zr2 + blk->zi2) < 4))
	{
		blk->zi = 2.0 * blk->zr * blk->zi
			+ (blk->i_beg + (blk->y * (blk->i_end - blk->i_beg) / WIDTH));
		blk->zr = blk->zr2 - blk->zi2
			+ (blk->r_beg + (blk->x * ((blk->r_end - blk->r_beg) / HEIGHT)));
		blk->zr2 = blk->zr * blk->zr;
		blk->zi2 = blk->zi * blk->zi;
		i++;
	}
	if (i == MAX_IT)
		return (MAX_IT);
	i = i + 1 - log(log2(fabs(blk->zr2 + blk->zi2)));
	return (i);
}
