#include <iostream>
#include <fstream>
#include "huffman.hh"
#include "bitio.hh"

int main(int argc, char **argv){//take in number of command line arguments, and arguments
	
	assert(argc == 2) //make sure there are two command line arguments

	std::string filename; 
	filename = argv[1]; //initialize and set filename to the name of the infile
	std::ifstream Infile(filename); //open ifstream of infile

	// int symbol = -1;

	while (true) {
	  while (symbol < 0) {
	    symbol = huff.decode(bitio.input_bit());
	  }
	  if (symbol == Huffman::HEOF) {
	    break;
	  } 
	  else {
	    outfile.put(symbol);
	    symbol = -1;
	   }
	 }
	
	
	filename.append(".plaintext"); //change file name before opening outfile

	std::ofstream Outfile(filename); //open outfile


	Infile.close(); //close infile
	Outfile.close();


 return 1;
}