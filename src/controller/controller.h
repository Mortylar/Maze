#ifndef SRC_CONTROLLER_CONTROLLER_H_
#define SRC_CONTROLLER_CONTROLLER_H_

#include "../model/model.h"

class Controller {
  private:
    Model* model_;

  public:
    Controller(Model* model): model_(model) {};

    std::vector<Line> Load(const char* file) {
      return model_->LoadMaze(file);
    }

    ~Controller() {if (model_) delete model_;}

};


#endif
