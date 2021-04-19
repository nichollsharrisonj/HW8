#include <iostream>
#include <fstream>
#include "huffman.hh"
#include "bitio.hh"


int main(int argc, char **argv){//take in number of command line arguments, and the arguments

	assert(argc == 2); //make sure there are two command line arguments	

	Huffman huff;
	std::string filename; 
	filename = argv[1]; //initialize and set filename to the name of the infile
	std::ifstream Infile(filename);

	filename.append(".comp"); //change the filename to have the appropriate extension
	std::ofstream Outfile(filename); //open an outfile
	Outfile<< "test";


	BitIO bitin(nullptr, &Infile);
	BitIO bitoout(&Outfile,nullptr);
	while (!Infile.eof()) {

		Huffman::bits_t symbol;
		char singlecharacter;
		Infile.get(singlecharacter);
		std::cout << singlecharacter;

	    if (int(singlecharacter) == 0){
	    	break;
	    }
	    symbol = huff.encode(singlecharacter);


	}

	Infile.close(); //close the infile
	Outfile.close(); //close the outfile

	return 1;
}