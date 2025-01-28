# GeomCpp
GeomCpp is a lightweight C++ library focused on providing fundamental geometric operations and algorithms. Designed to offer simple and efficient tools for working with basic geometric shapes.

## Features
- **Point and Vector Representation:**
    - Supports basic 2D and 3D points and vectors.
    - Uses templates to handle different numeric types (e.g., ``double``, ``float``) and dimensions.
- **Geometric Operations:**
    - **Dot Product:** Calculates the dot product between two vectors.
    - **Distance:** Computes the Euclidean distance between two points.
    - **Addition and Subtraction:** Allows vector addition and subtraction.
    - **Collinearity Check:** Determines if three 2D points are collinear.
- **Template-Based Design:**
    - Supports dimensional flexibility via template parameters (e.g., ``Point<T, Dim>`` for points of arbitrary dimensions).
    - Leverages C++ concepts and traits to ensure type safety and proper usage of geometric operations.

## Usage
```cpp
#include <iostream>
#include "Point.hpp"

using namespace GeomCPP;

int main() {
    // Create 3D points
    Point<double, 3> p1 = {{1.0, 2.0, 3.0}};
    Point<double, 3> p2 = {{4.0, 5.0, 6.0}};

    // Add two points
    Point<double, 3> p3 = p1 + p2;
    p3.print();  // Output: (5.0, 7.0, 9.0)

    // Dot product
    double dot_result = p1.dot(p2);
    std::cout << "Dot product: " << dot_result << "\n";  // Output: 32.0

    // Distance between two points
    double dist = p1.distance(p2);
    std::cout << "Distance: " << dist << "\n";  // Output: 5.19615

    using Point_2D = Point<double, 2>;
    std::cout << Point_2D::collinear({1,1}, {2,2}, {3,3}) << "\n";    

    return 0;
}
```