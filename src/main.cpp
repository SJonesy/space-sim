#include "EntityManager.h"

struct Position
{
  int x;
  int y;
};

struct Components
{
  Position* position;
  bool* is_destroyed;
};

int main(int argc, char *argv[]) 
{
  EntityManager entity_manager;

  Components components;
  components.position = new Position[MAX_ENTITIES]();
  components.is_destroyed = new bool[MAX_ENTITIES]();

  uint16 entity_id = entity_manager.CreateEntity();
  components.position[entity_id] = Position{0,0};
  components.is_destroyed[entity_id] = false;

  // "system"
  for (int i=0; i<=entity_manager.HighestID(); i++)
  {
    components.position[i].x++;
    components.position[i].y++;
  }

  components.is_destroyed[entity_id] = true;
  entity_manager.DestroyEntity(entity_id);

  delete[] components.position;
  delete[] components.is_destroyed;
  return 0;
}
