#ifndef SPATIAL_MAP_HPP
#define SPATIAL_MAP_HPP

#include <Eigen/Dense>
#include <iostream>
#include <vector>

template <typename T>
class SpatialMap {
public:
    SpatialMap(int x = 4, int y = 4, int z = 4)
    {
        size_xyz(0) = x;
        size_xyz(1) = y;
        size_xyz(2) = z;

        layout = new T*[x * y * z];
    };

    ~SpatialMap() {};

    void set(int x, int y, int z, T* value)
    {
        layout[x + (y * size_xyz.x()) + (z * size_xyz.x() * size_xyz.y())] = value;
    }

    T* get(int x, int y, int z)
    {
        return layout[x + (y * size_xyz.x()) + (z * size_xyz.x() * size_xyz.y())];
    }

    void resize(int x, int y, int z)
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

    int size()
    {
        return size_xyz.x() * size_xyz.y() * size_xyz.z();
    }

    int size(int axis)
    {
        return size_xyz(axis);
    }

    void print()
    {
        int count = size();

        std::cout << count << std::endl;

        for (int i = 0; i < count; i++) {
            std::cout << *layout[i] << " ";
        }

        std::cout << std::endl;

        // std::cout << std::string(data.begin(), data.end()) << std::endl;
    }

private:
    Eigen::Vector3i size_xyz;

    std::vector<T> data;
    T** layout;
};

#endif