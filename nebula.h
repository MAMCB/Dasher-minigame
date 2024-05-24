#ifndef NEBULA_H
#define NEBULA_H

#include "raylib.h"

class Nebula {
public:
    // Constructor
    Nebula(Texture2D &texture, Vector2 position,float updateTime, int velocity);
    
    // Destructor
    ~Nebula();
    
    // Update the nebula's position and animation frame
    void Update(float deltaTime);
    
    // Draw the nebula on the screen
    void Draw(Color tint);
    
    // Check if the nebula is off-screen
    bool IsOffScreen(int screenWidth);
    
    // Reset the nebula's position (useful for respawning)
    void ResetPosition(Vector2 newPosition);

    // Get the height of the nebula
    float GetHeight() const;

private:
    
    Texture2D nebula;
    Rectangle nebRec;
    int nebFrame;
    const float nebUpdateTime;
    float nebRunningTime;
    Vector2 nebPos;
    int nebVelocity;
};

#endif // NEBULA_H
