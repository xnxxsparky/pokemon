/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 01:05:58 by bcausseq          #+#    #+#             */
/*   Updated: 2026/06/11 02:14:19 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/context.h"
#include "includes/map.h"
#include "raylib/src/raylib.h"

void
apply_hooks_game(t_game *game)
{
	t_hooktable	hooks = {0};
	t_player	player = {0};

	if (hooks.w.activated)
		player.y--;
	else if (hooks.s.activated)
		player.y++;

	if (hooks.a.activated)
		player.x--;
	else if (hooks.d.activated)
		player.x++;

	else if (IsKeyDown(MENU))
		game->state = GAME_MENU;
}

//todo : add gamepad compatibility

void
hooks_up_game()
{
	t_hooktable	hooks = {0};

	if (IsKeyReleased(hooks.w.key))
		hooks.w.activated = false;
	if (IsKeyReleased(hooks.a.key))
		hooks.a.activated = false;
	if (IsKeyReleased(hooks.s.key))
		hooks.s.activated = false;
	if (IsKeyReleased(hooks.d.key))
		hooks.d.activated = false;
}

void
hooks_down_game()
{
	t_hooktable	hooks = {0};

	if (IsKeyDown(hooks.w.key))
		hooks.w.activated = true;
	if (IsKeyDown(hooks.a.key))
		hooks.a.activated = true;
	if (IsKeyDown(hooks.s.key))
		hooks.s.activated = true;
	if (IsKeyDown(hooks.d.key))
		hooks.d.activated = true;
}

void
init_hooks()
{
	t_hooktable	hooks = {0};

	hooks.w.key = KEY_W;
	hooks.a.key = KEY_A;
	hooks.s.key = KEY_S;
	hooks.d.key = KEY_D;
}
