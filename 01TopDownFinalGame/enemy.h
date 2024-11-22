#ifndef ENEMY
#define ENEMY
#include "raylib.h"
#include "character.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Texture2D tex, Texture2D run_tex, Vector2 pos);
    virtual void tick(float deltaTime) override;
    void setTarget(Character* hero);
    Character* getTarget() { return target;}
    virtual Vector2 getScreenPos();
    void setSpeed(float x) {speed = x;}
    void Delete();
    void setSlowDown(float x) {slowdown = x;}
    float getSlowDown() { return slowdown;}
    int getPointWorth() { return pointWorth;}
    void setPointWorth(int x) { pointWorth = x;}
private:
    Character* target{};
    float vision = 580;
    int respawn = 3;
    float slowdown = 0.f;
    int pointWorth = 0;
};
#endif