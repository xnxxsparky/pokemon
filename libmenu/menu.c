/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:17:06 by bcausseq          #+#    #+#             */
/*   Updated: 2026/06/11 22:23:12 by bcausseq         ###   ########.fr       */
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
back_mod(void *game)
{
	t_game	*ctx = (t_game *)game;

	ctx->state = GAME;
}

void
free_menus(t_game *game)
{
	if (game->menu_game.but)
		free(game->menu_game.but);
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

void
menu_mod_handler(t_game *game)
{
	if (IsKeyPressed(game->joystick.w.key))
	{
		game->menu_game.index_but--;
		if (game->menu_game.index_but < 0)
			game->menu_game.index_but = GAME_MENU_NBR - 1;
	}
	else if (IsKeyPressed(game->joystick.s.key))
	{
		game->menu_game.index_but++;
		if (game->menu_game.index_but > GAME_MENU_NBR)
			game->menu_game.index_but = 0;
	}
	else if (IsKeyPressed(game->joystick.enter.key))
		game->menu_game.but[game->menu_game.index_but].action(game);
	else if (IsKeyPressed(game->joystick.ret.key))
		back_mod(game);
}
