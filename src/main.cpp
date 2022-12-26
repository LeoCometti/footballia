#include "raylib.h"

#include "footballpitch.h"
#include "footballpitch.cpp"

//------------------------------------------------------------------------------------
// Modifications on the program
//------------------------------------------------------------------------------------

// Draw the Pitch

Vector2 ballPosition = { 0.0F, 0.0F };
float ballRadius = 2.2F;// 6.0F; 

void DrawPlayersOnPitch()
{
    ballPosition.x = GetMouseX() - ballRadius/2.0f;
    ballPosition.y = GetMouseY() - ballRadius/2.0f;

    // Check walls collision for bouncing
    if (ballPosition.x >= (GetScreenWidth() - ballRadius)) ballPosition.x = (GetScreenWidth() - ballRadius);
    else if (ballPosition.x <= ballRadius/2.0f) ballPosition.x = ballRadius/2.0f;
    if (ballPosition.y >= (GetScreenHeight() - ballRadius)) ballPosition.y = (GetScreenHeight() - ballRadius);
    else if (ballPosition.y <= ballRadius/2.0f) ballPosition.y = ballRadius/2.0f;

    DrawCircleV(ballPosition, ballRadius, MAROON);
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    FootballPitch footballPitch;
    ballPosition.x = GetScreenWidth()/2.0f;
    ballPosition.y = GetScreenHeight()/2.0f;
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            footballPitch.Draw();

            DrawPlayersOnPitch();

            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}