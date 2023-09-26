#include <iostream>
//#include <vector>

#include "../include/mapping.hpp"

Mapping::Mapping()
{
    test=11;
    map_cell new_cell;
    //cell.tag = "test";
    std::cout << "Hello MFer!!!" << std::endl;
}

Mapping::~Mapping()
{
    std::cout << "kbyeeeee" << std::endl;
}

int Mapping::function_placeholder(int arg)
{
    return arg + test;
}