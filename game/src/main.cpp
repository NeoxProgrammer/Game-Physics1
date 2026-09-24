#include "raylib.h"
#include "raymath.h"
#include "raygui.h"
#include <array>
#include <vector>
#include <iostream>
using namespace std;


struct PhysicsBody {
    Vector2 position;
    Vector2 velocity;
    
    void Draw() {
        DrawCircleV(position, 20.0f, BLUE);
	}

    void Update() {
        float dt = GetFrameTime();
        Vector2 accel = GRAVITY * dt;
        velocity += accel;
		position += velocity * dt;


    }





};


vector<PhysicsBody> bodies;

constexpr Vector2 GRAVITY = { 0.0f, 9.81f };

Vector2 new_launch_position = { 400.0f,400.0f };
float new_launch_angle = 0.0f;
float new_launch_speed = 100.0f;



int main()
{
    InitWindow(800, 800, "Physics-1");
    InitAudioDevice();
    SetTargetFPS(60);

    
    


    


	




    // Note that since raylib is an RHS, positive rotations are CLOCKWISE
    // You will most likely want to negate the launch angle so that your launch_velocity vector points upwards
    

	Vector2 my_example_direction = Vector2Rotate(Vector2UnitX, -new_launch_angle * DEG2RAD);

    while (!WindowShouldClose())
    {
        float tt = GetTime();       // Total time - time since the window was initialized
        float dt = GetFrameTime();  // Frame (delta) time - time from start to end of previous frame (ideally 1.0f / 60.0f milliseconds)
        // float hz = 1.0f / 60.0f; <-- dt should be approximately this value since we called SetTargetFPS(60);

		




       




        // 1. Calculate launch_direction Vector2 by using the Vector2Rotate function.
        // (Be sure to convert launch_angle from degrees to radians when passing it to Vector2Rotate)!
        // 2. Calculate launch_velocity Vector2 by multiplying launch_direction by launch_speed
        // 3. Render launch_velocity as a line from launch_position to launch_position + launch_velocity

        BeginDrawing();
        ClearBackground(WHITE);


        Vector2 my_example_direction = Vector2Rotate(Vector2UnitX, -new_launch_angle * DEG2RAD);
		Vector2 new_launch_velocity = my_example_direction * new_launch_speed;
		DrawLineEx(new_launch_position, new_launch_position + new_launch_velocity, 4.0f, RED);




        if (IsKeyPressed(KEY_SPACE))
        {
            
        }

		Vector2 accel = GRAVITY * dt;
        




        // Draw your launch_position + launch_velocity line here!
        
        DrawCircleV(new_launch_position, 20.0f, BLUE);

        // An example illustration of a rotated vector
        // DrawLineEx(example_position, example_position + example_direction * 100.0f, 4.0f, GRAY);
		//DrawLineEx(new_launch_position, new_launch_position + my_example_direction * 100.0f, 4.0f, BLUE);

       


        DrawText(TextFormat("Launch Angle %2.1f", new_launch_angle), 10, 250, 20, DARKGRAY);
        DrawText(TextFormat("Launch Speed %2.1f", new_launch_speed), 10, 390, 20, DARKGRAY);
        DrawText(TextFormat("Launch Position X %2.1f", new_launch_position.x), 10, 510, 20, DARKGRAY);
		DrawText(TextFormat("Launch Position Y %2.1f", new_launch_position.y), 10, 630, 20, DARKGRAY);

		GuiSlider({ 10.0f, 290.0f, 160.0f, 80.0f }, "0", "90", &new_launch_angle, 0.0f, 90.0f);
		GuiSlider({ 10.0f, 410.0f, 160.0f, 80.0f }, "10", "300", &new_launch_speed, 10.0f, 300.0f);
		GuiSlider({ 10.0f, 530.0f, 160.0f, 80.0f }, "0", "800", &new_launch_position.x, 0.0f, 800.0f);
		GuiSliderBar({ 10.0f, 650.0f, 160.0f, 80.0f }, "0", "800", &new_launch_position.y, 0.0f, 800.0f);
       
        

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}