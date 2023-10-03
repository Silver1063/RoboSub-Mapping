#include <iostream>
#include <vector>

#include "./mapping.hpp"

using namespace std;

Mapping::Mapping()
{

    int ROW = 50;
    int COL = 50;
    int LAY = 10;

    vector<vector<vector<MapCell *>>> map(ROW, vector<vector<MapCell *>>(COL, vector<MapCell *>(LAY)));

    int all = ROW * COL * LAY;

    Matrix4f identity = Matrix4f::Identity();

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            for (int k = 0; k < map[i][j].size(); k++)
            {
                MapCell *new_cell = new MapCell;
                new_cell->shape = SDF_CUBE;
                new_cell->transform = &identity;
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

    int size_in_bytes = sizeof(map) + sizeof(MapCell) * map.size() * map[0].size() * map[0][0].size();

    std::cout << sizeof(MapCell) << " bytes " << std::endl;
    std::cout << size_in_bytes / 1000000.0 << " MB " << std::endl;

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