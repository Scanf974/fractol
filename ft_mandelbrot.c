/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:48:36 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/23 21:21:57 by bsautron         ###   ########.fr       */
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
	t_plex		z;
	double		tmp;

	c.re = 1.5 * (x - WIDTH / 2) / ( 0.5 * env->zoom * WIDTH) - 0.5;
	c.im = (y - HEIGHT / 2) / (0.5 * env->zoom * HEIGHT) + 0;
	z.re = 0;
	z.im = 0;
	i = 0;
	while (i < env->mandel.iteration_max)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		if (z.re * z.re + z.im * z.im > 4)
			break ;
		i++;
	}
	if (i != env->mandel.iteration_max)
		ft_put_pixel_to_image(env, y, x, 0xffffff);
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
