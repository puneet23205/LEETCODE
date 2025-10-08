#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Create 9 sets for rows, cols, and boxes
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        
        // Traverse each cell
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.') continue; // Skip empty cells
                
                // Check row
                if (rows[r].count(val)) return false;
                rows[r].insert(val);
                
                // Check column
                if (cols[c].count(val)) return false;
                cols[c].insert(val);
                
                // Identify which 3x3 box the cell belongs to
                int boxIndex = (r / 3) * 3 + (c / 3);
                if (boxes[boxIndex].count(val)) return false;
                boxes[boxIndex].insert(val);
            }
        }
        return true; // If no duplicates found
    }
};
