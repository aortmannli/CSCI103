#include <string>
#include <vector>

// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
using std::vector;

class BigInt {
   public:
      BigInt(string s, int b = 10);   // convert string to BigInt
      string to_string(); // get string representation
      void add(BigInt foo); // add another BigInt to this one
      string Decimal(string str, int b); //converts number to base ten
  
  private:
      string num;
      vector<int> v;
      int base;

};
