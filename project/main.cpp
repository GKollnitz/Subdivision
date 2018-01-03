#include <iostream>
#include "HE_Mesh.h"
int main(int argc, char* argv[]) {

    int l;
    char* fileName = argv[2];
    for (int i = 0; i < argc ; ++i) {
        if (atoi(argv[i]))
            l = atoi(argv[i]);
    }
    HE_Mesh mesh;
    mesh.parseOBJ(fileName);
    mesh.generateQuadFaces(mesh.indexBuffer);
    mesh.generateVB();
    for (int j = 0; j < l; ++j) {
        mesh.subdivide();
    }
    return 0;
}