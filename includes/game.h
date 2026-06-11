/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:53:59 by bcausseq          #+#    #+#             */
/*   Updated: 2026/06/11 02:10:13 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include <stdbool.h>
#include <stdlib.h>
#include "../raylib/src/raylib.h"
#include "../libmenu/includes/menu.h"

typedef enum e_secondary_status
{
	CONFUSED,
	NONE_S
}	t_secondary_status;

typedef enum e_primary_status
{
	POISONED,
	BURNED,
	PARALYSED,
	FROZEN,
	ASLEEP,
	NONE_P
}	t_primary_status;

typedef enum e_item_types
{
	COMMON,
	MEDICAL,
	BALLS,
	TM,
	BERRIES,
	BATTLE_OBJ,
	RARE
}	t_item_types;

typedef enum e_types
{
	FIRE,
	ELECTRIK,
	GRASS,
	POISON,
	GHOST,
	DARK,
	FAIRY,
	WATER,
	GROUND,
	ROCK,
	STEEL,
	FLYING,
	NORMAL,
	DRAGON,
	PSYCHIC,
	BUG,
	FIGHTING,
	ICE
}	t_types;

typedef struct s_affect
{
	t_types	*affect;
	size_t	len;
}	t_affect;

typedef struct s_move
{
	char		*name;
	t_types		type;
	size_t		base_power;
	size_t		precision;
	size_t		power_points;
	t_affect	affects[3];
	//TODO : add an union ? I guess for all the secondary effects of the game (main status, secondary status, debuff of stats, buff of stats)
}	t_move;

typedef struct s_stats
{
	int	hp;
	int	attack;
	int	defense;
	int	special_attack;
	int	special_defense;
	int	speed;
}	t_stats;

typedef struct s_pokedex
{
	char	*name;
	size_t	index;
	t_types	types[2];
	char	*desc;
	//cry
	//front skin
	bool	caught;
}	t_pokedex;

typedef struct s_item
{
	char	*name;
	size_t	stock;
	t_item_types	type;
	//effect
}	t_item;

typedef struct s_pokemon
{
	char				*name;
	char				*nickname;
	t_stats				base;
	t_stats				iv;
	t_stats				ev;
	t_stats				total;
	//abylity ?
	//nature ?
	t_primary_status	p_status;
	t_secondary_status	s_status;
	size_t				xp;
	size_t				xp_next_lvl;
	size_t				curr_hp;
	size_t				lvl;
	//front and back skin
	t_types				types[2];
	t_move				moves[4];
	size_t				happy;
	t_item				held_item;
	size_t				t_id;
	//evolution ?
	t_affect			affects[3];
	size_t				index;
}	t_pokemon;

typedef struct s_id_card
{
	size_t	badges;
}	t_id_card;

typedef struct s_bag_page
{
	size_t	s_index;
	t_item	items[9999];
}	t_bag_page;

typedef struct s_bag
{
	t_bag_page		slots[7];
	t_item_types	last_open;
}	t_bag;

typedef struct s_trainer
{
	char		*name;
	size_t		id;
	t_pokedex	pokedex;//need to decide how many pokemon there'll be, cause it's just an array of pages
	t_pokemon	party[6];
	t_bag		bag;
	t_id_card	trainer_card;
}	t_trainer;

#endif
