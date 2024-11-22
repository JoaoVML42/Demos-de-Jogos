#include "prop.h"
#include "raymath.h"

Prop::Prop(Texture2D tex, Vector2 pos) :
    texture(tex),
    worldPos(pos)
{

}
void Prop::Render(Vector2 playerPos) {
    Vector2 screenPos = Vector2Subtract(worldPos, playerPos);
    DrawTextureEx(texture, screenPos, 0.f, scale, WHITE);
}
Rectangle Prop::getCollisionRec(Vector2 playerPos) {
    Vector2 screenPos{Vector2Subtract(worldPos, playerPos)};
    return Rectangle{screenPos.x, screenPos.y, texture.width * scale, texture.height * scale};
}