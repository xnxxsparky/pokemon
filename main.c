/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:39:41 by bcausseq          #+#    #+#             */
/*   Updated: 2026/06/11 22:27:39 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/window.h"
#include "raylib/src/raylib.h"
#include "libft_hidden/includes/libft.h"
#include "includes/context.h"
#include "includes/game.h"

//todo : swap_mod need to get the status of the keyboard and then switch case
//and in the case you handle everything

void
swap_mod(t_game *game)
{
	t_game_states	state = get_game_state(game);

	switch(state)
	{
		case GAME:
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Plz work", 190, 200, 20, LIGHTGRAY);
			EndDrawing();
			apply_hooks_game(game);
			if (IsKeyPressed(KEY_F))
				ToggleFullscreen();
			break;

		case GAME_MENU:
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("This is a menu in WIP", 190, 200, 20, LIGHTGRAY);
			EndDrawing();
			menu_mod_handler(game);
			if (IsKeyPressed(KEY_F))
				ToggleFullscreen();
			break;

		default:
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("The mod you are trying to access ins't yet deved", 190, 200, 20, LIGHTGRAY);
			EndDrawing();
			if (IsKeyPressed(KEY_F))
				ToggleFullscreen();
			break;

	}

}

int
main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	fill_context(&game);
	if (argc != 2 && argc != 3)
		return (1);

	init_hooks(&(game.joystick));
	init_menus(&game);

	(argc == 2) ? init_window((const char *)argv[1], false):init_window((const char *)argv[1], true);

	while (!WindowShouldClose())
		swap_mod(&game);
	CloseWindow();
	free_menus(&game);
	return (0);
}
