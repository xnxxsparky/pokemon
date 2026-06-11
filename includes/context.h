/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 02:09:48 by bcausseq          #+#    #+#             */
/*   Updated: 2026/06/11 02:18:20 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

typedef struct	s_game
{
	t_game_states	state;
}	t_game;

t_game_states
get_game_state(t_game *game);

void
fill_context(t_game *game);

void
apply_hooks_game(t_game *game);
