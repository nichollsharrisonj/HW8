### Huffman Encoding

##### Lucas Hamilton and Harrison Nicholls

###### Huffman

- In the private part of the `Huffman` class, we keep a vector of ints called `freq_table` for our frequency table. We also keep a datamember called `currentpath`, which we use during decoding.
- We wrote a `make_tree()` method for Huffman, which is needed by both `decode` and `encode`. `make_tree()` starts by calling `build_forest()` , which simply builds a forest of single trees with appropriate values of frequency taken from `freq_table`. It then removes the two lowest valued trees in this forest, and connects them to form a new tree, which it adds back into the forest.
- We also wrote `convert_path()`, which takes a `path_t` and returns the corresponding list of 1's and 0's.
- `encode`, which is passed a single character, calls `make_tree()`, and finds the path to the character using `path_to()`. It then calls `convert_path()` on the path, returning an encoding of the character. Before the return statement, it also updates the frequency table.
- `decode` also starts by building a tree, and then makes the appropriate step down the tree depending on the provided bit. `decode` can take multiple calls to find the character, so until it has reached a leaf, it returns -1. While it is working, it stores the current state of the path in `currentpath`, as mentioned earlier. When it finally reaches a leaf, it returns the character and updates the frequency table. 

###### BitIO

- 

