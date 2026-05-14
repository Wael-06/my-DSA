import collections

class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        # Create sets to keep track of numbers seen in rows, columns, and 3x3 squares
        rows = collections.defaultdict(set)
        cols = collections.defaultdict(set)
        squares = collections.defaultdict(set) # key = (r // 3, c // 3)

        for r in range(9):
            for c in range(9):
                val = board[r][c]
                
                # If the cell is empty, skip it
                if val == ".":
                    continue
                
                # Check if the value has already been seen in the current row, column, or square
                if (val in rows[r] or 
                    val in cols[c] or 
                    val in squares[(r // 3, c // 3)]):
                    return False
                
                # Add the value to our tracking sets
                rows[r].add(val)
                cols[c].add(val)
                squares[(r // 3, c // 3)].add(val)
                
        return True