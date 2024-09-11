# Huffman-Compression-Algorithm
Overview
This project implements the Huffman Compression Algorithm in C. Huffman coding is a popular method for lossless data compression, which uses variable-length codes to represent symbols based on their frequency of occurrence. The algorithm assigns shorter codes to more frequent symbols and longer codes to less frequent ones, minimizing the overall file size.

Features
Compress any text file using Huffman coding
Decompress a Huffman-encoded file
Simple and efficient implementation using priority queues (min-heaps) and binary trees
Command-line interface for ease of use
Prerequisites
To compile and run this program, you'll need:

A C compiler (e.g., GCC)
Basic understanding of command-line operations
Installation
Clone this repository:

bash
Copy code
git clone https://github.com/username/huffman-compression.git
cd huffman-compression
Compile the program:

bash
Copy code
gcc -o huffman huffman.c
Usage
Compression
To compress a text file:

bash
Copy code
./huffman -c input.txt output.huff
-c: Flag for compression
input.txt: The file to compress
output.huff: The compressed output file
Decompression
To decompress a Huffman-encoded file:

bash
Copy code
./huffman -d input.huff output.txt
-d: Flag for decompression
input.huff: The compressed file to decompress
output.txt: The decompressed output file
