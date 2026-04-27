class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        l = len(s)
        arr = ["" for _ in range(numRows)]

        row = 0
        down = True

        for i in range(l):
            arr[row] += s[i]

            if row == numRows - 1:
                down = False
            elif row == 0:
                down = True

            if down:
                row += 1
            else:
                row -= 1

        result = ""
        for i in range(numRows):
            result += arr[i]

        return result    
