#include <iostream>
#include <fstream>

int main(int argc, char **argv){//take in number of command line arguments, and arguments
	if (argc != 2){
		return 0;
	}
	std::string filename; 
	filename = argv[1]; //initialize and set filename to the name of the infile
	std::ifstream Infile(filename); //open ifstream of infile
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
	Infile.close();
	
	filename.append(".plaintext");
	std::ofstream Outfile(filename);
	Outfile.close();


 return 1;
}