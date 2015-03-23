/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:23:06 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/23 23:45:27 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		main(int argc, char **argv)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	if (argc == 2)
	{
		if (!(env.mlx = mlx_init()))
		{
			ft_putendl_fd("env -i lol", 2);
			exit(1);
		}
		env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "Oh My God, Look at her butt");
		env.img.ptr = mlx_new_image(env.mlx, WIDTH, HEIGHT);
		env.img.char_img = mlx_get_data_addr(env.img.ptr, &env.img.bpp, &env.img.size_line, &env.img.endian);
		ft_draw(&env, argv[1]);
		mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
		mlx_hook(env.win, MotionNotify, PointerMotionMask, pointer_motion_hook, &env);
		mlx_key_hook(env.win, key_hook, &env);
		mlx_expose_hook(env.win, expose_hook, &env);
		mlx_loop(env.mlx);
	}
	else
		ft_putendl("ya pas de fractal");
	return (0);
}
