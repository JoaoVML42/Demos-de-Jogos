#include "character.h"
#include "raymath.h"

Character::Character(float windowWidth, float windowHeight) :
    winWidth(windowWidth),
    winHeight(windowHeight) 
{
    width = texture.width / maxFrames;
    height = texture.height;
}

void Character::tick(float deltaTime)
{
    if (getHealth() > 100.f) {setHealth(100.f);}
    if (!getAlive()) { return;}

    if (IsKeyDown(KEY_A))
        velocity.x -= 1.f;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.f;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.f;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.f;
    
    if (velocity.x >= 0) {rightLeft = 1.f;}
    else if (velocity.x <= 0) {rightLeft = -1.f;}
    setSpeed(3.5f - getSlow());
    BaseCharacter::tick(deltaTime);
    if (Vector2Length(velocity) != 0.f)
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
    float rotation = 0;
    Vector2 origin{};
    Vector2 offset{};
    if (rightLeft > 0.f) {
        origin = {0.f, weapon.height * scale};
        offset = {45.f, 65.f};

        weaponCollision = {
        getScreenPos().x + offset.x + 25.f, 
        getScreenPos().y + offset.y - static_cast<float>(weapon.height) * scale * 0.75f,
        static_cast<float>(weapon.width) * scale * 0.75f,
        static_cast<float>(weapon.height) * scale * 0.75f};
        rotation = IsKeyDown(KEY_SPACE) ? 35.f : 0.f;
    }

    else {
        origin = {weapon.width * scale, weapon.height * scale};
        offset = {40.f, 60.f};

        weaponCollision = {
        getScreenPos().x + offset.x -30.f - weapon.width * scale * 0.75f, 
        getScreenPos().y + offset.y - static_cast<float>(weapon.height) * scale * 0.75f,
        static_cast<float>(weapon.width) * scale * 0.75f,
        static_cast<float>(weapon.height) * scale * 0.75f};
        rotation = IsKeyDown(KEY_SPACE) ? -25.f : 0.f;
    }
    
    Rectangle source{0.f, 0.f, static_cast<float>(weapon.width) * rightLeft, static_cast<float>(weapon.height)};
    Rectangle dest{getScreenPos().x + offset.x, getScreenPos().y + offset.y, weapon.width * scale * 0.75f, weapon.height * scale * 0.75f};
    DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);
    speedReset();
    // DrawRectangleLines(weaponCollision.x, weaponCollision.y, weaponCollision.width, weaponCollision.height, RED);
}

Vector2 Character::getScreenPos() {return Vector2{winWidth / 2.f - scale * 0.5f * width, winHeight / 2.f - scale * 0.5f * height};}