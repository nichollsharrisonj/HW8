#include "huffman.hh"
#include "hforest.hh"
#include "htree.hh"


Huffman::Huffman()
  : freq_table(ALPHABET_SIZE, 0), currentTree(make_tree())
  {
}

/*
Huffman::~Huffman(){

}
*/

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

  if (bit){       //shift tree according to the next bit, to be one of the children
    currentTree = currentTree->get_child(HTree::Direction::RIGHT);
  } else {
    currentTree = currentTree->get_child(HTree::Direction::LEFT);
  }

  bit = 0;

  if (currentTree->get_key() >= 0) {//We have reached a leaf
    int val = currentTree->get_key();
    freq_table[currentTree->get_key()]++;
    currentTree = make_tree();
    return val;
  }
  else {
    return -1; //Have not found the character yet
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
  for (int i = 0; i < ALPHABET_SIZE; i++){
    huff_forest.add_tree(std::make_shared<HTree>(i,freq_table[i]));
  }
  int size = ALPHABET_SIZE;
  huff_forest.add_tree(std::make_shared<HTree>(size, 1));
  return huff_forest;
}

HTree::tree_ptr_t Huffman::make_tree() {
  HForest huff_forest = build_forest();
  HTree::tree_ptr_t lowest;
  HTree::tree_ptr_t secondLowest;
  int lowestIndex;
  int secondLowestIndex;
  int lowestValue;
  int secondLowestValue;
  while (huff_forest.get_size() > 1){
    if ((huff_forest.get_index(0))->get_value() < (huff_forest.get_index(1))->get_value()) {
      lowest = huff_forest.get_index(0);
      secondLowest = huff_forest.get_index(1);
      lowestIndex = 0;
      secondLowestIndex = 1;
      lowestValue = lowest->get_value();
      secondLowestValue = secondLowest->get_value();
    } else {
      lowest = huff_forest.get_index(1);
      secondLowest = huff_forest.get_index(0);
      lowestIndex = 1;
      secondLowestIndex = 0;
      lowestValue = lowest->get_value();
      secondLowestValue = secondLowest->get_value();
    }
    for (int i = 2; i < huff_forest.get_size(); i++){
      if ((huff_forest.get_index(i))->get_value() < secondLowest->get_value()){
        if ((huff_forest.get_index(i))->get_value() < lowest->get_value()){
          secondLowest = lowest;
          secondLowestIndex = lowestIndex;
          lowest = huff_forest.get_index(i);
          lowestIndex = i;
          lowestValue = lowest->get_value();
          secondLowestValue = secondLowest->get_value();
        } else {
          secondLowest = huff_forest.get_index(i);
          secondLowestIndex = i;
          lowestValue = lowest->get_value();
          secondLowestValue = secondLowest->get_value();
        }
        }
      }
      HTree::tree_ptr_t newTree = std::make_shared<HTree>(-1, lowest->get_value() + secondLowest->get_value(), secondLowest, lowest);
      if (lowestIndex > secondLowestIndex){
        huff_forest.pop_by_index(lowestIndex);
        huff_forest.pop_by_index(secondLowestIndex);
      } else {
        huff_forest.pop_by_index(secondLowestIndex);
        huff_forest.pop_by_index(lowestIndex);
      }
      huff_forest.add_tree(newTree);
    }
    return huff_forest.get_index(0);
  }


    //things to add to hforest: returns forest_vect[i]
      //size function get_size()
      //way to iterate through the forest
      //function to delete the ith tree in the forest_vect
