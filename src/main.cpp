#include <flecs.h>

struct Position {
  float x, y;
};

int main(int argc, char *argv[]) {
  flecs::world ecs;

  ecs.system<Position>()
    .each([](Position& pos) {
      pos.x += 0;
      pos.y += 0;
    });

  auto e = ecs.entity()
    .set([](Position& pos) {
      pos = {10, 20};
    });

  while (true)
  {
    if (!ecs.progress()) {
      return 1;
    }
  }

  return 0;
}
