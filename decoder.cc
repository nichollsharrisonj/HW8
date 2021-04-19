int main(){
	while (true) {
	  while (symbol < 0) {
	    symbol = huff.decode(bitio.input_bit());
	  }
	  if (symbol == Huffman::HEOF) {
	    break;
	  } else {
	    out.put(symbol);
	    symbol = -1;
	   }
	 }
 return 1;
}