#include "huffman.hh"
#include "hforest.hh"
#include "htree.hh"


Huffman::Huffman(){
  : freq_table(257, 0)
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

int Huffman::decode(bool bit){

}

HForest Huffman::build_forest(){
  //intiialize a forest of leaves (trees with one elt)
  //Each leaf has key = symbol (ie character), value = frequency
    //get frequency from current frequency table of the object
  //return forest
  Hforest huff_forest;   //iterate through frequency table vector?
  for (int i = 0; i < 256; i++){
    huff_forest.add_tree(std::make_shared<HTree>(i,freq_table[i]));
  }
  huff_forest.add_tree(make_shared<HTree>(HEOF, 1));
  return huff_forest;

HTree::tree_ptr_t make_tree(){
  HForest huff_forest = build_forest();
  while (huff_forest.get_size() > 1){
    if ((huff_forest.get_index(0))->get_value() < (huff_forest.get_index(1))->get_value()) {
      tree_ptr_t lowest = huff_forest.get_index(0);
      tree_ptr_t secondLowest = huff_forest.get_index(1);
      int lowestIndex = 0;
      int secondLowestIndex = 1;
    } else {
      tree_ptr_t lowest = huff_forest.get_index(1);
      tree_ptr_t secondLowest = huff_forest.get_index(0);
      int lowestIndex = 1;
      int secondLowestIndex = 0;
    }
    for (int i = 2; i < huff_forest.get_size(); i++){
      if ((huff_forest.get_index(i))->get_value() < secondLowest->get_value()){
        if ((huff_forest.get_index(i))->get_value() < lowest->get_value()){
          secondLowest = lowest;
          secondLowestIndex = lowestIndex;
          lowest = huff_forest.get_index(i));
          lowestIndex = i;
        } else {
          secondLowest = huff_forest.get_index(i));
          secondLowestIndex = i;
        }
        }
      }
      tree_ptr_t newTree = make_shared(-1, lowest->get_value() + secondLowest->get_value(), secondLowest, lowest);
      huff_tree.pop_by_index(lowestIndex);
      huff_tree.pop_by_index(secondLowestIndex);
      huff_tree.add_tree(newTree);
    }
  }


    //things to add to hforest: returns forest_vect[i]
      //size function get_size()
      //way to iterate through the forest
      //function to delete the ith tree in the forest_vect

}
