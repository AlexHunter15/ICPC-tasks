#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    int white_row, white_col, black_row, black_col;
    cin >> white_row >> white_col >> black_row >> black_col;

    // Вычисляем разницу в строках и столбцах между белым и черным конями
    int diff_rows = abs(white_row - black_row);
    int diff_cols = abs(white_col - black_col);

    // Если разница в строках и столбцах одинакова и нечетна, то кони встретятся через один ход
    if (diff_rows == diff_cols && diff_rows % 2 == 1) {
        cout << 1 << " " << white_row << " " << white_col << endl;
    }
    // В противном случае кони встретятся через два хода
    else {
        // Если разница в строках и столбцах четна, то двигаем белого коня на одну клетку
        if ((diff_rows % 2 == 0) && (diff_cols % 2 == 0)) {
            cout << 2 << " " << white_row << " " << white_col << endl;
        }
        // Если разница в строках и столбцах разная по четности, то двигаем белого коня на две клетки
        else {
            // Передвигаем белого коня на клетку, которая находится на одной диагонали с черным конем
            int new_row = white_row + (black_row > white_row ? 1 : -1);
            int new_col = white_col + (black_col > white_col ? 1 : -1);
            cout << 2 << " " << new_row << " " << new_col << endl;
        }
    }

    return 0;
}
