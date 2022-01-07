// # MainFile.cpp #

// some used libraries
#include <iostream>
#include <cstdlib>
#include <vector>

#include "include/raylib.h" // cool library 

// included other files 
#include "ScreenFs.cpp"
#include "CurrentScreenFs.cpp"
#include "OtherFs.cpp"

int main() {

InitWindow(screenWidth, screenHeight, "Funny Pong - by AmySpark");
SetTargetFPS(60);

#include "VariablesNStructs.cpp"

while (!WindowShouldClose()) {

	BeginDrawing();
	ClearBackground(BLACK);

	// FPS TEXT
	DrawText(TextFormat("FPS %i", GetFPS()), 10, 10, 25, LIGHTGRAY);

	setsScreen();

	EndDrawing(); 

} // End of window

CloseWindow();

} // End of main