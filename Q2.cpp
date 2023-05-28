#include <iostream>
using namespace std;

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

int main()
{
    int x=3, y=3, z=4;
    char* arr= new char[x*y*z] {'a','b','a','x','o','x','p','a','t','p','a','k','m','a','n','d','a','y','n','t','s','f','a','t','s','a','s'};
    bool flag;
    char*** ptr=ConvertToDynamic( arr, x, y, z);
    char* find=new char[]{"man"};
    int** result= new int* [3];
    for (int i=0; i<3; i++)
    {
        result[i]=new int[3];
    } 
    int col=0;
    flag=MatchString3DArray(ptr,x,y,z,find, result, col);
    cout<<flag<<endl;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<col; j++)
        {
            cout<<result[i][j]<<' ';
        }
        cout<<endl;
    }
    DeleteArray(ptr, x, y, z);
}