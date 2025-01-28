#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <initializer_list>
#include <stdexcept>
#include <type_traits>
#include <concepts>

namespace GeomCPP
{

    template <typename T>
    concept point_numeric = std::is_arithmetic_v<T>;

    template <typename T, size_t Dim>
    struct point_traits
    {
        static void add(std::vector<T> &result, const std::vector<T> &p1, const std::vector<T> &p2)
        {
            result.resize(Dim);
            for (size_t i = 0; i < Dim; ++i)
            {
                result[i] = p1[i] + p2[i];
            }
        }

        static T dot(const std::vector<T> &p1, const std::vector<T> &p2)
        {
            T result = 0;
            for (size_t i = 0; i < Dim; ++i)
            {
                result += p1[i] * p2[i];
            }
            return result;
        }

        static T distance(const std::vector<T> &p1, const std::vector<T> &p2)
        {
            T dist = 0;
            for (size_t i = 0; i < Dim; ++i)
            {
                dist += (p1[i] - p2[i]) * (p1[i] - p2[i]);
            }
            return std::sqrt(dist);
        }
       
    };

}
