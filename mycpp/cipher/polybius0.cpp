#include <cmath>
#include <iostream>

using namespace std;

void LetterToNumber(string str) {
   int R, C;
   for (int i = 0; str[i]; i++) {
      R = ceil((str[i] - 'a') / 5) + 1;
      C = ((str[i] - 'a') % 5) + 1;
      if (str[i] == 'k') {
         R = R - 1;
         C = 5 - C + 1;
      }
      else if (str[i] >= 'j') {
         if (C == 1) {
            C = 6;
            R = R - 1;
         }
         C = C - 1;
      }
      cout<<R<<C;
   }
   cout << endl;
}


int main() {
   string str = "tutorialspoint";
   cout<<"The numeric encryption of string '"<<str<<"' is : ";
   LetterToNumber(str);
   return 0;
}


//https://www.tutorialspoint.com/polybius-square-cipher-in-cplusplus