#include "EntityManager.h"
#include "Components.h"

class Simulation
{
  public:
    Simulation();
    ~Simulation();
    void DoTick(int time);
  private:
    EntityManager entity_manager;
    Components components;
};
