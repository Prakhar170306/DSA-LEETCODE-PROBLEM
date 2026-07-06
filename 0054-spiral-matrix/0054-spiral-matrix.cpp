class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;

        int rows = matrix.size();
        int columns = matrix[0].size();

        int srow = 0;
        int erow = rows - 1;
        int scol = 0;
        int ecol = columns - 1;

        while (srow <= erow && scol <= ecol) {

         
            for (int j = scol; j <= ecol; j++) {
                answer.push_back(matrix[srow][j]);
            }
            srow++;

          
            for (int i = srow; i <= erow; i++) {
                answer.push_back(matrix[i][ecol]);
            }
            ecol--;

     
            if (srow <= erow) {
                for (int j = ecol; j >= scol; j--) {
                    answer.push_back(matrix[erow][j]);
                }
                erow--;
            }

          
            if (scol <= ecol) {
                for (int i = erow; i >= srow; i--) {
                    answer.push_back(matrix[i][scol]);
                }
                scol++;
            }
        }

        return answer;
    }
};