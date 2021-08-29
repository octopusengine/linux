#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

// example char manipulation
string cipher(const char*  input_s, int key = 13) {
    string t;
    printf("// %lu", strlen(input_s));

    for(int i=0; i<strlen(input_s); i++){
        printf("/ %d", i);
        printf("%c", input_s[i]);

        if (isspace(input_s[i])) { t +=  ' '; }
        else{ 
            t += (input_s[i] - 'a' + key)%26 + 'a'; 
            //t +=  '=';
            }        
    }

    return t;
}

//-------------------------------------------
int main(){
    int j,k;


    //std::string oString;
    //std::string oString("abc");
    //char str[] = s;
    //char* pStr;
    /*
    char* data;
    stringstream myStreamString;
    myStreamString << data;
    string myString = myStreamString.str();
    cout << myString << endl;
    */
    
    //std::string oString;
    // const char* dat = oString.c_str();

    /* -------------------------------
    // basic string
        
    string str = "geeksforgeeks";
    int n = str.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, str.c_str());
 
    for (int i = 0; i < n; i++)
        cout << char_array[i];
    //----------------------------
    */
   
    string cstr;
    //std::string str;
    string str;
    char char_array[256]; // fix lenght declaration
    printf("\n(strlen.ch) %lu", strlen(char_array));
    printf("\n(sizeof.ch) %ld", sizeof(char_array));
    printf("\n");

    int key;
    ///cout<<"Enter the key:\n";
    ///cin>>key;
    key = 13;
    cout<<"Enter the message:\n";
    //cin>>str;// assigning value to string s
    cin.getline(char_array,sizeof(char_array)); 

    //cout<<"\nInput message is " << str <<'\n';
    //printf("\n(s.size) %d", str.size());
    printf("\n");


    //strcpy(char_array, str.c_str());
/*
    for (int i = 0; i < sizeof(char_array); i++) {
        char_array[i] = str[i];
        cout << char_array[i];
    }
*/
    printf("\n(strlen) %ld", strlen(char_array));

    cstr = cipher(char_array,key); // caesar

    printf("\n"); 
    cout<<"\nEncrypted message is:\n" << cstr <<'\n';
    
    // return 0;
}