#ifndef SRC_MODEL_READER_READER_H_
#define SRC_MODEL_READER_READER_H_

#include <fstream>

#include "../field/field.h"

class Reader {
  protected:

    std::ifstream ifs_;

  public:
    void open(const char* file) {
      ifs_ = std::ifstream(file);
    }

    void close() {
      ifs_.close();
    }

    virtual Field* read()=0;

    virtual ~Reader() = default;
};

class MazeReader: public Reader {

  private:
    MazeField* ReadSize() {
      int cols = 0;
      int rows = 0;
      if (ifs_ >> cols) {
        if (ifs_ >> rows) {
          MazeField* maze = new MazeField(cols, rows);
          return maze;
        }
      }
      throw std::invalid_argument("Can't read from file\n");
    }

    void ReadRightBorder(MazeField& maze) {
      for (int i = 0; i < maze.GetRows(); ++i) {
        for (int j = 0; j < maze.GetCols(); ++j) {
          int x = 0;
          if (ifs_ >> x) {
            if (x > 0) maze.SetRightBorder(i,j);
          } else {
            throw std::invalid_argument("Can't read from file\n");
          }
        }
      }
    }

    void ReadDownBorder(MazeField& maze) {
      for (int i = 0; i < maze.GetRows(); ++i) {
        for (int j = 0; j < maze.GetCols(); ++j) {
          int x = 0;
          if (ifs_ >> x) {
            if (x > 0) maze.SetDownBorder(i,j);
          } else {
            throw std::invalid_argument("Can't read from file\n");
          }
        }
      }
    }

  public:

  MazeReader() = default;

  MazeReader(const char* file_name) {
    open(file_name);
    if (!ifs_.is_open()) throw std::invalid_argument("Can't open file\n");
  }

  Field* read() {
    MazeField* maze = ReadSize();
    ReadRightBorder(*maze);
    ReadDownBorder(*maze);
    return maze;
  }

  ~MazeReader() {
    close();
  }
};

#endif
