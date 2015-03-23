/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:49:08 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/23 16:09:05 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_draw(t_env *env, char *name)
{
	if (ft_strequ(name, "Mandelbrot"))
		ft_mandelbrot(env);
	else
	{
		ft_putendl("Elle n'existe pas ta fractal");
		exit(0);
	}
}
