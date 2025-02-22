#pragma once
#include <cmath>
#include <concepts>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <vector>

namespace GeomCPP {
template <typename T>
concept point_numeric = std::is_arithmetic_v<T>;
template <typename T>
concept valid_scalar = std::is_same_v<T, int> || std::is_same_v<T, float> ||
                       std::is_same_v<T, double>;

template <typename P1, typename P2, typename P3>
concept same_length_points = requires {
  requires P1::get_dimensions() ==
               P2::get_dimensions(); // Check dimensions of P1 and P2
  requires P2::get_dimensions() ==
               P3::get_dimensions(); // Check dimensions of P2 and P3
};
} // namespace GeomCPP
