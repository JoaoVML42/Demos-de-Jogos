#ifndef HEALING
#define HEALING
#include "raylib.h"
#include "character.h"
#include "raymath.h"
class healCrystal {
public:
    healCrystal(Texture2D tex, Vector2 posit, float value) {
        texture = tex,
        pos = posit,
        healingFactor = value;
        width = texture.width;
        height = texture.height;
    }
    float giveHeal() {
        UnloadTexture(texture);
        return healingFactor;
    }
    Rectangle getCollisionRec(Vector2 playerPos) {
        Vector2 screenPos{Vector2Subtract(pos, playerPos)};
        return Rectangle{screenPos.x, screenPos.y, texture.width * 2.f, texture.height * 2.f};
}   
    void Render(Vector2 playerPos, Character* hero) {
        Vector2 screenPos = Vector2Subtract(pos, playerPos);
        DrawTextureEx(texture, screenPos, 0.f, 2.f, WHITE);
    }

private:
    float healingFactor = 10;
    Texture2D texture{};
    Vector2 pos{0.f, 0.f};
    float width{};
    float height{};

};
#endif