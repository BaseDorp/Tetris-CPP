#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 500;  // Must be divisible by colums and gridSize
    const int screenHeight = 1000; // must be divisble with rows and gridSize
    const int rows = 10;
    const int colums = 5; // TODO dont know why this is half and not 20x10
    const int gridSize = screenWidth / rows;

    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    float fallSpeed = 5.0f;
    int frameCounter = 0;
    struct Square
    {
        int size = 50;
        Vector2 position = { 0, (float)(screenWidth / 2 - size) };
    };
    Square* s = new Square();
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        frameCounter++;

        if (((frameCounter / 60) % 2) == 1)
        {
            s->position.y += gridSize;
            frameCounter = 0;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawRectangle(screenWidth / 2 + s->size, s->position.y, s->size, s->size, GREEN);

        // Draw board
        for (int i = gridSize; i < screenHeight; i += gridSize)
        {
            DrawLine(0, i, screenWidth, i, LIGHTGRAY);
        }
        for (int i = gridSize; i < screenWidth; i += gridSize)
        {
            DrawLine(i, 0, i, screenHeight, LIGHTGRAY);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    delete s;
    
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}