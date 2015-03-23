/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:48:36 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/23 20:57:36 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	ft_init_mandel(t_env *env)
{
	env->zoom = 1;
	env->mandel.iteration_max = 128;
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
	if (i == env->mandel.iteration_max)
	{
		ft_put_pixel_to_image(env, y, x, 0xffffff);
	}
}

void	ft_mandelbrot(t_env *env)
{
	int		x;
	int		y;

	ft_init_mandel(env);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_each(y, x, env);
			x++;
		}
		y++;
	}
}
