#include "enemy.h"
#include "raymath.h"

Enemy::Enemy(Texture2D tex, Texture2D run_tex, Vector2 pos)
{
    texture = tex;
    idle = tex;
    run = run_tex;
    worldPos = pos;
    width = texture.width / maxFrames;
    height = texture.height;
    speed = 3.5f;
}
void Enemy::setTarget(Character* hero) {
    target = hero;
}
void Enemy::Delete() {
    UnloadTexture(texture);
    this->~Enemy();
}
Vector2 Enemy::getScreenPos() {
    return Vector2Subtract(worldPos, target->getworldPos());
}
void Enemy::tick(float deltaTime) {
    if (!getAlive()) {
        target->setPoints(target->getPoints() - getPointWorth());
        this->Delete();
        setPointWorth(0);
        return;
    }

    Vector2Distance(target->getScreenPos(), getScreenPos()) <= vision ? velocity = Vector2Subtract(target->getScreenPos(), getScreenPos()) : velocity = {};
    if (CheckCollisionRecs(target->GetCollisionRec(), GetCollisionRec())) {
        if (!IsKeyDown(KEY_SPACE) && !IsKeyPressed(KEY_SPACE)) { 
            target->setHealth(target->getHealth() - damagePerSec * deltaTime);
            if (getSlowDown() > 0.f) {
                target->setSlow(getSlowDown());
            }
        }

        else {target->setHealth(target->getHealth() - damagePerSec/1.25 * deltaTime);}
        velocity = {0.f, 0.f};
    }
    velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
    BaseCharacter::tick(deltaTime);
}
