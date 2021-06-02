//A Program to Solve a 9*9 Sodoku Problem

#include<iostream>
#include<conio.h>
#include<windows.h>
//assigned a Constant value to a Varible
#define N 9
using namespace std;

//Function to Check whether the Number which is to be Assigned is Safe or not.
//(i.e. it should not be attacked by that Row,Column or that 3*3 Square
bool Check_Number(int Matrix[N][N],int row,int column,int num)
{

    //To check whether the number is there in Row, if it is there then return false
    for(int i=0;i<N;i++)
    {
        if(Matrix[row][i] == num)
        {
            return false;
        }
    }

    //To check whether the number is there in Column, if it is there then return false
    for(int i=0;i<N;i++)
    {
        if(Matrix[i][column] == num)
        {
            return false;
        }
    }

    int Square_Start_Column = (column - (column%3));
    int Square_Start_Row = (row - (row%3));

    //To check whether the number is there in particular 3*3 Square, if it is there then return false
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(Matrix[i+Square_Start_Row][Square_Start_Column+j] == num)
            {
                return false;
            }
        }
    }

    return true;

}

//For Printing the Sudoku
void Print_Matrix(int Matrix[N][N])
{
    cout<<"\n\n";
    cout<<"       1     2     3     4     5     6     7     8     9"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"    #######################################################"<<endl;
        cout<<" "<<i+1;
        for(int j=0;j<N;j++)
        {
            cout<<"  |  ";
            if(Matrix[i][j] == 0)
            {
                cout<<" ";
            }
            else
            {
                cout<<Matrix[i][j];
            }
        }
        cout<<"  |"<<endl;
    }
    cout<<"    #######################################################"<<endl;
}

//This is the Intermediate Function for the Base Case and
//also for assigning the Number to the Empty Blocks.
//And this is the Function where the Recursion is happening.
bool Sudoku_Solver(int Matrix[N][N],int row,int column)
{
    //if we have reached at the 9 Row and 10 Column.
    //This is the Base Case when the Sudoku is Solved and now go back to Main Function
    if((row == N-1) && (column == N))
    {
        return true;
    }

    //if we have reached the 10 Column of a Particular Row
    //so now we have to move to next Row.
    if(column == N)
    {
        row++;
        column = 0;
    }


    //To check if the Number at that Particular Block is greater than 0 or not,
    //if greater than 0 so move to next column using recursion.
    //else (i.e. when it is equal to 0 that means that block is empty)
    //move forward to the next instruction in the same function.
    if(Matrix[row][column] > 0)
    {
        return (Sudoku_Solver(Matrix,row,column+1));
    }


    //for assigning the Number from 1 to 9 to the Empty Block one by one and
    //check if the Number is safe or not by calling check_number() function.
    for(int number=1;number<=N;number++)
    {
        if(Check_Number(Matrix,row,column,number))
        {
            Matrix[row][column] = number;
            if(Sudoku_Solver(Matrix,row,column+1))
            {
                return true;
            }
        }
        Matrix[row][column] = 0;
    }
    return false;

}


//Main Function
int main()
{
    int Matrix[N][N] = {0};
    int Matrix1[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    int ch;
    cout<<" ###############    SUDOKU SOLVER    ############### "<<endl;
    cout<<" Please Select any one Option : "<<endl;
    cout<<" 1. Want to Enter Your Sudoku Question. "<<endl;
    cout<<" 2. Or want to Solve My Sudoku Question(Challenging). "<<endl;
    cout<<" 3. Exit"<<endl;
    cout<<" Enter Your Choice : ";
    cin>>ch;

    switch(ch)
    {
    case 1 :
        cout<<"Enter your Sudoku Problem : \n";
        cout<<" Note : The Spaces Should be assigned with 0"<<endl;
        Sleep(1000);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                system("cls");
                cout<<" ###############    SUDOKU SOLVER    ############### "<<endl<<endl;
                Print_Matrix(Matrix);
                cout<<endl;
                cout<<"Enter Block "<<i+1<<" * "<<j+1<<" : ";
                cin>>Matrix[i][j];
            }
        }
        break;

    case 2 :
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                Matrix[i][j] = Matrix1[i][j];
            }
        }
        break;

    case 3 :
        cout<<"Thank You For Playing...#### Made By Anshul Verma  ####"<<endl;
        exit(1);
        break;

    default:
        cout<<"You Entered a Wrong Choice..."<<endl;
        exit(1);

    }

    cout<<"The Sudoku Question is : "<<endl;
    Print_Matrix(Matrix);
    cout<<"\nWant to Know the Solution of this Sudoku Problem...Press any Key!"<<endl;
    getch();

    if(Sudoku_Solver(Matrix,0,0))
    {
        cout<<"The Solved Sudoku is : "<<endl;
        Print_Matrix(Matrix);
    }
    else
    {
        cout<<"There is no Possible Solution for this Sudoku Problem..."<<endl;
    }
    return 0;
}
