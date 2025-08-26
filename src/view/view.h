#ifndef SRC_VIEW_VIEW_H_
#define SRC_VIEW_VIEW_H_

#include <QtWidgets/QApplication>

#include "../controller/controller.h"
#include "main_window.h"

class View {
  private:
    Controller* controller_;

  public:
    View(Controller* controller) : controller_(controller) {}

    int run(int argc, char** argv);

    ~View()=default;

};

#endif
