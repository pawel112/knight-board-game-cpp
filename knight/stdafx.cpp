// stdafx.cpp : source file that includes just the standard includes
// knight.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include <cstdlib>
#include "stdafx.h"
#include "chessboard.h"
#include "class.h"

using namespace knight;

player_1 player1;
player_2 player2;
const int MINIMUM_NUMBER = 1;
const int MAXIMUM_NUMBER = 64;
int player_1::jump_from_field = MINIMUM_NUMBER-1;
int movement_indirect1 = MINIMUM_NUMBER-1;
int movement_indirect2 = MINIMUM_NUMBER-1;
int movement_indirect3 = MINIMUM_NUMBER-1;
int movement_indirect_value = MINIMUM_NUMBER-1;
int counter_movements_computer = 0;
bool player_1::player_1_movement = true;
bool movement_indirect_isset = false;
bool end_of_the_players_1_movements = false;
bool end_of_the_players_2_movements = false;
struct structure_movements_computer temporary;

//others
struct struct_movements_table there_no_next_movement (void)
{
	struct struct_movements_table the_next_move;
	the_next_move.initial_field = 0;
	the_next_move.final_field = 0;
	the_next_move.value_jump = 0;
	return the_next_move;
}

bool make_the_movement (int initial_field, int final_field)
{
	add_the_first_move (initial_field, final_field);
	
	knight::chessboard::message_box->Text = L"Select the 1. field.";
	bool movement_of_white_pawns = false;
	if (player1.get_player_1_movement () == true)
	{
		movement_of_white_pawns = true;
	}

	//is the same fields?
	if (initial_field == final_field)
	{
		if ((player1.get_player_1_movement() == false) && (player2.get_player_2_is_human() == true))
		{
			knight::chessboard::message_box->Text = L"Select another pawn";
		}
		knight::chessboard::initial_field_movement = MINIMUM_NUMBER-1;
		remove_the_backlight_fields (true, true);
		return false;
	}

	if (((player1.get_player_1_movement() == true) && (get_field_value(initial_field) != 2)) || ((player1.get_player_1_movement() == false) && (get_field_value(initial_field) != 5)))
	{
		if ((player1.get_player_1_movement() == true) || ((player1.get_player_1_movement() == false) && (player2.get_player_2_is_human() == true)))
		{
			knight::chessboard::message_box->Text = L"Select another pawn";
		}
		knight::chessboard::initial_field_movement = MINIMUM_NUMBER-1;
		remove_the_backlight_fields (true, true);
		return false;
	}
	else if (((player1.get_player_1_movement() == true) && (get_field_value(final_field) == 7)) || ((player1.get_player_1_movement() == false) && (get_field_value(final_field) == 8)))
	{
		if ((player2.get_player_2_is_human() == false) && (get_field_value(2) == 5) && (get_field_value(4) == 5) && (get_field_value(6) == 5) && (get_field_value(8) == 5) && (get_field_value(9) == 5) && (get_field_value(11) == 5) && (get_field_value(13) == 5) && (get_field_value(15) == 5))
		{
			int result_of_player_1 = Convert::ToInt32(knight::chessboard::player_1_score->Text);
			knight::chessboard::message_box->Text = L"The 2. player won! Congratulations!";
			result_of_player_1++;
			knight::chessboard::player_1_score->Text = L""+result_of_player_1;
		}
		
		//movement correctly done
		set_value_field (final_field,6);
		int the_value_of_the_initial_field = get_field_value(initial_field);
		set_value_field (initial_field,get_field_value(final_field));
		set_value_field (final_field,the_value_of_the_initial_field);

		remove_the_backlight_fields (true, false);
		if (player1.get_player_1_movement() == true)
		{
			player1.set_movement_have_done (true);
		}
		else
		{
			player2.set_movement_have_done (true);
		}

		if (((final_field-initial_field) == 7) || ((final_field-initial_field) == 9) || ((final_field-initial_field) == -7) || ((final_field-initial_field) == -9))
		{
			end_of_movement();
		}
		else
		{
			the_end_of_the_of_movement_button_visible (true);
			player_1::set_jump_from_field (final_field);
		}
		
		remove_the_backlight_fields (true, true);
		return true;
	}

	if ((player1.get_player_1_movement() == false) && (player2.get_player_2_is_human() == true))
	{
		knight::chessboard::message_box->Text = L"Select another pawn";
	}
	knight::chessboard::initial_field_movement = MINIMUM_NUMBER-1;
	
	remove_the_backlight_fields (true, true);
	return false;
}

bool analize_of_computer_movements (void)
{
	struct struct_movements_table return_from_function;
	analysis_table_fields results;
	for (int i=MINIMUM_NUMBER; i<MAXIMUM_NUMBER; i++)
	{
		highlight_available_field(i);
		for (int j=MINIMUM_NUMBER; j<MAXIMUM_NUMBER; j++)
		{
			if (get_field_value(j) == 8)
			{
				set_value_field (j, 6);
				int weight_of_of_movement = 0;
				if ((j-i == -7) || (j-i == -9))
				{
					weight_of_of_movement = 1;
				}
				else if ((j-i == -14) || (j-i == -18))
				{
					weight_of_of_movement = 4;
				}
				if ((player_1::get_jump_from_field () == 0) || (player_1::get_jump_from_field () == i))
				{
					results.add_a_new_field (i, j, weight_of_of_movement);
				}
			}
		}
	}

	//checked possibility of jumping of higher weight
	remove_the_backlight_fields (true, true);
	for (int i=MINIMUM_NUMBER; i<MAXIMUM_NUMBER; i++)
	{
		if (((player_1::get_jump_from_field () == 0) || (player_1::get_jump_from_field () == i)) && (get_field_value (i) == 5))
		{
			//right
			//level 1
			if ((get_field_value(i-14) == 6) && ((get_field_value(i-7) == 2) || (get_field_value(i-7) == 5)))
			{
				results.add_a_new_field (i, i-14, 4);
				//right
				//level 2
				if ((get_field_value(i-28) == 6) && ((get_field_value(i-21) == 2) || (get_field_value(i-21) == 5)))
				{
					if ((movement_indirect1 == 0) || (8 > movement_indirect_value))
					{
						movement_indirect1 = i-14;
						movement_indirect2 = i-28;
						movement_indirect_value = 8;
					}
					results.add_a_new_field (i, i-14, 8);
					//right
					//level 3
					if ((get_field_value(i-42) == 6) && ((get_field_value(i-35) == 2) || (get_field_value(i-35) == 5)))
					{
						if ((movement_indirect1 == 0) || (12 > movement_indirect_value))
						{
							movement_indirect1 = i-14;
							movement_indirect2 = i-28;
							movement_indirect3 = i-42;
							movement_indirect_value = 12;
						}
						results.add_a_new_field (i, i-14, 12);
					}

					//left
					//level 3
					if ((get_field_value(i-46) == 6) && ((get_field_value(i-37) == 2) || (get_field_value(i-37) == 5)))
					{
						if ((movement_indirect1 == 0) || (12 > movement_indirect_value))
						{
							movement_indirect1 = i-14;
							movement_indirect2 = i-28;
							movement_indirect3 = i-46;
							movement_indirect_value = 12;
						}
						results.add_a_new_field (i, i-14, 12);
					}
				}

				//left
				//level 2
				if ((get_field_value(i-32) == 6) && ((get_field_value(i-23) == 2) || (get_field_value(i-23) == 5)))
				{
					if ((movement_indirect1 == 0) || (8 > movement_indirect_value))
					{
						movement_indirect1 = i-14;
						movement_indirect2 = i-32;
						movement_indirect_value = 8;
					}
					results.add_a_new_field (i, i-14, 8);
					//right
					//level 3
					if ((get_field_value(i-46) == 6) && ((get_field_value(i-39) == 2) || (get_field_value(i-39) == 5)))
					{
						if ((movement_indirect1 == 0) || (12 > movement_indirect_value))
						{
							movement_indirect1 = i-14;
							movement_indirect2 = i-32;
							movement_indirect3 = i-46;
							movement_indirect_value = 12;
						}
						results.add_a_new_field (i, i-14, 12);
					}

					//left
					//level 3
					if ((get_field_value(i-50) == 6) && ((get_field_value(i-41) == 2) || (get_field_value(i-41) == 5)))
					{
						if ((movement_indirect1 == 0) || (12 > movement_indirect_value))
						{
							movement_indirect1 = i-14;
							movement_indirect2 = i-32;
							movement_indirect3 = i-50;
							movement_indirect_value = 12;
						}
						results.add_a_new_field (i, i-14, 12);
					}
				}
			}

			//left
			//level 1
			if ((get_field_value(i-18) == 6) && ((get_field_value(i-9) == 2) || (get_field_value(i-9) == 5)))
			{
				results.add_a_new_field (i, i-18, 4);
				//right
				//level 2
				if ((get_field_value(i-32) == 6) && ((get_field_value(i-25) == 2) || (get_field_value(i-25) == 5)))
				{
					if ((movement_indirect1 == 0) || (8 > movement_indirect_value))
					{
						movement_indirect1 = i-18;
						movement_indirect2 = i-32;
						movement_indirect_value = 8;
					}
					results.add_a_new_field (i, i-18, 8);
					//right
					//level 3
					if ((get_field_value(i-46) == 6) && ((get_field_value(i-39) == 2) || (get_field_value(i-39) == 5)))
					{
						if ((movement_indirect1 == 0) || (12 > movement_indirect_value))
						{
							movement_indirect1 = i-18;
							movement_indirect2 = i-32;
							movement_indirect3 = i-46;
							movement_indirect_value = 12;
						}
						results.add_a_new_field (i, i-18, 12);
					}

					//left
					//level 3
					if ((get_field_value(i-50) == 6) && ((get_field_value(i-41) == 2) || (get_field_value(i-41) == 5)))
					{
						if ((movement_indirect1 == 0) || (12 > movement_indirect_value))
						{
							movement_indirect1 = i-18;
							movement_indirect2 = i-32;
							movement_indirect3 = i-50;
							movement_indirect_value = 12;
						}
						results.add_a_new_field (i, i-18, 12);
					}
				}

				//left
				//level 2
				if ((get_field_value(i-36) == 6) && ((get_field_value(i-27) == 2) || (get_field_value(i-27) == 5)))
				{
					if ((movement_indirect1 == 0) || (8 > movement_indirect_value))
					{
						movement_indirect1 = i-18;
						movement_indirect2 = i-36;
						movement_indirect_value = 8;
					}
					results.add_a_new_field (i, i-18, 8);
					//right
					//level 3
					if ((get_field_value(i-50) == 6) && ((get_field_value(i-43) == 2) || (get_field_value(i-43) == 5)))
					{
						if ((movement_indirect1 == 0) || (12 > movement_indirect_value))
						{
							movement_indirect1 = i-18;
							movement_indirect2 = i-36;
							movement_indirect3 = i-50;
							movement_indirect_value = 12;
						}
						results.add_a_new_field (i, i-18, 12);
					}

					//left
					//level 3
					if ((get_field_value(i-54) == 6) && ((get_field_value(i-45) == 2) || (get_field_value(i-45) == 5)))
					{
						if ((movement_indirect1 == 0) || (12 > movement_indirect_value))
						{
							movement_indirect1 = i-18;
							movement_indirect2 = i-36;
							movement_indirect3 = i-54;
							movement_indirect_value = 12;
						}
						results.add_a_new_field (i, i-18, 12);
					}
				}
			}
		}
	}

	return_from_function = results.return_the_best_movement();

	switch (return_from_function.value_jump)
	{
	case 0:
		if (counter_movements_computer == 0)
		{
			//undo the pawn
			for (int i=18; i<24; i=i+2)
			{
				if (get_field_value (i) == 5)
				{
					if (i==18)
					{
						counter_movements_computer = 0;
						set_value_field (27, 8);
						make_the_movement (18, 27);
						return false;
						break;
					}
					else if (i==24)
					{
						counter_movements_computer = 0;
						set_value_field (31, 8);
						make_the_movement (24, 31);
						return false;
						break;
					}
					else
					{
						int number = rand()%2;
						if (number == 0)
						{
							//left
							counter_movements_computer = 0;
							set_value_field (i+7, 8);
							make_the_movement (i, i+7);
							return false;
							break;
						}
						else
						{
							//right
							counter_movements_computer = 0;
							set_value_field (i+9, 8);
							make_the_movement (i, i+9);
							return false;
							break;
						}
					}
				}
			}
		}
		else
		{
			counter_movements_computer = 0;
			return false;
		}
	case 1:
		counter_movements_computer++;
		set_value_field (return_from_function.final_field, 8);
		make_the_movement (return_from_function.initial_field, return_from_function.final_field);
		return false;
	default:
		counter_movements_computer++;
		set_value_field (return_from_function.final_field, 8);
		make_the_movement (return_from_function.initial_field, return_from_function.final_field);
		player_1::set_jump_from_field (return_from_function.final_field);
		return true;
	}
}

int get_field_value (int number_field)
{
	if ((number_field < MINIMUM_NUMBER) || (number_field > MAXIMUM_NUMBER))
	{
		return 0;
	}

	System::String^ nazwa = return_field (number_field)->ImageLocation;

	if (nazwa == "b_c.PNG")
	{
		return 2;
	}
	if (nazwa == "b_p.PNG")
	{
		return 3;
	}
	else if (nazwa == "c_c.PNG")
	{
		return 5;
	}
	else if (nazwa == "c_p.PNG")
	{
		return 6;
	}
	else if (nazwa == "backlight_b_c.png")
	{
		return 7;
	}
	else if (nazwa == "backlight_c_c.png")
	{
		return 8;
	}
	return 0;
}

int is_end_of_the_game (void)
{
	int result_of_player_1 = Convert::ToInt32(knight::chessboard::player_1_score->Text);
	int result_of_player_2 = Convert::ToInt32(knight::chessboard::player_2_score->Text);

	if ((get_field_value(50) == 2) && (get_field_value(52) == 2) && (get_field_value(54) == 2) && (get_field_value(56) == 2) && (get_field_value(57) == 2) && (get_field_value(59) == 2) && (get_field_value(61) == 2) && (get_field_value(63) == 2) && (get_field_value(2) == 5) && (get_field_value(4) == 5) && (get_field_value(6) == 5) && (get_field_value(8) == 5) && (get_field_value(9) == 5) && (get_field_value(11) == 5) && (get_field_value(13) == 5) && (get_field_value(15) == 5))
	{
		knight::chessboard::game_started = false;
		the_end_of_the_of_movement_button_visible (false);
		player1.set_movement_have_done (true);
		player2.set_movement_have_done (true);
		knight::chessboard::message_box->Text = L"";
		knight::chessboard::which_player_field->Text = L"End of the game!";
		return 3;
	}

	if (player1.get_player_1_movement() == true)
	{
		if ((get_field_value(50) == 2) && (get_field_value(52) == 2) && (get_field_value(54) == 2) && (get_field_value(56) == 2) && (get_field_value(57) == 2) && (get_field_value(59) == 2) && (get_field_value(61) == 2) && (get_field_value(63) == 2))
		{
			knight::chessboard::message_box->Text = L"The 1. player won! Congratulations!";
			result_of_player_2++;
			knight::chessboard::player_2_score->Text = L""+result_of_player_2;
			end_of_the_players_1_movements = true;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if ((get_field_value(2) == 5) && (get_field_value(4) == 5) && (get_field_value(6) == 5) && (get_field_value(8) == 5) && (get_field_value(9) == 5) && (get_field_value(11) == 5) && (get_field_value(13) == 5) && (get_field_value(15) == 5))
		{
			knight::chessboard::message_box->Text = L"The 2. player won! Congratulations!";
			result_of_player_1++;
			knight::chessboard::player_1_score->Text = L""+result_of_player_1;
			end_of_the_players_2_movements = true;
			return 2;
		}
		else
		{
			return 0;
		}
	}
}

void the_end_of_the_of_movement_button_visible (bool is_visible)
{
	if (is_visible == true)
	{
		knight::chessboard::end_of_movement ->Visible = true;
		knight::chessboard::end_of_movement ->Enabled = true;
	}
	else
	{
		knight::chessboard::end_of_movement ->Visible = false;
		knight::chessboard::end_of_movement ->Enabled = false;
	}
};

void which_player_field_visible (bool is_visible)
{
	if (is_visible == true)
	{
		knight::chessboard::which_player_field->Visible = true;
	}
	else
	{
		knight::chessboard::which_player_field->Visible = false;
	}
};

void start_a_new_game (bool with_human)
{
	set_value_field (1,3);
	set_value_field (2,2);
	set_value_field (3,3);
	set_value_field (4,2);
	set_value_field (5,3);
	set_value_field (6,2);
	set_value_field (7,3);
	set_value_field (8,2);

	set_value_field (9,2);
	set_value_field (10,3);
	set_value_field (11,2);
	set_value_field (12,3);
	set_value_field (13,2);
	set_value_field (14,3);
	set_value_field (15,2);
	set_value_field (16,3);

	set_value_field (17,3);
	set_value_field (18,6);
	set_value_field (19,3);
	set_value_field (20,6);
	set_value_field (21,3);
	set_value_field (22,6);
	set_value_field (23,3);
	set_value_field (24,6);

	set_value_field (25,6);
	set_value_field (26,3);
	set_value_field (27,6);
	set_value_field (28,3);
	set_value_field (29,6);
	set_value_field (30,3);
	set_value_field (31,6);
	set_value_field (32,3);

	set_value_field (33,3);
	set_value_field (34,6);
	set_value_field (35,3);
	set_value_field (36,6);
	set_value_field (37,3);
	set_value_field (38,6);
	set_value_field (39,3);
	set_value_field (40,6);

	set_value_field (41,6);
	set_value_field (42,3);
	set_value_field (43,6);
	set_value_field (44,3);
	set_value_field (45,6);
	set_value_field (46,3);
	set_value_field (47,6);
	set_value_field (48,3);

	set_value_field (49,3);
	set_value_field (50,5);
	set_value_field (51,3);
	set_value_field (52,5);
	set_value_field (53,3);
	set_value_field (54,5);
	set_value_field (55,3);
	set_value_field (56,5);

	set_value_field (57,5);
	set_value_field (58,3);
	set_value_field (59,5);
	set_value_field (60,3);
	set_value_field (61,5);
	set_value_field (62,3);
	set_value_field (63,5);
	set_value_field (64,3);
	
	knight::chessboard::initial_field_movement = MINIMUM_NUMBER-1;
	knight::chessboard::moving_back_from_the_field = MINIMUM_NUMBER-1;
	knight::chessboard::game_started = true;

	knight::chessboard::message_box->Text = L"";
	knight::chessboard::field_with_the_computer_movement->Text = L"";
	which_player_field_visible (true);
	knight::chessboard::which_player_field->Text = L"Player 1. movement";

	player1.set_player_1_movement (true);
	player1.set_movement_have_done (false);
	player2.set_movement_have_done (false);
	end_of_the_players_1_movements = false;
	end_of_the_players_2_movements = false;
	the_end_of_the_of_movement_button_visible (false);
	knight::chessboard::player_1_score->Text = L"0";
	knight::chessboard::player_2_score->Text = L"0";
	temporary.movement_p_1 = 0;
	temporary.movement_p_2 = 0;
	temporary.movement_p_3 = 0;
	temporary.movement_k_1 = 0;
	temporary.movement_k_2 = 0;
	temporary.movement_k_3 = 0;

	if (with_human == false)
	{
		player2.set_player_2_is_human (false);
	}
	else
	{
		player2.set_player_2_is_human (true);
	}
	player_1::set_jump_from_field (0);
};

void set_value_field (int number_field, int value)
{
	if ((number_field == 33) && (value == 5))
	{
		number_field = 33-8;
	}
	
	switch (value)
	{
	case 2:
		//white pawn - black field
		return_field (number_field)->Load("b_c.PNG");
		break;
	case 3:
		//white field
		return_field (number_field)->Load("b_p.PNG");
		break;
	case 5:
		//black pawn - black field
		return_field (number_field)->Load("c_c.PNG");
		break;
	case 6:
		//black field
		return_field (number_field)->Load("c_p.PNG");
		break;
	case 7:
		//blue field
		return_field (number_field)->Load("backlight_b_c.png");
		break;
	case 8:
		//blue field
		return_field (number_field)->Load("backlight_c_c.png");
		break;
	default:
		return;
		break;
	}
};

void add_the_first_move (int nr_field1, int nr_field2)
{
	if (temporary.temp1 != 0)
	{
		return;
	}
	else
	{
		temporary.temp1 = nr_field1;
		temporary.temp2 = nr_field2;
	}
}

void highlight_available_field (int nr_field)
{
	knight::chessboard::message_box->Text = L"Select the 2. field.";
	bool movement_of_white_pawns = false;
	bool movement_done = true;
	if (player1.get_player_1_movement() == true)
	{
		if (player_1::get_jump_from_field() != 0)
		{
			if (nr_field != player_1::get_jump_from_field() )
			{
				knight::chessboard::message_box->Text = L"Select another pawn";
				knight::chessboard::initial_field_movement = MINIMUM_NUMBER-1;
				return;
			}
		}
		
		movement_of_white_pawns = true;
		if (get_field_value(nr_field) != 2)
		{
			knight::chessboard::message_box->Text = L"Select another pawn";
			knight::chessboard::initial_field_movement = MINIMUM_NUMBER-1;
			return;
		}
		movement_done = player1.get_movement_have_done();
	}
	else
	{
		if (player_1::get_jump_from_field() != 0)
		{
			if (nr_field != player_1::get_jump_from_field() )
			{
				if (player2.get_player_2_is_human() == true)
				{
					knight::chessboard::message_box->Text = L"Select another pawn";
				}
				knight::chessboard::initial_field_movement = MINIMUM_NUMBER-1;
				return;
			}
		}
		
		if (get_field_value(nr_field) != 5)
		{
			if (player2.get_player_2_is_human() == true)
			{
				knight::chessboard::message_box->Text = L"Select another pawn";
			}
			knight::chessboard::initial_field_movement = MINIMUM_NUMBER-1;
			return;
		}
		movement_done = player2.get_movement_have_done();
	}

	//backlight fields around | -9, -7, +7, +9
	if ((nr_field-9 > 0) && (movement_done == false))
	{
		if (movement_of_white_pawns == true)
		{
			if (get_field_value (nr_field-9) == 6)
			{
				set_value_field (nr_field-9,7);
			}
		}
		else
		{
			if (get_field_value (nr_field-9) == 6)
			{
				set_value_field (nr_field-9,8);
			}
		}
	}
	if ((nr_field-7 > 0) && (movement_done == false))
	{
		if (movement_of_white_pawns == true)
		{
			if (get_field_value (nr_field-7) == 6)
			{
				set_value_field (nr_field-7,7);
			}
		}
		else
		{
			if (get_field_value (nr_field-7) == 6)
			{
				set_value_field (nr_field-7,8);
			}
		}
	}
	if ((nr_field+7 < 65) && (movement_done == false))
	{
		if (movement_of_white_pawns == true)
		{
			if (get_field_value (nr_field+7) == 6)
			{
				set_value_field (nr_field+7,7);
			}
		}
		else
		{
			if (get_field_value (nr_field+7) == 6)
			{
				set_value_field (nr_field+7,8);
			}
		}
	}
	if ((nr_field+9 < 65) && (movement_done == false))
	{
		if (movement_of_white_pawns == true)
		{
			if (get_field_value (nr_field+9) == 6)
			{
				set_value_field (nr_field+9,7);
			}
		}
		else
		{
			if (get_field_value (nr_field+9) == 6)
			{
				set_value_field (nr_field+9,8);
			}
		}
	}

	//backlight shelves around | -18, -14, +14, +18
	if ((nr_field-18 > 0) && (nr_field-9 > 0))
	{
		if (movement_of_white_pawns == true)
		{
			if ((get_field_value (nr_field-18) == 6) && ((get_field_value (nr_field-9) == 5) || (get_field_value (nr_field-9) == 2)))
			{
				set_value_field (nr_field-18,7);
			}
		}
		else
		{
			if ((get_field_value (nr_field-18) == 6) && ((get_field_value (nr_field-9) == 5) || (get_field_value (nr_field-9) == 2)))
			{
				set_value_field (nr_field-18,8);
			}
		}
	}
	if ((nr_field-14 > 0) && (nr_field-9 > 0))
	{
		if (movement_of_white_pawns == true)
		{
			if ((get_field_value (nr_field-14) == 6) && ((get_field_value (nr_field-7) == 5) || (get_field_value (nr_field-7) == 2)))
			{
				set_value_field (nr_field-14,7);
			}
		}
		else
		{
			if ((get_field_value (nr_field-14) == 6) && ((get_field_value (nr_field-7) == 5) || (get_field_value (nr_field-7) == 2)))
			{
				set_value_field (nr_field-14,8);
			}
		}
	}
	if ((nr_field+14 < 65) && (nr_field+9 < 65))
	{
		if (movement_of_white_pawns == true)
		{
			if ((get_field_value (nr_field+14) == 6) && ((get_field_value (nr_field+7) == 5) || (get_field_value (nr_field+7) == 2)))
			{
				set_value_field (nr_field+14,7);
			}
		}
		else
		{
			if ((get_field_value (nr_field+14) == 6) && ((get_field_value (nr_field+7) == 5) || (get_field_value (nr_field+7) == 2)))
			{
				set_value_field (nr_field+14,8);
			}
		}
	}
	if ((nr_field+18 < 65) && (nr_field+9 < 65))
	{
		if (movement_of_white_pawns == true)
		{
			if ((get_field_value (nr_field+18) == 6) && ((get_field_value (nr_field+9) == 5) || (get_field_value (nr_field+9) == 2)))
			{
				set_value_field (nr_field+18,7);
			}
		}
		else
		{
			if ((get_field_value (nr_field+18) == 6) && ((get_field_value (nr_field+9) == 5) || (get_field_value (nr_field+9) == 2)))
			{
				set_value_field (nr_field+18,8);
			}
		}
	}
}

void clicked_field (int nr_field)
{	
	knight::chessboard::field_with_the_computer_movement->Text = L"";
	if (knight::chessboard::game_started == false)
	{
		 return;
	}
	else if ((get_field_value (nr_field) == 2) && (player1.get_player_1_movement () == false))
	{
		return;
	}
	else if ((get_field_value (nr_field) == 5) && (player1.get_player_1_movement () == true))
	{
		return;
	}
	else if ((get_field_value (nr_field) == 5) && (player2.get_player_2_is_human() == false))
	{
		return;
	}
	else if (knight::chessboard::initial_field_movement == MINIMUM_NUMBER-1)
	{
		knight::chessboard::initial_field_movement = nr_field;
		highlight_available_field (nr_field);
		return;
	}
	else
	{
		if (make_the_movement (knight::chessboard::initial_field_movement, nr_field) == true)
		{
			knight::chessboard::initial_field_movement = MINIMUM_NUMBER-1;
		}
		remove_the_backlight_fields (true, true);
	}
};

void end_of_movement (void)
{
	if (is_end_of_the_game () == 3)
	{
		return;
	}

	for (int i=MINIMUM_NUMBER; i<MAXIMUM_NUMBER; i++)
	{
		if ((get_field_value(i) == 7) || (get_field_value(i) == 8))
		{
			set_value_field (i,6);
		}
	}
	knight::chessboard::field_with_the_computer_movement->Text = L"";
	player1.set_movement_have_done (false);
	player2.set_movement_have_done (false);
	player_1::set_jump_from_field (MINIMUM_NUMBER-1);
	movement_indirect1 = MINIMUM_NUMBER-1;
	movement_indirect2 = MINIMUM_NUMBER-1;
	movement_indirect3 = MINIMUM_NUMBER-1;
	movement_indirect_value = MINIMUM_NUMBER-1;
	temporary.temp1 = MINIMUM_NUMBER-1;
	temporary.temp2 = MINIMUM_NUMBER-1;
	movement_indirect_isset = false;
				
	if (player1.get_player_1_movement() == true)
	{
		knight::chessboard::which_player_field->Text = L"Player 2. movement";
		player1.set_player_1_movement (false);
		if (end_of_the_players_2_movements == true)
		{
			end_of_movement();
		}

		if ((player1.get_player_1_movement () == false) && (player2.get_player_2_is_human() == false))
		{
			for (int i=0; i<1; )
			{
				bool temporary2 = analize_of_computer_movements ();
				if (temporary2 == false)
				{
					i++;
				}
			}

			remove_the_backlight_fields (true, true);
			player1.set_movement_have_done (false);
			player2.set_movement_have_done (false);
			player_1::set_jump_from_field (MINIMUM_NUMBER-1);
			movement_indirect1 = MINIMUM_NUMBER-1;
			movement_indirect2 = MINIMUM_NUMBER-1;
			movement_indirect3 = MINIMUM_NUMBER-1;
			movement_indirect_value = 0;
			movement_indirect_isset = false;
			knight::chessboard::which_player_field->Text = L"Player 1. movement";
			knight::chessboard::message_box->Text = L"Select the 1. field.";
		
			if (temporary.movement_k_2 == 0)
			{
				knight::chessboard::field_with_the_computer_movement->Text = L"Movement from "+conversion_to_letters (temporary.movement_p_1)+" to "+conversion_to_letters (temporary.movement_k_1)+".";
			}
			else if (temporary.movement_k_3 == 0)
			{
				knight::chessboard::field_with_the_computer_movement->Text = L"Movement from "+conversion_to_letters (temporary.temp1)+" to "+conversion_to_letters (temporary.temp2)+"\nand "+conversion_to_letters (temporary.movement_p_2)+" to "+conversion_to_letters (temporary.movement_k_2)+".";
				temporary.temp1 = MINIMUM_NUMBER-1;
				temporary.temp2 = MINIMUM_NUMBER-1;
			}
			else
			{
				knight::chessboard::field_with_the_computer_movement->Text = L"Movement from "+conversion_to_letters (temporary.movement_p_1)+" to "+conversion_to_letters (temporary.movement_k_1)+"\nand "+conversion_to_letters (temporary.movement_p_2)+" to "+conversion_to_letters (temporary.movement_k_2)+"\nand "+conversion_to_letters (temporary.movement_p_3)+" to "+conversion_to_letters (temporary.movement_k_3)+".";
			}

			temporary.movement_p_1 = 0;
			temporary.movement_p_2 = 0;
			temporary.movement_p_3 = 0;
			temporary.movement_k_1 = 0;
			temporary.movement_k_2 = 0;
			temporary.movement_k_3 = 0;
			player1.set_player_1_movement (true);
			the_end_of_the_of_movement_button_visible (true);
			return;
		}
	}
	else
	{
		knight::chessboard::which_player_field->Text = L"Player 1. movement";
		player1.set_player_1_movement (true);
		if (end_of_the_players_1_movements == true)
		{
			knight::chessboard::initial_field_movement = MINIMUM_NUMBER-1;
			end_of_movement();
		}
	}
	the_end_of_the_of_movement_button_visible (false);
};

void remove_the_backlight_fields (bool value_7, bool value_8)
{
	for (int i=MINIMUM_NUMBER; i<MAXIMUM_NUMBER+1; i++)
	{
		switch (get_field_value (i))
		{
		case 7:
			if (value_7 == true)
			{
				set_value_field (i,6);
			}
			break;
		case 8:
			if (value_8 == true)
			{
				set_value_field (i,6);
			}
			break;
		default:
			break;
		}
		
		if ((value_7 == true) && (get_field_value(i) == 7))
		{
			set_value_field (i,6);
			return;
		}
		else if ((value_8 == true) && (get_field_value(i) == 8))
		{
			set_value_field (i,6);
		}
	}
}

void button_end_of_movement_clicked (void)
{
	if ((get_field_value(50) == 2) && (get_field_value(52) == 2) && (get_field_value(54) == 2) && (get_field_value(56) == 2) && (get_field_value(57) == 2) && (get_field_value(59) == 2) && (get_field_value(61) == 2) && (get_field_value(63) == 2) && (get_field_value(2) == 5) && (get_field_value(4) == 5) && (get_field_value(6) == 5) && (get_field_value(8) == 5) && (get_field_value(9) == 5) && (get_field_value(11) == 5) && (get_field_value(13) == 5) && (get_field_value(15) == 5))
	{
		knight::chessboard::game_started = false;
		the_end_of_the_of_movement_button_visible (false);
		player1.set_movement_have_done (true);
		player2.set_movement_have_done (true);
		knight::chessboard::message_box->Text = L"";
		knight::chessboard::field_with_the_computer_movement->Text = L"";
		knight::chessboard::which_player_field->Text = L"End of the game!";
		return;
	}
	
	if (knight::chessboard::game_started == false)
	{
		 return;
	}
	else
	{
		knight::chessboard::initial_field_movement = MINIMUM_NUMBER-1;
		end_of_movement();
	}
};

System::String^ conversion_to_letters (int input_number)
{
	switch (input_number)
	{
	case 1:
		return "A1";
		break;
	case 2:
		return "B1";
		break;
	case 3:
		return "C1";
		break;
	case 4:
		return "D1";
		break;
	case 5:
		return "E1";
		break;
	case 6:
		return "F1";
		break;
	case 7:
		return "G1";
		break;
	case 8:
		return "H1";
		break;
	case 9:
		return "A2";
		break;
	case 10:
		return "B2";
		break;
	case 11:
		return "C2";
		break;
	case 12:
		return "D2";
		break;
	case 13:
		return "E2";
		break;
	case 14:
		return "F2";
		break;
	case 15:
		return "G2";
		break;
	case 16:
		return "H2";
		break;
	case 17:
		return "A3";
		break;
	case 18:
		return "B3";
		break;
	case 19:
		return "C3";
		break;
	case 20:
		return "D3";
		break;
	case 21:
		return "E3";
		break;
	case 22:
		return "F3";
		break;
	case 23:
		return "G3";
		break;
	case 24:
		return "H3";
		break;
	case 25:
		return "A4";
		break;
	case 26:
		return "B4";
		break;
	case 27:
		return "C4";
		break;
	case 28:
		return "D4";
		break;
	case 29:
		return "E4";
		break;
	case 30:
		return "F4";
		break;
	case 31:
		return "G4";
		break;
	case 32:
		return "H4";
		break;
	case 33:
		return "A5";
		break;
	case 34:
		return "B5";
		break;
	case 35:
		return "C5";
		break;
	case 36:
		return "D5";
		break;
	case 37:
		return "E5";
		break;
	case 38:
		return "F5";
		break;
	case 39:
		return "G5";
		break;
	case 40:
		return "H5";
		break;
	case 41:
		return "A6";
		break;
	case 42:
		return "B6";
		break;
	case 43:
		return "C6";
		break;
	case 44:
		return "D6";
		break;
	case 45:
		return "E6";
		break;
	case 46:
		return "F6";
		break;
	case 47:
		return "G6";
		break;
	case 48:
		return "H6";
		break;
	case 49:
		return "A7";
		break;
	case 50:
		return "B7";
		break;
	case 51:
		return "C7";
		break;
	case 52:
		return "D7";
		break;
	case 53:
		return "E7";
		break;
	case 54:
		return "F7";
		break;
	case 55:
		return "G7";
		break;
	case 56:
		return "H7";
		break;
	case 57:
		return "A8";
		break;
	case 58:
		return "B8";
		break;
	case 59:
		return "C8";
		break;
	case 60:
		return "D8";
		break;
	case 61:
		return "E8";
		break;
	case 62:
		return "F8";
		break;
	case 63:
		return "G8";
		break;
	case 64:
		return "H8";
		break;
	default:
		return "";
		break;
	}
	return "";
}

System::Windows::Forms::PictureBox^ return_field (int number_field)
{
	switch (number_field)
	{
	case 1:
		return knight::chessboard::pictureBox1;
		break;
	case 2:
		return knight::chessboard::pictureBox2;
		break;
	case 3:
		return knight::chessboard::pictureBox3;
		break;
	case 4:
		return knight::chessboard::pictureBox4;
		break;
	case 5:
		return knight::chessboard::pictureBox5;
		break;
	case 6:
		return knight::chessboard::pictureBox6;
		break;
	case 7:
		return knight::chessboard::pictureBox7;
		break;
	case 8:
		return knight::chessboard::pictureBox8;
		break;
	case 9:
		return knight::chessboard::pictureBox9;
		break;
	case 10:
		return knight::chessboard::pictureBox10;
		break;
	case 11:
		return knight::chessboard::pictureBox11;
		break;
	case 12:
		return knight::chessboard::pictureBox12;
		break;
	case 13:
		return knight::chessboard::pictureBox13;
		break;
	case 14:
		return knight::chessboard::pictureBox14;
		break;
	case 15:
		return knight::chessboard::pictureBox15;
		break;
	case 16:
		return knight::chessboard::pictureBox16;
		break;
	case 17:
		return knight::chessboard::pictureBox17;
		break;
	case 18:
		return knight::chessboard::pictureBox18;
		break;
	case 19:
		return knight::chessboard::pictureBox19;
		break;
	case 20:
		return knight::chessboard::pictureBox20;
		break;
	case 21:
		return knight::chessboard::pictureBox21;
		break;
	case 22:
		return knight::chessboard::pictureBox22;
		break;
	case 23:
		return knight::chessboard::pictureBox23;
		break;
	case 24:
		return knight::chessboard::pictureBox24;
		break;
	case 25:
		return knight::chessboard::pictureBox25;
		break;
	case 26:
		return knight::chessboard::pictureBox26;
		break;
	case 27:
		return knight::chessboard::pictureBox27;
		break;
	case 28:
		return knight::chessboard::pictureBox28;
		break;
	case 29:
		return knight::chessboard::pictureBox29;
		break;
	case 30:
		return knight::chessboard::pictureBox30;
		break;
	case 31:
		return knight::chessboard::pictureBox31;
		break;
	case 32:
		return knight::chessboard::pictureBox32;
		break;
	case 33:
		return knight::chessboard::pictureBox33;
		break;
	case 34:
		return knight::chessboard::pictureBox34;
		break;
	case 35:
		return knight::chessboard::pictureBox35;
		break;
	case 36:
		return knight::chessboard::pictureBox36;
		break;
	case 37:
		return knight::chessboard::pictureBox37;
		break;
	case 38:
		return knight::chessboard::pictureBox38;
		break;
	case 39:
		return knight::chessboard::pictureBox39;
		break;
	case 40:
		return knight::chessboard::pictureBox40;
		break;
	case 41:
		return knight::chessboard::pictureBox41;
		break;
	case 42:
		return knight::chessboard::pictureBox42;
		break;
	case 43:
		return knight::chessboard::pictureBox43;
		break;
	case 44:
		return knight::chessboard::pictureBox44;
		break;
	case 45:
		return knight::chessboard::pictureBox45;
		break;
	case 46:
		return knight::chessboard::pictureBox46;
		break;
	case 47:
		return knight::chessboard::pictureBox47;
		break;
	case 48:
		return knight::chessboard::pictureBox48;
		break;
	case 49:
		return knight::chessboard::pictureBox49;
		break;
	case 50:
		return knight::chessboard::pictureBox50;
		break;
	case 51:
		return knight::chessboard::pictureBox51;
		break;
	case 52:
		return knight::chessboard::pictureBox52;
		break;
	case 53:
		return knight::chessboard::pictureBox53;
		break;
	case 54:
		return knight::chessboard::pictureBox54;
		break;
	case 55:
		return knight::chessboard::pictureBox55;
		break;
	case 56:
		return knight::chessboard::pictureBox56;
		break;
	case 57:
		return knight::chessboard::pictureBox57;
		break;
	case 58:
		return knight::chessboard::pictureBox58;
		break;
	case 59:
		return knight::chessboard::pictureBox59;
		break;
	case 60:
		return knight::chessboard::pictureBox60;
		break;
	case 61:
		return knight::chessboard::pictureBox61;
		break;
	case 62:
		return knight::chessboard::pictureBox62;
		break;
	case 63:
		return knight::chessboard::pictureBox63;
		break;
	case 64:
		return knight::chessboard::pictureBox64;
		break;
	}
	System::Windows::Forms::PictureBox^ empty;
	return empty;
}