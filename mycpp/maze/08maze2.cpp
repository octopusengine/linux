//https://www.element14.com/community/community/code_exchange/blog/2013/01/02/c-tutorial--hello-raspberry-pi
#include <iostream> //cout <<
#include <stdio.h>  //file+fprintf
#include <fstream> //lines

using namespace std;


int Ms = 20;
int Mr= 10;


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
      if( feof(fp) )
      { 
         break ;
      }
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

	bool gameOver = false;
	while(!gameOver)
	{
		print(maze);

		char move = ' ';
		//cout << "Move: ";
         
/*      
    //c2 = getch();
    int c2 = fgetc(stdin);

    if(c2 == 72) {cout << endl << "Up Arrow" << endl;}
    else if(c2 == 80) {cout << endl << "Down Arrow" << endl;}
    else{cout << endl << "Incorrect Input" << endl;}
*/



		while(move != 'u' && move != 'd' && move != 'l' && move != 'r' && move != 'q'  && move != 'f')
		{
			string key ="";	
			cin >> move;
  			/*
  			int c = fgetc(stdin);
                         if (c == 119){       key = "u";
    }else if (c == 100){       key = "r";
    }else if (c == 115){       key = "d";
    }else if (c == 97){       key = "l";
    }
                         move=key;
*/


                        cout << move << endl;
		}

		if (move == 'u')
		{
			if (maze[row - 1][col] == ' ')
			{
				maze[row][col] = ' ';
				row--;
				maze[row][col] = '*';
			}
			else if (maze[row - 1][col] == '#')
			{
				gameOver = true;
			}
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
			{
				gameOver = true;
			}
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
			{
				gameOver = true;
			}
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
			{
				gameOver = true;
			}
		}
		else if (move == 'q')
		{
			gameOver = true;
		}
		
		else if (move == 'f')
		{
			cout << "file: " << endl;
			loadM(maze);
			saveM(maze);
			
			//save();
			//load();
		}
		
		
		else
		{
			cout << "Invalid Input" << endl;
		}
	}

	return 0;
}
