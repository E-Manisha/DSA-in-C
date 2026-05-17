#include <iostream>
#include <conio.h>
#include <stdlib.h> 
using namespace std;

char ch[10] = {'0','1','2','3','4','5','6','7','8','9'};

class tic_taco {
public:
    void input();
    int condition();
};

void tic_taco::input() {
    system("cls");
    cout << "*** Tic Tac Toe ***\n\n";
    cout << "      |      |     \n";
    cout << "   " << ch[1] << "  |  " << ch[2] << "  |  " << ch[3] << " \n";
    cout << " _____|_____ |_____\n";
    cout << "      |      |     \n";
    cout << "   " << ch[4] << "  |  " << ch[5] << "  |  " << ch[6] << " \n";
    cout << " _____|______|_____\n";
    cout << "      |      |     \n";
    cout << "   " << ch[7] << "  |  " << ch[8] << "  |  " << ch[9] << " \n";
    cout << "      |      |     \n";
}

int tic_taco::condition() {
    
    if (ch[1]==ch[2] && ch[2]==ch[3]) return 1;
    if (ch[4]==ch[5] && ch[5]==ch[6]) return 1;
    if (ch[7]==ch[8] && ch[8]==ch[9]) return 1;
    if (ch[1]==ch[4] && ch[4]==ch[7]) return 1;
    if (ch[2]==ch[5] && ch[5]==ch[8]) return 1;
    if (ch[3]==ch[6] && ch[6]==ch[9]) return 1;
    if (ch[1]==ch[5] && ch[5]==ch[9]) return 1;
    if (ch[3]==ch[5] && ch[5]==ch[7]) return 1;

   
    int count = 0;
    for (int i = 1; i <= 9; i++) {
        if (ch[i] == 'x' || ch[i] == 'O')
            count++;
    }
    if (count == 9) return 0;

    return -1; 
}

int main() {
    tic_taco game;
    int player = 1, input, status = -1;
    int play;

    cout << "Enter how many times you want to play: ";
    cin >> play;

    for (int round = 1; round <= play; round++) {
       
        for (int i = 1; i <= 9; i++) {
            ch[i] = '0' + i;
        }
        status = -1;
        player = 1;

        while (status == -1) {
            game.input();
            player = (player % 2 == 0) ? 2 : 1;
            char mark = (player == 1) ? 'x' : 'O';

            cout << "Enter a number (1-9) to mark for Player " << player
                 << " (or any other number to quit): ";
            cin >> input;

            if (input < 1 || input > 9) {
                status = 0;
                break;
            }

            if (ch[input] == 'x' || ch[input] == 'O') {
                cout << "That spot is already taken! Try again.\n";
                _getch(); 
                continue;
            }

            ch[input] = mark;
            status = game.condition();
            player++;
        }

        game.input();
        if (status == 1) {
            cout << "Player " << --player << " is the winner!\n";
        } else if (status == 0) {
            cout << "It's a draw!\n";
        }

        cout << "Press any key for next round...\n";
        _getch();
    }

    return 0;
}

