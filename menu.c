/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:09:40 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/12 16:16:50 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fract.h"

void	ft_menu(void)
{
	ft_putstr("Welcome\n");
	ft_putstr("Here is a list of commands:\n");
	ft_putstr("\tC - Change color\n");
	ft_putstr("\tArrows - Move the image\n");
	ft_putstr("\tMouse Scroll UP - Zoom in\n");
	ft_putstr("\tMouse Scroll DOWN - Zoom out\n");
	ft_putstr("\tR - Reset the chosen fractal\n");
	ft_putstr("\tESC - Close the application\n");
}
