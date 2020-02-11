#include <iostream>
using namespace std;

const int N=8; // Number of Queens
int c=0; // column count

int m[N][N]; //2D array to represent the chess board

void initialize() //funtion to initialize array
{
    int m[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            m[i][j]=0;
        }
    }
}

void print() //print array
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << m[i][j];
            cout << "  ";
        }
        cout<<endl;
    }
}

bool check(int r) //to check if a queen can be placed
{
    for(int i=0;i<N;i++) //checking row
    {
        if(m[r][i]==1)
        {
            return false;
        }
    }
    //checking diagonal
    for(int i=r,j=c;i>=0 && j >=0;i--,j--)
    {
        if(m[i][j]==1)
        {
            return false;
        }
    }
    for(int i=r,j=c;i<N && j >=0;i++,j--)
    {
        if(m[i][j]==1)
        {
            return false;
        }
    }
    //else placing queen is ok
    return true;
}

int main() {

    initialize();
    int x,ind,i=0;

    while (c<N) //loop for column count
    {
        while (i<N) //loop for row count
        {
            if(check(i)) //checking if queen can be placed
            {
                m[i][c]= 1; //placing a queen
                ind=1; // indicator to know check if a queen is placed
                break;
            }
            else
            {
                ind=0;
            }
            i+=1;
        }
        if(ind==0) //when queen is not placed backtracking
        {
            c=c-1;
            for(int j=0;j<N;j++) //to find and remove queen
            {
              if(m[j][c]==1)
              {
                  x = j;
                  break;
              }
            }
            i=x+1;
            m[x][c]=0; //queen removed
        }
        else
        {
            i=0;
            c++;
        }
    }
    print(); //printing solution
    return 0;
}