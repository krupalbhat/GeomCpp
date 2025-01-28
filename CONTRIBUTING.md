
# Contributing to GeomCPP

Thank you for considering contributing to GeomCPP! We welcome contributions that improve the library's functionality, add new geometric features, or enhance the existing codebase. This document will guide you on how to contribute.

## How to Contribute
1. Fork the repository on GitHub.
2. Create a new branch (git checkout -b feature-name).
3. Make your changes or add features.
4. Write unit tests (if applicable) for your changes.
5. Commit your changes (git commit -am 'Add new feature').
6. Push to your fork (git push origin feature-name).
7. Create a pull request describing your changes.

## Features to Add
1. Point Class

- Point Operations:
    - Add functions like midpoint (to calculate the midpoint between two points).
    - Implement more distance measures, such as Manhattan distance or Chebyshev distance.
    - Provide functionality for scaling a point.

2. Vector Class

- Cross Product:
    - Implement the cross product for 3D vectors.
- Normalization:
    - Add a method to normalize vectors (unit vectors).
- Angle Between Vectors:
    - Add a method to compute the angle between two vectors using dot product.
- Projection:
    - Add functionality to project one vector onto another.

3. Geometric Operations

- Convex Hull:
    - Implement algorithms like Graham Scan or QuickHull for computing the convex hull of a set of points.
- Dot Product:
    - Ensure that dot products can be computed efficiently for points and vectors in any dimension.
- Angle Calculation:
    - Compute the angle between vectors (both in 2D and 3D).
- Line Intersection:
    - Implement an algorithm to check if two lines (represented by points) intersect.

4. Higher-Dimensional Support
- Extend support for points, vectors, and operations to 4D+ spaces.
- Implement hyperplanes in higher-dimensional spaces.

5. Additional Geometric Structures

- **Lines:** Define classes for lines and implement geometric operations like intersection and distance to a point.
- **Circles and Spheres:** Implement classes for circles (2D) and spheres (3D) with operations like area and volume calculations, intersection with other shapes, etc.
- **Polygons:** Add support for polygons (e.g., triangles, rectangles, polygons in arbitrary dimensions), including area and perimeter calculations, and checks for convexity.

6. Algorithms
- **Voronoi Diagrams**: Implement a Voronoi diagram generator for a set of points.
- **Delaunay Triangulation:** Add functionality for Delaunay triangulation in 2D and higher dimensions.


## Code Style

- Please follow the Google C++ Style Guide when making changes.
- Include appropriate documentation and comments in your code.
- Write unit tests for new features and bug fixes.

## Reporting Issues

If you find any bugs or issues, please open an issue on GitHub and provide a detailed description of the problem.
