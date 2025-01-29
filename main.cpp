#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <limits>

const std::string KEY_FILE = "secret.key";

// Function to generate and save a key
void generateKey() {
    std::ofstream keyFile(KEY_FILE, std::ios::binary);
    if (!keyFile) {
        std::cout << "Error creating key file." << std::endl;
        return;
    }

    srand(static_cast<unsigned>(time(nullptr)));
    std::vector<char> key(32);
    for (auto &c : key) {
        c = static_cast<char>(rand() % 256);
    }

    keyFile.write(key.data(), key.size());
    std::cout << "Encryption key generated and saved as '" << KEY_FILE << "'." << std::endl;
}

// Function to load the key
std::vector<char> loadKey() {
    std::ifstream keyFile(KEY_FILE, std::ios::binary);
    if (!keyFile) {
        std::cout << "Key file '" << KEY_FILE << "' not found. Please generate a key first." << std::endl;
        return {};
    }

    std::vector<char> key(32);
    keyFile.read(key.data(), key.size());
    if (keyFile.gcount() != 32) {
        std::cout << "Key file is incomplete or corrupted. Please generate a new key." << std::endl;
        return {};
    }

    return key;
}

// Function to XOR the data with the key
void xorData(std::vector<char> &data, const std::vector<char> &key) {
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] ^= key[i % key.size()];
    }
}

// Function to encrypt a file
void encryptFile(const std::string &filePath, const std::vector<char> &key) {
    if (!std::filesystem::exists(filePath)) {
        std::cout << "File '" << filePath << "' does not exist." << std::endl;
        return;
    }

    std::ifstream inputFile(filePath, std::ios::binary);
    if (!inputFile) {
        std::cout << "Error opening file '" << filePath << "' for reading." << std::endl;
        return;
    }

    std::vector<char> data((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    if (data.empty()) {
        std::cout << "File '" << filePath << "' is empty or could not be read." << std::endl;
        return;
    }

    xorData(data, key);

    std::ofstream outputFile(filePath, std::ios::binary);
    if (!outputFile) {
        std::cout << "Error opening file '" << filePath << "' for writing." << std::endl;
        return;
    }

    outputFile.write(data.data(), data.size());
    std::cout << "File '" << filePath << "' encrypted successfully." << std::endl;
}

// Function to decrypt a file
void decryptFile(const std::string &filePath, const std::vector<char> &key) {
    encryptFile(filePath, key); // XOR operation is symmetric
    std::cout << "File '" << filePath << "' decrypted successfully." << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "No command provided." << std::endl;
        return 1;
    }

    int choice = std::atoi(argv[1]);

    if (choice == 1) {
        generateKey();
    } else if (choice == 2 && argc == 3) {
        std::string filePath = argv[2];
        auto key = loadKey();
        if (key.empty()) {
            std::cerr << "Key loading failed." << std::endl;
            return 1;
        }
        encryptFile(filePath, key);
    } else if (choice == 3 && argc == 3) {
        std::string filePath = argv[2];
        auto key = loadKey();
        if (key.empty()) {
            std::cerr << "Key loading failed." << std::endl;
            return 1;
        }
        decryptFile(filePath, key);
    } else {
        std::cerr << "Invalid command or arguments." << std::endl;
        return 1;
    }

    return 0;
}