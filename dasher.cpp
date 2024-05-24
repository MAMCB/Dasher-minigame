// #include "raylib.h"


// bool GroundCheck(float posY, float groundHeight);

//  // window dimensions
//     const int windowHeight{720};
//     const int windowWidth{1280};
// int main()
// {
   

//     InitWindow(windowWidth, windowHeight, "Dapper Dash");

//     //scarfy´s variables
//     Texture2D scarfy = LoadTexture("textures/scarfy.png");
//     Rectangle scarfyRec;
//     scarfyRec.width = scarfy.width / 6;
//     scarfyRec.height = scarfy.height;

//     // check animation frame
//     int frame{0};
//     const float updateTime{1.0 / 12.0};
//     float runningTime{0.0};
    
//     scarfyRec.x = 0;
//     scarfyRec.y = 0;
//     Vector2 scarfyPos;
//     scarfyPos.x = windowWidth / 2 - scarfyRec.width / 2;
//     scarfyPos.y = windowHeight - scarfyRec.height;

//     //nebula´s variables
//     Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
//     Rectangle nebRec{0.0f ,0.0f, nebula.width / 8.0f, nebula.height / 8.0f};
//     int nebFrame{0};
//     const float nebUpdateTime {1.0 / 12.0};
//     float nebRunningTime{0.0};
   
//     Vector2 nebPos{windowWidth, windowHeight - nebRec.height };
//     //nebula x velocity(pixels/second)
//     int nebVelocity{300};


    

//     int velocity{0};
//     // pixels/second
//     const int jumpVelocity{900};
//     bool isInAir{false};

//     // gravity acceleration (pixels/second) / second
//     const int gravity{1500};

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {
//         const float dt{GetFrameTime()};
//         BeginDrawing();
//         ClearBackground(WHITE);

//         // update animation frame
//         runningTime += dt;
//         if (runningTime >= updateTime && !isInAir)
//         {
//             runningTime = 0.0;
//             scarfyRec.x = frame * scarfyRec.width;
//             frame++;
//             if (frame > 5)
//             {
//                 frame = 0;
//             }
//         }
//         nebRunningTime += dt;
//         if(nebRunningTime >= nebUpdateTime)
//         {
//             nebRunningTime=0.0;
//             nebRec.x=nebFrame*nebRec.width;
//             nebFrame++;
//             if(nebFrame >7)
//             {
//                 nebFrame = 0;
//             }

//         }

//         // check if its in the air
//         isInAir = !GroundCheck(scarfyPos.y, windowHeight - scarfyRec.height);
//         if (!isInAir)
//         {
//             velocity = 0;
//             if (IsKeyPressed(KEY_SPACE))
//             {
//                 velocity -= jumpVelocity;
//             }
//         }
//         else
//         {
//             // apply gravity

//             velocity += gravity * dt;
//         }

//         // update position
//         scarfyPos.y += velocity * dt;
//         nebPos.x -= nebVelocity * dt;
//         DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
//         DrawTextureRec(nebula,nebRec,nebPos,WHITE);

//         EndDrawing();
//     }

//     UnloadTexture(scarfy);
//     UnloadTexture(nebula);
//     CloseWindow();
// }

// bool GroundCheck(float posY, float groundHeight)
// {
//     if (posY >= groundHeight)
//     {
//         return true;
//     }

//     return false;
// }
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

