#include "reader.h"
#include "../field/field.h"

int main() {
  //MazeReader reader("../example");

  MazeReader reader("../examp");
  Field* f = reader.read();
  f->print();
  delete f;

  return 0;
}
