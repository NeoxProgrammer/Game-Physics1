#include "raylib.h"
#include "raymath.h"
#include "raygui.h"

int main()
{
    InitWindow(800, 800, "Physics-1");
    InitAudioDevice();
    SetTargetFPS(60);
    Vector2 RandomPos = { GetRandomValue(0, 800), GetRandomValue(0, 800) };

	float x = 400, y = 400;
    float a = 6.0f; // amplitude radius of movement how fast it goes around the circle
    float b = 5.1f; // frequency of movement kind of how far it goes around the circle when changing the values thats what i found lol
    
    

    while (!WindowShouldClose())
    {
		float t = GetTime();
		float dt = GetFrameTime();

		// pretty sure this is how its supposed to be done but i dont know if it is correct or not but it works so im happy with it
		y = y + (cos(t * a)) * a * b * dt; // Update y position based on cosine function
		x = x + (-sin(t * a)) * a * b * dt; // Update x position based on sine function
		

		float time = GetTime();
        BeginDrawing();
        ClearBackground(WHITE);

        DrawText("Bashaar Ali 101545977", 50, 750, 30, RED);
        
        const char* text = TextFormat("Time: %f", time); 
        DrawText(text, 400, 400, 20, GREEN); 
        DrawCircle(x,y, 20,DARKPURPLE ); 

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
