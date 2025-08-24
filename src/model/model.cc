#include "model.h"

std::vector<Line>& Model::LoadMaze(const char* file_name) {
  Clear();
  MazeReader reader(file_name);
  maze_ = dynamic_cast<MazeField*>(reader.read());
  MazeForm form(maze_);
  form.Count();
  return form.GetForm(); 
}
