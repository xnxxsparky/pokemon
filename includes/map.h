/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:10:56 by bcausseq          #+#    #+#             */
/*   Updated: 2026/06/11 02:14:02 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAP_H
#define MAP_H

#define MENU	67

typedef struct	s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct	s_map
{
	int			*lvl_ground;
	int			*lvl_collision;
	t_player	player;
	int			height;
	int			width;
	int			tile_size;
}	t_map;

typedef struct	s_hooks
{
	int		key;
	bool	activated;
}	t_hooks;

typedef struct	s_hooktable
{
	t_hooks	w;
	t_hooks	a;
	t_hooks	s;
	t_hooks	d;
}	t_hooktable;

#endif
