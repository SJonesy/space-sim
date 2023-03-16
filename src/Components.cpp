#include "Components.h"
#include "EntityManager.h"

Components::Components()
{
  position = new Position[MAX_ENTITIES]();
  is_destroyed = new bool[MAX_ENTITIES]();
}

Components::~Components()
{
  delete[] position;
  delete[] is_destroyed;
}
