#ifndef SRC_COMMON_POINT_H_
#define SRC_COMMON_POINT_H_

#include <iostream>  //TODO remove

class Point {

  private:
    float x_;
    float y_;

    void Copy(const Point& other) noexcept {
      x_ = other.x_;
      y_ = other.y_;
    }

    bool IsEqualsFloats(float first, float second) const {
      const float k_ANTI_EPS = 10e-6;
      return ((std::abs(first - second) * k_ANTI_EPS)) <=
             std::min(std::abs(first), std::abs(second));
    }


  public:
    Point(float x = 0.0f, float y = 0.0f): x_(x), y_(y) {}

    Point(const Point& other) {
      if (this != &other) {
        Copy(other);
      } else {
        x_ = y_ = 0.0f;
      }
    }

    Point(Point&& other) {
      if (this != &other) {
        Copy(other);
      } else {
        x_ = y_ = 0.0f;
      }
    }

    Point& operator=(const Point& other) {
      Copy(other);
      return *this;
    }

    Point& operator=(Point&& other) {
      Copy(other);
      return *this;
    }

    void Print() { //TODO remove
      std::cout << "(" << x_ << ", " << y_ << ")" << std::endl;
    }

    bool operator==(const Point& other) const {
      return IsEqualsFloats(x_, other.x_) && IsEqualsFloats(y_, other.y_);
    }

    Point& Move(const float dx, const float dy) {
      x_ += dx;
      y_ += dy;
      return *this;
    }

    float GetX() const {
      return x_;
    }

    float GetY() const {
      return y_;
    }

    void SetX(float value) {
      x_ = value;
    }

    void SetY(float value) {
      y_ = value;
    }

};



#endif
