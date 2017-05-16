#include<iostream>

using namespace std;

bool abort(int** board, int dimension, int row, int column)
{
    int i, j;

    for (i = 0; i < column; i++)
        if (board[row][i])
            return true;

    for (i = row, j = column; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return true;

    for (i = row, j = column; j >= 0 && i < dimension; i++, j--)
        if (board[i][j])
            return true;

    return false;
}

// backtracking algorithm
bool backtracking(int** board, int dimension, int column)
{
    // base case
    if (column >= dimension)
        return true;

    for (int i = 0; i < dimension; i++)
    {
        if (!abort(board, dimension, i, column))
        {
            // place the first queen
            board[i][column] = 1;

            // recursion to place the other queens
            if ( backtracking(board, dimension, column + 1) )
                return true;

            board[i][column] = 0; // no solution for this column
        }
    }
    return false; // no solution to the problem
}

void printBoard(int** board, int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

// sample interactive test
int main()
{
    // sample 9x9 matrix to test the algorithm
    int n, i, j;
    cout << "Enter the dimension of the nxn board:" << endl;
    cin >> n;
    int** board;
    board = new int* [n]; // creating a dynamically allocated nxn matrix
    for(int i = 0; i < n; i++)
    {
        board[i] = new int [n];
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            board[i][j] = 0;

    if (backtracking(board, n, 0) == false )
    {
        cout << "Solution does not exist!" << endl;
        for(i = 0; i < n; i++) // freeing the memory allocated for the matrix
            delete[] board[i];
        delete board;
        return 0;
    }
    cout << "An example solution is:" << endl;
    printBoard(board, n);

    for(i = 0; i < n; i++) // freeing the memory allocated for the matrix
        delete[] board[i];
    delete board;
    return 0;
}
