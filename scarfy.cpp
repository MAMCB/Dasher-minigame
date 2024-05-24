#include "scarfy.h"
#include "raylib.h"

Scarfy::Scarfy(const char* textureFilePath,  int windowWidth,int windowHeight):scarfy(LoadTexture(textureFilePath)){
       scarfyRec.width = scarfy.width / 6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    scarfyPos.x = windowWidth / 2 - scarfyRec.width / 2;
    scarfyPos.y = windowHeight - scarfyRec.height;
    
}

bool Scarfy::GroundCheck( float windowHeight)
{
    return scarfyPos.y >= windowHeight - scarfyRec.height;
}

void Scarfy:: Update(float deltaTime,const bool  &isInAir)
{
     runningTime += deltaTime;
        if (runningTime >= updateTime && !isInAir) {
            runningTime = 0.0;
            scarfyRec.x = frame * scarfyRec.width;
            frame++;
            if (frame > 5) {
                frame = 0;
            }
        }
        scarfyPos.y += velocity * deltaTime;
}

void Scarfy::Draw()
{
     DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
}

void Scarfy:: ApplyGravity(float dt,const int  & gravity,const bool  &isInAir)
{
    if (!isInAir) {
            velocity = 0;
            if (IsKeyPressed(KEY_SPACE)) {
                velocity -= jumpVelocity;
            }
        } else {
            // Apply gravity
            velocity += gravity * dt;
        }
}

Scarfy::~Scarfy()
{
    UnloadTexture(scarfy);
}