#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring> // strlen
#include <fstream>
#include <sstream>
// #include <cctype>

using namespace std;

// DEBUG ///

string caesar(const char*  input_s, int key = 13) {
    string t;
    ///printf("// %lu", strlen(input_s));

    for(int i=0; i<strlen(input_s); i++){
        ///printf("/ %d", i);
        ///printf("%c", input_s[i]);

        if (isspace(input_s[i])) { t +=  ' '; }
        else{ 
            t += (input_s[i] - 'a' + key)%26 + 'a'; 
            //t +=  '=';
            }        
    }

    return t;
}

int main( int argc, char *argv[] ){
    
    string str, cstr;
    char char_array[256]; // fix lenght declaration
    ///printf("\n(strlen.ch) %lu", strlen(char_array));
    ///printf("\n(sizeof.ch) %d", sizeof(char_array));
    ///printf("\n");
    cout<<"---------------------\n";
    cout<<"--- Caesar cipher ---\n";
    cout<<"---------------------\n";

    if ( argc > 1 )
    {
        //  printf( "usage: %s input_filename [key]", argv[0] );
        FILE *file = fopen( argv[1], "r" );

        // fopen returns 0, the NULL pointer, on failure
        if ( file == 0 )
        { printf( "Could not open file\n" ); }
        else
        {
            // --- read file asi string
            std::ifstream inFile;
            inFile.open( argv[1] );

            std::stringstream strStream;
            strStream << inFile.rdbuf(); //read the file
            std::string fstr = strStream.str(); //str holds the content of the file
             
            cout<<"Input message from file is:\n" << fstr <<'\n';

            strcpy(char_array, fstr.c_str());
 
            //for (int i = 0; i < n; i++)
            //    cout << char_array[i];

        }

    }
    else
    {
    cout<<"Enter the message:\n";
    cin.getline(char_array,sizeof(char_array)); 
    }

    int key;
    cout<<"Enter the key:\n";
    cin>>key;

    ///printf("\n");
    ///printf("\n(strlen) %d", strlen(char_array));

    cstr = caesar(char_array,key);

    printf("-------------------------------------\n"); 
    cout<<"Encrypted message is:\n" << cstr <<'\n';
    printf("\n\n");
    
    return 0;
}