#ifndef SPATIAL_MAP_HPP
#define SPATIAL_MAP_HPP

#include <vector>

#include <Eigen/Dense>

template <typename T>
class SpatialMap {
public:
    SpatialMap(int x = 4, int y = 4, int z = 4);
    ~SpatialMap();

    void set(int x, int y, int z, T* value);
    T* get(int x, int y, int z);

    void resize(int x, int y, int z);
    int size();
    int size(int axis);

    void print();

private:
    Eigen::Vector3i size_xyz;

    std::vector<T> data;
    T* layout;
};

#endif