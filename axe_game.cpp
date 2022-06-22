
#include "raylib.h"
int main()
{
    //Window dimensions
    int width{800};
    int height{450};
    InitWindow(width,height, "Axe Game");

    //Circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_r{25};
    //Circle edges
    int l_circle_x{circle_x - circle_r};
    int r_circle_x{circle_x + circle_r};
    int u_circle_y{circle_y - circle_r};
    int b_circle_y{circle_y + circle_r};


    //Axe coordinates
    int axe_x{400}; 
    int axe_y{0}; 
    int axe_h{50}; 
    int axe_w{50}; 
    //Axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_h};
    int u_axe_y{axe_y};
    int b_axe_x{axe_x + axe_w};

    int direction{10};


    bool collision_with_axe = 
                            (b_axe_x >= u_circle_y) && 
                            (u_axe_y <= b_circle_y) && 
                            (l_axe_x <= r_circle_x) && 
                            (r_axe_x >= l_circle_x);


    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //Game logic begin
        if  (collision_with_axe) {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
         else 
         {
            //Update edges
             l_circle_x = circle_x - circle_r;
             r_circle_x = circle_x + circle_r;
             u_circle_y = circle_y - circle_r;
             b_circle_y = circle_y + circle_r;
             l_axe_x = axe_x;
             r_axe_x = axe_x + axe_h;
             u_axe_y = axe_y;
             b_axe_x = axe_x + axe_w;
             //Update collision with axe
             collision_with_axe = 
                            (b_axe_x >= u_circle_y) && 
                            (u_axe_y <= b_circle_y) && 
                            (l_axe_x <= r_circle_x) && 
                            (r_axe_x >= l_circle_x);

            DrawCircle(circle_x, circle_y, circle_r, BLUE);
            DrawRectangle(axe_x, axe_y, axe_w, axe_h, RED);

            //Move axe
            axe_y += direction;
            if(axe_y > (height - 25) || axe_y < 0 )
            {
                direction = -direction;
            }


            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }

       

        }

        //Game logic end
        EndDrawing();
    }
}