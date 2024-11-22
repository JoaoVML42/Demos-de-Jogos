#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(float winWidth, float winHeight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;
    Rectangle getWeaponCollisionRec() { return weaponCollision;}
    float getSlow() {return slow;}
    void setSlow(float x) { slow = x;}
    void speedReset() { speed = 3.5f, slow = 0.f;}
    void setSpeed(float x) { speed = x;}
    float getSpeed() { return speed;}
    void givePoints() {points -= 1;}
    int getPoints() { return points;}
    void setPoints(int x) { points = x;}
private:
    float winWidth{};
    float winHeight{};
    Texture2D weapon = LoadTexture("Classy+Clash+Sprites/characters/weapon_sword.png");
    Rectangle weaponCollision{};
    float slow = 0.f;
    int points = 0;
};
#endif