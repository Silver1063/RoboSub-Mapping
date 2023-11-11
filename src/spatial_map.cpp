#include <iostream>

#include "./spatial_map.hpp"

template <typename T>
SpatialMap<T>::SpatialMap(int x, int y, int z)
{
    size_xyz(0) = x;
    size_xyz(1) = y;
    size_xyz(2) = z;

    layout = new T*[x * y * z];
}

template <typename T>
SpatialMap<T>::~SpatialMap() { }

template <typename T>
void SpatialMap<T>::set(int x, int y, int z, T* value)
{
    layout[x + (y * size_xyz.x()) + (z * size_xyz.x() * size_xyz.y())] = value;
}

template <typename T>
T* SpatialMap<T>::get(int x, int y, int z)
{
    return layout[x + (y * size_xyz.x()) + (z * size_xyz.x() * size_xyz.y())];
}

template <typename T>
int SpatialMap<T>::size()
{
    return size_xyz.x() * size_xyz.y() * size_xyz.z();
}

template <typename T>
int SpatialMap<T>::size(int axis)
{
    return size_xyz(axis);
}

template <typename T>
void SpatialMap<T>::resize(int x, int y, int z)
{
    int* old_layout = layout;

    // int* new_data = new int[x * y * z];

    // to do copy contents of data into new_data

    layout = new int[x * y * z];

    size_xyz(0) = x;
    size_xyz(1) = y;
    size_xyz(2) = z;

    delete[] old_layout;
}

template <typename T>
void SpatialMap<T>::print()
{
    int count = size();

    std::cout << count << std::endl;

    for (int i = 0; i < count; i++) {
        std::cout << layout[i] << " ";
    }

    std::cout << std::endl;

    // std::cout << std::string(data.begin(), data.end()) << std::endl;
}