#include <iostream>
#include "./Core/Point.hpp"


using namespace GeomCPP;

int main() {
    // Create 3D points
    Point<double, 3> p1 = {{1.1, 2.2, 3.3}};
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

    std::cout << "Multiplying by scalar 3: \n";
    p1.scale(3);
    p1.print();

    return 0;
}
