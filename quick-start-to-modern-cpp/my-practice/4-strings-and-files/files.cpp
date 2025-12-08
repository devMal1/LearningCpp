#include <iostream>
#include <fstream>
#include <string_view>

struct PlayerData {
    std::string name;
    std::string team;
    char position[3u];
};

void printPlayer(const PlayerData &player) {
    std::cout << player.name << " (" << player.position << ") for " << player.team << std::endl;
}

// F I L E S - I N P U T
/*
You do not need to explicitly close the file because in this case it will get closed on deconstruction (when the function returns)
*/
int writeToTextFile(std::string_view filepath, std::string_view data) {
    auto file = std::ofstream{};

    file.open(filepath.data(), std::ios::out | std::ios::app); // write to the file | append to the file
    if (file.fail()) {
        return 1;
    }

    file << data << std::endl;

    if (!file.good()) {
        return 1;
    }

    return 0;
}

int writeToBinFile(std::string_view filepath, const PlayerData &data) {
    auto file = std::ofstream{};

    file.open(filepath.data(), std::ios::out | std::ios::binary); // write to file | binary file
    if (file.fail()) {
        return 1;
    }

    // write expects its first argument to be of char *, so we need to cast the data to this
    file.write((char *)&data, sizeof(PlayerData));

    if (!file.good()) {
        return 1;
    }

    return 0;
}

// F I L E S - O U T P U T
int readFromBinFile(std::string_view filepath, PlayerData &data) {
    auto file = std::ifstream{};

    file.open(filepath.data(), std::ios::in | std::ios::binary); // read from file | binary file
    if (file.fail()) {
        return 1;
    }

    // read expects its first argument to be of char *, so we need to cast the data to this
    file.read((char *)&data, sizeof(PlayerData));

    if (!file.good()) {
        return 1;
    }

    return 0;
}

int main() {
    const auto filepath = std::string{"text.txt"};
    const auto message = std::string{"Hello world in this text file!"};
    writeToTextFile(filepath, message);

    const auto player = PlayerData{.name="Malik Malone", .position="PG", .team="Remnantites"};
    writeToBinFile("playerdata.bin", player);

    auto playerFromFile = PlayerData{};
    readFromBinFile("playerdata.bin", playerFromFile);
    printPlayer(playerFromFile);

    return 0;
}
