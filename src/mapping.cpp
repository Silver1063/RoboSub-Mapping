#include <iostream>
#include <vector>

#include "./mapping.hpp"

using namespace std;

Mapping::Mapping()
{

    int x = 3; // 50;
    int y = 3; // 25;
    int z = 3; // 2;

    vector<vector<vector<MapCell *>>> map(z, vector<vector<MapCell *>>(y, vector<MapCell *>(x, nullptr)));

    int all = x * y * z;

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            for (int k = 0; k < map[i][j].size(); k++)
            {
                MapCell *new_cell = new MapCell;
                new_cell->shape = SDF_CUBE;
                new_cell->transform = Matrix4f::Identity();
                // new_cell->tags = "asdfasdfasdfasdfasf";
                map[i][j][k] = new_cell;
            }
        }
    }

    //
    //
    // topographic map
    // Graph<MapCell>

    // use pointers for cells so that changes are reflected in both maps

    // path finding A*star manhattan distance using array shape?

    // need to correct for dead reckoning
    // what sensors do we have, what will localization take care of?
    // loop closure correct the space at least once?

    // what am i getting from localization/computer vision,
    // what am i giving to everyone else

    // ros2 messages

    std::cout << map.capacity() << std::endl;
    std::cout << map[0].capacity() << std::endl;
    std::cout << map[0][0].capacity() << std::endl;
    std::cout << sizeof(map) << std::endl;

    Vector3f a(1, 1, 1);
    Vector3f b(1, 1, 1);

    sdf_box(a, b);
}

Mapping::~Mapping()
{
    std::cout << "kbyeeeee" << std::endl;
}

float Mapping::sdf_box(Vector3f p, Vector3f b, Matrix4f t)
{
    //
    // p = p * t.inverse();
    Vector3f q = p.cwiseAbs() - b;
    return fmax(q.norm(), 0.0) + fmin(fmax(q.x(), fmax(q.y(), q.z())), 0.0);
}