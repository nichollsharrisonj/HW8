#include "huffman.hh"
#include "hforest.hh"
#include "htree.hh"


Huffman::Huffman()
  : freq_table(257, 0)
  {
}

Huffman::~Huffman(){

}

Huffman::bits_t Huffman::encode(int symbol){
  //make a forest, then make the tree
  //tree.path_to(symbol) convert to bits_t
  //update freq table
  HTree::tree_ptr_t huff_tree = make_tree();
  HTree::possible_path_t path = huff_tree->path_to(symbol);
  freq_table[symbol]++;

  return convert_path(*path);
}

Huffman::bits_t Huffman::convert_path(path_t path){
  bits_t out(path.size(), 0);
  for (int i = 0; 0 < path.size(); i++){
    if (path.front() == HTree::Direction::LEFT){
      out[i] = 1;
    }
    path.pop_front();
  }
  return out;
}


int Huffman::decode(bool bit){
  HTree::tree_ptr_t huff_tree =  Huffman::make_tree();
  HTree::tree_ptr_t currnode = huff_tree;  //start the current node at the beginning of the tree
  if (bit){   //Expand currentpath list based on given bit
    currentpath.push_back(HTree::Direction::RIGHT);
  }
  else {
    currentpath.push_back(HTree::Direction::LEFT);
  }
  for(int i=0; i < static_cast<int>(currentpath.size()); i++){
    currnode = currnode->get_child(currentpath[i]);
    }
  if (currnode->get_value() >= 0){//We have reached a leaf

  }

  //take freq_table
  //Build a complete huffman tree + EOF
  //take the inputted bit, and traverse the tree
  // do this until reaching a leaf, at which point output the character
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

HTree::tree_ptr_t Huffman::make_tree() {
  HForest huff_forest = build_forest();
  HTree::tree_ptr_t lowest;
  HTree::tree_ptr_t secondLowest;
  int lowestIndex;
  int secondLowestIndex;
  while (huff_forest.get_size() > 1){
    if ((huff_forest.get_index(0))->get_value() < (huff_forest.get_index(1))->get_value()) {
      lowest = huff_forest.get_index(0);
      secondLowest = huff_forest.get_index(1);
      lowestIndex = 0;
      secondLowestIndex = 1;
    } else {
      lowest = huff_forest.get_index(1);
      secondLowest = huff_forest.get_index(0);
      lowestIndex = 1;
      secondLowestIndex = 0;
    }
    for (int i = 2; i < huff_forest.get_size(); i++){
      if ((huff_forest.get_index(i))->get_value() < secondLowest->get_value()){
        if ((huff_forest.get_index(i))->get_value() < lowest->get_value()){
          secondLowest = lowest;
          secondLowestIndex = lowestIndex;
          lowest = huff_forest.get_index(i);
          lowestIndex = i;
        } else {
          secondLowest = huff_forest.get_index(i);
          secondLowestIndex = i;
        }
        }
      }
      HTree::tree_ptr_t newTree = std::make_shared<HTree>(-1, lowest->get_value() + secondLowest->get_value(), secondLowest, lowest);
      huff_forest.pop_by_index(lowestIndex);
      huff_forest.pop_by_index(secondLowestIndex);
      huff_forest.add_tree(newTree);
    }
  }


    //things to add to hforest: returns forest_vect[i]
      //size function get_size()
      //way to iterate through the forest
      //function to delete the ith tree in the forest_vect
