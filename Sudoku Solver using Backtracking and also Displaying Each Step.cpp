#include<iostream>
#include<conio.h>
#include<windows.h>
//assigned a Constant value to a Varible
#define N 9
using namespace std;


//To check whether the number is there in Row, if it is there then return false
bool Present_in_Row(int Matrix[N][N],int row,int num)
{
    for(int i=0;i<N;i++)
    {
        if(Matrix[row][i] == num)
        {
            return true;
        }
    }
    return false;
}


//To check whether the number is there in Column, if it is there then return false
bool Present_in_Column(int Matrix[N][N],int column,int num)
{
    for(int i=0;i<N;i++)
    {
        if(Matrix[i][column] == num)
        {
            return true;
        }
    }
    return false;
}

//To check whether the number is there in particular 3*3 Square, if it is there then return false
bool Present_in_Square(int Matrix[N][N],int Square_Start_Row,int Square_Start_Column,int num)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(Matrix[i+Square_Start_Row][j+Square_Start_Column] == num)
            {
                return true;
            }
        }
    }
    return false;
}


//Function to Check whether the Number which is to be Assigned is Safe or not.
//(i.e. it should not be attacked by that Row,Column or that 3*3 Square
bool Check_Number(int Matrix[N][N],int row,int column,int num)
{
    return (!Present_in_Row(Matrix,row,num) && !Present_in_Column(Matrix,column,num) && !Present_in_Square(Matrix,row - row%3,column - column%3,num) && Matrix[row][column] == 0);
}


bool Search_For_Empty_Block(int Matrix[N][N],int& row,int& column)
{
    for(row=0;row<N;row++)
    {
        for(column=0;column<N;column++)
        {
            if(Matrix[row][column] == 0)
            {
                return true;
            }
        }
    }
    return false;
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
bool Sudoku_Solver(int Matrix[N][N])
{
    int row = 0,column = 0;
    if(!Search_For_Empty_Block(Matrix,row,column))
    {
        return true;
    }


    //for assigning the Number from 1 to 9 to the Empty Block one by one and
    //check if the Number is safe or not by calling check_number() function.
    for(int number=1;number<=N;number++)
    {
        if(Check_Number(Matrix,row,column,number))
        {
            Matrix[row][column] = number;
            system("cls");
            Print_Matrix(Matrix);
            if(Sudoku_Solver(Matrix))
            {
                return true;
            }
            Matrix[row][column] = 0;
        }
    }
    return false;//Backtracking happens here

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
        cout<<" Wait..."<<endl;
        Sleep(3000);
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

    if(Sudoku_Solver(Matrix) == true)
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
