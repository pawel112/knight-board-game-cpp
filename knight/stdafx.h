// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once

struct struct_movements_table there_no_next_movement (void);
bool analize_of_computer_movements (void);
bool make_the_movement (int initial_field, int final_field);
int get_field_value (int number_field);
int is_end_of_the_game (void);
void the_end_of_the_of_movement_button_visible (bool is_visible);
void which_player_field_visible (bool is_visible);
void start_a_new_game (bool with_human);
void set_value_field (int number_field, int value);
void highlight_available_field (int nr_field);
void add_the_first_move (int nr_field1, int nr_field2);
void clicked_field (int nr_field);
void end_of_movement (void);
void remove_the_backlight_fields (bool value_7, bool value_8);
void button_end_of_movement_clicked (void);
System::String^ conversion_to_letters (int input_number);
System::Windows::Forms::PictureBox^ return_field (int number_field);

// TODO: reference additional headers your program requires here