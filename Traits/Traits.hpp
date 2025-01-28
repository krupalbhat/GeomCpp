#include <iostream>
#include <concepts>
#include <type_traits>
#include <vector>

template <typename T>
concept same_length_vectors = requires(const std::vector<T> &v1,
                                       const std::vector<T> &v2, const std::vector<T> &v3) {
    { v1.size() } -> std::convertible_to<size_t>;
    { v2.size() } -> std::convertible_to<size_t>;
    { v3.size() } -> std::convertible_to<size_t>;

    requires v1.size() == v2.size() && v2.size() == v3.size();
};
