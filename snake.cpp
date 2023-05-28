# include <iostream>
# include <cstdlib>
# include <ctime>
using namespace std;

int** createsnakeboard(int M, int N)
{
    int** board= new int* [M];
    int count=1;
    for (int i=0; i<M; i++)
    {
        board[i]=new int[N];
    }
    for(int i=M-1; i>=0; i--)
    {
        if (i%2==0)
        {
            for (int j=0; j<N; j++)
            {
                board[i][j]=count++;
            }
        }    
        else
        {
            for (int j=N-1 ; j>=0; j--)
            {
                board[i][j]=count++;
            }
        }
    }
return board;}

void displayboard(int** board, int M, int N)
{
    cout<<endl<<endl;
    for(int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (board[i][j]<10)
                cout<<'0'<<board[i][j]<<' ';
            else    
                cout<< board[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

int** createsnakes(int** board, int M, int N)
{
    int** snakes= new int* [2];
    for (int i=0; i<2; i++)      //create a 2D array
        snakes[i]=new int [N-1]; 
    for (int j=0; j<N-1; j++)    // initialize start of snake
        snakes[0][j]=(rand()%((M*N)-1)+1);
    for (int j=0; j<N-1; j++)    // initialize end of snake
        snakes[1][j]=(rand()%((M*N)-1)+1);
    
    for (int k=0; k<N-1; k++)   //check if 2 start cordinates are same
    {
        for (int l=k+1; l<N-1; l++ )
        {
            if (snakes[0][k]==snakes[0][l])
            {
                snakes[0][l]=(rand()%((M*N)-1)+1);
            }
        } 
    }
    for (int i=0; i<N-1; i++)   // ensuring ends are less than start of snake
    {
        if (snakes[0][i]<snakes[1][i])
        {
            int temp=0;
            temp=snakes[0][i];
            snakes[0][i]=snakes[1][i];
            snakes[1][i]=temp;
        }
        if (snakes[0][i]==snakes[1][i])
        {
            snakes[1][i]=rand()%(((M*N)-1)-1);
        }
    }

    // for(int i=0; i<2; i++)
    // {
    //     for (int j=0; j<N-1; j++)
    //     {
    //         cout<< snakes[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }


return snakes;}

int** createladder ( int** board, int M, int N, int** snakes)
{
    int** ladder= new int* [2];
    for (int i=0; i<2; i++)      //create a 2D array
        ladder[i]=new int [N-1]; 
    for (int j=0; j<N-1; j++)    // initialize start of snake
    {    
        ladder[0][j]=(rand()%((M*N)-1))+1;
        for (int i=0; i<2 ; i++)
        {
            for(int k=0; k<N-1; k++)
            {
                if (ladder[0][j]==snakes[i][k])
                    ladder[0][j]=(rand()%((M*N)-1))+1;
            }
        }
    }
    for (int j=0; j<N-1; j++)    // initialize end of snake
    {    
        ladder[1][j]=(rand()%((M*N)-1))+1;
        for (int i=0; i<2 ; i++)
        {
            for(int k=0; k<N-1; k++)
            {
                if (ladder[1][j]==snakes[i][k])
                    ladder[1][j]=rand()%((M*N)-1);
            }
        }
    }    
    
    for (int k=0; k<N-1; k++)   //check if 2 start cordinates are same
    {
        for (int l=k+1; l<N-1; l++ )
        {
            if (ladder[0][k]==ladder[0][l])
            {
                ladder[0][l]=(rand()%((M*N)-1))+1;
            }
        } 
    }
    for (int i=0; i<N-1; i++)   // ensuring ends are less than start of snake
    {
        if (ladder[0][i]<ladder[1][i])
        {
            int temp=0;
            temp=ladder[0][i];
            ladder[0][i]=ladder[1][i];
            ladder[1][i]=temp;
        }
        if (ladder[0][i]==ladder[1][i])
        {
            ladder[1][i]=(rand()%((M*N)-1))+1;
        }
    }
    
    
    // for(int i=0; i<2; i++)
    // {
    //     for (int j=0; j<N-1; j++)
    //     {
    //         cout<< ladder[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }


return ladder;}

int diceroll()
{
    return (rand()%6+1);
}

void working(int** board,int  rows,int cols,int** snakes,int** ladder)
{
    int player1=0, player2=0, dice;
    bool flag1=0,flag2=0;    
    
    
    while (player1<25 && player2<25)
    {
        if (player1==0)
        {
            dice=diceroll();
            cout<<"Dice is: "<<dice<<endl;
            if (dice==6)
            {
                flag1=1;
                player1=1;
            }
        }
        else
        {
            dice=diceroll();
            cout<<"Dice is: "<<dice<<endl;
            player1+=dice;
            for ( int i=0; i<cols-1; i++)      // snake check
            {
                if (player1==snakes[0][i])
                {
                    cout<<":( Player I got bit ):\n";
                    player1= snakes[1][i];
                    break;
                }
                
            }
            for ( int i=0; i<cols-1; i++)      // ladder check
            {
                if (player1==ladder[1][i])
                {
                    cout<<":) Laaaaaaderrrrrrrrrr (:\n";
                    player1= ladder[0][i];
                    break;
                }                
            }
        }
        if (player1>=25)
        {
            cout<<"\t\t\t\t\tPLAYER 1 WINS";
            break;
        }
        cout<<"Player 1 is at "<<player1<<endl;
        
        char pause;
        cout<<"Enter any key to continue....";
        cin>>pause;
        
        if (player2==0)
        {
            dice=diceroll();
            cout<<"Dice is: "<<dice<<endl;
            if (dice==6)
            {
                flag2=1;
                player2=1;
            }
        }
        else
        {
            dice=diceroll();
            cout<<"Dice is: "<<dice<<endl;
            player2+=dice;
            for ( int i=0; i<cols-1; i++)      // snake check
            {
                if (player2==snakes[0][i])
                {
                    cout<<":( Player II got bit ):\n";
                    player2= snakes[1][i];
                    break;
                }   
            }
            for ( int i=0; i<cols-1; i++)      // ladder check
            {
                if (player2==ladder[1][i])
                {
                    cout<<":) Laaaaaaderrrrrrrrrr (:\n";
                    player2= ladder[0][i];
                    break;
                }                
            }
            if (player2>=25)
            {
                cout<<"\t\t\t\t\tPLAYER 2 WINS\n";
                break;
            }
        }
        cout<<"Player 2 is at "<<player2<<endl;
        pause;
        cout<<"Enter any key to continue....";
        cin>>pause;
    }
}


void startSnakeGame()
{
    srand(time(0));
    int rows,cols;
    cout<<"Enter number of rows: ";
    cin>>rows;
    cout<<"Enter number of columns: ";
    cin>>cols;

    int** board=createsnakeboard(rows, cols);
    displayboard(board,rows,cols);
    int** snakes=createsnakes(board, rows,cols);
    int** ladder=createladder(board, rows,cols, snakes); 
    working(board, rows, cols, snakes, ladder);
    
}

int main()
{

    startSnakeGame();
}