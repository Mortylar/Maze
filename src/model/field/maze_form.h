#ifndef SRC_MODEL_FIELD_MAZE_FORM_H_
#define SRC_MODEL_FIELD_MAZE_FORM_H_

#include <vector>

#include "field.h"
#include "../../common/point.h"
#include "../../common/line.h"

class MazeForm {
  private:
    MazeField* maze_;
    std::vector<Line> form_;

    void SetBorders() {
      form_.push_back(Line(Point(0.0f, 0.0f), Point(0.0f, 1.0f)));
      form_.push_back(Line(Point(0.0f, 0.0f), Point(1.0f, 0.0f)));
      form_.push_back(Line(Point(1.0f, 0.0f), Point(1.0f, 1.0f)));
      form_.push_back(Line(Point(0.0f, 1.0f), Point(1.0f, 1.0f)));
      //TODO Down and Right borders?
    }


  public:
    MazeForm(MazeField* maze): maze_(maze) {
      std::cout << "AAA";
      form_ = std::vector<Line>();
      maze_->print();
      std::cout << "BBB" << std::endl;
    }

    void Count() {
      const float k_DX = 1.0f / maze_->GetCols();
      const float k_DY = 1.0f / maze_->GetRows();
      SetBorders();
      std::cout << "Enter " << std::endl;
      std::cout << "Rows = " << maze_->GetRows() << std::endl;
      std::cout << "Cols = " << maze_->GetCols() << std::endl;
      for (size_t i = 0; i < maze_->GetCols(); ++i) {
        for (size_t j = 0; j < maze_->GetRows(); ++j) {
          float x = i*k_DX;
          float y = j*k_DY;
          if (maze_->IsRightBorder(j,i)) {
            form_.push_back(Line(Point(x + k_DX, y), Point(x + k_DX, y + k_DY)));
          }
          if (maze_->IsDownBorder(j,i)) {
            form_.push_back(Line(Point(x, y + k_DY), Point(x + k_DX, y + k_DY)));
          }
        }
      }
    }

    std::vector<Line> GetForm() {return form_; }

};


#endif
