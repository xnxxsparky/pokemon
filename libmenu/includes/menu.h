/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:57:09 by bcausseq          #+#    #+#             */
/*   Updated: 2026/06/11 02:27:10 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
#define MENU_H

/*
 * do I add an ingame phone for the NPC to sometimes contact the player ?
 */

typedef enum	e_game_states
{
	MAIN_MENU,
	LOAD_SAVE,
	GAME,
	GAME_MENU,
	GAME_OPTIONS,
	BAG,
	POKEMON_MENU,
	BADGES,
	POKEDEX,
	SAVE,
	OPTIONS,
	CHAT_NPC,
	STORE,
	UNKNOWN
}	t_game_states;

typedef struct	s_buttons
{
	char	*text;
	int		x;
	int		y;
	void	(*action)(t_game *game);
}	t_buttons;

typedef struct	s_menu
{
	t_buttons	*but;
	int			but_nbr;
	int			index_but;
}	t_menu;

#endif
