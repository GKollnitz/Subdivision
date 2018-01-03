//
// Created by gunkol-5 on 9/5/17.
//

#ifndef GSCEPT_LAB_ENV_HEMESH_H
#define GSCEPT_LAB_ENV_HEMESH_H
#include "HEdge.h"

#define POW 13
#define BLOCKSIZE (1<<POW)
template <class T>
class mem_pool
{
private:
    struct block
    {
        T data[BLOCKSIZE];
    };
    std::vector<block*> blocks;
    int next_free;
public:
    mem_pool();
    void new_block();
    T* new_element();
    T* operator[](int);
};

template <class T>
inline mem_pool<T>::mem_pool()
{
    next_free = -1;
};

template<class T>
inline void mem_pool<T>::new_block()
{
    blocks.push_back(new block);
}

template<class T>
inline T* mem_pool<T>::new_element()
{
    next_free++;
    if((next_free&(BLOCKSIZE-1))==0)
    {
        new_block();
    }
    return &blocks[next_free>>POW]->data[(next_free&(BLOCKSIZE-1))];
};

template<class T>
inline T* mem_pool<T>::operator[](int i)
{
    return &blocks[i>>POW]->data[(i&(BLOCKSIZE-1))];
};

class HE_Mesh
{
public:
    //functions
    void parseOBJ(const char*);
    void generateQuadFaces(int *);
    void generateVB();
    void subdivide();
    inline mem_pool<HE_Vertex> generateFacePoints();
    inline mem_pool<HE_Vertex> generateEdgePoints(mem_pool<HE_Vertex>);
    inline mem_pool<HE_Vertex> generateNewVertexes(mem_pool<HE_Vertex>);
    void generateRest(mem_pool<HE_Vertex>);

    mem_pool<HE_Edge> edges;
    mem_pool<HE_Face> faces;
    mem_pool<HE_Vertex> originalVertexes;
    mem_pool<HE_Vertex> vertexes;
    vertex * vertexBuffer;

    int nrFaces;
    int vertLength;
    int indexBLength;

    bool isQuad = false;

    int* indexBuffer;
};

#endif //GSCEPT_LAB_ENV_HEMESH_H
