//
// Created by gunkol-5 on 9/5/17.
//
#include <vector>
#include "Mathlib3d.h"
#include <sstream>
#include <cstring>
#include "HE_Mesh.h"

void split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
}

void HE_Mesh::parseOBJ(const char * name)
{
    int vertL = 0;
    int uvL = 0;
    int normL = 0;
    std::vector< int > vertexIndices, uvIndices, normalIndices;
    std::vector< Vector4D > temp_vertices;
    std::vector< Vector4D > temp_uvs;
    std::vector< Vector4D > temp_normals;

    FILE * file = fopen(name, "r");


    if (file == NULL)
    {
        printf("Can't open the file");
    }

    while (1) {
        char lineHeader[128];
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF) //EOF = End Of File
            break;

        if (strcmp(lineHeader, "v") == 0) {
            vertL += 1;
            Vector4D vertex;

            fscanf(file, "%f %f %f\n", &vertex.cooV[0], &vertex.cooV[1], &vertex.cooV[2]);
            temp_vertices.push_back(vertex);
        } else if (strcmp(lineHeader, "vn") == 0) {
            Vector4D normal;
            fscanf(file, "%f %f %f\n", &normal.cooV[0], &normal.cooV[1], &normal.cooV[2]);
            normL += 1;
            temp_normals.push_back(normal);
        } else if (strcmp(lineHeader, "vt") == 0) {
            Vector4D uv;
            fscanf(file, "%f %f\n", &uv.cooV[0], &uv.cooV[1]);
            uvL += 1;
            uv.cooV[1] = -uv.cooV[1];
            temp_uvs.push_back(uv);
        } else if (strcmp(lineHeader, "f") == 0) {
            char cArr[256];
            fscanf(file, "%[^\n]\n", &cArr);
            std::string str(cArr);
            std::vector<std::string> vertices;
            split(str, ' ', vertices);
            vertices.erase(vertices.begin()); //First element is a empty string since the line starts with space after f
            if (vertices.size() == 3) {
                std::vector<std::string> vertex2;
                split(vertices[0], '/', vertex2);
                if (vertex2.size() == 1) {
                    for (int i = 0; i < 3; i++) {
                        std::vector<std::string> vertex_properties;
                        split(vertices[i], '/', vertex_properties);
                        vertexIndices.push_back(stoi(vertex_properties[0]));
                    }
                }
                else if (vertex2.size() == 2) {
                    for (int i = 0; i < 3; i++) {
                        std::vector<std::string> vertex_properties;
                        split(vertices[i], '/', vertex_properties);
                        vertexIndices.push_back(stoi(vertex_properties[0]));
                        uvIndices.push_back(stoi(vertex_properties[1]));
                    }
                } else {
                    for (int i = 0; i < 3; i++) {

                        std::vector<std::string> vertex_properties;
                        split(vertices[i], '/', vertex_properties);
                        vertexIndices.push_back(stoi(vertex_properties[0]));
                        uvIndices.push_back(stoi(vertex_properties[1]));
                        normalIndices.push_back(stoi(vertex_properties[2]));
                    }
                }
            } else if (vertices.size() == 4){
                isQuad = true;
                std::vector<std::string> vertex2;
                split(vertices[0], '/', vertex2);

                if (vertex2.size() == 1) {
                    for (int i = 0; i < 4; i++) {

                        std::vector<std::string> vertex_properties;
                        split(vertices[i], '/', vertex_properties);
                        vertexIndices.push_back(stoi(vertex_properties[0]));
                    }
                }
                else if (vertex2.size() == 2) {
                    for (int i = 0; i < 4; i++) {

                        std::vector<std::string> vertex_properties;
                        split(vertices[i], '/', vertex_properties);
                        vertexIndices.push_back(stoi(vertex_properties[0]));
                        uvIndices.push_back(stoi(vertex_properties[1]));
                    }
                }
                else {
                    for (int i = 0; i < 4; i++) {

                        std::vector<std::string> vertex_properties;
                        split(vertices[i], '/', vertex_properties);
                        vertexIndices.push_back(stoi(vertex_properties[0]));
                        uvIndices.push_back(stoi(vertex_properties[1]));
                        normalIndices.push_back(stoi(vertex_properties[2]));
                    }
                }
            }
        }
    }

    vertLength = vertL;
    indexBuffer = new int[vertexIndices.size()];
    for(int i = 0; i<temp_vertices.size(); i++)
    {
        HE_Vertex * tempV = originalVertexes.new_element();
        tempV->vert.x = temp_vertices[i].cooV[0]*0.5;
        tempV->vert.y = temp_vertices[i].cooV[1]*0.5;
        tempV->vert.z = temp_vertices[i].cooV[2]*0.5;

    }
    indexBLength = vertexIndices.size();
    for(int i = 0; i<vertexIndices.size(); i++)
    {
        indexBuffer[i] = vertexIndices[i];
    }
}

void HE_Mesh::generateQuadFaces(int* indexB)
{
    //# of faces = indexBuffer.size / 3 (om trianglar)
    //# of edges = indexBuffer
    if(!isQuad) {
    }
    else if (isQuad)
    {
        nrFaces = indexBLength*0.25;
        int edgesIndex = 0;
        for (int i = 0; i < nrFaces; i++) {

            HE_Face *tempFace = faces.new_element();

            HE_Edge *edge1 = edges.new_element();
            HE_Edge *edge2 = edges.new_element();
            HE_Edge *edge3 = edges.new_element();
            HE_Edge *edge4 = edges.new_element();

            originalVertexes[(indexB[edgesIndex]-1)]->oldIndex = (indexB[edgesIndex]-1);
            originalVertexes[(indexB[edgesIndex+1]-1)]->oldIndex = (indexB[edgesIndex+1]-1);
            originalVertexes[(indexB[edgesIndex+2]-1)]->oldIndex = (indexB[edgesIndex+2]-1);
            originalVertexes[(indexB[edgesIndex+3]-1)]->oldIndex = (indexB[edgesIndex+3]-1);

            edge1->start = originalVertexes[(indexB[edgesIndex]-1)];
            edge2->start = originalVertexes[(indexB[edgesIndex+1]-1)];
            edge3->start = originalVertexes[(indexB[edgesIndex+2]-1)];
            edge4->start = originalVertexes[(indexB[edgesIndex+3]-1)];

            tempFace->member = edge1;
            tempFace->index = i;
            edge1->next = edge2;
            edge1->face = tempFace;
            edge1->index = edgesIndex;

            edge2->next = edge3;
            edge2->face = tempFace;
            edge2->index = edgesIndex+1;

            edge3->next = edge4;
            edge3->face = tempFace;
            edge3->index = edgesIndex+2;

            edge4->next = edge1;
            edge4->face = tempFace;
            edge4->index = edgesIndex+3;

            edge1->start->owner = edge1;
            edge2->start->owner = edge2;
            edge3->start->owner = edge3;
            edge4->start->owner = edge4;

            edgesIndex += 4;
        }

        for (int i = 0; i < edgesIndex; i++) {
            for (int j = 0; j < edgesIndex; j++) {
                if (edges[i]->start == edges[j]->next->start && edges[i]->next->start == edges[j]->start)
                {
                    edges[i]->pair = edges[j];
                }
            }
        }
    }
}


void HE_Mesh::generateVB()
{

    vertexBuffer = new vertex[indexBLength*2];
    for(int i = 0; i<indexBLength; i++)
    {
        vertexBuffer[i] = originalVertexes[(indexBuffer[i]-1)]->vert;
    }
    vertexes = originalVertexes;
}

inline mem_pool<HE_Vertex> HE_Mesh::generateFacePoints()
{
    mem_pool<HE_Vertex> newVertexList;
    for(int i = 0; i<nrFaces; i++)
    {
        //For each face, add a face point
        //Set each face point to be the average of all original points for the respective face.
        HE_Vertex* fp = newVertexList.new_element();
        vertex fpv;
        HE_Edge* member = faces[i]->member;
        vertex f = member->start->vert;
        vertex fn  = member->next->start->vert;
        vertex fn2 = member->next->next->start->vert;
        vertex fn3 = member->next->next->next->start->vert;

        fpv.x = (f.x
                 + fn.x
                 + fn2.x
                 + fn3.x)*0.25;

        fpv.y = (f.y
                 + fn.y
                 + fn2.y
                 + fn3.y)*0.25;

        fpv.z = (f.z
                 + fn.z
                 + fn2.z
                 + fn3.z)*0.25;
        fp->vert = fpv;
        fp->oldIndex = i;
        faces[i]->index = i;
    }
    return newVertexList;
}

inline mem_pool<HE_Vertex> HE_Mesh::generateEdgePoints(mem_pool<HE_Vertex> newVertexList)
{
    mem_pool<HE_Vertex> ePoints;
    int edgePointsMade = 0;
    for(int i = 0; i<(nrFaces*4); i++)
    {
        //For each edge, add an edge point
        //Set each edge point to be the average of the two neighbouring face points and its two original endpoints.
        float newX = 0;
        float newY = 0;
        float newZ = 0;
        vertex f1 = newVertexList[edges[i]->face->index]->vert;
        vertex f2 = newVertexList[edges[i]->pair->face->index]->vert;
        vertex e1 = edges[i]->next->start->vert;
        vertex e2 = edges[i]->start->vert;
        newX = (f1.x+f2.x+e1.x+e2.x)*0.25;
        newY = (f1.y+f2.y+e1.y+e2.y)*0.25;
        newZ = (f1.z+f2.z+e1.z+e2.z)*0.25;

        bool exists = false;

        // Vill bara skapa en edgePoint per par av edges

        if(edges[i]->pair->index < i)
        {
            exists = true;
        }
        if(exists)
        {
            edges[i]->index = edges[i]->pair->index;
        }
        else
        {
            HE_Vertex* edgePoint = newVertexList.new_element();
            edges[i]->index = edgePointsMade;
            edgePoint->vert.x = newX;
            edgePoint->vert.y = newY;
            edgePoint->vert.z = newZ;
            edgePoint->oldIndex = nrFaces+edgePointsMade;;
            edgePointsMade++;
        }
        //------------
    }
    return newVertexList;
}

inline mem_pool<HE_Vertex> HE_Mesh::generateNewVertexes(mem_pool<HE_Vertex> newVertexList)
{
    for(int i = 0; i<vertLength; i++)
    {
        //For each original point P, take the average F of all n (recently created) face points for faces touching P,
        //and take the average R of all n edge midpoints for (original) edges touching P,
        //where each edge midpoint is the average of its two endpoint vertices (not to be confused with new "edge points" above).
        vertex R;
        vertex F;
        vertex P = vertexes[i]->vert;
        vertex Total;
        int n = 0;
        bool done = false;
        HE_Edge* currentEdge = vertexes[i]->owner;
        while(!done)
        {
            vertex ce = currentEdge->start->vert;
            vertex cen = currentEdge->next->start->vert;
            R.x = R.x+((ce.x+cen.x)*0.5f);
            R.y = R.y+((ce.y+cen.y)*0.5f);
            R.z = R.z+((ce.z+cen.z)*0.5f);

            vertex nef = newVertexList[currentEdge->face->index]->vert;
            F.x = F.x+nef.x;
            F.y = F.y+nef.y;
            F.z = F.z+nef.z;

            n++;
            currentEdge = currentEdge->pair->next;
            if(vertexes[i]->owner == currentEdge)
            {
                done = true;
            }
        }

        // Move each original point to the point
        //  (F+2R+(n-3)P)/n     This is the barycenter of P, R and F with respective weights (n − 3), 2 and 1.
        R.x = R.x/n;
        R.y = R.y/n;
        R.z = R.z/n;
        F.x = F.x/n;
        F.y = F.y/n;
        F.z = F.z/n;
        P.x = P.x*(n-3);
        P.y = P.y*(n-3);
        P.z = P.z*(n-3);

        Total.x = F.x + 2.0f*R.x;
        Total.y = F.y + 2.0f*R.y;
        Total.z = F.z + 2.0f*R.z;

        Total.x = (Total.x + P.x)/n;
        Total.y = (Total.y + P.y)/n;
        Total.z = (Total.z + P.z)/n;

        HE_Vertex* v = newVertexList.new_element();
        v->vert=Total;
        v->owner = vertexes[i]->owner;
        v->oldIndex = (nrFaces*4)*0.5+nrFaces+i;

        //Connect each new vertex point to the new edge points of all original edges incident on the original vertex.

    }
    return newVertexList;
}

void HE_Mesh::generateRest(mem_pool<HE_Vertex> newVertexList)
{
    int nrEdges = nrFaces*4;
    int faceIndex = 0;
    int edgeIndex = 0;
    vertex* newVertexes = new vertex[nrEdges*4];
    mem_pool<HE_Face> newFaces;
    mem_pool<HE_Edge> newEdges;
    for(int i = 0; i<nrFaces; i++) {
        HE_Edge *temp = faces[i]->member;

        HE_Face *face1 = newFaces.new_element();
        HE_Face *face2 = newFaces.new_element();
        HE_Face *face3 = newFaces.new_element();
        HE_Face *face4 = newFaces.new_element();

        HE_Edge *edge1_1 = newEdges.new_element();
        HE_Edge *edge1_2 = newEdges.new_element();
        HE_Edge *edge1_3 = newEdges.new_element();
        HE_Edge *edge1_4 = newEdges.new_element();

        HE_Edge *edge2_1 = newEdges.new_element();
        HE_Edge *edge2_2 = newEdges.new_element();
        HE_Edge *edge2_3 = newEdges.new_element();
        HE_Edge *edge2_4 = newEdges.new_element();

        HE_Edge *edge3_1 = newEdges.new_element();
        HE_Edge *edge3_2 = newEdges.new_element();
        HE_Edge *edge3_3 = newEdges.new_element();
        HE_Edge *edge3_4 = newEdges.new_element();

        HE_Edge *edge4_1 = newEdges.new_element();
        HE_Edge *edge4_2 = newEdges.new_element();
        HE_Edge *edge4_3 = newEdges.new_element();
        HE_Edge *edge4_4 = newEdges.new_element();

        face1->member = edge1_1;
        face2->member = edge2_1;
        face3->member = edge3_1;
        face4->member = edge4_1;

        face1->index = faceIndex + 0;
        face1->index = faceIndex + 1;
        face1->index = faceIndex + 2;
        face1->index = faceIndex + 3;

        //Split of edges
        //"edge"+face+"_"+edge
        edge1_1->start = newVertexList[temp->start->oldIndex + (nrEdges *0.5) + nrFaces];
        edge1_1->face = face1;
        edge1_1->index = edgeIndex + 0;
        edge1_1->next = edge1_2;

        edge2_4->start = newVertexList[nrFaces + temp->index];
        edge2_4->face = face2;
        edge2_4->index = edgeIndex + 7;
        edge2_4->next = edge2_1;

        edge2_1->start = newVertexList[temp->next->start->oldIndex + (nrEdges *0.5) + nrFaces];
        edge2_1->face = face2;
        edge2_1->index = edgeIndex + 4;
        edge2_1->next = edge2_2;

        edge3_4->start = newVertexList[nrFaces + temp->next->index];
        edge3_4->face = face3;
        edge3_4->index = edgeIndex + 11;
        edge3_4->next = edge3_1;

        edge3_1->start = newVertexList[temp->next->next->start->oldIndex + (nrEdges *0.5) + nrFaces];
        edge3_1->face = face3;
        edge3_1->index = edgeIndex + 8;
        edge3_1->next = edge3_2;

        edge4_4->start = newVertexList[nrFaces + temp->next->next->index];
        edge4_4->face = face4;
        edge4_4->index = edgeIndex + 15;
        edge4_4->next = edge4_1;

        edge4_1->start = newVertexList[temp->next->next->next->start->oldIndex + (nrEdges *0.5) + nrFaces];
        edge4_1->face = face4;
        edge4_1->index = edgeIndex + 12;
        edge4_1->next = edge4_2;

        edge1_4->start = newVertexList[nrFaces + temp->next->next->next->index];
        edge1_4->face = face1;
        edge1_4->index = edgeIndex + 3;
        edge1_4->next = edge1_1;
        //------------
        HE_Vertex* nv = newVertexList[faces[i]->index];
        //Creation of cross
        edge1_2->next = edge1_3;
        edge1_2->start = newVertexList[nrFaces + temp->index];
        edge1_2->face = face1;
        edge1_2->pair = edge2_3;
        edge1_2->index = edgeIndex + 1;

        edge1_3->next = edge1_4;
        edge1_3->start = nv;
        edge1_3->face = face1;
        edge1_3->pair = edge4_2;
        edge1_3->index = edgeIndex + 2;

        edge2_2->next = edge2_3;
        edge2_2->start = newVertexList[nrFaces + temp->next->index];
        edge2_2->face = face2;
        edge2_2->pair = edge3_3;
        edge2_2->index = edgeIndex + 5;

        edge2_3->next = edge2_4;
        edge2_3->start = nv;
        edge2_3->face = face2;
        edge2_3->pair = edge1_2;
        edge2_3->index = edgeIndex + 6;

        edge3_2->next = edge3_3;
        edge3_2->start = newVertexList[nrFaces + temp->next->next->index];
        edge3_2->face = face3;
        edge3_2->pair = edge4_3;
        edge3_2->index = edgeIndex + 9;

        edge3_3->next = edge3_4;
        edge3_3->start = nv;
        edge3_3->face = face3;
        edge3_3->pair = edge2_2;
        edge3_3->index = edgeIndex + 10;

        edge4_2->next = edge4_3;
        edge4_2->start = newVertexList[nrFaces + temp->next->next->next->index];
        edge4_2->face = face4;
        edge4_2->pair = edge1_3;
        edge4_2->index = edgeIndex + 13;

        edge4_3->next = edge4_4;
        edge4_3->start = nv;
        edge4_3->face = face4;
        edge4_3->pair = edge3_2;
        edge4_3->index = edgeIndex + 14;
        //-------------

        if (!temp->pair->pairIsSplit) {
            temp->pairIsSplit = true;
            temp->pair = edge1_1;
        } else if (temp->pair->pairIsSplit) {
            edge1_1->pair = temp->pair->pair->next->pair->next;
            temp->pair->pair->next->pair->next->pair = edge1_1;
            edge2_4->pair = temp->pair->pair;
            temp->pair->pair->pair = edge2_4;
        }

        temp = temp->next;

        if (!temp->pair->pairIsSplit) {
            temp->pairIsSplit = true;
            temp->pair = edge2_1;
        } else if (temp->pair->pairIsSplit) {
            edge2_1->pair = temp->pair->pair->next->pair->next;
            temp->pair->pair->next->pair->next->pair = edge2_1;
            edge3_4->pair = temp->pair->pair;
            temp->pair->pair->pair = edge3_4;
        }

        temp = temp->next;

        if (!temp->pair->pairIsSplit) {
            temp->pairIsSplit = true;
            temp->pair = edge3_1;
        } else if (temp->pair->pairIsSplit) {
            edge3_1->pair = temp->pair->pair->next->pair->next;
            temp->pair->pair->next->pair->next->pair = edge3_1;
            edge4_4->pair = temp->pair->pair;
            temp->pair->pair->pair = edge4_4;
        }

        temp = temp->next;

        if (!temp->pair->pairIsSplit) {
            temp->pairIsSplit = true;
            temp->pair = edge4_1;
        } else if (temp->pair->pairIsSplit) {
            edge4_1->pair = temp->pair->pair->next->pair->next;
            temp->pair->pair->next->pair->next->pair = edge4_1;
            edge1_4->pair = temp->pair->pair;
            temp->pair->pair->pair = edge1_4;
        }


        //Owner of verts
        edge1_1->start->owner = edge1_1;
        edge1_4->start->owner = edge1_4;
        edge2_1->start->owner = edge2_1;
        edge2_4->start->owner = edge2_4;
        edge3_1->start->owner = edge3_1;
        edge3_4->start->owner = edge3_4;
        edge4_1->start->owner = edge4_1;
        edge4_4->start->owner = edge4_4;
        edge1_3->start->owner = edge1_3;
        //-------------

        newVertexes[edgeIndex + 0] = edge1_1->start->vert;
        newVertexes[edgeIndex + 1] = edge1_2->start->vert;
        newVertexes[edgeIndex + 2] = edge1_3->start->vert;
        newVertexes[edgeIndex + 3] = edge1_4->start->vert;
        newVertexes[edgeIndex + 4] = edge2_1->start->vert;
        newVertexes[edgeIndex + 5] = edge2_2->start->vert;
        newVertexes[edgeIndex + 6] = edge2_3->start->vert;
        newVertexes[edgeIndex + 7] = edge2_4->start->vert;
        newVertexes[edgeIndex + 8] = edge3_1->start->vert;
        newVertexes[edgeIndex + 9] = edge3_2->start->vert;
        newVertexes[edgeIndex + 10] = edge3_3->start->vert;
        newVertexes[edgeIndex + 11] = edge3_4->start->vert;
        newVertexes[edgeIndex + 12] = edge4_1->start->vert;
        newVertexes[edgeIndex + 13] = edge4_2->start->vert;
        newVertexes[edgeIndex + 14] = edge4_3->start->vert;
        newVertexes[edgeIndex + 15] = edge4_4->start->vert;

        faceIndex += 4;
        edgeIndex += 16;
    }
    //Re-set the lists in preperation of the next Subdivision
    vertexes = newVertexList;
    vertLength = nrFaces+(nrEdges*0.5)+vertLength;
    nrFaces = nrFaces*4;
    vertexBuffer = newVertexes;
    edges = newEdges;
    faces = newFaces;
}

void HE_Mesh::subdivide()
{
    mem_pool<HE_Vertex>newVertexList = generateFacePoints();
    newVertexList = generateEdgePoints(newVertexList);
    newVertexList = generateNewVertexes(newVertexList);
    generateRest(newVertexList);
}