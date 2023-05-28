# include <iostream>
using namespace std;

void helperspace(int n)
{
	if (n<=0){
		
	}
	else{
		cout<<" ";
		helperspace(n-0.5);
	}
}

void PrintPattern1(int start, int end){
	if (end==3){
	}
	else if (end<3){
	cout<<"  *"<<endl;
	}
	else{
	helperspace(end);
	cout<<"*"<<endl;
	PrintPattern1(start,end-2);
	helperspace(end);
	cout<<"*"<<endl;
	}
	
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


int main ()
{
    int num;
    cout<<"Enter number: ";
    cin>>num;
    PrintPattern2(num,num);
}