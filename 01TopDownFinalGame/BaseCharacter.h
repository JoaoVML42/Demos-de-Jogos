
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter {
public: 
    BaseCharacter();
    Vector2 getworldPos() { return worldPos; }
    void setRunTexture(Texture2D x);
    void setIdleTexture(Texture2D x);
    void setTexture(Texture2D x);
    void undoMovement();
    Rectangle GetCollisionRec();
    virtual void tick(float deltaTime);
    virtual Vector2 getScreenPos() = 0;
    bool getAlive() { return alive;}
    void setAlive(bool x) {alive = x;}
    float getHealth() { return health;}
    void setHealth(float h) { health = h;}
    float getDamage() { return damagePerSec;}
    void setDamage(float x) { damagePerSec = x;}
    void setColor(Color x) {color = x;}
protected:
    float width{};
    float height{};
    const float windowHeight = 1080;
    const float windowWidth = 1080;
    Texture2D texture = LoadTexture("Classy+Clash+Sprites/characters/knight_idle_spritesheet.png");
    Texture2D idle = LoadTexture("Classy+Clash+Sprites/characters/knight_idle_spritesheet.png");
    Texture2D run = LoadTexture("Classy+Clash+Sprites/characters/knight_run_spritesheet.png");
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    Vector2 texturePos{windowWidth / 2.f - 4.f * 0.5f * windowWidth, windowHeight / 2.f - 4.f * 0.5f * windowHeight};
    Vector2 velocity{};
    float rightLeft{};
    float runningTime{};
    float scale = 4.f;
    int frame{};
    int maxFrames = 6;
    const float updateTime = 0.08;
    float speed = 3.5f;
    Vector2 Pos{};
    float health = 100;
    float damagePerSec = 10;
    Color color = WHITE;
private:
    bool alive = true;
};

#endif