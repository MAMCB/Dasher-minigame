
#include "raylib.h"
#include "nebula.h"
#include "scarfy.h"
#include <vector>



// Window dimensions
const int windowHeight{720};
const int windowWidth{1280};

int main() {
    InitWindow(windowWidth, windowHeight, "Dapper Dash");

    // Scarfy's variables
   Scarfy scarfy("textures/scarfy.png",windowWidth,windowHeight);
    bool isInAir{false};

    // Gravity acceleration (pixels/second) / second
    const int gravity{1500};

    // Nebula's variables
    Texture2D nebulaTexture = LoadTexture("textures/12_nebula_spritesheet.png");
    Vector2 nebulaInitialPosition{windowWidth, windowHeight - (float)nebulaTexture.height / 8};
    Nebula nebula(nebulaTexture, nebulaInitialPosition,18.0, 300);
    Vector2 nebula2InitialPosition{windowWidth+300,windowHeight-(float)nebulaTexture.height / 8};
    Nebula nebula2(nebulaTexture, nebula2InitialPosition,12.0, 300);
    Vector2 nebula3InitialPosition{windowWidth+600,windowHeight-(float)nebulaTexture.height / 8};
    Nebula nebula3(nebulaTexture,nebula3InitialPosition,16.0,300);
    Vector2 nebula4InitialPosition{windowWidth+800,windowHeight-(float)nebulaTexture.height / 8};
    Nebula nebula4(nebulaTexture,nebula4InitialPosition,16.0,300);
    std::vector<Nebula *> nebulae={&nebula,&nebula2,&nebula3,&nebula4};
    std::vector<Color> colors ={WHITE,RED,BLUE};

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        const float dt{GetFrameTime()};
        BeginDrawing();
        ClearBackground(WHITE);


        // Update animation frame
       scarfy.Update(dt,isInAir);

        // Check if Scarfy is in the air
        isInAir = !scarfy.GroundCheck(windowHeight);
        scarfy.ApplyGravity(dt,gravity,isInAir);
          
        

      for(std::size_t i{0};i<nebulae.size();i++)
      {
        
        nebulae.at(i)->Update(dt);
         // Check if nebula is off-screen
        if (nebulae.at(i)->IsOffScreen(windowWidth)) {
            nebulae.at(i)->ResetPosition({windowWidth, windowHeight - nebulae.at(i)->GetHeight()});
        }
        nebulae.at(i)->Draw(colors.at((i<colors.size())?i:i%3));
       
      }
        
        

       


        // Draw
        scarfy.Draw();
        
        

        EndDrawing();
    }

    UnloadTexture(nebulaTexture);
    CloseWindow();

    return 0;
}

