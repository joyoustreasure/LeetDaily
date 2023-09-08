class Solution:

    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        
        for i in range(numRows):
            if i == 0:
                res.append([1])
            else:
                prev_row = res[-1]
                new_row = [1]  # Start with 1
                for j in range(1, i):
                    new_row.append(prev_row[j-1] + prev_row[j])
                new_row.append(1)  # End with 1
                res.append(new_row)
                
        return res

