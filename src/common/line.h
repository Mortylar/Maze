#ifndef SRC_COMMON_LINE_H_
#define SRC_COMMON_LINE_H_

#include "point.h"

class Line {
  private:
    Point x_;
    Point y_;

    void Copy(const Line& other) noexcept {
      x_ = other.x_;
      y_ = other.y_;
    }
    
    void SetDefault() noexcept {
      x_ = Point();
      y_ = Point();
    }


  public:

    Line(Point x = Point(), Point y = Point()): x_(x), y_(y) {};

    Line(const Line& other) {
      if (this != &other) {
        Copy(other);
      } else {
        SetDefault();
      }
    }

    Line(Line&& other) { 
      if (this != &other) {
        Copy(other);
      } else {
        SetDefault();
      }
    }

    Line& operator=(const Line& other) {
      Copy(other);
      return *this;
    }

    Line& operator=(Line& other) {
      Copy(other);
      return *this;
    }

    bool operator==(const Line& other) const {
      return (x_ == other.x_) && (y_ == other.y_);
    }

    Line& Move(const float dx, const float dy) {
      x_.Move(dx, dy);
      y_.Move(dx, dy);
      return *this;
    }

    Point GetX() const {
      return x_;
    }

    Point GetY() const {
      return y_;
    }
    void Print() {
      std::cout << "Line ((" << x_.GetX() << "; " << x_.GetY() << "), ";
      std::cout << "(" << y_.GetX() << "; " << y_.GetY() << ")" << std::endl;
    }
};

#endif
