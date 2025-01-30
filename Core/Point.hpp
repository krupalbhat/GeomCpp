#pragma once
#include "Point_traits.hpp"
#include <iterator>
namespace GeomCPP
{

    template <typename T, size_t Dim>
        requires point_numeric<T>
    class Point
    {
        using point = Point<T, Dim>;

        std::vector<T> coordinates;

    public:
        auto begin() { return coordinates.begin(); }
        auto end() { return coordinates.end(); }
        Point(std::vector<T> init) : coordinates(init)
        {
            // std::cout << "Initializer list size: " << init.size() << std::endl;
            // std::cout << "Vector size: " << coordinates.size() << std::endl;
            if (coordinates.size() != Dim)
            {
                throw std::invalid_argument("Incorrect number of coordinates.");
            }
        }

        point operator+(const point &other) const
        {
            point result(std::vector<T>(Dim, T{}));

            point_traits<T, Dim>::add(result.coordinates, coordinates, other.coordinates);
            return result;
        }

        point operator=(const point &other) const
        {
            point result({});
            result.coordinates = other.coordinates;
            return result;
        }
        T dot(const point &other) const
        {
            return point_traits<T, Dim>::dot(coordinates, other.coordinates);
        }
        constexpr bool operator==(const point &other) const
        {
            for (size_t i = 0; i < Dim; ++i)
            {
                if (std::abs(coordinates[i] - other.coordinates[i]) > 1e-9)
                    return false;
            }
            return true;
        }
        T distance(const point &other) const
        {
            return point_traits<T, Dim>::distance(coordinates, other.coordinates);
        }
        static bool collinear(const std::vector<T> &p1, const std::vector<T> &p2, const std::vector<T> &p3)
        {
            if (p1.size() != p2.size() || p2.size() != p3.size())
            {
                throw std::invalid_argument("All points must have the same dimension.");
            }
            if (p1.size() == 2)
            {
                T determinant = (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0]);
                return std::abs(determinant) < 1e-9;
            }
            return false;
        }
        void print() const
        {
            std::cout << "(";
            for (size_t i = 0; i < Dim; ++i)
            {
                std::cout << coordinates[i];
                if (i < Dim - 1)
                    std::cout << ", ";
            }
            std::cout << ")\n";
        }
    };
}