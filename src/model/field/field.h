#ifndef SRC_MODEL_FIELD_FIELD_H_
#define SRC_MODEL_FIELD_FIELD_H_

#include <cstring>
#include <iostream> //TODO remove

class Field {
  private:

  public:
  
    virtual ~Field() = default;
    virtual void print() = 0;
};

class MazeField: public Field {
  private:
    static const char K_RIGHT_BORDER = 1;
    static const char K_DOWN_BORDER = 2;
    char* field_;
    size_t rows_;
    size_t cols_;

    char* Allocate(size_t n) {
      if (n == 0) return nullptr;
      return new char[n]();
    }

    void Clear() noexcept {
      rows_ = 0;
      cols_ = 0;
      delete[] field_;
      field_ = nullptr;
    }

    void Swap(MazeField&& other) noexcept {
      std::swap(rows_, other.rows_);
      std::swap(cols_, other.cols_);
      std::swap(field_, other.field_);
    }

    void Copy(const MazeField& other) {
      rows_ = other.rows_;
      cols_ = other.cols_;
      std::memcpy(field_, other.field_, rows_*cols_);
    }

    char& Get(size_t i, size_t j) const {
      return field_[i * rows_ + j];
    }

  public:

  MazeField(): cols_(0), rows_(0), field_(nullptr) {}

  MazeField(size_t rows, size_t cols): rows_(rows), cols_(cols) {
    field_ = Allocate(rows*cols);
  }

  MazeField(const MazeField& other) {
    if (&other != this) {
      field_ = Allocate(other.rows_ * other.cols_);
      Copy(other);
    } //TODO
  }

  MazeField(MazeField&& other): MazeField() {
    Swap(std::move(other));
    //TODO
  }

  MazeField& operator=(const MazeField& other) {
    if (&other != this) {
      this->Clear();
      Copy(other);
    }
    return *this;
  }

  MazeField& operator=(MazeField&& other) {
    if (&other != this) {
      this->Clear();
      Swap(std::move(other));
    }
    return *this;
  }

  ~MazeField() {
    Clear();
  }

  size_t GetRows() const noexcept { return rows_;}

  size_t GetCols() const noexcept { return cols_; }

  bool SetRightBorder(size_t i, size_t j) {
    if ((i < rows_) && (j < cols_)) {
      Get(i,j) |= K_RIGHT_BORDER;
      return true;
    }
    return false;
  }

  bool SetDownBorder(size_t i, size_t j) {
    if ((i < rows_) && (j < cols_)) {
      Get(i,j) |= K_DOWN_BORDER;
      return true;
    }
    return false;
  }

  bool IsRightBorder(size_t i, size_t j) const {
    if ((i < rows_) && (j < cols_)) {
      return Get(i, j) & K_RIGHT_BORDER;
    }
    return false;
  }

  bool IsDownBorder(size_t i, size_t j) const {
    if ((i < rows_) && (j < cols_)) {
      return Get(i, j) & K_DOWN_BORDER;
    }
    return false;
  }

  void print() { //TODO to_string()
    std::cout << rows_ << "x" << cols_ << std::endl;
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        std::cout << char(field_[i * rows_ + j]  + '0') << " ";
      }
      std::cout << std::endl;
    }
  }

};

#endif
