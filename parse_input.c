/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:49:03 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/12 01:21:58 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fract.h"

void	ft_error(void)
{
	ft_putstr("Argumento invalido amigo...\n");
	exit(255);
}

double	ft_atof(char *str, int i, int neg, double nb)
{
	double	div;

	div = 0.1;
	while (str[i] == '+' || ft_isspace(str[i]) || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (nb * neg);
}

void	ft_typed(t_data *blk, char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		argv[1][i] = ft_tolower(argv[1][i]);
		i++;
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		blk->type = "mandelbrot";
	else if (ft_strcmp(argv[1], "dove") == 0)
		blk->type = "dove";
	else if (ft_strcmp(argv[1], "burningship") == 0)
		blk->type = "burningship";
	else if (ft_strcmp(argv[1], "tricorn") == 0)
		blk->type = "tricorn";
	else if (ft_strcmp(argv[1], "julia") == 0)
		blk->type = "julia";
	else
		ft_error();
}

void	blk_init(t_data *blk, char **argv, int argc)
{
	if (argc == 3 || argc < 2)
		ft_error();
	else if (argc == 4)
	{
		blk->ci = ft_atof(argv[2], 0, 1, 0.0);
		blk->cr = ft_atof(argv[3], 0, 1, 0.0);
		if (blk->ci < -2 || blk->cr == -2 || blk->cr > 2 || blk->ci > 2)
			ft_error();
	}
	else if (argc == 2)
	{
		blk->ci = 0.8;
		blk->cr = 0;
	}
	ft_typed(blk, argv);
	blk->i_end = 2.0;
	blk->i_beg = -2.0;
	blk->r_end = 1.5;
	blk->r_beg = -2.5;
	blk->palet = 2;
	blk->r = 2;
	blk->b = 13;
}

int	main(int argc, char *argv[])
{
	t_data	blk;

	blk_init(&blk, argv, argc);
	blk.mlx = mlx_init();
	blk.win = mlx_new_window(blk.mlx, WIDTH, HEIGHT, "Fract-oil");
	blk.img = mlx_new_image(blk.mlx, WIDTH, HEIGHT);
	blk.addr = mlx_get_data_addr(blk.img, &blk.bits_per_pixel, &blk.line_length,
			&blk.endian);
	ft_render(&blk);
	mlx_put_image_to_window(blk.mlx, blk.win, blk.img, 0, 0);
	mlx_hook(blk.win, WIN_X, 0, &ft_close, &blk);
	mlx_key_hook(blk.win, &ch_ose, &blk);
	mlx_mouse_hook(blk.win, &clk_act, &blk);
	mlx_loop(blk.mlx);
}
