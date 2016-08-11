#include "stdafx.h"
#include "class.h"
#include "chessboard.h"
#include <cstdlib>

extern const int MINIMUM_NUMBER = 1;
extern const int MAXIMUM_NUMBER = 64;
extern int movement_indirect1;
extern int movement_indirect2;
extern int movement_indirect3;
extern bool movement_indirect_isset;
extern struct structure_movements_computer temporary;

//class player 1
bool player_1::get_the_player_first ()
{
	return the_player_first;
};

bool player_1::get_movement_have_done ()
{
	return movement_have_done;
}

bool player_1::get_player_1_movement ()
{
	return player_1_movement;
}

int player_1::get_jump_from_field ()
{
	return jump_from_field;
}


void player_1::set_movement_have_done (bool movement_have_done_new)
{
	movement_have_done = movement_have_done_new;
}

void player_1::set_player_1_movement (bool player_1_movement_new)
{
	player_1_movement = player_1_movement_new;
}

void player_1::set_jump_from_field (int jump_from_field_new)
{
	if (jump_from_field_new >= MINIMUM_NUMBER-1)
	{
		jump_from_field = jump_from_field_new;
	}
	else
	{
		jump_from_field = MINIMUM_NUMBER-1;
	}
}

//class player 2
player_2::player_2 ()
{
	player_1();
	player_2_is_human = true;
}

bool player_2::get_player_2_is_human (void)
{
	return player_2_is_human;
}

void player_2::set_player_2_is_human (bool player_2_is_human_new)
{
	player_2_is_human = player_2_is_human_new;
}

//table analysis table fields
analysis_table_fields::analysis_table_fields()
{
	clear_table();
};

struct struct_movements_table analysis_table_fields::return_the_best_movement (void)
{
	int current_weight_of_movement = 1;
	int the_number_of_possible_moves = 0;
	analysis_table_fields numbers;

	if ((movement_indirect_isset == false) && (movement_indirect1 != 0))
	{
		movement_indirect_isset = true;
		temporary.movement_p_1 = 0;
		temporary.movement_k_1 = 0;
		temporary.movement_p_2 = movement_indirect1;
		temporary.movement_k_2 = movement_indirect2;
		temporary.movement_p_3 = movement_indirect2;
		temporary.movement_k_3 = movement_indirect3;
	}
	else if ((movement_indirect1 != 0) && (movement_indirect2 != 0) && (movement_indirect3 != 0))
	{
		struct struct_movements_table best_movement;
		best_movement.initial_field = movement_indirect1;
		best_movement.final_field = movement_indirect2;
		best_movement.value_jump = 20;
		movement_indirect1 = 0;
		return best_movement;
	}
	else if ((movement_indirect1 == 0) && (movement_indirect2 != 0) && (movement_indirect3 != 0))
	{
		struct struct_movements_table best_movement;
		best_movement.initial_field = movement_indirect2;
		best_movement.final_field = movement_indirect3;
		best_movement.value_jump = 20;
		movement_indirect1 = 0;
		movement_indirect2 = 0;
		movement_indirect3 = 0;
		movement_indirect_isset = false;
		return best_movement;
	}
	
	//movements are added to the table
	for (int i=MINIMUM_NUMBER-1; i<MAXIMUM_NUMBER; i++)
	{
		if (possible_movements[i][0] == 1)
		{
			break;
		}
		else if (possible_movements[i][2] == current_weight_of_movement)
		{
			numbers.add_a_new_field (possible_movements[i][0], possible_movements[i][1], possible_movements[i][2]);
		}
		else if (possible_movements[i][2] > current_weight_of_movement)
		{
			numbers.clear_table();
			numbers.add_a_new_field (possible_movements[i][0], possible_movements[i][1], possible_movements[i][2]);
			current_weight_of_movement = possible_movements[i][2];
		}
	}

	//count the numbers of possible movements
	for (int i=MINIMUM_NUMBER-1; i<MAXIMUM_NUMBER; i++)
	{
		if (numbers.possible_movements[i][1] != 0)
		{
			the_number_of_possible_moves++;
		}
		else
		{
			break;
		}
	}
	
	if (the_number_of_possible_moves == 0)
	{
		return there_no_next_movement();
	}

	if (the_number_of_possible_moves == 1)
	{
		struct struct_movements_table best_movement;
		best_movement.initial_field = possible_movements[0][0];
		best_movement.final_field = possible_movements[0][1];
		best_movement.value_jump = possible_movements[0][2];
		temporary.movement_p_1 = best_movement.initial_field;
		temporary.movement_k_1 = best_movement.final_field;
		return best_movement;
	}
	else
	{
		struct struct_movements_table best_movement;
		int liczba = rand()%the_number_of_possible_moves; 
		best_movement.initial_field = numbers.possible_movements[liczba][0];
		best_movement.final_field = numbers.possible_movements[liczba][1];
		best_movement.value_jump = numbers.possible_movements[liczba][2];
		temporary.movement_p_1 = best_movement.initial_field;
		temporary.movement_k_1 = best_movement.final_field;
		return best_movement;
	}
	return there_no_next_movement();
};

void analysis_table_fields::add_a_new_field (int initial_field, int final_field, int value_jump)
{
	if (possible_movements[0][2] < value_jump)
	{
		clear_table();
	}
	else if (possible_movements[0][2] > value_jump)
	{
		return;
	}
	
	for (int i=MINIMUM_NUMBER-1; i<MAXIMUM_NUMBER; i++)
	{
		if (possible_movements[i][0] == 0)
		{
			possible_movements[i][0] = initial_field;
			possible_movements[i][1] = final_field;
			possible_movements[i][2] = value_jump;
			return;
		}
	}
};

void analysis_table_fields::clear_table (void)
{
	for (int i=MINIMUM_NUMBER-1; i<MAXIMUM_NUMBER; i++)
	{
		for (int j=0; j<3; j++)
		{
			possible_movements[i][j] = 0;
		}
	}
}