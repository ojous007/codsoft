#include <iostream>
using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin();
void board();
bool markSquare(int choice, char mark);

int main()
{
    int player = 1;
    int choice;

    char mark;
    int gameStatus;

    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (markSquare(choice, mark))
        {
            player++;
            gameStatus = checkwin();
        }
        else
        {
            cout << "Invalid move. Please try again." << endl;
            cin.ignore();
            cin.get();
        }
    } while (gameStatus == -1);

    board();

    if (gameStatus == 1)
        cout << "Player " << --player << " wins!" << endl;
    else
        cout << "Game draw!" << endl;

    cin.ignore();
    cin.get();
    return 0;
}

int checkwin()
{
    for (int i = 1; i <= 7; i += 3)
    {
        if (square[i] == square[i + 1] && square[i + 1] == square[i + 2])
            return 1;
    }

    for (int i = 1; i <= 3; i++)
    {
        if (square[i] == square[i + 3] && square[i + 3] == square[i + 6])
            return 1;
    }

    if (square[1] == square[5] && square[5] == square[9])
        return 1;
    if (square[3] == square[5] && square[5] == square[7])
        return 1;

    for (int i = 1; i <= 9; i++)
    {
        if (square[i] != 'X' && square[i] != 'O')
            return -1;
    }

    return 0;
}

void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |     " << endl << endl;
}

bool markSquare(int choice, char mark)
{
    if (choice < 1 || choice > 9 || square[choice] == 'X' || square[choice] == 'O')
        return false;

    square[choice] = mark;
    return true;
}
