/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 13:32:37 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/23 13:56:09 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int			key_hook(int keycode, t_env *env)
{
	dprintf(1, "%d\n", keycode);
	if (keycode == 53)
		exit(0);
	(void)env;
	return (0);
}
