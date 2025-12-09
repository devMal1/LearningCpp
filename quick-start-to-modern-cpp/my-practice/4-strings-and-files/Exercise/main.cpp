#include <sstream>
#include <filesystem>
#include <string>
#include <map>

#include "utils.h"

namespace fs = std::filesystem;

using WordVector = std::vector<std::string>;
using WordCountPair = std::pair<std::string, std::size_t>;
using CountedWordsMap = std::map<std::string, std::size_t>;

/*
    - count the different words from the word vector
    - store the word, occurrence pairs to the map
*/
CountedWordsMap count_words(const WordVector &words) {
    auto counted_words = CountedWordsMap{};

    for (auto &word : words) {
        if (!counted_words.contains(word)) {
            auto word_count_pair = WordCountPair{word, 0};
            counted_words.insert(word_count_pair);
        }

        counted_words[word] += 1;

    }

    return counted_words;
}

WordVector split_text(const std::string &text, char delimiter);

int main() {
    auto current_path = fs::current_path();
    current_path /= "text.txt";

    auto text = readFile(current_path.string());
    std::cout << text << std::endl << std::endl;

    auto splitted_text = split_text(text, ' ');
    print_vector(splitted_text);

    /* Exercise starts here */
    auto counted_words = count_words(splitted_text);
    print_map(counted_words);

    return 0;
}

WordVector split_text(const std::string &text, char delimiter) {
    auto words = WordVector{};

    auto iss = std::istringstream{text};
    auto item = std::string{};

    while (std::getline(iss, item, delimiter)) {
        words.push_back(item);
    }

    return words;
}
