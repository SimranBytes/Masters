#include <bits/stdc++.h>
using namespace std;

class NQueen {
    int n;
    vector<int> colAtRow;          // colAtRow[r] = chosen column for row r
    vector<bool> cols, diag1, diag2;

    bool solveRow(int r) {
        if (r == n) return true; // placed all queens
        for (int c = 0; c < n; ++c) {
            if (cols[c] || diag1[r - c + n - 1] || diag2[r + c]) continue;
            cols[c] = diag1[r - c + n - 1] = diag2[r + c] = true;
            colAtRow[r] = c;
            if (solveRow(r + 1)) return true;
            cols[c] = diag1[r - c + n - 1] = diag2[r + c] = false;
        }
        return false;
    }

public:
    explicit NQueen(int n) : n(n), colAtRow(n, -1), cols(n, false),
        diag1(2 * n - 1, false), diag2(2 * n - 1, false) {}

    bool solve() { return solveRow(0); }

    void printBoard() const {
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c)
                cout << (colAtRow[r] == c ? 'Q' : '.') << ' ';
            cout << '\n';
        }
    }
};

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    if (n <= 0) {
        cout << "N must be positive.\n";
        return 0;
    }
    NQueen solver(n);
    if (solver.solve()) {
        cout << "One solution:\n";
        solver.printBoard();
    } else {
        cout << "No solution exists for N = " << n << "\n";
    }
    return 0;
}
