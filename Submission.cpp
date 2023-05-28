// Syed Aalyan Raza Kazmi
// 22I-0833
// Section A 
// Assignment 1

#include <iostream>
using namespace std;

char* removeSentence(char* Para, char* input)
{
    int lengthpara=0, lengthinput=0, location;
    for (int i=0; Para[i]!='\0'; i++)
    {
        lengthpara++;
    }
    char* ptr= new char[lengthpara];
    for (int i=0; Para[i]!='\0'; i++)
    {
        ptr[i]=Para[i];
    }
    for (int i=0; input[i]!='\0'; i++)
    {
        lengthinput++;
    }
    for (int i=0; ptr[i]!='\0'; i++)
    {
        if (ptr[i]==(*input))
        {
            bool match=0;
            for ( int j=0,k=i; j<lengthinput; j++,k++)
            {
                if (ptr[k]!=input[j])
                {
                    match=1;
                    break;
                }
            }
            if (match==0)
            {
                location= i;
                for ( int a=location; a<lengthpara-lengthinput; a++)
                {
                    ptr[a]=ptr[a+lengthinput];
                }
                lengthpara -= lengthinput;
                i -= lengthinput;
            }
        }
    }
    for (int i = 0; i < lengthpara - 1; i++)
    {
        if (ptr[i] == ' ' && ptr[i] == ptr[i+1])
        {
            lengthpara--;
            for (int k = i; k < lengthpara; k++)
            {
                ptr[k] = ptr[k+1];
            }
            i--;
        }
    }    
    ptr[lengthpara] = '\0'; 
    return ptr;
}

bool FindSubString(char* Str, char* substr, int& start, int& end)
{
    int lenstr=0, lensubstr=0, j=0;    
    while(Str[j])
    {
        lenstr++;
        j++;
    }
    j=0;    
    while(substr[j])
    {
        lensubstr++;
        j++;
    }        
    
    bool flag=false;
    for ( int i=0; i<lenstr; i++)
    {
        if (Str[i]==(*substr))
        {
            for (int j=0; j<lensubstr; j++)
            {
                if  (Str[(i+j)%lenstr]!=substr[j])
                {
                    flag=true;
                    break;
                }
            }             
        }
    if (flag==false)
            {
                start=i;
                end=i+lensubstr;
                while (end>lenstr)
                    end-=lenstr;
                break;
            }    
    }
return !flag;
}

char*** ConvertToDynamic(char arr[], int x, int y, int z)
{
    char*** ptr= new char**[x];
    for (int i=0; i<x; i++)
    {
        ptr[i]=new char*[y];
        for (int j=0; j<y; j++)
        {
            ptr[i][j]=new char[z];
            for (int k=0; k<z; k++)
            {
                ptr[i][j][k] = arr[(i*y*z) + (j*z) + k];
            }

        }    
    }
return ptr;}

bool MatchString3DArray(char*** mat, int xSize, int ySize, int zSize, char * input, int** resultMat, int& colSize)
{
    int leninput=0,i=0;
    bool flag=0;
    while(input[i])
    {
        colSize++;
        i++;

    }
    for (int i=0; i<xSize; i++)
    {
        for (int j=0; j<ySize; j++)
        {
            for (int k=0; k<zSize; k++)
            {
                if (mat[i][j][k]==input[0])
                {
                    // flag=1;
                    // for (int l=0; l<colSize; l++)
                    // {
                    //     if (mat[i][j][k+l]==input[l])
                    //         continue;
                    //     else if(mat[i][j+l][k] == input[l])
                    //         continue;
                    //     else if(mat[i][j+l][k+l] == input[l])
                    //         continue;
                    //     else if(mat[i + l][j][k] == input[l])
                    //         continue;
                    //     else if(mat[i + l][j+l][k] == input[l])
                    //         continue;
                    //     else if(mat[i + l][j][k+l] == input[l])
                    //         continue;
                    //     else if(mat[i + l][j+l][k+l] == input[l])
                    //         continue;
                    //     else
                    //         flag = 0;

                   // }
                    flag=1;
                    for (int l=0; l<colSize; l++)
                    {
                        if (mat[i][j][k+l]!=input[l])
                        {
                            flag=0;
                            break;
                        }
                    }
                    if (flag==1)
                    {
                        for (int a=0; a<colSize; a++)
                        {
                            for (int b=0; b<3; b++)
                            {
                                int num=k;
                                if (b==0)
                                    resultMat[b][a] = i;
                                else if(b==1)
                                    resultMat[b][a] = j;
                                else 
                                    resultMat[b][a]=num++;    
                            }
                        }
                    return 1;
                    }
                    flag=1;
                    for (int l=0; l<colSize; l++)
                    {
                        if (mat[i][j+l][k]!=input[l])
                        {
                            flag=0;
                            break;
                        }  
                    }
                    if (flag==1)
                    {
                        for (int a=0; a<colSize; a++)
                        {
                            for (int b=0; b<3; b++)
                            {
                                int num=j;
                                if (b==0)
                                    resultMat[b][a]=i;
                                else if (b==1)
                                    resultMat[b][a]=num++;
                                else
                                    resultMat[b][a]=k;    
                            }
                        }
                        return 1;
                    }
                    flag=1;
                    for (int l=0; l<colSize; l++)
                    {
                        if (mat[i+l][j][k]!=input[l])
                        {
                            flag=0;
                            break;
                        }
                    }
                    if (flag==1)                    {
                        for (int a=0; a<colSize; a++)
                        {
                            for (int b=0; b<3; b++)
                            {
                                int num=i;
                                if (b==0)
                                    resultMat[b][a]=num++;
                                else if (b==1)
                                    resultMat[b][a]=j;
                                else
                                    resultMat[b][a]=k;    
                            }
                        }
                        return 1;
                    }                    
                }
            }
        }    
    }
return flag;}

void DeleteArray(char***& arr, int x, int y, int z)
{
    for (int i=0; i<x; i++)
    {
        for (int j=0; j<y; j++)
        {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
    arr=NULL;
}

bool isperfectNumber(int n)
{
    static int divisor=1;
    static int sumOfDivisors=0;
    if (divisor == n) 
    {
        if (sumOfDivisors == n) 
        {
            return true;
        } 
        else
        {
            return false;
        }
    }
    
    else if (n % divisor == 0) 
    {
        sumOfDivisors += divisor;
    }
    divisor++;
    
return isperfectNumber(n);}

int helper_vowel(char* str,int length,int itteration )
{
    if ( itteration==length)
    {
        return 0;
    }
    else if (str[itteration]=='a'|| str[itteration]=='e'||str[itteration]=='i'||str[itteration]=='o'||str[itteration]=='u'||str[itteration]=='A'||str[itteration]=='E'|| str[itteration]=='I'||str[itteration]=='O'||str[itteration]=='U')
    {
        itteration++;
        return 1+ helper_vowel(str, length, itteration);
    }
    else
    {
        itteration++;
        return  helper_vowel(str, length, itteration);
    }
}

int findVowels(char* str)
{
    int length=0, vowels=0, itteration=0;
    for (int i=0; str[i]; i++ )
    {
        length++;
    }
    vowels=helper_vowel(str, length, itteration);
    
return vowels;}


int pascal(int row, int col)
{
    if (col == 0)  
        return 1;
    else if (col == row)  
        return 1; 
    else
    {
        row--;
        int colless=col-1; 
        int pascal1= pascal(row, colless );
        int pascal2= pascal(row, col);
        int result= pascal1+pascal2;
        return result;
    }
}

void helper_pattern1(int val,char space=' ')
{
    if (val==0)
        return;
    cout<< space<<space;
    helper_pattern1(--val);
}

void PrintPattern1(int start, int end)
{
    int num = end/2;
    if (start==end)
        return;
    else
    {
        if ( start <= num )
        {
            helper_pattern1( num -start);
        }
        else if (start >num)
        {
            helper_pattern1(start-num);
        }
    }
    cout<<'*'<<endl;
    PrintPattern1( start+1, end); 
}

void printstars(int star)
{
    if (star==0)
        return;
    else
    {
        cout<<'*';
        printstars(star-1);
    }    
}

void printspaces(int spaces)
{
    if (spaces==0)
        return;
    else
    {
        cout<<' ';
        printspaces(spaces-1);
    }    
}

void upperpart(int n,int spaces)
{
    if (n==0)
        return;
    printstars(n);
    printspaces(spaces);
    printstars(n);
    cout<<endl;
    upperpart(--n,spaces+2);
}

void lowerpart(int stars, int spaces, int n)
{
    if (stars>n)
        return;
    printstars(stars);
    printspaces(spaces);
    printstars(stars);
    cout<<endl;
    lowerpart(++stars,spaces-2,n);
}

void printHollowDiamond(int n)
{
    int spaces=0;
    upperpart(n,spaces);
    spaces=2*n-2;
    int stars=1;
    lowerpart(stars,spaces,n);
}

void printdots(int dots)
{
    if (dots==0)
        return;
    else
    {
        cout<<".";
        printdots(--dots);
    }    
}

void helper_pattern2(int val,int  val1)
{
    printspaces(val1);
    cout<<'#';
    printdots(val1);
    printstars((val-val1)*2);
    cout<<'|';
    printstars((val-val1)*2);
    printdots(val1);
    cout<<'#'<<endl;
}

void helper_pattern21(int val)
{
    printspaces(val);
    cout<<'#';
    printdots(val);
    cout<<'|';
    printdots(val);
    cout<<'#'<<endl;
}

void helper_pattern22(int val,int val1)
{    
    if (val1==1)
        {
            return;
        } 
        else
        {   
            helper_pattern2(val,val1);
            helper_pattern22(val, --val1);
            helper_pattern2(val,val1);   
        }
}
void PrintPattern2(int val, int val1)
{
    helper_pattern22(val, val1);
    helper_pattern21(val);
}

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