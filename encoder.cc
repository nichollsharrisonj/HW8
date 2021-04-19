#include <iostream>
#include <fstream>

int main(int argc, char **argv){//take in number of command line arguments, and arguments
	if (argc != 2){
		return 0;
	}
	std::string filename; 
	filename = argv[1]; //initialize and set filename to the name of the infile
	std::ifstream Infile(filename);


	// while (true) {
	//     // symbol = huff.encode(bitio.input_bit());
	// }

	Infile.close(); //close the infile

	filename.append(".comp");
	//change the filename to have the appropriate extension
	std::ofstream Outfile(filename); //open an outfile
	Outfile<< "test";
	Outfile.close(); //close the outfile

	return 1;
}