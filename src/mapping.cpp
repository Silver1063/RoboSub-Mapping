#include "./mapping.hpp"

Mapping::Mapping()
{
    std::cout << transform << std::endl;

    Vector3f a;
    a << 1, 1, 1;
    Vector3f b;
    b << 2, 3, -1;

    sdf_box(a, b);
}

Mapping::~Mapping()
{
    std::cout << "kbyeeeee" << std::endl;
}

float Mapping::sdf_box(Vector3f p, Vector3f b)
{
    Vector3f q = p.cwiseAbs() - b;
    std::cout << q << std::endl;
    return 0.0;
}