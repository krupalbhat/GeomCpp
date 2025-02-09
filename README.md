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
#include "./GeomCpp/Core/Point.hpp"

using namespace GeomCPP;

int main()
{
    // Create 3D points
    Point<double, 3> p1 = {{1.1, 2.2, 3.3}};
    Point<double, 3> p2 = {{4.0, 5.0, 6.0}};

    Point<double, 3> p3 = p1 + p2;
    std::cout << "Sum: ";
    p3.print(); 

    double dot_result = p1.dot(p2);
    std::cout << "Dot product: " << dot_result << "\n"; 

    double dist = p1.distance(p2);
    std::cout << "Distance: " << dist << "\n"; 

    std::cout << "Scaling p1 by 3.4: \n";
    p1.scale(3.4);
    p1.print(); 

    using Point_2D = Point<double, 2>;

    std::cout << "Collinear test: "
              << Point_2D::collinear(Point_2D({1, 1}), Point_2D({2, 2}), Point_2D({3, 3}))
              << "\n"; // Expected output: 1 (true)

    // Iterate over coordinates using range-based for loop
    std::cout << "Coordinates of p2: ";
    for (const auto &coord : p2)
    {
        std::cout << coord << " ";
    }
    std::cout << std::endl;

    return 0;
}
```