#pragma once

#include "CurrentScreenFs.cpp"
#include "VariablesNStructs.cpp"

/* # Prototypes | mainFunctions # */
void setsScreen();
void setsExitScreen();
// # ball functions #
void ballThing();
void randomBallDirection();
int setsBallDirection(int P_horzSideP, int P_vertSide);

/* # DEFINITION OF FUNCTIONS # */

// # uses a switch on currentScreen to set the screen
void setsScreen() {
	
	switch(currentScreen) { 
		
		// case MAINMENU
		case MAINMENU:
		
		mainMenuScreen();

		// End of case MAINEMENU
		break;

		// case GAMEPLAY
		case GAMEPLAY:
		
		gameplayScreen();
		
		// End of case GAMEPLAY
		break;

		// case OPTIONS
		case OPTIONS:
	
		optionsScreen();
	
		// End of case OPTIONS
		break;

		// case CREDITS
		case CREDITS:

		creditsScreen();
	
		// End of case CREDITS
		break;
	
	} // End of switch(currentScreen)

	setsExitScreen();

} // End of setsScreen();

// # sets the screen which the game will exit to when certain key is pressed
void setsExitScreen() {
	if (currentScreen == MAINMENU) {
		SetExitKey(KEY_ESCAPE);
	}

	else if (currentScreen == GAMEPLAY || currentScreen == OPTIONS) {
		SetExitKey(KEY_END);
	}

	if (IsKeyPressed(KEY_ESCAPE) && currentScreen == OPTIONS || currentScreen == CREDITS) {
		currentScreen = MAINMENU;
	}

} // End of setsExitScreen();

// # BALL FUNCTIONS #

// # does ball thingies
void ballThing() {

	// if ball should move then does this thing
	if (ballShouldMove == true && paused == false) {
		
		// does the ball go to left or right?
		if (horzSide == 1 && ballShouldMove == true) {
			ballPos.x -= ballVelocity;
		}

		else if (horzSide == 2 && ballShouldMove == true) {
			ballPos.x += ballVelocity; 
		}

		// does the ball go up or down
		if (vertSide == 1 && ballShouldMove == true) {
			ballPos.y -= ballVelocity;
		
		}

		else if (vertSide == 2 && ballShouldMove == true) {
			ballPos.y += ballVelocity;
		}
		
	}	

	// else, ball stays in its place
	else if (ballShouldMove == false && paused == true) {
		ballPos = { ballPos.x, ballPos.y };
	}

	if (gaming) {

		if (IsKeyPressed(KEY_G)) {
			horzSide = GetRandomValue(1, 2);
			vertSide = GetRandomValue(1, 2);
		}

	}
	
	// Checks if ball is collisioning with player 1
	if (CheckCollisionCircleRec(ballPos, 15, player1RC)) {
		randomBallDirection();
	}  

	// Checks if ball is collisioning with player 2
	else if (CheckCollisionCircleRec(ballPos, 15, player2RC)) {
		randomBallDirection();
	}

	// Does the ball collision floor or ceiling?
	if (ballPos.y > 630 || ballPos.y < 20) {
		randomBallDirection();
	}

	// If ball scores on player 1
	if (ballPos.x > 710) {
		playerWhoScored = 1;
		player1Score++;
		playerScoredB = true;
		playerScored();
	}

	// If ball scores on player 2
	else if (ballPos.x < 10) {
		playerWhoScored = 2;
		player2Score++;
		playerScoredB = true;
		playerScored();
	}

} // End of ballThing();


// # generates some random numbers and stuff to set a random direction to the ball
void randomBallDirection() {
	
	// If the ball collisioned aument it's velocity
	if (ballCollisioned) {
		ballVelocity += 0.05;
	}

	// generates a random value
	horzSide = GetRandomValue(1, 2);
	vertSide = GetRandomValue(1, 2);

	// # does the ball go to left or right?
	// Goes to the left 
	if (horzSide == 1 && ballCollisioned == true) {
		ballPos.x -= ballVelocity;
	}
	
	// Goes to the right
	else if (horzSide == 2 && ballCollisioned == true) {
		ballPos.x += ballVelocity; 
	}

	// # does the ball go up or down?
	// Goes to up
	if (vertSide == 1 && ballCollisioned == true) {
		ballPos.y -= ballVelocity;
	}

	// Goes to down
	else if (vertSide == 2 && ballCollisioned == true) {
		ballPos.y += ballVelocity;
	}

} // End of randomBallDirection();

// # sets the ball direction to a specific direction decided by 2 parameters, horzSide (horizontal) and vertSide (vertical) 
int setsBallDirection(int P_horzSide, int P_vertSide) {

	horzSide = P_horzSide;
	vertSide = P_vertSide;

	// # does the ball go to left or right?
	// Goes to the left 
	if (horzSide == 1 && ballCollisioned == true) {
		ballPos.x -= ballVelocity;
	}
	
	// Goes to the right
	else if (horzSide == 2 && ballCollisioned == true) {
		ballPos.x += ballVelocity; 
	}

	// # does the ball go up or down?
	// Goes to up
	if (vertSide == 1 && ballCollisioned == true) {
		ballPos.y -= ballVelocity;
	}

	// Goes to down
	else if (vertSide == 2 && ballCollisioned == true) {
		ballPos.y += ballVelocity;
	}

	return 0;

} // End of setsBallDirection();
