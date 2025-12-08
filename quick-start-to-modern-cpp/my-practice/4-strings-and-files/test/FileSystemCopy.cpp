#include <iostream>
#include <filesystem>

// Creating fs namespace alias is common practice
namespace fs = std::filesystem;

int main() {
    // F I L E  S Y S T E M
    /*
    Works on all three operating systems.
    Available since C++17
    */
    // Create a file path
    auto workspace_path = fs::path{"/Users/Shared"};
    auto test_path = workspace_path;
    // can use this operator to append to the path
    test_path /= "test";
    std::cout << test_path << std::endl;

    // Get the current path
    auto current_path = fs::current_path();
    current_path /= "file_systems.cpp";
    std::cout << current_path << std::endl;

    // Get information about the current path/file
    std::cout << "relative_path: " << current_path.relative_path() << std::endl;
    std::cout << "parent_path: " << current_path.parent_path() << std::endl;
    std::cout << "filename: " << current_path.filename() << std::endl;
    std::cout << "stem: " << current_path.stem() << std::endl;
    std::cout << "extension: " << current_path.extension() << std::endl;

    std::cout << "exists: " << std::boolalpha << fs::exists(current_path) << std::endl;
    std::cout << "is_regular_file: " << std::boolalpha << fs::is_regular_file(current_path) << std::endl;
    std::cout << "id_directory: " << std::boolalpha << fs::is_directory(current_path) << std::endl;

    // Iterate through all folder contents
    for (auto it = fs::directory_iterator(fs::current_path()); it != fs::directory_iterator{}; ++it) {
        std::cout << *it << std::endl;
    }

    // Can create a new directory
    auto new_directory_path = fs::current_path();
    new_directory_path /= "test";
    if (!fs::exists(new_directory_path)) {
        fs::create_directories(new_directory_path);
    }

    // Can copy to a new file
    auto new_file_path = new_directory_path;
    new_file_path /= "FileSystemCopy.cpp";
    if (!fs::exists(new_file_path)) {
        fs::copy_file(current_path, new_file_path);
    }

    return 0;
}
