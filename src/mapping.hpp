#ifndef MAPPING_HPP
#define MAPPING_HPP

#include <Eigen/Dense>
// #include <Eigen/CXX11/Tensor>

using namespace Eigen;

class Mapping
{
  public:
    enum sdf_type
    {
        SDF_EMPTY,
        SDF_CUBE,
        SDF_SPHERE,
        SDF_TORUS,
    };
    
    //I should probably read the rules for the competition huh?
    enum object_type 
    {
      TERRAIN,
    };

    Mapping();
    ~Mapping();

    float sdf_empty();

    float sdf_box(Vector3f p, Vector3f b, Matrix4f t = Matrix4f::Identity());

    float sdf_sphere();

    float sdf_torus();

  private:
    struct MapCell
    {
        uint8_t shape;
        Matrix4f *transform;
        // std::string tags;
    };

    //LINE HERE LMAO

    Matrix4f transform = Matrix4f::Identity();

    void ready();

    void update();
};

#endif