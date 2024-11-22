#include "raylib.h"
#include "raymath.h"
#include <string>
#include "character.h"
#include "prop.h"
#include "enemy.h"
#include "healing.h"
using namespace std;

// screen values
float windowWidth = 1080;
float windowHeight = 1080;
float mapScale = 4;
bool victory = false;

int main()
{
    InitWindow(windowWidth, windowHeight, "Projeto SemiFinal");
    InitAudioDevice();
    // main character
    Character hero(windowWidth, windowHeight);

    // struct Enemy Group
    struct Group
    {
        Texture2D idleTexture;
        Texture2D runTexture;
        Vector2 origin;
        float health;
        float damage;
        float speed;
    };

    // enemies
    Group goblins[10];
    for (int i = 0; i < 10; i += 1)
    {
        goblins[i] = {LoadTexture("Classy+Clash+Sprites/characters/goblin_idle_spritesheet.png"),
                      LoadTexture("Classy+Clash+Sprites/characters/goblin_run_spritesheet.png"),
                      Vector2{1000.f + 50.f * i, 800.f + 30.f * i},
                      100.f,
                      2.5f,
                      3.f};
    }
    Enemy goblinsGroup[10]{
        {goblins[0].idleTexture, goblins[0].runTexture, goblins[0].origin},
        {goblins[1].idleTexture, goblins[1].runTexture, goblins[1].origin},
        {goblins[2].idleTexture, goblins[2].runTexture, goblins[2].origin},
        {goblins[3].idleTexture, goblins[3].runTexture, goblins[3].origin},
        {goblins[4].idleTexture, goblins[4].runTexture, goblins[4].origin},
        {goblins[5].idleTexture, goblins[5].runTexture, goblins[5].origin},
        {goblins[6].idleTexture, goblins[6].runTexture, goblins[6].origin},
        {goblins[7].idleTexture, goblins[7].runTexture, goblins[7].origin},
        {goblins[8].idleTexture, goblins[8].runTexture, goblins[8].origin},
        {goblins[9].idleTexture, goblins[9].runTexture, goblins[9].origin},
    };

    Group slimes[15];
    for (int i = 0; i < 15; i += 1)
    {
        slimes[i] = {LoadTexture("Classy+Clash+Sprites/characters/slime_idle_spritesheet.png"),
                     LoadTexture("Classy+Clash+Sprites/characters/slime_run_spritesheet.png"),
                     Vector2{2000.f + 80.f * i, 1800.f + 80.f * i},
                     200.f,
                     1.5f,
                     1.5f};
    }
    Enemy slimesGroup[15]{
        {slimes[0].idleTexture, slimes[0].runTexture, slimes[0].origin},
        {slimes[1].idleTexture, slimes[1].runTexture, slimes[1].origin},
        {slimes[2].idleTexture, slimes[2].runTexture, slimes[2].origin},
        {slimes[3].idleTexture, slimes[3].runTexture, slimes[3].origin},
        {slimes[4].idleTexture, slimes[4].runTexture, slimes[4].origin},
        {slimes[5].idleTexture, slimes[5].runTexture, slimes[5].origin},
        {slimes[6].idleTexture, slimes[6].runTexture, slimes[6].origin},
        {slimes[7].idleTexture, slimes[7].runTexture, slimes[7].origin},
        {slimes[8].idleTexture, slimes[8].runTexture, slimes[8].origin},
        {slimes[9].idleTexture, slimes[9].runTexture, slimes[9].origin},
        {slimes[10].idleTexture, slimes[10].runTexture, slimes[10].origin},
        {slimes[11].idleTexture, slimes[11].runTexture, slimes[11].origin},
        {slimes[12].idleTexture, slimes[12].runTexture, slimes[12].origin},
        {slimes[13].idleTexture, slimes[13].runTexture, slimes[13].origin},
        {slimes[14].idleTexture, slimes[14].runTexture, slimes[14].origin},
    };

    Group redGoblins[10];
    for (int i = 0; i < 10; i += 1)
    {
        redGoblins[i] = {LoadTexture("Classy+Clash+Sprites/characters/goblin_idle_spritesheet.png"),
                         LoadTexture("Classy+Clash+Sprites/characters/goblin_run_spritesheet.png"),
                         Vector2{2600.f + 100.f * i, 2600.f + 50.f * i},
                         300.f,
                         15.f,
                         2.f};
    }
    Enemy redGoblinsGroup[10]{
        {redGoblins[0].idleTexture, redGoblins[0].runTexture, redGoblins[0].origin},
        {redGoblins[1].idleTexture, redGoblins[1].runTexture, redGoblins[1].origin},
        {redGoblins[2].idleTexture, redGoblins[2].runTexture, redGoblins[2].origin},
        {redGoblins[3].idleTexture, redGoblins[3].runTexture, redGoblins[3].origin},
        {redGoblins[4].idleTexture, redGoblins[4].runTexture, redGoblins[4].origin},
        {redGoblins[5].idleTexture, redGoblins[5].runTexture, redGoblins[5].origin},
        {redGoblins[6].idleTexture, redGoblins[6].runTexture, redGoblins[6].origin},
        {redGoblins[7].idleTexture, redGoblins[7].runTexture, redGoblins[7].origin},
        {redGoblins[8].idleTexture, redGoblins[8].runTexture, redGoblins[8].origin},
        {redGoblins[9].idleTexture, redGoblins[9].runTexture, redGoblins[9].origin}};

    Group goblinBosses[3];
    for (int i = 0; i < 3; i += 1)
    {
        goblinBosses[i] = {LoadTexture("Classy+Clash+Sprites/characters/goblin_idle_spritesheet.png"),
                           LoadTexture("Classy+Clash+Sprites/characters/goblin_run_spritesheet.png"),
                           Vector2{3600.f + 100.f * i, 3600.f + 50.f * i},
                           1000.f,
                           20.f,
                           3.f};
    }
    Enemy goblinBossesGroup[3]{
        {goblinBosses[0].idleTexture, goblinBosses[0].runTexture, goblinBosses[0].origin},
        {goblinBosses[1].idleTexture, goblinBosses[1].runTexture, goblinBosses[1].origin},
        {goblinBosses[2].idleTexture, goblinBosses[2].runTexture, goblinBosses[2].origin}};

    Enemy *enemies[]{
        &goblinsGroup[0],
        &goblinsGroup[1],
        &goblinsGroup[2],
        &goblinsGroup[3],
        &goblinsGroup[4],
        &goblinsGroup[5],
        &goblinsGroup[6],
        &goblinsGroup[7],
        &goblinsGroup[8],
        &goblinsGroup[9],
        &slimesGroup[0],
        &slimesGroup[1],
        &slimesGroup[2],
        &slimesGroup[3],
        &slimesGroup[4],
        &slimesGroup[5],
        &slimesGroup[6],
        &slimesGroup[7],
        &slimesGroup[8],
        &slimesGroup[9],
        &slimesGroup[10],
        &slimesGroup[11],
        &slimesGroup[12],
        &slimesGroup[13],
        &slimesGroup[14],
        &redGoblinsGroup[0],
        &redGoblinsGroup[1],
        &redGoblinsGroup[2],
        &redGoblinsGroup[3],
        &redGoblinsGroup[4],
        &redGoblinsGroup[5],
        &redGoblinsGroup[6],
        &redGoblinsGroup[7],
        &redGoblinsGroup[8],
        &redGoblinsGroup[9],
        &goblinBossesGroup[0],
        &goblinBossesGroup[1],
        &goblinBossesGroup[2]};
    for (int i = 0; i < static_cast<int>(sizeof(enemies) / sizeof(enemies[0])); i += 1)
    {
        enemies[i]->setTarget(&hero);
        if (i < 10)
        {
            enemies[i]->setHealth(goblins[0].health);
            enemies[i]->setDamage(goblins[0].damage);
            enemies[i]->setSpeed(goblins[0].speed);
        }
        else if (i < 25)
        {
            enemies[i]->setHealth(slimes[0].health);
            enemies[i]->setDamage(slimes[0].damage);
            enemies[i]->setSpeed(slimes[0].speed);
            enemies[i]->setSlowDown(enemies[i]->getTarget()->getSpeed() / 2);
        }
        else if (i < 31)
        {
            enemies[i]->setHealth(redGoblins[0].health);
            enemies[i]->setDamage(redGoblins[0].damage);
            enemies[i]->setSpeed(redGoblins[0].speed);
            enemies[i]->setColor(RED);
        }
        else
        {
            enemies[i]->setHealth(goblinBosses[0].health);
            enemies[i]->setDamage(goblinBosses[0].damage);
            enemies[i]->setSpeed(goblinBosses[0].speed);
            enemies[i]->setColor(GRAY);
            enemies[i]->setSlowDown(enemies[i]->getTarget()->getSpeed() / 2);
            hero.setPoints(hero.getPoints() + 1);
            enemies[i]->setPointWorth(1);
        }
    }

    // background
    Texture2D map = LoadTexture("tiledmap.png");
    Vector2 mapPos = {0.f, 0.f};
    Texture2D victoryImage = LoadTexture("A knight warms himself by the fire at night.png");
    Prop props[5]{
        Prop{LoadTexture("Classy+Clash+Sprites/nature_tileset/Rock.png"), Vector2{600.f, 1200.f}},
        Prop{LoadTexture("Classy+Clash+Sprites/nature_tileset/Log.png"), Vector2{750.f, 800.f}},
        Prop{LoadTexture("Classy+Clash+Sprites/nature_tileset/Log.png"), Vector2{1850.f, 600.f}},
        Prop{LoadTexture("Classy+Clash+Sprites/nature_tileset/Log.png"), Vector2{200.f, 1800.f}},
        Prop{LoadTexture("Classy+Clash+Sprites/nature_tileset/Log.png"), Vector2{800.f, 2800.f}}};
    healCrystal crystals[5] {
        {LoadTexture("Pink_crystal3.png"), Vector2{1200.f, 600.f}, 20.f},
        {LoadTexture("Pink_crystal3.png"), Vector2{2000.f, 2000.f}, 40.f},
        {LoadTexture("Pink_crystal3.png"), Vector2{680.f, 1200.f}, 10.f},
        {LoadTexture("Pink_crystal3.png"), Vector2{2800.f, 3000.f}, 50.f},
        {LoadTexture("Pink_crystal3.png"), Vector2{1450.f, 1800.f}, 35.f},
    };
    healCrystal* crystalGroup[5]{
        &crystals[0], &crystals[1], &crystals[2], &crystals[3], &crystals[4]
    };

    Music backgroundTheme = LoadMusicStream("human sadness 8bit.mp3");
    Music endTheme = LoadMusicStream("Human Sadness (end credits) - 8 bit .mp3");
    SetTargetFPS(120);
    while (true && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Você é um cavaleiro viajante em\n\n\numa terra há muito esquecida.\n\n\nSua missão é derrotar todos os monstros\n\n\npor perto para poder ver mais uma noite...\n\n\n\n\n\n\nMOVIMENTOS -> w,a,s,d\n\n\n\n\nATAQUE -> Barra de Espaço\n\n\n\n\nFique de olho nas pedras rosas,\n\n\nelas lhe darão auxílio.\n\n\n\n\n\n\nPressione Espaço para começar.", windowWidth/8, 50, 42, WHITE);
        EndDrawing();
        if (IsKeyPressed(KEY_SPACE)) { break;}
    }
    PlayMusicStream(backgroundTheme);
    while (!WindowShouldClose() && !victory)
    {
        if (!hero.getAlive())
        {
            for (Enemy *i : enemies)
            {
                i->setAlive(false);
            }
            StopMusicStream(backgroundTheme);
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Voce Perdeu!", windowWidth / 4.f, windowHeight / 2.f, 100, RED);
            EndDrawing();
        }
        else if (hero.getAlive() && !victory)
        {
            UpdateMusicStream(backgroundTheme);
            BeginDrawing();
            ClearBackground(WHITE);
            mapPos = Vector2Scale(hero.getworldPos(), -1.f);
            DrawTextureEx(map, mapPos, 0.f, mapScale, WHITE);
            Color life{};
            if (hero.getHealth() >= 60)
            {
                life = GREEN;
            }
            else if (hero.getHealth() >= 30)
            {
                life = ORANGE;
            }
            else
            {
                life = RED;
            }
            string health("HP: ");
            health.append(std::to_string(hero.getHealth()), 0, 5);
            DrawText(health.c_str(), windowWidth / 8.f, 50.f, 42, life);
            hero.tick(GetFrameTime());

            if (hero.getworldPos().x < 0.f || hero.getworldPos().y < 0.f ||
                hero.getworldPos().x + windowWidth > map.width * mapScale ||
                hero.getworldPos().y + windowHeight > map.height * mapScale)
            {
                hero.undoMovement();
            }
            for (auto prop : props)
            {
                prop.Render(hero.getworldPos());
                if (CheckCollisionRecs(hero.GetCollisionRec(), prop.getCollisionRec(hero.getworldPos())))
                {
                    hero.undoMovement();
                }
            }
            for (healCrystal* i : crystalGroup) {
                i->Render(hero.getworldPos(), &hero);
                if (CheckCollisionRecs(i->getCollisionRec(hero.getworldPos()), hero.GetCollisionRec())) {
                    hero.setHealth(100.f);
                    i->~healCrystal();
                }
            }
            if (IsKeyPressed(KEY_SPACE) || IsKeyReleased(KEY_SPACE))
            {
                for (Enemy *i : enemies)
                {
                    if (CheckCollisionRecs(i->GetCollisionRec(), hero.getWeaponCollisionRec()))
                    {
                        i->setHealth(i->getHealth() - 20.f);
                    }
                }
            }

            for (Enemy *i : enemies)
            {
                i->tick(GetFrameTime());
            }
            if (hero.getPoints() <= 0)
            {
                StopMusicStream(backgroundTheme);
                float waitTime{};
                waitTime += GetFrameTime();
                if (waitTime >= 0.01){ victory = true;}
            }
            EndDrawing();
        }
    }
    
    if (victory) {
        PlayMusicStream(endTheme);
        UnloadTexture(map);
        hero.~Character();
        for (healCrystal* i : crystalGroup) { i->~healCrystal();}
        for (auto prop : props) { prop.~Prop();}
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextureEx(victoryImage, {0.f, 0.f}, 0.f, 1.5f, WHITE);
        DrawText("Fim.", windowWidth - windowWidth / 4.f, windowHeight - windowHeight/4.f, 150, WHITE);
        EndDrawing();
        while (!WindowShouldClose())
        {
            UpdateMusicStream(endTheme);
            BeginDrawing();
            ClearBackground(BLACK);
            DrawTextureEx(victoryImage, {0.f, 0.f}, 0.f, 1.5f, WHITE);
            DrawText("Fim.", windowWidth - windowWidth / 4.f, windowHeight - windowHeight/4.f, 150, WHITE);
            EndDrawing();
        }
    }


    UnloadTexture(map);
    CloseWindow();
}