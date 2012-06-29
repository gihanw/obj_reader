#ifndef OBJ_READER_H
#define OBJ_READER_H

#include <stdlib.h>

typedef struct {
        double x, y, z;
} vector;

typedef struct {
        int vertex[3];
        char material[50];
} face;

class objReader
{
public:
        objReader();
        void objLoadModel();
        void objLoadFile(char* filename);
        char* m;

        size_t size;
        vector* vertexArray;
        face* faceArray;
        int nVertex, nFaces;
        double maxX, maxY, maxZ;
        double boundaryRadius;
};

#endif
