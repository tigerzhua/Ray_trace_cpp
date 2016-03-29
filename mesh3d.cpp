#include "mesh3d.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

#define PI 3.1415926535

using namespace std;

Mesh3d::Mesh3d(){
    mesh_vertices.clear();
    mesh_face_normal.clear();
    mesh_vertex_normal.clear();
    mesh_faces_tri.clear();
    mesh_faces_idx.clear();
}

Mesh3d::Mesh3d(const char* filename){
    std::ifstream infile(filename, std::ios::in);
    if (!infile) { std::cout<<"Cannot open "<<filename<<std::endl; return; }

    //initialize
    mesh_vertices.clear();
    mesh_face_normal.clear();
    mesh_vertex_normal.clear();
    mesh_faces_tri.clear();
    mesh_faces_idx.clear();

    std::cout<<"Loading 3D mesh: "<<filename<<std::endl;
    //real loading start
    std::string line;
    while (getline(infile, line)) {
        if (line.size() != 0){
            if (line.substr(0,2) == "v ") {
                istringstream pos(line.substr(2));//start from the character right after "v "
                  double temp_x, temp_y, temp_z;
                  pos >> temp_x;
                  pos >> temp_y;
                  pos >> temp_z;
                  Point3d temp_v = Point3d(temp_x, temp_y, temp_z);
                mesh_vertices.push_back(temp_v);//add the verice
            }
            else if (line.substr(0,2) == "f ") {
                istringstream faces(line.substr(2));
                int a,b,c;
                  faces >> a; a--;//-- so that the indexs fit that in the mesh_vertices vector
                  faces >> b; b--;
                  faces >> c; c--;
                Int3d index; index.x = a; index.y = b; index.z = c;
                mesh_faces_idx.push_back(index);

                mesh_faces_tri.push_back(mesh_vertices[a]);
                mesh_faces_tri.push_back(mesh_vertices[b]);
                mesh_faces_tri.push_back(mesh_vertices[c]);
            }
            else if (line[0] == '#') { /* comment, ignoring this line */ }
            else { /* do nothing */ }
        }
        else { /* ignoring this line */ }
  }
  std::cout<<"Loading "<<filename<<" successful!"<<std::endl;
  infile.close();
  calculate_face_normal();
  //calculate_vertex_normal();
}

void Mesh3d::calculate_face_normal(){
  cout<<"Calculating face normals..."<<endl;
  if (!mesh_faces_tri.empty()){
      for (int i = 0; i < mesh_faces_tri.size(); i+=3) {
            Point3d a = mesh_faces_tri[i];
            Point3d b = mesh_faces_tri[i+1];
            Point3d c = mesh_faces_tri[i+2];

            Point3d va;
            va.set_x( a.get_x()-b.get_x() );
            va.set_y( a.get_y()-b.get_y() );
            va.set_z( a.get_z()-b.get_z() );
            Point3d vb;
            vb.set_x( a.get_x()-c.get_x() );
            vb.set_y( a.get_y()-c.get_y() );
            vb.set_z( a.get_z()-c.get_z() );

            //cross product
            Point3d result;
            result.set_x( va.get_y() * vb.get_z() - vb.get_y() * va.get_z() );
            result.set_y( vb.get_x() * va.get_z() - va.get_x() * vb.get_z() );
            result.set_z( va.get_x() * vb.get_y() - vb.get_x() * va.get_y() );

            float val = sqrt( result.get_x()*result.get_x() +
                              result.get_y()*result.get_y() +
                              result.get_z()*result.get_z() );

            result.set_x( result.get_x()/val );
            result.set_y( result.get_y()/val );
            result.set_z( result.get_z()/val );

            mesh_face_normal.push_back(result);
      }
  }
  else{
    cout<<"No faces loaded, cannot calculate normals"<<endl;
  }
}

void Mesh3d::calculate_vertex_normal(){
  cout<<"Calculating vertex normals..."<<endl;

  Point3d result;
  int temp_size;

  if (!mesh_faces_tri.empty()){

      //too hard to explain the codes below.....
      std::vector< std::vector<int> > temp_normal_list;
      temp_normal_list.resize(mesh_vertices.size());

      for (int i = 0; i < mesh_faces_idx.size(); i++) {
            int index_x = mesh_faces_idx[i].x;
            int index_y = mesh_faces_idx[i].y;
            int index_z = mesh_faces_idx[i].z;
            (temp_normal_list[ index_x ]).push_back(i);
            (temp_normal_list[ index_y ]).push_back(i);
            (temp_normal_list[ index_z ]).push_back(i);
            //cout<<mesh_faces_idx[i].x<<" "<<mesh_faces_idx[i].y<<" "<<mesh_faces_idx[i].z<<endl;
      }

      for (int j = 0; j < temp_normal_list.size(); j++){

          temp_size = (temp_normal_list[j]).size();

          if (temp_size > 0){//not a lonely vertex
              for (int k = 0; k < temp_size; k++){
                  result.add_x( (mesh_face_normal[ (temp_normal_list[j])[k] ]).get_x() );
                  result.add_y( (mesh_face_normal[ (temp_normal_list[j])[k] ]).get_y() );
                  result.add_z( (mesh_face_normal[ (temp_normal_list[j])[k] ]).get_z() );
                  //cout<<(temp_normal_list[j])[k]<<" "<<result.x<<" "<<result.y<<" "<<result.z<<endl;
              }
              result.set_x( result.get_x()/temp_size );
              result.set_y( result.get_y()/temp_size );
              result.set_z( result.get_z()/temp_size );

              float val = sqrt( result.get_x()*result.get_x() +
                                result.get_y()*result.get_y() +
                                result.get_z()*result.get_z() );

              result.set_x( result.get_x()/val );
              result.set_y( result.get_y()/val );
              result.set_z( result.get_z()/val );
          }
          mesh_vertex_normal.push_back(result);
          result = Point3d();
      }
  }
  else
    cout<<"No faces loaded, cannot calculate normals"<<endl;
}

Mesh3d::~Mesh3d(){
    mesh_vertices.clear();
    mesh_face_normal.clear();
    mesh_vertex_normal.clear();
    mesh_faces_tri.clear();
    mesh_faces_idx.clear();
}

/*
void Mesh3d::draw(unsigned char mode){
        //Mode:
        //(SURFACE_NORMAL)1 for surface normal
        //(VERTEX_NORMAL)2 for vertex normal

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glEnable(GL_TEXTURE_GEN_R);

    if (mode == SURFACE_NORMAL){
	    glBegin(GL_TRIANGLES);
	        for (int i = 0; i < mesh_faces_tri.size(); i+=3){
                //draw surface normal
                glNormal3f(mesh_face_normal[i/3].x, mesh_face_normal[i/3].y, mesh_face_normal[i/3].z);

                glVertex3f(mesh_faces_tri[i].x, mesh_faces_tri[i].y, mesh_faces_tri[i].z);
	            glVertex3f(mesh_faces_tri[i+1].x, mesh_faces_tri[i+1].y, mesh_faces_tri[i+1].z);
	            glVertex3f(mesh_faces_tri[i+2].x, mesh_faces_tri[i+2].y, mesh_faces_tri[i+2].z);
	        }
	    glEnd();
	    return;
    }

    if (mode == VERTEX_NORMAL){
	    glBegin(GL_TRIANGLES);
	        for (int i = 0; i < mesh_faces_tri.size(); i+=3){
                //draw vertex normal
                glNormal3f(mesh_vertex_normal[mesh_faces_idx[i/3].x].x, mesh_vertex_normal[mesh_faces_idx[i/3].x].y, mesh_vertex_normal[mesh_faces_idx[i/3].x].z);
                glTexCoord2f(mesh_texture_coord[mesh_faces_idx[i/3].x].s,mesh_texture_coord[mesh_faces_idx[i/3].x].t);
                glVertex3f(mesh_faces_tri[i].x, mesh_faces_tri[i].y, mesh_faces_tri[i].z);

                glNormal3f(mesh_vertex_normal[mesh_faces_idx[i/3].y].x, mesh_vertex_normal[mesh_faces_idx[i/3].y].y, mesh_vertex_normal[mesh_faces_idx[i/3].y].z);
                glTexCoord2f(mesh_texture_coord[mesh_faces_idx[i/3].y].s,mesh_texture_coord[mesh_faces_idx[i/3].y].t);
	            glVertex3f(mesh_faces_tri[i+1].x, mesh_faces_tri[i+1].y, mesh_faces_tri[i+1].z);

	            glNormal3f(mesh_vertex_normal[mesh_faces_idx[i/3].z].x, mesh_vertex_normal[mesh_faces_idx[i/3].z].y, mesh_vertex_normal[mesh_faces_idx[i/3].z].z);
                glTexCoord2f(mesh_texture_coord[mesh_faces_idx[i/3].z].s,mesh_texture_coord[mesh_faces_idx[i/3].z].t);
	            glVertex3f(mesh_faces_tri[i+2].x, mesh_faces_tri[i+2].y, mesh_faces_tri[i+2].z);
	        }
	    glEnd();
    }

	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_GEN_R);
}
*/
/*
void Mesh3d::calculate_ymax(){
    GLfloat temp = mesh_vertices[0].y;
    for (int i = 0; i < mesh_vertices.size(); i++){
        if(mesh_vertices[i].y > temp)
            temp = mesh_vertices[i].y;
    }
    ymax = temp;
}
*/
