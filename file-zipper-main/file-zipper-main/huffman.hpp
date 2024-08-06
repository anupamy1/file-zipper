#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <string>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

// Define Huffman Tree Node
struct Node {
    char data;            // Character data
    unsigned freq;        // Frequency of the character
    string code;          // Huffman code for the character
    Node *left, *right;   // Pointers to left and right children

    // Default constructor
    Node() : data(0), freq(0), code(""), left(nullptr), right(nullptr) {}
};

// Huffman coding class
class huffman {
private:
    vector<Node*> arr;                          // Array of nodes for ASCII characters
    fstream inFile, outFile;                    // File streams for input and output
    string inFileName, outFileName;             // Input and output file names
    Node *root;                                 // Root of the Huffman tree

    // Comparison class for priority queue
    class Compare {
    public:
        bool operator()(Node* l, Node* r) {
            return l->freq > r->freq;
        }
    };

    priority_queue<Node*, vector<Node*>, Compare> minHeap; // Min-heap for Huffman tree

    // Initialize array of nodes
    void createArr();

    // Traverse the Huffman tree and assign codes to characters
    void traverse(Node*, string);

    // Convert binary string to decimal integer
    int binToDec(string);

    // Convert decimal integer to binary string
    string decToBin(int);

    // Build Huffman tree from the given path and character
    void buildTree(char, string&);

    // Create min-heap from character frequencies
    void createMinHeap();

    // Build the Huffman tree
    void createTree();

    // Generate Huffman codes for each character
    void createCodes();

    // Save encoded data to the output file
    void saveEncodedFile();

    // Read the Huffman tree from the file
    void getTree();

    // Decode the input file and save the result
    void saveDecodedFile();

public:
    // Constructor to initialize file names and create array
    huffman(string inFileName, string outFileName)
        : inFileName(inFileName), outFileName(outFileName), root(nullptr) {
        createArr();
    }

    // Compress the input file
    void compress();

    // Decompress the input file
    void decompress();
};

#endif // HUFFMAN_HPP
