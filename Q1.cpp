// Syed Aalyan Raza Kazmi
// 22I-0833
// Section A 
// Assignment 1

#include <iostream>
using namespace std;

//Question 1
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
            i--; // adjust index to recheck current position
        }
    }    
    ptr[lengthpara] = '\0'; // add null character at end of the new string
    return ptr;
}

// int main()
// {
//     char* given= new char [] {"A son asked his father (a programmer) why the sun rises in the east, and sets in the west. His response? It works, don’t touch!"};
//     char* to_remove= new char [] {"(a programmer)"};
//     cout<< removeSentence( given, to_remove)<<endl;
//     delete[] given;
//     delete[] to_remove;
// }


// Question 2
bool FindSubString(char* Str, char* substr, int& start, int& end) {
    int lenstr = 0, lensubstr = 0, j = 0;
    while (Str[j]) {
        lenstr++;
        j++;
    }
    j = 0;
    while (substr[j]) {
        lensubstr++;
        j++;
    }

    bool flag = false;
    for (int i = 0; i < lenstr; i++) {
        if (Str[i] == (*substr)) {
            int k = i;
            for (int j = 0; j < lensubstr; j++) {
                if (Str[k] != substr[j]) {
                    flag = true;
                    break;
                }
                k++;
                if (k == lenstr) k = 0;
            }
            if (flag == false) {
                start = i;
                end = (i + lensubstr-1) % lenstr;
                break;
            }
        }
    }
    return !flag;
}

// int main()
// {
//     int start = -1, end = -1;
//     char* given = new char[] { "abcdab" };
//     char* to_find = new char[] { "bad" };
//     bool flag = FindSubString(given, to_find, start, end);
//     cout << start << endl << end << endl << flag;
//     delete given;
//     delete to_find;
// }

// Question 3

int pascal(int row, int col) {
        
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

// int main() {
//     int rownum, colnum;
//     cout << "Enter the row: ";
//     cin >> rownum;
//     cout << "Enter the column: ";
//     cin  >> colnum;
//     cout << pascal(rownum, colnum) << endl;
    
// return 0;}

//Question 4

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
    
    if (n % divisor == 0) 
    {
        sumOfDivisors += divisor;
    }
    divisor++;
    
return isperfectNumber(n);}

int main()
{
    int number;
    cout<< "Enter number to check for perfect number: ";
    cin>>number;
    cout<<isperfectNumber(number);
}
