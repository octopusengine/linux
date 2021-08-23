//https://www.element14.com/community/community/code_exchange/blog/2013/01/02/c-tutorial--hello-raspberry-pi
#include <iostream> //cout <<
#include <stdio.h>  //file+fprintf
#include <fstream> //lines

#include <unistd.h>   //_getch*/
#include <termios.h>  //_getch*/


#define KB_UP 65 //72
#define KB_DOWN 66
#define KB_LEFT 68 //75
#define KB_RIGHT 67
#define KB_ESCAPE 27

using namespace std;


int Ms = 20;
int Mr= 10;

char getch(){
    /*#include <unistd.h>   //_getch*/
    /*#include <termios.h>  //_getch*/
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    //printf("%c\n",buf);
    return buf;
 }



void print(char maze[10][9])
{
	//std::system("clear");
	printf("\033[2J\033[1;1H"); //https://en.wikipedia.org/wiki/ANSI_escape_code
	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 9; j++)
		{			cout << maze[i][j];		}
		cout << endl;
	}
}


void loadM(char maze[10][9])
{
	printf("%s", "---load---start\n");
	std::ifstream infile( "./mazef.txt");
	std::string line;
	//char cm;
	int ln=0;
	//while (std::getline(infile, line))
	//	std::istringstream iss(line);
	for( std::string line; getline( infile, line ); )
	{
            //cm = fgetc(line);
           	//printf("%c", cm);
           	//printf("%s", line);
           	///printf("%d %s", ln,") ");
           	
           	//cout << line << endl;
                      	
           	for (int li=0; li<Ms;li++)
				{ 
					maze[ln][li]=line[li]; 
					//printf("%s","x" );
					printf("%d %d ",li,ln );
				}						
				
			ln++;	
	
	}
	printf("%s", "---load---end\n");

}

void loadMx(char maze[10][9])
{	
	FILE * fp;
	fp = fopen ("./mazef.txt", "r");
	char cm;	
	for(int i = 0; i < 10; i++)
	{	for(int j = 0; j < 9; j++)
		{	cm = fgetc(fp);
            if( feof(fp) )
			{ 			break ;			}
			printf("%c", cm);			
			//if( !feol(fp) )
			//{			maze[i][j]=cm;		    }			
		}	
		fprintf(fp, "\n" );	
	}	
	fclose(fp);
	fprintf(fp, "\n" );	
}

void saveM(char maze[10][9])
{
	// Write the file
	//FILE* file = fopen("file.dat", "wb");
	FILE * fp;
	fp = fopen ("./maze.txt", "w+");
		
	//fwrite(&points, sizeof(int), 1, file);
	//fwrite(data, sizeof(double), points, file);
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			//fwrite(maze[i][j], 1, 1, file);;
			
			 //stringstream strs;
             //strs << number;
             //string temp_str = strs.str();
             //char* char_type = (char*) temp_str.c_str();
             
			//fprintf(fp, "%s", std::to_string(maze[i][j]) );
			
			//fprintf(fp, "%d", (maze[i][j]) ); //ok asi int
			//fprintf(fp, "%d"" %s", mc,"," ); //carky mezi
			
			//just assign the int to a char variable.
			//int i = 65;
			int mi = maze[i][j];
			char mc = mi;
			fprintf(fp, "%c", mc); 
			
			
		}	
		fprintf(fp, "\n" );	
	}	
	fclose(fp);
}


void save()
{
   FILE * fp;
   fp = fopen ("./file.txt", "w+");   
   fprintf(fp, "%s %s %s %d", "We", "are", "in", 2016);   
   fclose(fp);
}

void load ()
{
   FILE *fp;
   int c;  
   fp = fopen("./file.txt","r");
   
   while(1)
   {
      c = fgetc(fp);
      if( feof(fp) ) { break ; }
      printf("%c", c);
   }
   fclose(fp);  

}

int main()
{
	//char maze[20][10]; 
	char maze[][9] = { { '+', '-', '-', '-', '-', '-', '-', '-', '+' },
	                   { '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|' },
	                   { '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|' },
	                   { '|', ' ', '+', '-', '-', '-', '+', ' ', '|' },
	                   { '|', '#', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	                   { '|', '-', '+', ' ', '+', ' ', '+', '-', '|' },
	                   { '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|' },
	                   { '|', ' ', '|', ' ', '+', '-', '+', ' ', '|' },
	                   { '|', '*', '|', ' ', ' ', ' ', ' ', ' ', '|' },
					   { '+', '-', '-', '-', '-', '-', '-', '-', '+' } };

	int row = 8;
	int col = 1;
	
	
	loadM(maze);
	

	bool gameOver = false;
	while(!gameOver)
	{
		

    //int c2 = getch();
    //cout << "key:" << c2 << endl;

    //if(c2 == 72) {cout << endl << "Up Arrow" << endl;}
    //else if(c2 == 80) {cout << endl << "Down Arrow" << endl;}
    //else{cout << endl << "Incorrect Input" << endl;}

		///if(GetAsyncKeyState(KB_UP)){}
		//while(move != 'u' && move != 'd' && move != 'l' && move != 'r' && move != 'q'  && move != 'f')
		
		
   int KB_code=0;
   while(KB_code != KB_ESCAPE )
   { 
     
            KB_code = getch();
            //printf("KB_code = %i \n",KB_code);
            //if (KB_code<90) { cout << "key > " << KB_code << endl;}

            switch (KB_code)
            {				
                case KB_LEFT:
					//Do something
                    maze[row][col] = ' ';
					col--;
					maze[row][col] = '*';
                break;

                case KB_RIGHT:
                    //Do something 
                    maze[row][col] = ' ';
					col++;
					maze[row][col] = '*';      
                                              
                break;

                case KB_UP:
                     //Do something  
                     maze[row][col] = ' ';
					 row--;
					 maze[row][col] = '*';                
                break;

                case KB_DOWN:
                    //Do something
                    //move="d"; 
                    maze[row][col] = ' ';
					row++;
					maze[row][col] = '*';                 
                break;
		
			
			
			}
			
			print(maze);		
			
	
              //cout << move << endl;
		
        /*
		if (move == 'u')
		{
			if (maze[row - 1][col] == ' ')
			{
				maze[row][col] = ' ';
				row--;
				maze[row][col] = '*';
			}
			else if (maze[row - 1][col] == '#')
			{				gameOver = true;			}
		}
		else if (move == 'd')
		{
			if (maze[row + 1][col] == ' ')
			{
				maze[row][col] = ' ';
				row++;
				maze[row][col] = '*';
			}
			else if (maze[row + 1][col] == '#')
			{				gameOver = true;			}
		}
		else if (move == 'l')
		{
			if (maze[row][col - 1] == ' ')
			{
				maze[row][col] = ' ';
				col--;
				maze[row][col] = '*';
			}
			else if (maze[row][col - 1] == '#')
			{				gameOver = true;			}
		}
		else if (move == 'r')
		{
			if (maze[row][col + 1] == ' ')
			{
				maze[row][col] = ' ';
				col++;
				maze[row][col] = '*';
			}
			else if (maze[row][col + 1] == '#')
			{				gameOver = true;			}
		}
		else if (move == 'q')
		{			gameOver = true;		}
		
		else if (move == 'f')
		{
			cout << "file: " << endl;
			loadM(maze);
			saveM(maze);			
			//save();
			//load();
		}		
		
		else
		{			cout << "Invalid Input" << endl;		}
		*/ 

  }
  
}
return 0;
}
