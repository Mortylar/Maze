#include "model.h"

std::vector<Line> Model::LoadMaze(const char* file_name) {
  Clear();
  MazeReader reader(file_name);
  std::cout << "Model file " << file_name << std::endl;
  maze_ = dynamic_cast<MazeField*>(reader.read());
  std::cout << "Rows Cols" << maze_->GetRows() << maze_->GetCols() << std::endl;
  std::cout << std::endl;
  maze_->print();
  MazeForm form(maze_);
  std::cout << "Next Count " << std::endl;
  form.Count();
  std::cout << "Counted " << std::endl;
  return form.GetForm(); 
}
