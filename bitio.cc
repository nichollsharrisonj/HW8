#include "bitio.hh"

BitIO::BitIO(std::ostream* os, std::istream* is)
  : streamOut(os), streamIn(is), currentIndex(0)
{
};

BitIO::~BitIO(){
  //check length of stored string
    //if length > 0, need to add zeros so it gets to 8 and then print
    //add zeros to the end??
  //NEED TO DO MORE
  // while (currentIndex < 7){
  //   *streamOut << 0;
  //   currentIndex++;
  // }

  while (streamOut && currentIndex){
    output_bit(0);
  }
}

void BitIO::output_bit(bool bit){
  assert(streamOut);
  storedString[currentIndex] = bit;
  currentIndex++;
  if (currentIndex==8){
    currentIndex = 0;
    unsigned char charprint = static_cast<unsigned char>( storedString.to_ulong() );
    streamOut->put(charprint);
    storedString.reset();
  }
  }


bool BitIO::input_bit(){
  assert(streamIn);
  if (currentIndex == 0){
    unsigned int byteToRead = static_cast<unsigned long>(streamIn->get());
    storedString = byteToRead;
  }
  bool bit = storedString.test(currentIndex);
  currentIndex++;
  if (currentIndex == 8){
    currentIndex = 0;
    storedString.reset();
  }
  return bit;
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
