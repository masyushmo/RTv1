/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:41:52 by mmasyush          #+#    #+#             */
/*   Updated: 2019/10/23 15:20:58 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv.h"

int		init_sdl(t_sdl  *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (ft_error((char *)SDL_GetError()));
	if (!(sdl->window = SDL_CreateWindow("RTV", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_SHOWN)))
		return (ft_error((char *)SDL_GetError()));
	if (!(sdl->surface = SDL_GetWindowSurface(sdl->window)))
		return (ft_error((char *)SDL_GetError()));
	return (1);
}

void	set_pixel(int x, int y, Uint32 color, SDL_Surface *surr)
{
	Uint32	*pixels;

	pixels = surr->pixels;
	pixels[y * surr->w + x] = color;
}

Uint32	get_pixel(SDL_Surface *texture, int x, int y)
{
	Uint32 *ptr;

	ptr = (Uint32 *)texture->pixels;
	return (ptr[(y * texture->w) + x]);
}
