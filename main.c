#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include <string.h>
#include <time.h>

const int num_rooms = 24;
const int piece_height = 5;
const int piece_width = 5;
long oldseed;

int getRand(int min, int max)
{
    time_t seed;
    seed = time(NULL) + oldseed;

    oldseed = seed;

    srand(seed);

    int n = max - min + 1;
    int i = rand() % n;

    if (i < 0)
    {
        i = -i;
    }
    return min + i;
}

int map_pieces[num_rooms][piece_height][piece_width] = {
    // 1 door
    {
        {1, 1, 2, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 1, 2, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 2, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 1, 1, 1},
        {2, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {2, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {2, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 2, 1, 1, 1},
    },
    {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 2, 1, 1},
    },
    {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 2, 1},
    },
    {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 2},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 2},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 2},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 1, 2, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    // 2 doors
    {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 2},
        {1, 0, 0, 0, 1},
        {1, 1, 2, 1, 1},
    },
    {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {2, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 2, 1, 1},
    },
    {
        {1, 1, 2, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 2, 1, 1},
    },
    {
        {1, 1, 2, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 2},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 2, 1, 1},
        {1, 0, 0, 0, 1},
        {2, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 2, 1, 1},
        {2, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 2, 1, 1},
        {1, 0, 0, 0, 2},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 2, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 2},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 2, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {2, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 2, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 2, 1},
    },
    {
        {1, 1, 2, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 2, 1, 1, 1},
    },

};

void getTile(int room, int y, int x, int posY, int posX, int random)
{

    if (map_pieces[room][y][x] == 0)
    {
        DrawText("#", posX, posY, 30, WHITE);
    }
    else if (map_pieces[room][y][x] == 1)
    {
        DrawText("O", posX, posY, 30, WHITE);
    }
    else if (map_pieces[room][y][x] == 2)
    {
        if (random == 2)
        {
            DrawText("/", posX, posY, 30, WHITE);
        }
        else if (random == 3)
        {
            DrawText("</", posX, posY, 30, WHITE);
        }
        
    }
}

void drawRoom(int random, int random2, int positionX, int positionY)
{

    for (int i = 0; i < 1; i++)
    {
        for (int y = 0; y < piece_height; y++)
        {
            for (int x = 0; x < piece_width; x++)
            {
                getTile(random2, y, x, positionY, positionX, random);
                positionX += 50;
                DrawText(TextFormat("random2: %d", random2 + 1), 600, 400, 30, WHITE);
            }
            positionY += 50;
            positionX = 50;
        }
        positionY += 50;
    }
}

void drawMap()
{
}

void drawSyntax(int posX, int posY)
{

    DrawText("The ´#´ means floor", posX, posY, 30, WHITE);
    posY += 50;
    DrawText("The ´O´ means wall", posX, posY, 30, WHITE);
    posY += 50;
    DrawText("The ´</´ means locked door", posX, posY, 30, WHITE);
    posY += 50;
    DrawText("The ´/´ means unlocked door", posX, posY, 30, WHITE);
}

int main(void)
{

    InitWindow(GetScreenWidth(), GetScreenHeight(), "TestingRand");

    int randomINT = getRand(2, 3);
    int random2 = getRand(1, 23);

    int positionX = 50;
    int positionY = 50;

    while (!WindowShouldClose())
    {
        SetTargetFPS(60);

        BeginDrawing();

        ClearBackground(DARKGRAY);

        if (IsKeyReleased(KEY_F))
        {
            ToggleFullscreen();
        }

        drawRoom(randomINT, random2, positionX, positionY);
        // drawSyntax(280, 100);

        //   DrawText(TextFormat("random1: %d", randomINT), 400, 450, 30, WHITE);

        EndDrawing();
    }

    return 0;
}