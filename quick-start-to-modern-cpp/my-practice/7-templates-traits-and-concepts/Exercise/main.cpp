#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

template <typename T>
struct is_string : public std::is_same<std::string, T> {};

template <typename T>
struct is_view : public std::is_same<std::string_view, T> {};

template <typename StringType, typename ViewType>
struct is_string_and_view : public std::conjunction<is_string<StringType>, is_view<ViewType>> {};

template <typename StringType, typename ViewType>
StringType to_upper_case(ViewType text) {
    static_assert(is_string_and_view<StringType, ViewType>::value, "Only strings and string_views allowed.");

    auto uppercased = StringType{text};
    std::transform(uppercased.begin(), uppercased.end(), uppercased.begin(), toupper);
    return uppercased;
}

template <typename StringType, typename ViewType>
StringType to_lower_case(ViewType text) {
    static_assert(is_string_and_view<StringType, ViewType>::value, "Only strings and string_views allowed.");

    auto lowercased = StringType{text};
    std::transform(lowercased.begin(), lowercased.end(), lowercased.begin(), tolower);
    return lowercased;
}


int main() {
    auto input_text = std::string{};
    std::cout << "Please enter any text: ";
    std::cin >> input_text;

    std::cout << "to_upper_case: " << to_upper_case<std::string, std::string_view>(input_text) << std::endl;
    std::cout << "to_lower_case: " << to_lower_case<std::string, std::string_view>(input_text) << std::endl;

    return 0;
}
