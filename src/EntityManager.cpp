#include "EntityManager.h"

#include <cstdio>
#include <cassert>

EntityManager::EntityManager()
{
  entities = new uint16[MAX_ENTITIES];
  for (int i=0; i<=MAX_ENTITIES; i++)
  {
    entities[i] = i;
  }
  highest_id = 0;
  next_id = entities;
}

EntityManager::~EntityManager()
{
  delete[] entities;
}

int EntityManager::CreateEntity()
{
  uint16 id_to_return = *next_id;

  if (*next_id > highest_id)
  {
    highest_id = *next_id;
  }

  assert(*next_id < MAX_ENTITIES);
  next_id++;
  return id_to_return;
}

void EntityManager::DestroyEntity(uint16 entity_id)
{
  if (*next_id == highest_id)
  {
    highest_id--;
  }

  next_id--;
  *next_id = entity_id;
}
