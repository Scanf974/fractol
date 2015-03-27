/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 13:56:47 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/27 07:25:26 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_put_pixel_to_image(t_env *env, int y, int x, int color)
{
	size_t          index;

	index = x * 4 + y * env->img.size_line;
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
	{
		env->img.char_img[index] = (unsigned char)color;
		env->img.char_img[index + 1] = (unsigned char)(color >> 8);
		env->img.char_img[index + 2] = (unsigned char)(color >> 16);
	}
}
