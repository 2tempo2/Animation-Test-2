#pragma once

void set_character(char (character_sheet)[3][4], char (stencil)[3][4]) {
	for (int i = 0; i < 3; i++) {
		for (int o = 0; o < 4; o++) {
			character_sheet[i][o] = stencil[i][o];
		}
	}
}

char generic[3][4]{
 ' ',' ', 'o', '>',
 '{', '(', ' ', ' ',
 ' ', '/', '\\', ' '
};

char climbing[3][4]{
 '\\','o', ' ', ' ',
 ' ', ')', ' ', ' ',
 '/', '<', ' ', ' '
};



 
// Generic:
//   o>
// {(
//  /\
//
////////////////////////////
//Climbing:
// \o
//  )
// /<
// 
/////////////////////////////


