#include "nebula.h"
#include "raylib.h"

// Constructor
Nebula::Nebula(Texture2D &texture, Vector2 position,float updateTime, int velocity)
    : nebula(texture), 
      nebRec({0.0f, 0.0f, nebula.width / 8.0f, nebula.height / 8.0f}), 
      nebFrame(0), 
      nebUpdateTime(1.0f / updateTime), 
      nebRunningTime(0.0f), 
      nebPos(position), 
      nebVelocity(velocity) {}

// Destructor
Nebula::~Nebula() {
   
}

// Update the nebula's position and animation frame
void Nebula::Update(float deltaTime) {
    nebRunningTime += deltaTime;
    if (nebRunningTime >= nebUpdateTime) {
        nebRunningTime = 0.0f;
        nebFrame++;
        if (nebFrame > 7) {
            nebFrame = 0;
        }
        nebRec.x = nebFrame * nebRec.width;
    }
    nebPos.x -= nebVelocity * deltaTime;
}

// Draw the nebula on the screen
void Nebula::Draw(Color tint) {
    DrawTextureRec(nebula, nebRec, nebPos, tint);
}

// Check if the nebula is off-screen
bool Nebula::IsOffScreen(int screenWidth) {
    return (nebPos.x + nebRec.width < 0);
}

// Reset the nebula's position (useful for respawning)
void Nebula::ResetPosition(Vector2 newPosition) {
    nebPos = newPosition;
}

// Get the height of the nebula
float Nebula::GetHeight() const {
    return nebRec.height;
}
