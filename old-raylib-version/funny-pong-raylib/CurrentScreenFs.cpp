#pragma once

#include "ScreenFs.cpp"
#include "OtherFs.cpp"
#include "VariablesNStructs.cpp"

/* # Prototypes | currentScreenCasesFunctions # */
void mainMenuScreen();
void gameplayScreen();
void optionsScreen();
void creditsScreen();

/* Used functions | no idea how this works LOL */
void ballThing();
int setsBallDirection(int P_horzSideP, int P_vertSide);

/* # Definition of functions # */

// What happens when currentScreen == MAINMENU;
void mainMenuScreen() {

	DrawText("FUNNY PONG", 165, 200, 60, WHITE);
	DrawText("by amySpark", 200, 250, 50, GRAY);

	DrawText("gameplay", 100, 400, 40, gameplayOption);
	DrawText("options", 460, 400, 40, optionsOption);
		
	// DEBUG:
	DrawText(TextFormat("titleScrollPos %i", titleScrollPos), 165, 350, 30, WHITE);

	// # If haven't moved 
	// # Left movements #

	// If press key left then selects gameplay  
	if (IsKeyPressed(KEY_LEFT) && playerHasMoved == false) {
		titleScrollPos = 1; 
		playerHasMoved = true;

	} // TitleScrollPos = 1

	if (titleScrollPos == 1) {
		gameplayOption = selectedMenu;
		optionsOption = GRAY;

		if (IsKeyPressed(KEY_ENTER)) {
			currentScreen = GAMEPLAY;
		}

		if (IsKeyPressed(KEY_RIGHT)) {
			titleScrollPos = 2;
		}

	} // End of titleScrollPos == 1
	 
	// # Right movements #

	// If press key right then selects options
	else if (IsKeyPressed(KEY_RIGHT) && playerHasMoved == false) {
		titleScrollPos = 2;
		playerHasMoved = true;

	} // titleScrollPos = 1

	if (titleScrollPos == 2) {
		optionsOption = selectedMenu;
		gameplayOption = GRAY;

		if (IsKeyPressed(KEY_ENTER)) {
			currentScreen = OPTIONS;
		}

		else if (IsKeyPressed(KEY_LEFT)) {
			titleScrollPos = 1;
		}

		// # Funny easter egg credits thingy
		// If holding right and down
		else if (IsKeyPressed(KEY_DOWN)) {
			currentScreen = CREDITS;
		} 
	} // End of titleScrollPos == 2
		
	// # Else cases on the menu selection #

	/*if (IsKeyPressed(KEY_LEFT) && titleScrollPos == 1 && playerHasMoved == true) {
		titleScrollPos = 2;
	}

	else if (IsKeyPressed(KEY_RIGHT) && titleScrollPos == 2 && playerHasMoved == true) {
		titleScrollPos = 1;
	}*/

} // End of mainMenuScreen();

// What happens when currentScreen == GAMEPLAY;
void gameplayScreen() {

	// # Drawing characters
	/* PLAYER 1*/ DrawRectangleV(player1pos, playerSize, playerColor);
	/* PLAYER 2*/ DrawRectangleV(player2pos, playerSize, playerColor);

	// # Decoration thingies
	DrawRectangle(screenWidth/2 - 10, 40, 12, 40, GRAY); 
	DrawRectangle(screenWidth/2 - 10, 100, 12, 40, GRAY); 
	DrawRectangle(screenWidth/2 - 10, 160, 12, 40, GRAY); 

	// # Press space to start playing
	DrawText("Press space to play.", 120, 520, 45, textColor);

	if (IsKeyPressed(KEY_SPACE)) {
		gaming = true;
	}

	// if gaming == true (true gamer moment);
	if (gaming == true) {
		playerColor = WHITE;
		textColor = BLACK;
		ballShouldMove = true;	

		// BALL!1!11
		DrawCircleV(ballPos, 15, ballColor);

		DrawText(TextFormat("horzSide %i", horzSide), 250, 250, 20, GRAY);
		DrawText(TextFormat("vertSide %i", vertSide), 250, 300, 20, GRAY);
		DrawText(TextFormat("framesCounter %i", framesCounter), 250, 350, 20, GRAY);
		DrawText(TextFormat("seconds %i", seconds), 250, 400, 20, GRAY);

		DrawText(TextFormat("%i",player1Score), 90, 555, 60, WHITE); /* Player 1 score */  
		DrawText(TextFormat("%i",player2Score), 610, 555, 60, WHITE); /* Player 2 score */  

		// ballThing
		ballThing();

		// # This part controls the movement of the players LOL
		
		// # Player 1

		// If player 1 goes down
		if (IsKeyDown(player1KBs[0])) {
			player1pos.y -= playerVelocity; 
		}

		// If Player 1 goes up
		else if (IsKeyDown(player1KBs[1])) {
			player1pos.y += playerVelocity;
		}

		// if player 1 goes too much up
		if (player1pos.y > 490) {
			player1pos.y = 490;
		}

		// If player 1 goes too much down
		else if (player1pos.y < 0) {
			player1pos.y = 0;
		}

		// # Player 2 

		// If player 2 goes down
		if (IsKeyDown(player2KBs[0])) {
			player2pos.y -= playerVelocity; 
		}

		// If Player 2 goes up
		else if (IsKeyDown(player2KBs[1])) {
			player2pos.y += playerVelocity;
		}

		// if player 2 goes too much up
		if (player2pos.y > 490) {
			player2pos.y = 490;
		}

		// If player 2 goes too much down
		else if (player2pos.y < 0) {
			player2pos.y = 0;
		}

		// # Calls winScreen function;
		if (player1Score > 4 || player2Score > 4 ) {
			winScreen();
		}

		// # CALLS PAUSE STATE FUNCTION
		if (IsKeyPressed(KEY_ESCAPE) && currentScreen == GAMEPLAY && gaming == true && winState == false) {
			pauseStateImg = LoadTexture("assets/pauseStateImg.png");
			showTexture = true;
			paused = true;
		}

		if (paused) {
			pauseState();
		}

		// # DETERMINES WHICH PLAYER WON
		if (player1Score > 4 && !(player2Score > 4)) {
			playerWhoWon = 1;
		}

		else if (player2Score > 4 && !(player1Score > 4)) {
			playerWhoWon = 2;
		}

	} // End of true gaming;

	// STUPID DEBUG STUFF
	// SETS BALL DIRECTION
	if (IsKeyPressed(KEY_A)) {
		setsBallDirection(2, 2); 
	}

} // End of gameplayScreen();

// What happens when currentScreen == OPTIONS;
void optionsScreen() {

	DrawText("option", 200, 250, 50, GRAY);

} // End of optionsScreen();

// What happens when currentScreen == CREDITS;
void creditsScreen() {

	DrawText("credits", 200, 250, 50, GRAY);

} // End of creditsScreen();

