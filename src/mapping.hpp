#ifndef MAPPING_HPP
#define MAPPING_HPP

class Mapping
{
  public:
    Mapping();
    ~Mapping();

  private:
    int test = 10;
    int function_placeholder(int arg);
    struct map_cell
    {
        char tag = 't';
    };
};

#endif