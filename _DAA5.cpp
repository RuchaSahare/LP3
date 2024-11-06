#include<iostream>
#include<vector>
using namespace std;

class nQueen {
public:
    nQueen() {
        cout << "Enter the size of chessboard: ";
        cin >> size;
        board.resize(size, vector<bool>(size, false));
        count = 0;
    }
    
    void print() {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j]) {
                    cout << "Q ";  // Added a space for better formatting
                } else {
                    cout << "X ";  // Fixed missing semicolon
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    
    bool isSafe(int row, int col) {
        for(int i = 0; i < size; i++) {
            if(board[i][col] || 
               (row - i >= 0 && col - i >= 0 && board[row - i][col - i]) ||
               (row - i >= 0 && col + i < size && board[row - i][col + i]) ||
               (row + i < size && col - i >= 0 && board[row + i][col - i]) ||
               (row + i < size && col + i < size && board[row + i][col + i]) // Fixed missing closing parenthesis
            ) {
                return false;
            }
        }
        return true;
    }
    
    void set_first_queen() {
        cout << "Enter the coordinates of first queen: " << endl;
        int row, col;
        cout << "Enter row (1-" << size << "): " << endl;
        cin >> row;
        cout << "Enter column (1-" << size << "): " << endl;
        cin >> col;
        board[row - 1][col - 1] = true;
        print();
    }
    
    void solve(int row) {
        if(row == size) {
            count++;
            print();
            return;
        }
        
        if(anyQueenPlaced(row)) {
            solve(row + 1);
            return;
        }
        
        for(int col = 0; col < size; col++) {
            if(isSafe(row, col)) {
                board[row][col] = true;
                solve(row + 1);
                board[row][col] = false; // Backtrack
            }
        }
    }
    
    void display() {
        if(count > 0) {
            cout << "Solution exists for given position of queen." << endl;
        } else {
            cout << "Solution does not exist for this position of queen." << endl;
        }
    }
    
private:
    int size;
    int count;
    vector<vector<bool>> board;
    
    bool anyQueenPlaced(int row) {
        for(int col = 0; col < size; col++) {
            if(board[row][col]) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    nQueen n;
    n.set_first_queen();
    n.solve(0);
    n.display();
    return 0;
}

