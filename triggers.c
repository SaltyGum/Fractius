/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:38:11 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/12 12:26:42 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fract.h"

double	dove(t_data *blk, double cr, double ci)
{
	double	i;

	i = 0;
	blk->zr = 0.0;
	blk->zi = 0.0;
	blk->zr2 = blk->zr * blk->zr;
	blk->zi2 = blk->zi * blk->zi;
	while ((i < MAX_IT) && ((blk->zr2 + blk->zi2) < 4))
	{
		blk->zi = fabs(2.0 * blk->zr * blk->zi) + -ci;
		blk->zr = sqrt(blk->zr2) - sqrt(blk->zi2) + cr;
		blk->zr2 = blk->zr * blk->zr;
		blk->zi2 = blk->zi * blk->zi;
		i++;
	}
	if (i == MAX_IT)
		return (MAX_IT);
	i = i + 1 - log(log2(fabs(blk->zr2 + blk->zi2)));
	return (i);
}

double	julia(t_data *blk, double zr, double zi)
{
	double	i;

	i = 0;
	blk->zr = zr;
	blk->zi = zi;
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

double	burn_ship(t_data *blk, double cr, double ci)
{
	double	i;

	i = 0;
	blk->zr = 0.0;
	blk->zi = 0.0;
	blk->zr2 = blk->zr * blk->zr;
	blk->zi2 = blk->zi * blk->zi;
	while ((i < MAX_IT) && ((blk->zr2 + blk->zi2) < 4))
	{
		blk->zi = fabs(2.0 * blk->zr * blk->zi) + -ci;
		blk->zr = blk->zr2 - blk->zi2 + cr;
		blk->zr2 = blk->zr * blk->zr;
		blk->zi2 = blk->zi * blk->zi;
		i++;
	}
	if (i == MAX_IT)
		return (MAX_IT);
	i = i + 1 - log(log2(fabs(blk->zr2 + blk->zi2)));
	return (i);
}

double	tri_fact(t_data *blk, double cr, double ci)

{
	double	i;

	i = 0;
	blk->zr = 0.0;
	blk->zi = 0.0;
	blk->zr2 = blk->zr * blk->zr;
	blk->zi2 = blk->zi * blk->zi;
	while ((i < MAX_IT) && ((blk->zr2 + blk->zi2) < 4))
	{
		blk->zi = -(2.0 * blk->zr * blk->zi) + ci;
		blk->zr = blk->zr2 - blk->zi2 + cr;
		blk->zr2 = blk->zr * blk->zr;
		blk->zi2 = blk->zi * blk->zi;
		i++;
	}
	if (i == MAX_IT)
		return (MAX_IT);
	i = i + 1 - log(log2(fabs(blk->zr2 + blk->zi2)));
	return (i);
}

double	mandelb(t_data *blk, double cr, double ci)
{
	double	i;

	i = 0;
	blk->zr = 0.0;
	blk->zi = 0.0;
	blk->zr2 = blk->zr * blk->zr;
	blk->zi2 = blk->zi * blk->zi;
	while ((i < MAX_IT) && ((blk->zr2 + blk->zi2) < 4))
	{
		blk->zi = 2.0 * blk->zr * blk->zi + ci;
		blk->zr = blk->zr2 - blk->zi2 + cr;
		blk->zr2 = blk->zr * blk->zr;
		blk->zi2 = blk->zi * blk->zi;
		i++;
	}
	if (i == MAX_IT)
		return (MAX_IT);
	i = i + 1 - log(log2(fabs(blk->zr2 + blk->zi2)));
	return (i);
}
