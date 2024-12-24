#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "Character_Grids.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

void gameplay();
string hide_cursor{ "\033[?25l" };
string show_cursor{ "\033[?25h" };

void shutter();
void clear_character(char character_sheet[3][4]);
void detect_emptiness(bool is_empty[3][4], char character_sheet[3][4]);
//void set_shutter_speed()    !!for climbing!!

int main() {

	cout << "Animation ready . . .\n\n";
	system("pause");
	system("cls");

	gameplay();

	system("pause");
	return 0;
}

void shutter() {
	std::this_thread::sleep_for(std::chrono::milliseconds(250)); // CHRANGED FROM 150 TO 59
	//system("cls");
};

void clear_character(char character_sheet[3][4]) {
	
	for (int i = 0; i < 3; i++) {
		for (int o = 0; o < 4; o++) {

			character_sheet[i][o] = ' ';

		}
	}

}
void detect_emptiness(bool is_empty[3][4], char character_sheet[3][4]) {

	for (int i = 0; i < 3; i++) {
		for (int o = 0; o < 4; o++) {

			if (character_sheet[i][o] == ' ') {
				is_empty[i][o] = true;
			}
			else is_empty[i][o] = false;

		}
	}

}

//LINE 2 CH 38

void gameplay() {

	const std::vector <string> original{ 
	"                                                                                                                                         /   )    \\   /        \\      z",
	"                                                                                                                                        |   |      \\ /          \\______",
	"                                                                                                                                        |   |       O            ======",
	"                                              ______o0                                                                                  |   |      / \\           ______",
	"                                             o88808080                                                                                   \\   )    /   \\         /      ",
	"                                            _080808800                                                                ________>~~o________\\_/____/_____\\_______/______",
	"                                            0888080088                                 o00oo                  _____ooo08080888800808808080880808/8088080\\0800080080808",
	"              ____o00oo__ {o             __d8800808088_                               o80880o               _o088080800080008008080880800088080/080808080\\088080080880",
	"  ___________o00808008000o/_____________o08808000880800__________>--o____o080o______o08088080o_____________oo080800800080008080080808808008008/00808080800\\08080808080",
	"  8808888800880880880088088880008088888080808800808080808000880080808008008080000800080008080080800808008088880888808880088888088808808000888/0808008808008\\8008080808",
	"                                                                                                                                                                       ",
	"                                                                                                                                                                       ",
	"                                                                                                                                                                       "
	}; // Mastercopy for animation

	std::vector <string> row = original; // Active copy for animation


	int position{ 0 }; 
	int choice{ 0 };
	int vertical_modifier{ 0 }; 
	bool end_animation{ false };
	bool up_cleaner{ false }; // (right-up)
	bool up_double_cleaner{ false }; // (right-up-up)
	bool down_cleaner{ false };// (right-down)   [[ BROKEN ]]
	bool down_cleaner_2{ false }; // experimental replacement for down_cleaner
	bool cliff_cleaner{ false }; // manual cleaner for cliff
	bool cycle{ true };
	bool climb_mode{ false };
	bool hold_position{ false };

	char player_part[3][4]
	{ ' ',' ', 'o', '>',
	  '{', '(', ' ', ' ',
	  ' ', '/', '\\', ' '};
	bool part_empty[3][4]
	{ false, false, false, false,
	  false, false, false, false,
	  false, false, false, false };
	
	set_character(player_part, generic);

	//NOTE: replacement problem solved. issue is in vertical modifier
	// be mindful not to go out of bounds on the row array (buffer overflow)
					

	while (end_animation == false) {
		cout << hide_cursor;

		for (position = 0; position < 106; position++) { //start is position = 0 or 2

			//cycle = !cycle; // swaps between true and false wiith each loop
			
			//clear_character(player_part);
			
			detect_emptiness(part_empty, player_part);
			
			if (climb_mode == true) {
				clear_character(player_part);
				set_character(player_part, climbing);
				detect_emptiness(part_empty, player_part);
			}
			
			if (hold_position == true) {
				detect_emptiness(part_empty, player_part);
				position--;
			}
			else { set_character(player_part, generic); detect_emptiness(part_empty, player_part); }

			
			/*
			if (part_empty[0][3] == true) {
				cout << "\n\n\nSuccess!";
				system("pause");
			}
			*/



	// character movement & grid cleaning
				
				if (part_empty[0][0] == false) {
					row[6 + vertical_modifier][position + 4] = player_part[0][0]; // top left box
				}
				else row[6 + vertical_modifier][position + 4] = original[6 + vertical_modifier][position + 4];
				
				if (part_empty[0][1] == false) {
					row[6 + vertical_modifier][position + 5] = player_part[0][1]; // top mid box
				}
				else row[6 + vertical_modifier][position + 5] = original[6 + vertical_modifier][position + 5];
				
				if (part_empty[0][2] == false) {
					row[6 + vertical_modifier][position + 6] = player_part[0][2]; // o
				} 
				else row[6 + vertical_modifier][position + 6] = original[6 + vertical_modifier][position + 6];
				
				if (part_empty[0][3] == false) {
					row[6 + vertical_modifier][position + 7] = player_part[0][3]; // >
				}
				else row[6 + vertical_modifier][position + 7] = original[6 + vertical_modifier][position + 7];
				
				if (part_empty[1][0] == false) {
					row[7 + vertical_modifier][position + 4] = player_part[1][0]; //  {
				}
				else row[7 + vertical_modifier][position + 4] = original[7 + vertical_modifier][position + 4];
				
				if (part_empty[1][1] == false) {
					row[7 + vertical_modifier][position + 5] = player_part[1][1]; // (
				}
				else row[7 + vertical_modifier][position + 5] = original[7 + vertical_modifier][position + 5];

				if (part_empty[1][2] == false) {
					row[7 + vertical_modifier][position + 6] = player_part[1][2]; // mid
				}
				else row[7 + vertical_modifier][position + 6] = original[7 + vertical_modifier][position + 6];

				if (part_empty[1][3] == false) {
					row[7 + vertical_modifier][position + 7] = player_part[1][3]; // mid
				}
				else row[7 + vertical_modifier][position + 7] = original[7 + vertical_modifier][position + 7];

				if (part_empty[2][0] == false) {
					row[8 + vertical_modifier][position + 4] = player_part[2][0]; // /
				}
				else row[8 + vertical_modifier][position + 4] = original[8 + vertical_modifier][position + 4];
				
				if (part_empty[2][1] == false) {
					row[8 + vertical_modifier][position + 5] = player_part[2][1]; // '\\' 
				}
				else row[8 + vertical_modifier][position + 5] = original[8 + vertical_modifier][position + 5];

				if (part_empty[2][2] == false) { 
					row[8 + vertical_modifier][position + 6] = player_part[2][2]; // bottom
				}
				else row[8 + vertical_modifier][position + 6] = original[8 + vertical_modifier][position + 6];

				if (part_empty[2][3] == false) {
					row[8 + vertical_modifier][position + 7] = player_part[2][3]; // bottom
				}
				else row[8 + vertical_modifier][position + 7] = original[8 + vertical_modifier][position + 7];
				
				
				
				
				




				//PICK UP HERE: add extra lines here that will draw the full 3x3 grid of character parts.
				//				the current issue is with climbing. it wont switch the character display because they are showing the full 3x3.
				//		   #2 : 3x4 is made. 3x3 was too small
				//				player_part[2][3] keeps being detected as full when its empty(fixed)
				//		   #3 : will need to add trees and dynamic snowflakes
				//				climbing animation is broken (wont cleanly switch stencils)
				// 
				//RRAAAAAAHHHHHH
				//
				//make a note to add character customization by showing a 3x3 preview and showing updated 3x3 as user inputs them.
				//
			

			//// CLEANERS
			/////////////////////////////////	
				// background restoration
				//if (part_empty[6 + vertical_modifier][position + 5] == true)
				if (part_empty[0][0] == true) {
					row[6 + vertical_modifier][position + 5] = original[6 + vertical_modifier][position + 5]; // top clean up
				}
				row[7 + vertical_modifier][position + 3] = original[7 + vertical_modifier][position + 3]; // middle clean up ([1][-1])
				//row[8 + vertical_modifier][position + 3] = original[8 + vertical_modifier][position + 4]; // bottom clean up //PROBLEMATIC-possibly written elsewhere
				
				// diagonal & special restoration
				if (up_cleaner == true) { // (character movement to right)
					
					
					row[7 + (vertical_modifier + 1)][position + 3] = original[7 + (vertical_modifier + 1)][position + 3];// middle-diagonal (left-down(head)) clean up
					row[8 + (vertical_modifier + 1)][position + 4] = original[8 + (vertical_modifier + 1)][position + 4]; // bottom-diagonal (left-down(left leg)) clean up
					row[8 + (vertical_modifier + 1)][position + 5] = original[8 + (vertical_modifier + 1)][position + 5]; // bottom-diagonal (left-down(right leg)) clean up
					row[6 + (vertical_modifier + 1)][position + 6] = original[6 + (vertical_modifier + 1)][position + 6]; // middle-(elbow cleaner)
					

				}
				if (down_cleaner == true) { // (character movement to right)
		
					row[5 + vertical_modifier][position + 5] = original[5 + vertical_modifier][position + 5]; // head cleaner (top)
					row[5 + vertical_modifier][position + 6] = original[5 + vertical_modifier][position + 6]; // elbow cleaner (top)
					row[6 + vertical_modifier][position + 4] = original[6 + vertical_modifier][position + 4]; // back cleaner (top)
					row[6 + vertical_modifier][position + 3] = original[6 + vertical_modifier][position + 3]; // elbow cleaner (mid)
				
				}


				if (down_cleaner_2 == true) {

					row[6 + vertical_modifier][position + 3] = original[6 + vertical_modifier][position + 3];

				}


				if (up_double_cleaner == true){
					row[5 + (vertical_modifier + 4)][position + 3] = original[5 + (vertical_modifier + 4)][position + 3];// middle-diagonal (left-down(head)) clean up
					row[6 + (vertical_modifier + 4)][position + 4] = original[6 + (vertical_modifier + 4)][position + 4];// bottom-diagonal (left-down(left lef)) clean up
					row[6 + (vertical_modifier + 4)][position + 5] = original[6 + (vertical_modifier + 4)][position + 5];// bottom-diagonal (left-down(right lef)) clean up
				}
				// double down cleaner accesses unavailbe lines, so manual cliff cleaning should be activated only when decending the cliff
				if (cliff_cleaner == true) {



					//if ((row[1][54] != player_part[0][0])  ())
						//row[1][54] = '$';
					if ((position > 47) && (position < 50)) {

						if (row[1][55] != player_part[0][3]) { row[1][55] = original[1][55]; }



					}
						//row[2][53] = '$';

						//row[4][53] = '$';
						//row[4][54] = '$'; //right next to cliff right side
						//row[5][54] = '$'; //right next to cliff right side
						//row[5][55] = '$'; //right next to cliff right side
						//row[6][54] = '$'; //right next to cliff right side



					/* MAYBE NOT BROKEN*/
					if ((row[2][50] != '(') && (row[2][50] != '{')) {
						row[2][50] = original[2][50];
					}
					if ((row[2][51] != '(') && (row[2][51] != '{')) {
						row[2][51] = original[2][51];
					}
					if (position == 48) {
						row[2][51] = original[2][51]; // mid elbow clean up '{'
						row[2][52] = original[2][52]; // mid back clean up '('
						row[1][53] = original[1][53]; // top head cleanup 'o'
						row[1][54] = original[1][54]; // top elbow cleanup '>'
					} // ^manual cleanup for cliff descent
					

					// original[5 + (vertical_modifier + 4)][position + 3];// middle-diagonal (left-down(head)) clean up
					//added 2//row[6 + (vertical_modifier + 4)][position + 4] = original[6 + (vertical_modifier + 4)][position + 4];// bottom-diagonal (left-down(left lef)) clean up
					//row[6 + (vertical_modifier + 4)][position + 5] = original[6 + (vertical_modifier + 4)][position + 5];// bottom-diagonal (left-down(right lef)) clean up
				}
				// DOUBLE DOWN DIAGONAL FOR THE CLIMB
			////////////////////////////////////
			

			if (position > 1){
				down_cleaner = true;
				down_cleaner_2 = true; //
				up_cleaner = true; //
				up_double_cleaner = true; //
				cliff_cleaner = true;     //
			}

			if(position == 8)
			{
				vertical_modifier = -1;
			}
			if (position == 20)
			{ 
				vertical_modifier = 0; 
			}
			if (position == 35)
			{ 
				vertical_modifier = -1; // single up on cliff
			
			}
			if (position == 37) // double up on cliff
			{
				vertical_modifier = -3;

			}
			if (position == 38) {
				vertical_modifier = -5;
			}
			if (position == 48) { clear_character(player_part), set_character(player_part, climbing); }
			if (position == 49 && vertical_modifier < 0) { // 48
	

				
				if (hold_position == false) {
					vertical_modifier = -3;
					climb_mode = true;
				}
				if (hold_position == true) { vertical_modifier--; }
				
				
				hold_position = !hold_position;
				
			}
			if (position == 51) {
				vertical_modifier = -1;
			}
			if (position == 52) {
				climb_mode = false;
			}

		
			
			

			//scene drawing
			{

				cout << "_____________________________________________________________" << endl;
				for (int i = 0; i < 9; i++) {

					for (int offset = 0; offset < 60; offset++) {
						cout << row[i][position + offset];
					}
					cout << endl;
				}
				cout << "_____________________________________________________________";

				//DEBUG MENU
				cout << "\n\n" << "  |Frame: " << position << "/146" << endl << "  |Vertical Modifier: " << vertical_modifier;
				cout << endl << "  |Mode: ";
				if (climb_mode == true) { cout << "Climbing"; }
				if (climb_mode == false) { cout << "Generic"; }
				
				cout << "\n\n" << "  Grid Empties: \n";
				for (int i = 0; i < 3; i++) { 
					for (int o = 0; o < 4; o++) {
						cout << "|" << part_empty[i][o];
					}
					cout << endl;
				}
				cout << "\n\n" << "  Character Grid: \n";
				for (int i = 0; i < 3; i++) {
					for (int o = 0; o < 4; o++) {
						cout << player_part[i][o];
					}
					cout << endl;
				}
				shutter();
			}


			// dialogue
			
			if (position == 999) {

				cout << show_cursor;
				cout << "\n\n\nMake a choice:\n\n(1) Option 1\n(2) Option 2\n\n";

				std::cin >> choice;
				switch (choice) {
				case 1:
					cout << "\n\nYou picked one";
					break;
				case 2:
					cout << "\n\nYou picked two";
					break;
				}
				cout << hide_cursor;
				system("pause");

			}
			if (position == 11) {

				cout << show_cursor;
				cout << "\n\n\nYou notice a stiff arm sticking out of the snow."
					<< "\n\nMake a choice : \n\n(1) Option 1\n(2) Option 2\n\n";


				//face covered with snow
					//option to uncover face or not
					//give description of guys face but say he doesn't look familiar. 
					//he has the same government jacket as the player
					//he had been killed, dropped flat and froze there after some time 


				std::cin >> choice;
				switch (choice) {
				case 1:
					cout << "\n\nYou picked one";
					break;
				case 2:
					cout << "\n\nYou picked two";
					break;
				}
				cout << hide_cursor;
				system("pause");

			}

			//practice decision effect
			if (choice == 2) { row[4][120] = '2'; }

			if (position < 105) { system("cls"); }

		}
		end_animation = true;
		system("pause");
	}


}





/* frame template
if (frameNum == x) {
			cout << "                       " << endl;
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;
			//wait
			system("cls");
		};

*/