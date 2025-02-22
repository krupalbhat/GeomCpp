#pragma once
#include "./Point.hpp"
#include <cmath>
#include <concepts>
#include <stdexcept>

namespace GeomCPP {

template <typename T, size_t Dim>
  requires point_numeric<T>
class Line {
public:
  using point = Point<T, Dim>;
  using iterator = typename std::array<T, Dim>::iterator;
  using const_iterator = typename std::array<T, Dim>::const_iterator;

private:
  point start;
  point end;

public:
  Line(const point &start_point, const point &end_point)
      : start(start_point), end(end_point) {
    if (start == end) {
      throw std::invalid_argument(
          "Start and end points of a line must be distinct.");
    }
  }

  point get_start() const { return start; }
  point get_end() const { return end; }

  T length() const { return start.distance(end); }

  bool contains(const point &p) const {
    auto line_vec = end - start;
    auto point_vec = p - start;

    if (line_vec.magnitude() < 1e-9)
      return false; // Line segment too small to check containment

    // Check if the point vector is a scalar multiple of the line vector
    for (size_t i = 0; i < Dim; ++i) {
      if (std::abs(line_vec[i]) > 1e-9) // Avoid division by zero
      {
        T ratio = point_vec[i] / line_vec[i];
        for (size_t j = 0; j < Dim; ++j) {
          if (std::abs(line_vec[j]) > 1e-9 &&
              std::abs(point_vec[j] / line_vec[j] - ratio) > 1e-9) {
            return false;
          }
        }
        return (ratio >= 0 && ratio <= 1);
      }
    }
    return false;
  }

  bool is_parallel(const Line &other) const {
    auto this_direction = end - start;
    auto other_direction = other.end - other.start;

    for (size_t i = 1; i < Dim; ++i) {
      if (std::abs(this_direction[i] * other_direction[0] -
                   this_direction[0] * other_direction[i]) > 1e-9)
        return false;
    }
    return true;
  }

  bool intersects(const Line &other) const {
    if (is_parallel(other))
      return false;

    auto p1 = start;
    auto p2 = end;
    auto p3 = other.start;
    auto p4 = other.end;

    T denominator =
        (p1[0] - p2[0]) * (p3[1] - p4[1]) - (p1[1] - p2[1]) * (p3[0] - p4[0]);

    if (std::abs(denominator) < 1e-9)
      return false;

    T t = ((p1[0] - p3[0]) * (p3[1] - p4[1]) -
           (p1[1] - p3[1]) * (p3[0] - p4[0])) /
          denominator;

    T u = -((p1[0] - p2[0]) * (p1[1] - p3[1]) -
            (p1[1] - p2[1]) * (p1[0] - p3[0])) /
          denominator;

    return t >= 0 && t <= 1 && u >= 0 && u <= 1;
  }

  void print() const {
    std::cout << "Line from ";
    start.print();
    std::cout << " to ";
    end.print();
  }
};

} // namespace GeomCPP