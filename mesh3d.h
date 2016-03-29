#ifndef MESH_3D_H
#define MESH_3D_H

#include "point3d.h"
#include "vector3d.h"

//std includes
#include <vector>
#include <math.h>

class Int3d
{
    public:
        //vectors
        int x;
        int y;
        int z;
};

class Mesh3d
{
    public:

        Mesh3d();

        Mesh3d(const char* filename);

        ~Mesh3d();

            //storage
            std::vector<Point3d> mesh_vertices;
            std::vector<Point3d> mesh_face_normal;
            std::vector<Point3d> mesh_vertex_normal;

            //face vectors to boost performance
            std::vector<Int3d> mesh_faces_idx;//save face index
            std::vector<Point3d> mesh_faces_tri;//save faces as triangles

        //void draw(unsigned char mode);
        //Mode:
        //1 SURFACE_NORMAL
        //2 VERTEX_NORMAL

        void calculate_face_normal();
        void calculate_vertex_normal();
        //void calculate_ymax();

        //    GLfloat ymax;

        //shader function

    private:
};

#endif // MESH_3D_H
