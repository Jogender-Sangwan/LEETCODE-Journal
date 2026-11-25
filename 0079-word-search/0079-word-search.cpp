#include <vector>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = static_cast<int>(board.size());
        int n = static_cast<int>(board[0].size());
        int len = static_cast<int>(word.size());

        if (len > m * n) return false;

        array<int, 128> boardFreq{};
        for (const auto& row : board) {
            for (char c : row) {
                ++boardFreq[static_cast<unsigned char>(c)];
            }
        }

        array<int, 128> wordFreq{};
        for (char c : word) {
            ++wordFreq[static_cast<unsigned char>(c)];
            if (wordFreq[static_cast<unsigned char>(c)] > boardFreq[static_cast<unsigned char>(c)]) {
                return false;
            }
        }

        if (boardFreq[static_cast<unsigned char>(word.back())] <
            boardFreq[static_cast<unsigned char>(word.front())]) {
            reverse(word.begin(), word.end());
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == word[0] && dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int idx) {
        if (idx == static_cast<int>(word.size()) - 1) {
            return true;
        }

        char saved = board[r][c];
        board[r][c] = '#';

        static constexpr int dr[4] = {-1, 1, 0, 0};
        static constexpr int dc[4] = {0, 0, -1, 1};

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < static_cast<int>(board.size()) &&
                nc >= 0 && nc < static_cast<int>(board[0].size()) &&
                board[nr][nc] == word[idx + 1]) {
                if (dfs(board, word, nr, nc, idx + 1)) {
                    board[r][c] = saved;
                    return true;
                }
            }
        }

        board[r][c] = saved;
        return false;
    }
};
