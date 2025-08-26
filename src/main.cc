#include "model/model.h"
#include "controller/controller.h"
#include "view/view.h"

int main(int argc, char** argv) {
  Model model;
  Controller controller(&model);
  View view(&controller);
  return view.run(argc, argv);
}
