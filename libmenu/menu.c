/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:17:06 by bcausseq          #+#    #+#             */
/*   Updated: 2026/06/11 22:01:01 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

#define GAME_MENU_NBR 6

void
pokedex_mod(void *game)
{
	t_game	*ctx = (t_game *)game;

	ctx->state = POKEDEX;
}

void
pokemon_mod(void *game)
{
	t_game	*ctx = (t_game *)game;

	ctx->state = POKEMON_MENU;
}

void
bag_mod(void *game)
{
	t_game	*ctx = (t_game *)game;

	ctx->state = BAG;
}

void
badges_mod(void *game)
{
	t_game	*ctx = (t_game *)game;

	ctx->state = BADGES;
}

void
save_mod(void *game)
{
	t_game	*ctx = (t_game *)game;

	ctx->state = SAVE;
}

void
options_mod(void *game)
{
	t_game	*ctx = (t_game *)game;

	ctx->state = OPTIONS;
}

void
init_menus(t_game *game)
{
	//todo : change 0 0 by coords of the menu, and the func mod
	const t_buttons	but_text[GAME_MENU_NBR] = 
	{
		{"Pokedex", 0, 0, pokedex_mod},
		{"Pokemon", 0, 0, pokemon_mod},
		{"Bag", 0, 0, bag_mod},
		{"Profile", 0, 0, badges_mod},
		{"Save", 0, 0, save_mod},
		{"Options", 0, 0, options_mod}
	};

	game->menu_game.but_nbr = GAME_MENU_NBR;

	game->menu_game.but = ft_calloc(GAME_MENU_NBR, sizeof(t_buttons));
	if (!game->menu_game.but)
		ft_fprintf(2, "Malloc failled for the game menu\n"); return ;

	ft_memcpy(game->menu_game.but, but_text, sizeof(t_buttons) * GAME_MENU_NBR);
}
