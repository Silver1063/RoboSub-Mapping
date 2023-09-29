#include "./mapping.hpp"


Mapping::Mapping()
{
    //metric map
    //MapCell map[][][]
    // 
    /*
    
    struct {
        int UID;
        
        int shape = sdfenum.SHAPE
        maybe more than one for complex shapes
        
        Matrix4f transform -> offset, scale rotation etc
        
        tags/attributes -> obstacle, goal, object, terrain etc  
        probably string or enum
        
        
    }
    
    
    */
    //
    //topographic map
    //Vector<MapCell>
    
    //use pointers for cells so that changes are reflected in both maps
    
    //path finding A*star manhattan distance using array shape?
    
    //need to correct for dead reckoning
    //what sensors do we have, what will localization take care of?
    //loop closure correct the space at least once?
    
    
    //what am i getting from localization/computer vision,
    //what am i giving to everyone else
    
    //ros2 messages
    
    
    std::cout << transform << std::endl;

    Vector3f a;
    a << 1, 1, 1;
    Vector3f b;
    b << 1, 1, 1;

    sdf_box(a, b);
}

Mapping::~Mapping()
{
    std::cout << "kbyeeeee" << std::endl;
}

float Mapping::sdf_box(Vector3f p, Vector3f b, Matrix4f t = Matrix4f::Identity())
{
    //p = p * t.inverse();
    Vector3f q = p.cwiseAbs() - b;
    return fmax(q.norm(),0.0) + fmin(fmax(q.x(),fmax(q.y(),q.z())),0.0);
}