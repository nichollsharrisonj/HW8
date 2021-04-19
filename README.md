### Huffman Encoding

##### Lucas Hamilton and Harrison Nicholls

###### Huffman

- In the private part of the `Huffman` class, we keep a vector of ints called `freq_table` for our frequency table. We also keep a datamember called `currentpath`, which we use during decoding.
- We wrote a `make_tree()` method for Huffman, which is needed by both `decode` and `encode`. `make_tree()` starts by calling `build_forest()` , which simply builds a forest of single trees with appropriate values of frequency taken from `freq_table`. It then removes the two lowest valued trees in this forest, and connects them to form a new tree, which it adds back into the forest.
- We also wrote `convert_path()`, which takes a `path_t` and returns the corresponding list of 1's and 0's.
- `encode`, which is passed a single character, calls `make_tree()`, and finds the path to the character using `path_to()`. It then calls `convert_path()` on the path, returning an encoding of the character. Before the return statement, it also updates the frequency table.
- `decode` also starts by building a tree, and then makes the appropriate step down the tree depending on the provided bit. `decode` can take multiple calls to find the character, so until it has reached a leaf, it returns -1. While it is working, it stores the current state of the path in `currentpath`, as mentioned earlier. When it finally reaches a leaf, it returns the character and updates the frequency table.

###### BitIO

- The private section of Bitio has two sets of data members.
  - The first set has variables to store the istream and ostream
    - One of these will be null in each instance of bitio, and this is ensured to work by asserting the stream exists before trying to output or input bits
  - The second set has variables to hold the current byte, and an index for the byte
    - storedString either stores the current byte which bits are being read from (in input_bit), or the parital byte which is being written to (output_bit)
- The deconstructor for bitio ensures that all bits are written (if the instance is for outputting) by calling output_bit(0) until the currentIndex is 0
  - The index will only be 0 directly after writing to the stream
  - This will put trailing 0's on any unfinished byte
- Output bit reads bits individually until it has 8 in storedString, then writes them
- Input bit reads an entire byte from the stream, and then indexes through them and prints them one at a time
  - When finished with the current byte, it resets the currentIndex to 0 and will read a new byte on the next call.

###### Encoder

- Encoder opens both files and reads byte by byte until it reaches the end of the file
  - for each byte it reads, it encodes the symbol and then writes the encoded version to the Outfile
- once all bytes that are not EOF have been read, both files are closed
- This also checks that both files open and that the input file does not start empty
  - If the input file is empty, it simply closes both files and ends
- It also appends .comp to the filename to create the new file

###### Decoder

- Decoder opens both files and reads byte by byte with bitio until it reaches the end of the file
  - It then iterates through every bit of the byte and uses huffman to decode that bit
    - if the result of decoding is negative, a leaf has not been found and nothing is done
    - if the result of decoding is positive, a leaf has been found and the result is written to the output file
- Once all bytes that are not EOF have been read, both files are closed
- This also checks that both files open and that the input file does not start empty
  - If the input file is empty, it simply closes both files and ends
- .plaintext is appended to the new filename.

###### Compression tests
| File Name               | Size before compression | Compressed file size in bytes | Decompressed file matches raw file exactly |
| ----------------------- | ----------------------- | ----------------------------- | ------------------------------------------ |
| asciiart.txt            | 337                     | 111                           | y                                          |
| htreesourcecode.txt     | 660                     | 437                           | y                                          |
| loremipsum.txt          | 6124                    | 3311                          | y                                          |
| alluniquecharacters.txt | 77                      | 77                            | y                                          |
| makefilesourcecode.txt  | 834                     | 588                           | y                                          |
