#include <iostream>
#include <fstream>
#include "huffman.hh"
#include "bitio.hh"



	// while (true) {
	//   while (symbol < 0) {
	//     symbol = huff.decode(bitio.input_bit());
	//   }
	//   if (symbol == Huffman::HEOF) {
	//     break;
	//   }
	//   else {
	//     outfile.put(symbol);
	//     symbol = -1;
	//    }
	//  }




int main(int argc, char **argv){//take in number of command line arguments, and the arguments

	assert(argc == 2); //make sure there are two command line arguments

	Huffman huff;
	std::string filename;
	filename = argv[1]; //initialize and set filename to the name of the infile
	std::ifstream Infile(filename);

	filename.append(".plaintext"); //change the filename to have the appropriate extension
	std::ofstream Outfile(filename); //open an outfile


	BitIO bitin(nullptr, &Infile);
	BitIO bitout(&Outfile, nullptr);
	while (!Infile.eof()) {

		// Huffman::bits_t byte;
		// for (int i = 0; i<8, i++){
		// byte[i] = Infile.get(singlecharacter);
		// symbol = huff.decode(byte);
		// char charbit;
		// Infile.get(charbit);
		bool bit;
		bit = bitin.input_bit();
		int decoded = huff.decode(bit);
		if (decoded >= 0){
			Outfile.put(decoded);
		}
	 //    for (bool bit : symbol){
	 //    	bitout.output_bit(bit);
		// }

	}
	//Add the EOF at the end
	// Huffman::bits_t EOF = huff.encode(257);
	// for (bool bit : EOF){
	// 	bitout.output_bit(bit);
	Infile.close(); //close the infile
	Outfile.close(); //close the outfile

	return 1;
}
