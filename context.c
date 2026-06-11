/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 02:01:19 by bcausseq          #+#    #+#             */
/*   Updated: 2026/06/11 02:10:41 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmenu/includes/menu.h"
#include "includes/context.h"

t_game_states
get_game_state(t_game *game)
{
	return (game->state);
}

void
fill_context(t_game *game)
{
	game->state = GAME;
}
