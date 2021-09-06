#include <iostream> //cout <<
#include <stdio.h>  //file+fprintf
#include <fstream>  //lines
#include <unistd.h>  //_getch*/
#include <termios.h> //_getch*/
#include <chrono>

#define DEBUG
#define MAZEX 32
#define MAZEY 12
#define KB_UP 65 //72
#define KB_DOWN 66
#define KB_LEFT 68 //75
#define KB_RIGHT 67
#define KB_ESCAPE 27

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::milliseconds;


char maze[MAZEX][MAZEY];
string info_line = ".:.";
bool bingo = false;
int KB_code = 0;  	// kbd arrows

// start position
int row = 10;
int col = 1;
int points = 0;
bool snake = false;
char old = ' ';
bool gameOver;
//int t1;
auto t1 = high_resolution_clock::now();

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


void clear_maze()
{	for(int j = 0; j < MAZEY; j++)
	{ for(int i = 0; i < MAZEX; i++) maze[i][j] = ' '; }
}


void print_maze()
{
	//std::system("clear");
	printf("\033[2J\033[1;1H"); //https://en.wikipedia.org/wiki/ANSI_escape_code
	//cls();
	
	for(int j = 0; j < MAZEY; j++)
	{
		for(int i = 0; i < MAZEX; i++)
			{ cout << maze[i][j]; }
		cout << endl;
	}
}


void load_maze(string file_name)
{    
	clear_maze();
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

           	for (int li=0; li< MAZEX; li++)
				{
					//if( feof(line[li]) ) { break; }	

					maze[li][ln]=line[li]; 
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



void run_maze(string mazeName = "maze",int snakeLimit = 3, int gamePoints = 5)
{
//--- init
points = 0;
gameOver = false;
t1 = high_resolution_clock::now(); // start


while(!gameOver)
{	
   KB_code = 0;		
   while(KB_code != KB_ESCAPE )
   { 
        KB_code = getch();
        //printf("KB_code = %i \n",KB_code);
        //if (KB_code<90) { cout << "key > " << KB_code << endl;}
        if (snake) {old = '.';} else {old= ' ';}

        switch (KB_code)
        {							
            case KB_LEFT:
			    if (maze[col-1][row] == '#'){ 
					bingo = true; maze[col-1][row] = ' ';}
			    if (maze[col-1][row] == ' '){
                maze[col][row] = old;
				col--;
				maze[col][row]= '*';}
            break;

            case KB_RIGHT:
			    if (maze[col+1][row] == '#'){ 
					bingo = true; maze[col+1][row] = ' ';}
			    if (maze[col+1][row] == ' '){
                maze[col][row] = old;
				col++;
				maze[col][row] = '*';}                           
            break;

            case KB_UP:
				if (maze[col][row-1] == '#'){ 
					bingo = true; maze[col][row-1] = ' ';}
			    if (maze[col][row-1] == ' '){
                maze[col][row] = old;
			    row--;
				maze[col][row] = '*';}                 
            break;

            case KB_DOWN:
				if (maze[col][row+1] == '#'){ 
					bingo = true; maze[col][row+1] = ' ';}
			    if (maze[col][row+1] == ' '){
                maze[col][row] = old;
			    row++;
				maze[col][row] = '*';}                  
            break;			
		}
			
		print_maze();	

        auto t2 = high_resolution_clock::now();
    	auto ms_int = duration_cast<milliseconds>(t2 - t1);
    	//duration<double, std::milli> ms_double = t2 - t1;
    	//std::cout << ms_int.count() << "ms\n";
    	//std::cout << ms_double.count() << "ms";


		info_line = "| " + mazeName + " | " + to_string(col) + " | " + to_string(row)+ " | #" + to_string(points) + " | :" + to_string(ms_int.count()/1000);
		cout << info_line << "\n";
		cout << "+------------------------------+"  << "\n";

		if (bingo) {
			bingo = 0;
			points += 1;
			if ( col > 10) { cout << "BINGO! 123";}
			else { cout << "BINGO! 567";
			//gameOver = true;
			}
		}
		
		cout << "\n";	
	    //cout << move << endl;
		if (points > snakeLimit -1) snake = true;
		if (points > gamePoints) gameOver = true;
    }  
 }
}


//=====================================================
int main()
{
    #ifdef DEBUG
       	printf( "[ --- maze init ]\n" );
		cout << MAZEX << "x" << MAZEY;	
       	printf( "\n\n" );
    #endif

	//char maze[20][10]; 
	char maze0[][MAZEY] = { 
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
	cout << "\nload1.ok\n\n";
#endif
//maze[MAZEX][MAZEY] = maze0[MAZEX][MAZEY]; // 
print_maze();	
run_maze("maze1",3,5); //3,6 snakeLimit, gamePoints
cout << "\n=========== maze1.ok ============\n\n";

load_maze("./maze2.txt"); 
print_maze();
run_maze("maze2",5,12); 
cout << "\n=========== maze2.ok ============\n\n";

load_maze("./maze3.txt"); 
print_maze();
run_maze("maze3",5,12); 
cout << "\n=========== maze3.ok ============\n\n";


cout << "\n----------------------------------\n"; 
cout << "           KEY = test-abc\n\n\n";	

return 0;
}

/*
//https://www.element14.com/community/community/code_exchange/blog/2013/01/02/c-tutorial--hello-raspberry-pi
*/