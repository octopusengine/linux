#include <iostream> //cout <<
#include <stdio.h>  //file+fprintf
#include <fstream>  //lines

#include <unistd.h>  //_getch*/
#include <termios.h> //_getch*/


//#define DEBUG
#define MAZEX 9
#define MAZEY 10
#define KB_UP 65 //72
#define KB_DOWN 66
#define KB_LEFT 68 //75
#define KB_RIGHT 67
#define KB_ESCAPE 27

using namespace std;


char maze[MAZEY][MAZEX];
string info_line = ".:.";
bool bingo = false;
int KB_code = 0;  	// kbd arrows

// start position
int row = 8;
int col = 1;


char getch(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0) perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0) perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0) perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0) perror ("tcsetattr ~ICANON");
    return buf;
}


void print_maze()
{
	//std::system("clear");
	printf("\033[2J\033[1;1H"); //https://en.wikipedia.org/wiki/ANSI_escape_code
	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 9; j++)
			{ cout << maze[i][j]; }
		cout << endl;
	}
}


void load_maze(string file_name)
{    
	ifstream infile(file_name);
	string line;
	int ln=0;
	//while (std::getline(infile, line))
	//	std::istringstream iss(line);
	for( line; getline( infile, line ); )	
	{
           	#ifdef DEBUG
			cout << line << endl;
            #endif

           	for (int li=0; li< MAZEY; li++)
				{  

					//if( feof(line[li]) ) { break; }	

					maze[ln][li]=line[li]; 
					//printf("%s","x" );
					#ifdef DEBUG
						printf("%d %d . ",li,ln );
    				#endif					
				}				
			ln++;	
	}
	//return maze_temp[MAZEX][MAZEY];
}

/*
void save_maze(string file_name)
{
	// Write the file
	//FILE* file = fopen("file.dat", "wb");
	FILE * fp;
	fp = fopen ("./test.txt", "w+");
		
	//fwrite(&points, sizeof(int), 1, file);
	//fwrite(data, sizeof(double), points, file);
	for(int i = 0; i < MAZEY; i++)
	{
		for(int j = 0; j < MAZEX; j++)
		{
			int mi = maze[i][j];
			char mc = mi;
			fprintf(fp, "%c", mc); 
		}	
		fprintf(fp, "\n" );	
	}	
	fclose(fp);
}
*/

//--------------------------------------------------------------------
int main()
{
    #ifdef DEBUG
       	printf( "[ --- maze init ]\n" );
		cout << MAZEX << "x" << MAZEY;	
       	printf( "\n\n" );
    #endif

	//char maze[20][10]; 
	char maze0[][MAZEX] = { 
                 { '+', '-', '-', '-', '-', '-', '-', '-', '+' },
	             { '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|' },
	             { '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|' },
	             { '|', ' ', '+', '-', '-', '-', '+', ' ', '|' },
	             { '|', '#', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	             { '|', '-', '+', ' ', '+', ' ', '+', '-', '|' },
	             { '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|' },
	             { '|', ' ', '|', ' ', '+', '-', '+', ' ', '|' },
	             { '|', '*', '|', ' ', ' ', ' ', ' ', ' ', '|' },
				 { '+', '-', '-', '-', '-', '-', '-', '-', '+' } };

	
	load_maze("./maze1.txt"); 
	#ifdef DEBUG
		cout << "\nload.ok\n\n";
    #endif
    //maze[MAZEX][MAZEY] = maze0[MAZEX][MAZEY]; // 
	print_maze();
	bool gameOver = false;
    

//===============
while(!gameOver)
{	
   KB_code = 0;		
   while(KB_code != KB_ESCAPE )
   { 
        KB_code = getch();
        //printf("KB_code = %i \n",KB_code);
        //if (KB_code<90) { cout << "key > " << KB_code << endl;}

        switch (KB_code)
        {				
            case KB_LEFT:
			    if (maze[row][col-1] == '#'){ bingo = true; }
			    if (maze[row][col-1] == ' '){
                maze[row][col] = ' ';
				col--;
				maze[row][col] = '*';}
            break;

            case KB_RIGHT:
			    if (maze[row][col+1] == '#'){ bingo = true; }
			    if (maze[row][col+1] == ' '){
                maze[row][col] = ' ';
				col++;
				maze[row][col] = '*';}                           
            break;

            case KB_UP:
				if (maze[row-1][col] == '#'){ bingo = true; }
			    if (maze[row-1][col] == ' '){
                maze[row][col] = ' ';
			    row--;
				maze[row][col] = '*';}                 
            break;

            case KB_DOWN:
				if (maze[row+1][col] == '#'){ bingo = true; }
			    if (maze[row+1][col] == ' '){
                maze[row][col] = ' ';
			    row++;
				maze[row][col] = '*';}                  
            break;			
		}
			
		print_maze();	

		info_line = to_string(row) + " | " + to_string(col) + " | ";
		cout << "\n" << info_line;
		if (bingo) {cout << "BINGO! 123"; gameOver = true;}
		cout << "\n";	
	    //cout << move << endl;
		
        /*
		else if (move == 'f')
		{
			cout << "file: " << endl;
			loadM(maze);
			saveM(maze);			
			//save();
			//load();
		}		
		
		else
		{	cout << "Invalid Input" << endl; }
		*/ 

  }  
}

cout << "\n----------"; 
cout << "KEY = pokus\n\n\n";	

return 0;
}


/*
//https://www.element14.com/community/community/code_exchange/blog/2013/01/02/c-tutorial--hello-raspberry-pi
*/