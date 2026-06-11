/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:43:09 by bcausseq          #+#    #+#             */
/*   Updated: 2026/06/10 21:53:09 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/window.h"
#include "raylib/src/raylib.h"

void
init_window(const char *title, bool fullscreen)
{
	const t_window	window = 
	{
		.title = title,
		.screenWidth = WIDTH,
		.screenHeight = HEIGHT,
		.fps = FPS,
		.fullscreen = fullscreen
	};
	InitWindow(window.screenWidth, window.screenHeight, window.title);
	SetTargetFPS(window.fps);
	if (window.fullscreen)
		ToggleFullscreen();
}
