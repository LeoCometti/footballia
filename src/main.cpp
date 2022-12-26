#include "raylib.h"

#include "footballpitch.h"
#include "footballpitch.cpp"
#include "ballmotion.h"
#include "ballmotion.cpp"

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
    BallMotion ballMotion;
    ballMotion.SetPosition(footballPitch.GetCentreSpot());
    Rectangle touchArea = footballPitch.GetPitchLimits();
    Vector2 touchPosition = { 0, 0 };
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        //touchPosition = GetTouchPosition(0);

        //if (CheckCollisionPointRec(touchPosition, touchArea))
        Vector2 pos = { GetMouseX(), GetMouseY() };
        ballMotion.SetFuturePosition(pos);
        //Vector2 pos2 = { 100, 800 };
        //ballMotion.SetFuturePosition(100, 800);

            //ballMotion.SetFuturePosition(GetTouchPosition(0));
       

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            footballPitch.Draw();

            ballMotion.Draw();
            
            DrawText(TextFormat("Box position X: %03.1f", ballMotion.GetPosition().x), 0, 10, 10, BLACK);
            DrawText(TextFormat("Box position Y: %03.1f", ballMotion.GetPosition().y), 0, 30, 10, BLACK);
            DrawText(TextFormat("Box future position X: %03.1f", ballMotion.GetFuturePosition().x), 0, 50, 10, BLACK);
            DrawText(TextFormat("Box future position Y: %03.1f", ballMotion.GetFuturePosition().y), 0, 70, 10, BLACK);
            DrawText(TextFormat("Angle: %03.2f", ballMotion.GetAngle()), 0, 90, 10, BLACK);
            DrawText(TextFormat("Speed X: %03.4f", ballMotion.GetSpeedX()), 0, 110, 10, BLACK);
            DrawText(TextFormat("Speed Y: %03.4f", ballMotion.GetSpeedY()), 0, 130, 10, BLACK);
            DrawText(TextFormat("Distance: %03.1f", ballMotion.Distance()), 0, 150, 10, BLACK);
            DrawText(TextFormat("Mouse position X: %03i", GetMouseX()), 0, 170, 10, BLACK);
            DrawText(TextFormat("Mouse position Y: %03i", GetMouseY()), 0, 190, 10, BLACK);

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