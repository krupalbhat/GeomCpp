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
#include "./GeomCpp/Visualizer/Visualizer.hpp"

namespace gp = GeomCPP;

int main()
{
    // Create 2D points
    gp::Point<double, 2> p1 = {{100.1, 200.2}};
    gp::Point<double, 2> p2 = {{400.0, 500.0}};

    gp::Point<double, 2> p3 = p1 + p2;
    std::cout << "Sum: ";
    p3.print();

    double dot_result = p1.dot(p2);
    std::cout << "Dot product: " << dot_result << "\n";

    double dist = p1.distance(p2);
    std::cout << "Distance: " << dist << "\n";

    std::cout << "Scaling p1 by 1.4: \n";
    p1.scale(1.4);
    p1.print();

    using Point_2D = gp::Point<double, 2>;

    std::cout << "Collinear test: "
              << Point_2D::collinear(Point_2D({1.0, 1}), Point_2D({2.0, 2.0}), Point_2D({3.0, 3.0}))
              << "\n"; // Expected output: 1 (true)

    std::cout << "Coordinates of p2: ";
    for (const auto &coord : p2)
    {
        std::cout << coord << " ";
    }
    std::cout << std::endl;
    gp::Visualizer vis;

    vis.addPoint(p1);
    vis.addPoint(p2);
    vis.addPoint(p3);
    vis.run();
    return 0;
}
```
## Compiling and running
GeomCPP Requires SFML for visualization as adepencency, so make sure you have it before you run the visualizer. Running visualizer is not mandatory, you can use the ``GeomCPP`` classes as a standalone entity, in that case you wont need the SFML library.
```bash
    g++ test.cpp -o geom_cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++20 && ./geom_cpp
```
