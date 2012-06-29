#include <iostream>
#include "obj_reader.h"

using namespace std;

int main(int argc, char** argv)
{
        objReader testobj;
        testobj.objLoadFile(argv[1]);
        testobj.objLoadModel();

        cout<<"No. of vertices: "<<testobj.nVertex<<endl;
        cout<<"No. of faces: "<<testobj.nFaces<<endl;

        return 0;
}
