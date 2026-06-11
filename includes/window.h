/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:07:14 by bcausseq          #+#    #+#             */
/*   Updated: 2026/06/10 21:53:39 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
#define WINDOW_H

#define WIDTH	800
#define HEIGHT	450
#define FPS		60

#include "../raylib/src/raylib.h"
#include <stdbool.h>

typedef struct	s_window
{
	const char		*title;
	unsigned int	screenWidth;
	unsigned int	screenHeight;
	unsigned int	fps;
	bool			fullscreen;
}	t_window;

void
init_window(const char *title, bool fullscreen);

#endif
