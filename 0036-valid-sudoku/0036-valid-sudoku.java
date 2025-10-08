import java.util.*;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        // Create 9 hash sets for rows, columns, and boxes
        HashSet<Character>[] rows = new HashSet[9];
        HashSet<Character>[] cols = new HashSet[9];
        HashSet<Character>[] boxes = new HashSet[9];
        
        for (int i = 0; i < 9; i++) {
            rows[i] = new HashSet<>();
            cols[i] = new HashSet<>();
            boxes[i] = new HashSet<>();
        }
        
        // Traverse the board
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                
                if (val == '.') continue; // skip empty cells
                
                // Check row
                if (rows[r].contains(val)) return false;
                rows[r].add(val);
                
                // Check column
                if (cols[c].contains(val)) return false;
                cols[c].add(val);
                
                // Determine which 3x3 box we're in
                int boxIndex = (r / 3) * 3 + (c / 3);
                if (boxes[boxIndex].contains(val)) return false;
                boxes[boxIndex].add(val);
            }
        }
        return true; // no rule violated
    }
}
