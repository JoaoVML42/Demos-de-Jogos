#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter() {

}
void BaseCharacter::setTexture(Texture2D x) { texture = x;}
void BaseCharacter::setIdleTexture(Texture2D x) { idle = x;}
void BaseCharacter::setRunTexture(Texture2D x) { run = x;}
void BaseCharacter::undoMovement() {worldPos = worldPosLastFrame;}
void BaseCharacter::tick(float deltaTime)
{
    if (getHealth() <= 0.f) {
        setAlive(false);
    }
    worldPosLastFrame = worldPos;
    runningTime += deltaTime;

    if (runningTime > updateTime) {
        frame += 1.f;
        runningTime = 0.f;
        if (getHealth() < 50.f) {setHealth(getHealth() + 0.01f);}
    }
    if (frame > 5.f) {frame = 0.f;}

    if (Vector2Length(velocity) != 0.f) {
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        texture = run;
    }
    else {
        texture = idle;
        rightLeft = 1.f;
    }

    velocity = {};
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Pos, 0.f, color);
}
Rectangle BaseCharacter::GetCollisionRec() {
    return Rectangle{getScreenPos().x, getScreenPos().y, width * scale, height * scale};
}