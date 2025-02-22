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

## Adding and Visualizing A point
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
![Screenshot_20250210_181118](https://github.com/user-attachments/assets/b4d28684-94e1-4eb2-a82e-82db12dc04f0)

## Adding and Visualizing a Line
```cpp
#include "../../Core/Line.hpp"
#include "../../Core/Point.hpp"
#include <iostream>
#include "../../Visualizer/Visualizer.hpp"

namespace gp = GeomCPP;

int main()
{
    // Define 2D points
    gp::Point<double, 2> p1 = {{100.0, 200.0}};
    gp::Point<double, 2> p2 = {{400.0, 600.0}};
    gp::Point<double, 2> p3 = {{200.0, 300.0}};
    gp::Point<double, 2> p4 = {{500.0, 700.0}};
    gp::Point<double, 2> p5 = {{150.0, 450.0}};
    gp::Point<double, 2> p6 = {{350.0, 250.0}};
    gp::Point<double, 2> p7 = {{450.0, 500.0}};
    gp::Point<double, 2> p8 = {{600.0, 100.0}};

    gp::Line<double, 2> line1(p1, p2);
    gp::Line<double, 2> line2(p3, p4);
    gp::Line<double, 2> line3(p5, p6);
    gp::Line<double, 2> line4(p7, p8);
    gp::Line<double, 2> line5(p2, p8); // Diagonal
    gp::Line<double, 2> line6(p3, p7); 

    std::cout << "Line 1 Length: " << line1.length() << "\n";
    std::cout << "Line 2 Length: " << line2.length() << "\n";
    std::cout << "Line 3 Length: " << line3.length() << "\n";
    std::cout << "Line 4 Length: " << line4.length() << "\n";

    std::cout << "Line1 parallel to Line2? " << line1.is_parallel(line2) << "\n";
    std::cout << "Line3 parallel to Line4? " << line3.is_parallel(line4) << "\n";

    gp::Point<double, 2> test_point = {{2.5, 4.0}};
    std::cout << "Point (2.5, 4.0) on Line1? " << line1.contains(test_point) << "\n";

    gp::Visualizer vis;
    vis.addPoint(p1);vis.addPoint(p2);
    vis.addPoint(p3);vis.addPoint(p4);
    vis.addPoint(p5);vis.addPoint(p6);
    vis.addPoint(p7);vis.addPoint(p8);

    vis.addLine(p1, p2);vis.addLine(p3, p4);
    vis.addLine(p5, p6);vis.addLine(p7, p8);
    vis.addLine(p2, p8);vis.addLine(p3, p7);

    vis.run();

    return 0;
}
```
![Screenshot_20250222_110755](https://github.com/user-attachments/assets/f4390381-468b-47c7-acf6-2bbdec4f7f19)

## Compiling and running
GeomCPP Requires SFML for visualization as adepencency, so make sure you have it before you run the visualizer. Running visualizer is not mandatory, you can use the ``GeomCPP`` classes as a standalone entity, in that case you wont need the SFML library.
```bash
g++ test.cpp -o geom_cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++20 && ./geom_cpp
```
## Running Tests
``GeomCpp`` uses Google's testing framework **GTest** to run tests.

### Step-by-Step Instructions
1. **Navigate to the ``tests`` directory:**
```sh
    cd tests
```
2. **Create a build directory:**
```sh
    mkdir build && cd build
```
3. **Run CMake to configure the project:**
```sh
    cmake ..
```
## Running All Tests
- To build all tests, you can either run:
```sh
    make
```
or
```sh
    make all_tests
```
