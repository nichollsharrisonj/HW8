#include "bitio.hh"

BitIO::BitIO(std::ostream* os, std::istream* is) {
  isOut = 0;
  isIn = 0;
  storedString = {0, 0, 0, 0, 0, 0, 0, 0};
  if (os) {
    streamOut = os;
    isOut = 1;
  } else if (is) {
    streamIn = is;
    isIn = 1;
  }
};

BitIO::~BitIO(){
  //check length of stored string
    //if length > 0, need to add zeros so it gets to 8 and then print
    //add zeros to the end??
  //NEED TO DO MORE
}

void BitIO::output_bit(bool bit){
  storedString.push_back(bit);
  storedString[currentIndex] = bit;
  currentIndex++;
  if (currentIndex == 7){
    for (int i = 0; i < 8; i++){
      std::cout << storedString[i];
      *streamOut << /*maybe <<*/ storedString[i];
    }
    storedString.assign(storedString.size(), 0);
    currentIndex = 0;
  }
}

bool BitIO::input_bit(){
  //ALWAYS ONLY READING THE MOST RECENT INPUTTED BIT, SEE TEST_BITIO.cc
  bool input;
  *streamIn>>input;
  return input;
}

bool BitIO::printIndex(int index){
  return storedString[index];
}


/*
HOMEWORK TIPS:
- Reading/writing a single character:
    - get()/put()
- Binary mode: iOS::binary
- Command-line arguments: argc/argv
- Standard streams:
    - Cin cout cerr
- Formatted I/O
    - Can google these and figure out precise uses if you want
- BITIO either takes an input string or an output stream
    - output_bit
        - Feed one bit at a time, until reaches 8 bits and then prints the byte
        - RAII
            - If someone doesn’t give you 8 bits, need to format it so it will still print
    - input_bit
*/
