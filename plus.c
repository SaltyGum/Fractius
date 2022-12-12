/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:06:13 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/12 01:27:00 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fract.h"

void	ft_palet(t_data *blk)
{
	if (blk->palet == 0)
	{
		blk->r = 2;
		blk->g = 0;
		blk->b = 13;
		blk->palet++;
	}
	else if (blk->palet == 1)
	{
		blk->r = 2;
		blk->g = 13;
		blk->b = 0;
		blk->palet++;	
	}
	else if (blk->palet == 2)
	{
		blk->r = 0;
		blk->g = 13;
		blk->b = 2;
		blk->palet++;	
	}
	else if (blk->palet == 3)
	{
		blk->r = 0;
		blk->g = 2;
		blk->b = 13;
		blk->palet++;	
	}
	else if (blk->palet == 4)
	{
		blk->r = 13;
		blk->g = 2;
		blk->b = 0;
		blk->palet++;	
	}
	else if (blk->palet == 5)
	{
		blk->r = 13;
		blk->g = 0;
		blk->b = 2;
		blk->palet = 0;
	}
	printf("atual -. %d\n", blk->palet);
}
