#include <stdio.h>
#include <iostream>
#include <sstream> //std::stringstream
#include <vector>
// #include <iterator>
#include <fstream>
#include <string>
// #include <regex>
#include <random>

#define DEBUG 0
#define LENKEY 256 // main random key string lenght (13+4)*12 = 204 > 256
#define MODP 32    // modulo for format print

using namespace std;


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
    for(int i = 0; i < num; i++) { s += 'a' + rand()%24; }
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


//--------------------------------------------------------
int main ( int argc, char *argv[] )
{
    if (DEBUG) {
    printf( "[ --- device entropy for random ]\n" );
    std::random_device rd;
    std::cout << rd.entropy() << '\n';
    }
    else { srand(time(0)); }

    int distance = 13; 
    string sr = random_string(LENKEY);

    if ( argc < 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s input_filename [distance]", argv[0] );
    }
    else
    {
        if ( argc == 3 ) { 
            //print_string(argv[0]);
            //print_string(argv[1]);
            //print_string(argv[2]);
            distance = stoi(argv[2]); 
            } 

        if (DEBUG) {
            printf( "[ --- arguments ]\n" );
            printf("\n%d - ", argc);

            printf( "[ --- basic random string ]\n" );
            //std::cout << sr << "\n"; //you can do anything with the string!
            string sf = format_print(sr);
            save_string(sf, "random_string0.txt");
            }


        // We assume argv[1] is a filename to open
        FILE *file = fopen( argv[1], "r" );

        /* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        { printf( "Could not open file\n" ); }
        else
        {
            // --- read file asi string
            std::ifstream inFile;
            inFile.open( argv[1] ); //open the input file

            std::stringstream strStream;
            strStream << inFile.rdbuf(); //read the file
            std::string str = strStream.str(); //str holds the content of the file

            if (DEBUG) {
            printf( "[ --- input string from file ]\n" );
            std::cout << str << "\n"; //you can do anything with the string!
            printf( "\n\n" );
            }

            // --- split string to array
            char delim=' ';
            vector<string> arr;
            tokenize(str, delim, arr);


            if (DEBUG) {
            printf( "[ --- list of the words ]\n" );
            for(auto it:arr) cout << it << " / ";
            printf("\n");
            }
            
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
                        ///printf("=%d", i); 
                        i += 1;                      
                    }              
                    
                    if (DEBUG) {
                        printf("\n%d - ", sl);
                        print_string(arr[wi]);                    
                        }
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
            printf("\n");
            string sf = format_print(sn); // string final
            save_string(sf, "random_string.txt");            
        }
    }
    printf("\n");
}

/* ----------------------------------
./infilt in12.txt
*/
