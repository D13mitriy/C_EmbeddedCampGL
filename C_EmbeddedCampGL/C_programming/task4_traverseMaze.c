        #include <stdio.h>
    #include <stdlib.h>

    #define ROW 11
    #define COL 11
    #define N 121


    int maze[ROW][COL] = { {0,0,0,0,0,1,0,0,0,0,0},
                           {0,1,1,1,1,1,0,1,1,1,0},
                           {0,0,0,0,0,1,0,0,0,1,0},
                           {0,1,1,1,0,1,1,1,1,1,0},
                           {0,1,0,1,0,0,0,0,0,1,0},
                           {0,1,0,1,1,1,1,1,1,1,0},
                           {0,0,0,1,0,0,0,1,0,1,0},
                           {0,1,1,1,0,1,1,1,0,1,0},
                           {0,1,0,0,0,0,0,0,0,1,0},
                           {0,1,1,1,1,1,0,0,1,1,0},
                           {0,0,0,0,0,1,0,0,0,0,0} }; 
 

    void printMaze(int maze[][COL])
    {
	    size_t x, y;
	    static int counter= 0;
	    printf("\n%d)\n", counter);
	    for( x = 0; x < ROW; ++x)
	    {
		    for( y = 0; y < COL; ++y)
		    {
			    printf("%d", maze[x][y]);
		    }
		
		puts("");
	    }
   	    printf("\n\n");
   	    counter++;
    }

    
    int validMove( int maze[][COL], int r, int c, int * const finish)
    {
    
	    return ( r>= 0 && r < COL && c >= 0 && c < ROW && maze[r][c] != 0 && maze[r][c] != 5 && (*finish != 1));
    }

    int* entrance(int maze[ROW][COL], int *fx, int  *fy)
    {
         int * p = NULL;     
         int idx = 0;
     
         for(; idx < COL; ++idx)
         {
            if(maze[*fx][idx] == 1) 
             {	    
	          *fy = idx;
	           p = (int*)&(maze[0][idx]);
	           return p;            
             }
         }
         return p;
    }

    void Next(int maze[][COL], int x, int y, int * counter, int * const finish);

    int goRIGHT(int maze[][COL], int x, int y, int * const finish)
    {
        y += 1;
	Next(maze, x , y, &(maze[x][y]), finish);
        return 1;
    }

    int goDOWN(int maze[][COL], int x, int y, int * const finish)
    {
        x += 1;
	Next(maze, x , y , &(maze[x][y]), finish);
        return 1;
    }

    int goLEFT(int maze[][COL], int x, int y, int * const finish)
    {
        y -= 1;
	Next(maze, x , y, &(maze[x][y]), finish);
	return 1;
    }

    int goUP(int maze[][COL], int x, int y, int * const finish)
    {
     	x -= 1;
	Next(maze, x, y , &(maze[x][y]), finish);	
	return 1;
    }

    void Next(int maze[][COL], int x, int y, int * enter, int * const finish)
    {
        *enter = 5;
        if( x == (ROW - 1) ) //Base of recursion
	{	
		*finish = 1;
		printMaze(maze);
		return;
        }
	printMaze(maze);
	while(enter == NULL)
    	{
       	    printf("No entrance.");		
		    enter = entrance(&maze[x][y], x, y);
        }	    
        	
	    validMove( maze, x, y - 1, finish) ?  goLEFT(maze, x, y, finish) : 0;
          
            validMove( maze, x + 1, y, finish) ?  goDOWN(maze, x, y, finish) : 0;
        
	    validMove( maze, x, y + 1, finish) ? goRIGHT(maze, x, y, finish) : 0;
        
	    validMove( maze, x - 1, y, finish) ?    goUP(maze, x, y, finish) : 0;
        	    
        return maze[x][y] = 1;   
    }


    int X = 0, Y = 0;



    int main()
    {   
	int finish = 0;
        int* p = entrance(maze, &X,&Y);
        printMaze(maze);
        Next(maze, X, Y, p, &finish);    
        return 0;
    }
