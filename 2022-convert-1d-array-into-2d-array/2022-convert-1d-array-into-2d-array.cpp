class Solution {
public:
    vector<vector<int>> construct2DArray(
        vector<int>& original,
        int m,
        int n
    ) {
        // Required number of elements available nahi hain
        if (original.size() != m * n) {
            return {};
        }

        vector<vector<int>> answer(m, vector<int>(n));

        int index = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                answer[i][j] = original[index];
                index++;
            }
        }

        return answer;
    }
};