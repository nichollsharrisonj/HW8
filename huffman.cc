#include "huffman.hh"


Huffman::Huffman()
: freq_table(257,0)
{

}

Huffman::~Huffman(){

}

Huffman::bits_t Huffman::encode(int symbol){
  //make a forest, then make the tree
  //tree.path_to(symbol) convert to bits_t
  //update freq table
  HTree huff_tree = make_tree();
  HTree::path_t path = *huff_tree.path_to(symbol);
  freq_table[symbol]++;

  return convert_path(path);
}

Huffman::bits_t Huffman::convert_path(path_t path){
  bits_t out(path.size(), 0);
  for (int i = 0; 0 <= path.size(); i++){
    if (path.front() == HTree::Direction::LEFT){
      out[i] = 1;
    }
    path.pop_front();
  }
  return out;
/*
  bits_t out(path.length(),0);  // make a vector of 1s and 0s initialized to 0
  for (int i = 0, i < path.length(), i++){
    if (dir == HTree::Direction::RIGHT){
    //put 1 in vector if direction is right
    //intiailized to all be 0, so don't need to change anything for lefts
    }
  }

  return out;
  */
}

int Huffman::decode(bool bit){

}

HForest Huffman::build_forest(){
  //intiialize a forest of leaves (trees with one elt)
  //Each leaf has key = symbol (ie character), value = frequency
    //get frequency from current frequency table of the object
  //return forest
  HForest huff_forest;   //iterate through frequency table vector?
  for (int i = 0; i < 256; i++){
    huff_forest.add_tree(std::make_shared<HTree>(i,freq_table[i]));
  }
  huff_forest.add_tree(std::make_shared<HTree>(HEOF, 1));
  return huff_forest;
}

HTree Huffman::make_tree(){
  //do the huffman algorithm to make a tree from a forest
  HForest huff_forest = build_forest();
  while (huff_forest.get_size() > 1){//size of forest > 1
    tree_ptr_t lowest = -1;
    tree_ptr_t secondLowest = -1;
    for (int i = 0; i < huff_forest.get_size(); i++){
      if (secondLowest < 0 || (huff_forest.get_index(i))->get_value() < secondLowest){
        if (lowest < 0 || (huff_forest.get_index(i))->get_value() < lowest){
          secondLowest = lowest;
          lowest = huff_forest.get_index(i))->get_value();
        else {
          secondLowest = huff_forest.get_index(i))->get_value();
        }
        }
      }
    }
  }
}


    //things to add to hforest:
      //add get_index returns forest_vect[i]
      //size function get_size()
      //way to iterate through the forest

}
