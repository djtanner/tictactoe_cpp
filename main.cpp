#include <iostream>

using namespace std;

int main()
{
    char board[3][3] = {{'#', '#', '#'}, {'#', '#', '#'}, {'#', '#', '#'}};
    char player = 'X', winner = '#';

    for (int moves = 0; moves < 9; moves++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                cout << board[i][j] << ' ';
            }
            cout << endl;
        }

        int row, col;
        cout << "Enter a row number (1 or 2 or 3): ";
        cin >> row;
        cout << "Enter a column number (1 or 2 or 3): ";
        cin >> col;

        if (board[row - 1][col - 1] == '#')
        {
            board[row - 1][col - 1] = player;
        }
        else
        {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif

            cout << "Invalid move" << endl;
            continue;
        }
        bool gameEnded = false;
        // check all rows
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            {
                gameEnded = true;
                winner = player;
                break;
            }
        }
        if (gameEnded)
            break;

        // check all cols
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            {
                gameEnded = true;
                winner = player;
                break;
            }
        }
        if (gameEnded)
            break;

        // check diagonals

        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        {
            gameEnded = true;
            winner = player;
        }
        if (gameEnded)
            break;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        {
            gameEnded = true;
            winner = player;
        }
        if (gameEnded)
            break;

        if (player == 'X')
            player = 'O';
        else
            player = 'X';

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
    if (winner == 'X')
        cout << "Player X has won" << endl;
    else if (winner == 'O')
        cout << "Player O has won" << endl;
    else
        cout << "It's a tie" << endl;
    return 0;
}