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

	filename.append(".plaintext"); //change the filename to have the appropriate extension
	std::ofstream Outfile(filename); //open an outfile

	assert(&Infile);
	assert(&Outfile);			//assert Infile and Outfile are open

	BitIO bitin(nullptr, &Infile);
	BitIO bitout(&Outfile, nullptr);

	if (Infile.peek() != std::ifstream::traits_type::eof() ){		//ensures the file is not empty
		while (!Infile.eof()) {
			bool bit;
			bit = bitin.input_bit();
			int decoded = huff.decode(bit);
			if (decoded >= 0){
				Outfile.put(decoded);
			}

		}
	}

	Infile.close(); //close the infile
	Outfile.close(); //close the outfile

	return 1;
}
