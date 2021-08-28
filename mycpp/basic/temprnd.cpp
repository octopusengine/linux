//https://www.element14.com/community/community/code_exchange/blog/2013/01/02/c-tutorial--hello-raspberry-pi

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
 
int main()
{
// Randomly generate a secret number
srand((unsigned int) time(NULL));
int num = (rand() % 10) + 1;
int num_guesses = 3;
 
// Print out number first (used for debugging purposes, no cheating!)
//cout << num << endl;
 
// Game intro
cout << "I'm thinking of a secret number, can you guess it?" << endl;
 
int guess = 0;
for (int i = 0; i < num_guesses; i++)
{
// Read in guess
cout << "Guess? ";
cin >> guess;
 
// Guess logic
if (guess == num)
{
// Tell the user that they guessed correctly
// and then exit the program
cout << "Correct, my secret number was " << num << endl;
return 0;
}
else
{
if (num < guess)
{
cout << "My secret number is less than " << guess << endl;
}
else
{
cout << "The secret number is greater than " << guess << endl;
}
}
}
 
// If the loop ends, that means that the user is out of guesses
// and never guessed the correct number
cout << "Sorry, the correct number was " << num << endl;
 
return 0;
}



//compile>
//g++ -std=c++0x File.cpp -oFile
//run:
// ./File