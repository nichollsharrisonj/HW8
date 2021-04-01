include "huffman.hh"


Huffman::Huffman(){

}

Huffman::~Huffman(){

}

Huffman::bits_t Huffman::encode(int symbol){
  //make a forest, then make the tree
  //tree.path_to(symbol) convert to bits_t
  //update freq table
  HTree huff_tree = make_tree();

  HTree::path_t path = huff_tree.path_to(symbol);

  bits_t out(path.length(),0);  // make a vector of 1s and 0s initialized to 0
  for (int i = 0, i < path.length(), i++){
    if (dir == HTree::Direction::RIGHT){
    //put 1 in vector if direction is right
    //intiailized to all be 0, so don't need to change anything for lefts
    }
  }

  return out;

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

HTree::HTree Huffman::make_tree(){
  //do the huffman algorithm to make a tree from a forest
}
