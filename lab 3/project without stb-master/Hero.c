#include <gl/gl.h>
#include <stdio.h>
#include <stdlib.h>

#include "Hero.h"

float speed = 2.5;
float gravity = 0.2;
typedef struct
{
    float x, y, dx, dy; //обе координаты и скорость изменения
} Hero;

void Hero_Init(Hero *obj, float x1, float y1, float dx1, float dy1)
{
    obj->x=x1;
    obj->y=y1;
    obj->dx=dx1;
    obj->dy=dy1;
}

void Hero_Move(Hero *obj)
{
    obj->y+=obj->dy;
    obj->x+=obj->dx;
    obj->dy-=gravity;
    if (GetKeyState(VK_LEFT)<0 && State==1)
    {
        currentframe+=0.15;
        obj->dx-=speed;
        obj->x+=obj->dx;
        obj->dx=0;
        if (currentframe>8) currentframe-=7;
    }
    if (GetKeyState(VK_RIGHT)<0 && State==1)
    {
        currentframe+=0.15;
        obj->dx+=speed;
        obj->x+=obj->dx;
        obj->dx=0;
        if (currentframe>8) currentframe-=7;
        directional=0;
    }
    if (GetKeyState(VK_UP)<0 && (obj->y<20) && State==1)
    {
        obj->dy =speed*1.2;
        obj->y+=obj->dy;
    }
}
