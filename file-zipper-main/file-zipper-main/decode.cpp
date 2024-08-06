#include <iostream>
#include "huffman.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        return 1; // Return a non-zero value to indicate an error
    }

    // Create a Huffman object with the input and output file names
    try {
        huffman hf(argv[1], argv[2]);
        hf.decompress();
        cout << "Decompressed successfully" << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1; // Return a non-zero value to indicate an error
    }

    return 0; // Return 0 to indicate success
}
