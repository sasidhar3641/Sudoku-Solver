#include <iostream>
#include <vector>

using namespace std;

class sudoku_Solver {
private:
    vector<vector<char>> board;
public:
    void board_create() {
        board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };
    }

    void sudokuSolver() {
        if(solve()) {
            display();
        } else {
            cout << "No solution exists!" << endl;
        }
    }

    bool solve() {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(isValid(i, j, c)) {
                            board[i][j] = c;
                            if(solve()) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i]==c)
                return false;
            if(board[i][col]==c)
            return false;
            int ir=3*(row/3)+i/3;
            int ic=3*(col/3)+i%3;
            if(board[ir][ic]==c)
            return false;
        }
        return true;
    }

    void display() {
        int i,j;
        for (i=0;i<9;i++) {
            for (j=0;j<9;j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    sudoku_Solver ss;
    ss.board_create();
    ss.sudokuSolver();
    return 0;
}
