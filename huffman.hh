/*
 * Huffman: a class to encode and decode symbols based on adaptive Huffman coding
 * https://en.wikipedia.org/wiki/Huffman_coding
 */

#pragma once

#include <climits>
#include <vector>

#include "htree.hh"
#include "hforest.hh"

class Huffman {
 public:
  // Maximum number of symbols we need to encode (a symbol fits in a char) + EOF
  static const int ALPHABET_SIZE = (1 << CHAR_BIT) + 1;  // (2 ** 8) + 1
  static const int HEOF = ALPHABET_SIZE - 1;  // Special symbol to denote end of file

  using bits_t = std::vector<bool>;
  using path_t = HTree::path_t;

  Huffman();
  ~Huffman();
  Huffman(const Huffman&) = delete;
  Huffman(Huffman&&) = delete;
  Huffman& operator=(const Huffman&) = delete;
  Huffman& operator=(Huffman&&) = delete;

  // Encode a symbol into a sequence of bits, then update frequency table.
  bits_t encode(int symbol);

  // Decode a single bit into a symbol. If no symbol can be unmabiguously decoded
  // without additional bits, returns a negative value.
  // Subsequent calls with more bits should eventually resolve to either
  // a character symbol or HEOF.
  // Finally, updates the frequency table with this additional symbol.
  int decode(bool bit);
private:
  //HTree huffTree;
  std::vector<int> freq_table;     //vector[symbol] is the frequency for symbol

  HForest build_forest();    //this function will build an HForest of leaves from a frequency_table

  HTree::tree_ptr_t make_tree();      //makes a huffman tree for the current frequency table

  bits_t convert_path(path_t path);     //since we need to convert strings from path_t to bits_t in encode and decode, seperating it means we only write it once
};
