#include <stdio.h>
#include <iostream>
#include <sstream>   //std::stringstream
#include <vector>
#include <fstream>
#include <string>
#include <random>
// #include <iterator>
// #include <regex>


//#define DEBUG
#define LENKEY 512 // main random key string lenght (13+4)*12 = 204 > 256(1-15) or 512(1-38)
#define MODP 32    // modulo for format print
#define BASE 26    // ascii alphabet

using namespace std;

int CaMeL = 1; // [0] lower / [1] CaMeL / [2] todo: & numbers

void tokenize(string &str, char delim, vector<string> &out)
{
	size_t start;
	size_t end = 1;

	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

string random_string(int num){
    string s;
    for(int i = 0; i < num; i++) {
        char srnd = 'a' + rand()%BASE;
        if ( CaMeL > 0 ) {
           //int selector = rand()%10;
           if (rand()%10>6) srnd = 'A' + rand()%BASE;
        }
        s += srnd;
  
    }
    return s;
}

string format_print (string s){
    string sn; // new string
    int i=0;
        for(char& c : s) {
            sn += c;
            printf( "%c", c );
            i += 1;
        if (i % MODP == 0) { printf("\n"); sn += "\n"; }
        }
return sn;
}

void save_string(string s, string file_name = "secret_key.txt"){
    std::ofstream out(file_name);
    out << s;
    out.close();
}

void print_string(string s){ std::cout << s << "\n"; }

int arr_len(int *p) { return sizeof(p)/sizeof(*p); }


//--------------------------------------------------
int main ( int argc, char *argv[] )
{
    #ifdef DEBUG
    	printf( "[ --- device entropy for random ]\n" );
    	std::random_device rd;
    	std::cout << rd.entropy() << '\n';
    #else
        srand(time(0));
    #endif

    string sr = random_string(LENKEY);

    // argv[0] - program name
    if ( argc < 2 )
    { printf( "usage: %s input_filename [distance] [CaMeL]", argv[0] );  }
    else
    {
        int distance = 13; 
        CaMeL = 0; // [0] lower / [1] CaMeL / [2] todo: & numbers
        if ( argc > 2 ) distance = stoi(argv[2]); // 1-17
        if ( argc > 3 ) CaMeL = stoi(argv[3]); // 1/0

        #ifdef DEBUG
            printf( "[ --- arguments ]\n" );
            printf("\n%d - ", argc);
            printf("\n-1- %s ", argv[1]);
            printf("\n-2- %d ", distance);
            printf("\n-3- %d ", CaMeL);
            printf( "[ --- basic random string ]\n" );
            //std::cout << sr << "\n"; //you can do anything with the string!
            string sf = format_print(sr);
            save_string(sf, "random_string0.txt");
        #endif


        // We assume argv[1] is a filename to open
        FILE *file = fopen( argv[1], "r" );

        /* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {   printf( "Could not open file\n" ); }
        else
        {
            // --- read file asi string
            std::ifstream inFile;
            inFile.open( argv[1] ); //open the input file

            std::stringstream strStream;
            strStream << inFile.rdbuf(); //read the file
            std::string str = strStream.str(); //str holds the content of the file

            #ifdef DEBUG
            	printf( "[ --- input string from file ]\n" );
            	std::cout << str << "\n"; //you can do anything with the string!
            	printf( "\n\n" );
            #endif

            // --- split string to array
            char delim=' ';
            vector<string> arr;
            tokenize(str, delim, arr);

            #ifdef DEBUG
            	printf( "[ --- list of the words ]\n" );
            	for(auto it:arr) cout << it << " / ";
            	printf("\n");
            #endif

            int wi = 0;
            int temp_dist = 0;
            string sn;     // string new
            string word;   // single word
            //for(char& c : sr)
            //for (int i = 0; i < LENKEY +2; i++) // work around +2
            int i = 0;
            do
            {
                if (temp_dist == distance) {
                //sn += "*";
                    word = arr[wi];
                    int sl = word.length();

                    if (wi>11) { wi = 12; temp_dist = 0; }
                    else {
                    for (int j = 0; j < sl; j++) {
                        sn += word[j];
                        i += 1;
                    }

                    #ifdef DEBUG
                        printf("\n%d - ", sl);
                        print_string(arr[wi]);
                    #endif
                    }

                    temp_dist = 0;
                    wi += 1;
                    }
                else {
                    sn += sr[i];
                    temp_dist += 1;
                    ///printf("-%d", i);
                    i += 1;
                    }
            }
            while (i < LENKEY);

            printf("\n--------------------------------");
            printf("\n-------- supplement-key --------");
            printf("\n");
            string sf = format_print(sn); // string final
            save_string(sf, "supplement_key.txt");
        }
    }
    printf("\n");
}

/* ----------------------------------
./infilt input.txt

--- / --|
27 / 28 |
  /(512)|
*/
