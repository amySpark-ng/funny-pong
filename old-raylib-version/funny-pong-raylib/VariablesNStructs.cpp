/* # avoids 're-definition erros' | pretty smart  */  
#pragma once

// # Window and important stuff ig? #
const int screenWidth = 720;
const int screenHeight = 650;
int framesCounter;
int seconds;

// # Menu stuff #
int titleScrollPos = 0;
bool paused;
bool playerHasMoved = false;
Color selectedMenu = WHITE; // Color that selectedOptions use
Color gameplayOption = GRAY; 
Color optionsOption = GRAY;

// # Player stuff and thingies #
int playerVelocity = 15; // OG is 10
std::vector<KeyboardKey> player1KBs = { KEY_W, KEY_S }; // These are the keybinds to character 1 to move
std::vector<KeyboardKey> player2KBs = { KEY_UP, KEY_DOWN }; // These are the keybinds to character 2 to move
Color playerColor = GRAY; 
Vector2 player1pos = { 45, 240 }; // Position of player 1
Vector2 player2pos = { 660, 240 }; // Position of player 2
Vector2 playerSize = { 20, 160 }; // Size of the player (forgot how this works)

Rectangle player1RC = { player1pos.x, player1pos.y, playerSize.x, playerSize.y };
Rectangle player2RC = { player2pos.x, player2pos.y, playerSize.x, playerSize.y };

// # Sprite stuff #
Texture2D mainTitleTexture;
Texture2D player1Texture;
Texture2D player2Texture;
Texture2D ballTexture;
Texture2D pauseStateImg;
bool showTexture = false;

// # Score for player stuff #
int player1Score;
int player2Score;
int playerWhoScored; // stores the 'id' of the player who scored (  1 or 2)
int playerWhoWon; // stores the 'id' of the player who won (being 1 or 2)
bool playerScoredB;
bool winState = false;

// ball stuff 
int sideItWent;
int horzSide;
int vertSide;
double ballVelocity = 6; // every time it does collision with a player it auments by 0.05
bool ballShouldMove;
bool ballCollisioned;
Vector2 ballPos = { screenWidth/2, screenHeight/2 };
Color ballColor = WHITE;

// # Etc stuff #
bool gaming;
bool countTime;
Color textColor = WHITE;
typedef enum GameScreen { MAINMENU, GAMEPLAY, OPTIONS, CREDITS } GameScreen;
GameScreen currentScreen = MAINMENU;
