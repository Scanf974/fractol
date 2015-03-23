/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:48:36 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/23 20:52:52 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	ft_init_mandel(t_env *env)
{
	env->zoom = 2.2;
	env->mandel.iteration_max = 128;
	env->mandel.lim_x1 = -2.1;
	env->mandel.lim_x2 = 0.6;
	env->mandel.lim_y1 = -1.2;
	env->mandel.lim_y2 = 1.2;
	env->mandel.image_x = (env->mandel.lim_x2 - env->mandel.lim_x1) * env->zoom;
	env->mandel.image_y = (env->mandel.lim_y2 - env->mandel.lim_y1) * env->zoom;
	//env->mandel.zoom_x = WIDTH / (env->mandel.lim_x2 - env->mandel.lim_x1);
	//env->mandel.zoom_y = 240 / (env->mandel.lim_y2 - env->mandel.lim_y1);
	//dprintf(1, "%f %f\n", WIDTH / (env->mandel.lim_x2 - env->mandel.lim_x1), env->mandel.zoom_x);
}

static void	ft_each(int y, int x, t_env *env)
{
	int			i;
	t_plex		c;
	t_plex		new;
	t_plex		old;
	double		tmp;

	c.re = 1.5 * (x - WIDTH / 2) / ( 0.5 * env->zoom * WIDTH) - 0.5;
	c.im = (y - HEIGHT / 2) / (0.5 * env->zoom * HEIGHT) + 0;
	dprintf(1, "%f\n", c.im);
	new.re = 0;
	new.im = 0;
	old.re = 0;
	old.im = 0;
	i = 0;
	while (i < env->mandel.iteration_max)
	{
		old.re = new.re;
		old.im = new.im;
		new.re = old.re * old.re - old.im * old.im + c.re;
		new.im = 2 * old.re * old.im + c.im;
		if (new.re * new.re + new.im * new.im > 4)
			break ;
		i++;
	}
	if (i != env->mandel.iteration_max)
	{
		env->img.char_img[ x * 4 + y * env->img.size_line] = i % 256;
		env->img.char_img[ x * 4 + y * env->img.size_line + 1] = 255;
		env->img.char_img[ x * 4 + y * env->img.size_line + 2] = 255 * (i < env->mandel.iteration_max);
	}
}

void	ft_mandelbrot(t_env *env)
{
	int		x;
	int		y;

	ft_init_mandel(env);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			ft_each(y, x, env);
			y++;
		}
		x++;
	}
}
