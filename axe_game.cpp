#include "raylib.h"

int main()
{
    // window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "James' window");

    // circle coordinates
    int circleX{200};
    int circleY{200};
    int circleRadius{25};
    // circle edges
    int circleLeft{circleX - circleRadius};
    int circleRight{circleX + circleRadius};
    int circleTop{circleY - circleRadius};
    int circleBottom{circleY + circleRadius};

    // axe coordinates
    int axeX{400};
    int axeY{0};
    int axelength{50};

    // axe edges
    int axeLeft{axeX};
    int axeRight{axeX + axelength};
    int axeTop{axeY};
    int axeBottom{axeY + axelength};

    int direction{10};

    bool collisionWithAxe =
        circleRight >= axeLeft && circleLeft <= axeRight &&
        circleBottom >= axeTop && circleTop <= axeBottom;


    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collisionWithAxe)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
            DrawText("Press R to Restart", 400, 250, 20, RED);
            if (IsKeyDown(KEY_R))
            {
                // reset the game
                circleX = 200;
                circleY = 200;
                axeY = 0;
                collisionWithAxe = false;
            }
        }
        else
        {

            // Game logic begiens here

            // update the edges
            circleLeft = circleX - circleRadius;
            circleRight = circleX + circleRadius;
            circleTop = circleY - circleRadius;
            circleBottom = circleY + circleRadius;
            axeLeft = axeX;
            axeRight = axeX + axelength;
            axeTop = axeY;
            axeBottom = axeY + axelength;
            collisionWithAxe =
                circleRight >= axeLeft && circleLeft <= axeRight &&
                circleBottom >= axeTop && circleTop <= axeBottom;


            DrawCircle(circleX, circleY, circleRadius, BLUE);
            DrawRectangle(axeX, axeY, axelength, axelength, RED);

            // move the axe
            axeY += direction;
            // reverse the direction if the axe hits the window boundary
            if (axeY > height || axeY < 0)
            {
                // reverse the direction
                direction *= -1;
            }
            // move the circle right
            if (IsKeyDown(KEY_D) && circleX < width)
            {
                circleX += 10;
            }
            // move the circle left
            if (IsKeyDown(KEY_A) && circleX > 0)
            {
                circleX -= 10;
            }
            // move circle up
            if (IsKeyDown(KEY_W) && circleY > 0)
            {
                circleY -= 10;
            }
            // move circle down
            if (IsKeyDown(KEY_S) && circleY < height)
            {
                circleY += 10;
            }

            // game logic ends here
        }

        EndDrawing();
    }
}