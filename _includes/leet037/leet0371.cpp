class Solution {
public:
void solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++)
        for (int j = 1; j <= 9; j++)
            row[i][j] = col[i][j] = cel[i][j] = false;
    int remain = 0;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                val[i][j] = board[i][j] - '0';
                row[i][val[i][j]] = col[j][val[i][j]] = cel[(i / 3) * 3 + j / 3][val[i][j]] = true;
            }
            else {
                val[i][j] = 0;
                remain++;
            }
            available[i][j] = 0;
        }
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (!val[i][j])
                for (int k = 1; k <= 9; k++)
                    if (!row[i][k] && !col[j][k] && !cel[(i / 3) * 3 + j / 3][k])
                        available[i][j]++;
    DFS(remain);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            board[i][j] = val[i][j] + '0';
}

void DFS(int remain) {
    if (!remain) {
        found = true;
        return;
    }
    int min_avai = 10, ni, nj;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (!val[i][j] && available[i][j] < min_avai) {
                min_avai = available[i][j];
                ni = i;
                nj = j;
            }
    for (int k = 1; k <= 9; k++)
        if (!row[ni][k] && !col[nj][k] && !cel[(ni / 3) * 3 + nj / 3][k]) {
            int ci[24], cj[24], p = 0;
            for (int j = 0; j < 9; j++)
                if (!val[ni][j] && j != nj && !col[j][k] && !cel[(ni / 3) * 3 + j / 3][k]) {
                    ci[p] = ni;
                    cj[p] = j;
                    available[ci[p]][cj[p]]--;
                    p++;
                }
            for (int i = 0; i < 9; i++)
                if (!val[i][nj] && i != ni && !row[i][k] && !cel[(i / 3) * 3 + nj / 3][k]) {
                    ci[p] = i;
                    cj[p] = nj;
                    available[ci[p]][cj[p]]--;
                    p++;
                }
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (!val[(ni / 3) * 3 + i][(nj / 3) * 3 + j] && i != (ni % 3) && j != (nj % 3) && !row[(ni / 3) * 3 + i][k] && !col[(nj / 3) * 3 + j][k]) {
                        ci[p] = (ni / 3) * 3 + i;
                        cj[p] = (nj / 3) * 3 + j;
                        available[ci[p]][cj[p]]--;
                        p++;
                    }
            row[ni][k] = true;
            col[nj][k] = true;
            cel[(ni / 3) * 3 + nj / 3][k] = true;
            val[ni][nj] = k;
            DFS(remain - 1);
            if (found)
                return;
            val[ni][nj] = 0;
            row[ni][k] = false;
            col[nj][k] = false;
            cel[(ni / 3) * 3 + nj / 3][k] = false;
            for (int i = 0; i < p; i++)
                available[ci[i]][cj[i]]++;
        }
}

int val[9][9], available[9][9];
bool row[9][10], col[9][10], cel[9][10], found = false;
};
