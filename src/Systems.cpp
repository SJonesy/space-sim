#include "Systems.h"

bool Systems::StressTest(const EntityManager& entity_manager){
  // testing entity creation
  for (int j= 0; j<= 3; j++)
  {
    for (int i = 0; i<=60000; i++)
    {
      uint16 entity_id = entity_manager.CreateEntity();
      components.position[entity_id] = Position{0,0};
      components.is_destroyed[entity_id] = false;
    }
    
    // "system"
    for (int i=0; i<=entity_manager.HighestID(); i++)
    {
      components.position[i].x++;
      components.position[i].y++;
    }

    for (int i=0; i<=entity_manager.HighestID(); i+=2)
    {
      components.is_destroyed[i] = true;
      entity_manager.DestroyEntity(i);
    }
  }

  return true;
}
