// Returns the number of 1s in the binary representation of x
int kernighan(int x) {
  int bits = 0;
  while (x) {
    x &= (x - 1);
    ++bits;
  }
  return bits;
}