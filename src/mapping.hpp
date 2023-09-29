#ifndef MAPPING_HPP
#define MAPPING_HPP

#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

class Mapping
{
public:
  Mapping();
  ~Mapping();

  float sdf_box(Vector3f p, Vector3f b, Matrix4f t = Matrix4f::Identity());

private:
  Matrix4f transform = Matrix4f::Identity();
  
  void ready();
  void update();
  

  struct map_cell
  {
    char tag = 't';
    Matrix4f transform;
  };
};

#endif