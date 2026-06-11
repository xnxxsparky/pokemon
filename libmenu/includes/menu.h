/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:57:09 by bcausseq          #+#    #+#             */
/*   Updated: 2026/06/11 21:24:14 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
#define MENU_H

/*
 * do I add an ingame phone for the NPC to sometimes contact the player ?
 */

typedef struct	s_buttons
{
	char	*text;
	int		x;
	int		y;
	void	(*action)(void *game);
}	t_buttons;

typedef struct	s_menu
{
	t_buttons	*but;
	int			but_nbr;
	int			index_but;
}	t_menu;

#endif
