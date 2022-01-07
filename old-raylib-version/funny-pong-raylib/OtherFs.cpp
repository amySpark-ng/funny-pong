#pragma once

#include "ScreenFs.cpp"
#include "CurrentScreenFs.cpp"
#include "VariablesNStructs.cpp"

/* # Prototypes | OtherFunctions # */
void countTimeF();
void playerScored();
void pauseState();
void winScreen();

/* # Used functions */
void randomBallDirection();
void ballThing();

/* # DEFINITION OF FUNCTIONS # */

// # Counts time for restart of the game
void countTimeF() {

	while (countTime) {
		
		framesCounter++;

		if (framesCounter == 60 || framesCounter == 120) {
			seconds++;
		}

		if (seconds >= 2) {
			countTime = false;
		}

	} // End of while

} // End of countsTimeForRestart()

// # If player did a point this functions is called
void playerScored() {

	countTime = true;
	ballVelocity = 6;

	countTimeF();

	ballPos = { screenWidth/2, screenHeight/2 };

	if (seconds == 2) {
		ballShouldMove = true;
	}

	if (ballShouldMove) {
		randomBallDirection();
	}

} // End of playerScored();

// # enters in paused state :nerd: lol
void pauseState() {

	// the game is paused and the ball SHOULD NOT move 
	paused = true;
	ballShouldMove = false;

	// the functions thinks if the ball should move or not (it shouldn't)
	ballThing();

	// loads the "paused image"

	// If showTexture == true then draws it
	if (showTexture) {
		DrawTextureV(pauseStateImg, player1pos, WHITE);
	}

	// Player shouldn't move while paused
	player1KBs = { KEY_NULL, KEY_NULL };
	player2KBs = { KEY_NULL, KEY_NULL };

	// # Press enter to unpause;
	DrawText("press enter to de-pause", 100, 250, 40, BLACK);

	if (IsKeyPressed(KEY_ENTER)) { // De-pauses
		
		UnloadTexture(pauseStateImg);

		showTexture = false;
		ballShouldMove = true;	
		paused = false;
		
		ballThing();

		player1KBs = { KEY_W, KEY_S };
		player2KBs = { KEY_UP, KEY_DOWN };
	
	}

} // End of pauseState();

// # Shows player stats when someone scores over 5 score 
void winScreen() {

	winState = true;

	ballPos = { 0, 0 };
	ballShouldMove = false;	

	horzSide = 0;
	vertSide = 0;

	player1KBs = { KEY_NULL, KEY_NULL };	
	player2KBs = { KEY_NULL, KEY_NULL };

	DrawText(TextFormat("PLAYER %i WON!", playerWhoWon), 200, 250, 50, GRAY);

} // End of winScreen();