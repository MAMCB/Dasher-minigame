#ifndef SCARFY_H
#define SCARFY_H
#include "raylib.h"

class Scarfy {
    public:
        Scarfy(const char* textureFilePath, int windowWidth,int windowHeight);
        bool GroundCheck(float windowHeight);
        
        void Update(float deltaTime,const bool  &isInAir);
    
        void Draw();
        void ApplyGravity(float dt,const int  & gravity,const bool  &isInAir);

        ~Scarfy();
    private:
         // Scarfy's variables
    Texture2D scarfy;
    Rectangle scarfyRec;
   

    Vector2 scarfyPos;
    

    // Check animation frame
    int frame{0};
    const float updateTime{1.0 / 12.0};
    float runningTime{0.0};

    int velocity{0};
    // Pixels/second
    const int jumpVelocity{900};
};


#endif