#ifndef SPACE_SIM_COMPONENTS_H
#define SPACE_SIM_COMPONENTS_H

struct Position
{
  int x;
  int y;
};

class Components
{
  public:
    Components();
    ~Components();
    Position* position;
    bool* is_destroyed;
  private:

};

#endif
