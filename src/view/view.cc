#include "view.h"


int View::run(int argc, char** argv) {
  QApplication app(argc, argv);
  MainWindow window(controller_);
  window.show();
  return app.exec();
}
