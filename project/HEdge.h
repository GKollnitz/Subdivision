//
// Created by gunkol-5 on 9/5/17.
//
#include "Mathlib3d.h"
#include <vector>
#ifndef GSCEPT_LAB_ENV_HEDGE_H
#define GSCEPT_LAB_ENV_HEDGE_H
struct vertex
{
    vertex(){x = 0; y=0;z=0;};
    ~vertex(){};
    float x;
    float y;
    float z;

};

struct HE_Edge;
struct HE_Vertex;
struct HE_Face
{

    int index = -1;
    HE_Edge* member;
};

struct HE_Edge
{
    bool pairIsSplit = false;
    int index = -1;

    HE_Edge* next;
    HE_Face* face;
    HE_Vertex* start;
    HE_Edge* pair = nullptr;
};

struct HE_Vertex
{
    int oldIndex = -1;
    vertex vert;
    HE_Edge* owner;
};

#endif //GSCEPT_LAB_ENV_HEDGE_H
