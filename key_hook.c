/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 13:32:37 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/30 00:11:20 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int			key_hook(int keycode, t_env *env)
{
	dprintf(1, "%d\n", keycode);
	if (keycode == ESP)
		exit(0);
	if (keycode == PLUS)
		env->zoom += 0.2;
	ft_bzero(env->img.char_img, WIDTH * 4  * HEIGHT);
	ft_draw(env, "Mandelbrot");
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
	return (0);
}
