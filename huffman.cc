include "huffman.hh"


Huffman::Huffman(){

}

Huffman::~Huffman(){

}

Huffman::bits_t Huffman::encode(int symbol){

}

int Huffman::decode(bool bit){

}

HForest::HForest Huffman::build_forest(){
  //intiialize a forest of leaves (trees with one elt)
  //Each leaf has key = symbol (ie character), value = frequency
    //get frequency from current frequency table of the object
  //return forest
  Hforest huff_forest;   //iterate through frequency table vector?
  for (int i = 0, i < 256, i++){
    huff_forest.add_tree(HTree(i,freq_table[i]));
  }
  huff_forest.add_tree(HTree(HEOF, 1));
  return huff_forest;
}
