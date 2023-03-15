#ifndef SPACE_SIM_ENTITY_MANAGER_H
#define SPACE_SIM_ENTITY_MANAGER_H

typedef unsigned short uint16;
typedef unsigned long long uint64;

static const uint16 MAX_ENTITIES=65535;

class ComponentFlags
{
public:
  ComponentFlags();
  ~ComponentFlags();
  bool IsEmpty(){ return BitField==0; }
private:
  uint64 BitField;
};

class EntityManager
{
  public:
    EntityManager();
    ~EntityManager();
    int CreateEntity();
    void DestroyEntity(uint16 id);
    uint16 HighestID(){ return highest_id; }
  private:
    uint16* entities;
    uint16* next_id;
    uint16 highest_id;
};

#endif
