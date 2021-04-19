#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){//take in number of command line arguments, and arguments
	if (argc != 2){
		return 0;
	}
	string filename; 
	filename = *argv[1];
	ifstream File(filename);


	// while (true) {
	//     // symbol = huff.encode(bitio.input_bit());
	// }
	
	File.close()

	return 1;
}