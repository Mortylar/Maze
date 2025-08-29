#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include <vector>

#include "field/field.h"
#include "field/maze_form.h"
#include "reader/reader.h"
#include "../common/line.h"

class Model {
  private:
    MazeField* maze_ = nullptr;

    void Clear() { if (maze_) delete maze_; }

  public:
    Model() = default;

    std::vector<Line> LoadMaze(const char* file_name);

    ~Model() { Clear(); }
};


#endif
