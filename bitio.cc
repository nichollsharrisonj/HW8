#include "bitio.hh"

BitIO::BitIO(std::ostream* os, std::istream* is) {
  if (os) {
    streamOut = os;
    isOut = 1;
    isIn = 0;
  } else if (is) {
    streamIn = is;
    isOut = 0;
    isIn = 1;
  }
};

BitIO::~BitIO(){
  //check length of stored string
    //if length > 0, need to add zeros so it gets to 8 and then print
    //add zeros to the end??
  //NEED TO DO MORE
  while (storedString.size() > 0){ //this adds zeros until output bit prints it, then leaves. if already empty, don't do anything
    output_bit(0);
  }
}

void BitIO::output_bit(bool bit){
  storedString.push_back(bit);
  if (storedString.size() == 8){
    while (storedString.size() > 0){
      streamOut << /*maybe <<*/ storedString[0];
      storedString.erase(storedString.begin());
    }
  }
}

bool BitIO::input_bit(){
  bool input;
  streamIn>>input;
  return input;
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
