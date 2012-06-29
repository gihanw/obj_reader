#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <iostream>
#include "obj_reader.h"

using namespace std;

objReader::objReader()
{
        m = NULL;
        nVertex = 0;
        nFaces = 0;
        size = 0;
}

void objReader::objLoadFile(char* filename)
{
        {
                size_t bytes = 0;
                FILE* file = fopen(filename, "rt");

                if (file != NULL) {
                        fseek(file, 0, SEEK_END);
                        size_t end = ftell(file);
                        fseek(file, 0, SEEK_SET);

                        m = (char*) malloc(end);
                        bytes = fread(m, sizeof(char), end, file);

                        fclose(file);
                }

                size = bytes;
        }
}

void objReader::objLoadModel()
{
        char* p = NULL, * e = NULL;
        bool start = true;
        char mtl[50];
        p = m;
        e = m + size;

        while (p != e) {
                if (memcmp(p, "v",  1) == 0) nVertex++;
                else if (memcmp(p, "f",  1) == 0) nFaces++;

                while (*p++ != (char) 0x0A);
        }

        vertexArray = (vector*) malloc(sizeof(vector) * nVertex);
        faceArray = (face*) malloc(sizeof(face) * nFaces);

        p = m;
        int nV = 0, nF = 0;

        while (p != e) {
                if (memcmp(p, "v", 1) == 0) {
                        sscanf(p, "v %lf %lf %lf", &vertexArray[nV].x, &vertexArray[nV].y, &vertexArray[nV].z);
                        nV++;
                } else if (memcmp(p, "f", 1) == 0) {
                        sscanf(p, "f %d %d %d", &faceArray[nF].vertex[0], &faceArray[nF].vertex[1], &faceArray[nF].vertex[2]);
                        strcpy(faceArray[nF].material,mtl);
                        nF++;
                } else if (memcmp(p, "usemtl", 6) == 0) {
                        sscanf(p, "usemtl %s", mtl);
                }

                while (*p++ != (char) 0x0A);
        }
}
