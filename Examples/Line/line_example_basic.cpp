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
