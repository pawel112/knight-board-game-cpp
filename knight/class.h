#pragma once

struct struct_movements_table
{
	int initial_field;
	int final_field;
	int value_jump;
};

struct structure_movements_computer
{
	int movement_p_1;
	int movement_p_2;
	int movement_p_3;
	int movement_k_1;
	int movement_k_2;
	int movement_k_3;
	int temp1;
	int temp2;
};

//class player 1
class player_1
{
private:
	bool the_player_first;
	bool movement_have_done;
	static bool player_1_movement;
	static int jump_from_field;
public:
	player_1 (): the_player_first(true), movement_have_done(false) { };
	bool get_the_player_first ();
	bool get_movement_have_done ();
	static bool get_player_1_movement ();
	static int get_jump_from_field ();
	void set_movement_have_done (bool movement_have_done_new);
	static void set_player_1_movement (bool player_1_movement_new);
	static void set_jump_from_field (int jump_from_field_new);
};

//class player 2
class player_2: public player_1
{
private:
	bool player_2_is_human;
public:
	player_2();
	bool get_player_2_is_human (void);
	void set_player_2_is_human (bool player_2_is_human_new);
};

//table analysis table fields
class analysis_table_fields
{
private:
	int possible_movements[64][3];
public:
	analysis_table_fields();
	struct struct_movements_table return_the_best_movement (void);
	void add_a_new_field (int initial_field, int final_field, int value_jump);
	void clear_table (void);
};