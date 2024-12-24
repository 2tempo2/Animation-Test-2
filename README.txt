12/23/24

GENERAL IDEA:
This software was made as an attempt to understand where the foundation of pc gaming began, and how it felt to use limited resources. 
The goal is to create a graphical medium for a game but only by using some of the most basic libraries.
All of the graphics seen are just 12 strings, with its characters being modified every game-loop.
This software is not meant to be a standalone experience. That'd be dull. 
When completed, it will be pieced into a story that'll give the graphics context.


COMPLETED SO FAR:
Background (environment) and foreground (character) are pre-drawn, separated, and overlapped.
Background clean up (getting rid of the character trail produced by movement)
Dialogue options (game-loop stops momentarily to ask for user input, then continues)


BROKEN:
Frames 47-50
	Mountain descent glitches out character body.
	Climb_mode has a delayed effect and needs to be remade to work from one frame to the next. 
		(maybe move its definition to the bottom of game-loop)
	
	

 

UPCOMING:
Attachment to full game.
Second character (NPC).

