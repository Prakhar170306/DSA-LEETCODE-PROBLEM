class Solution {
public:
    vector<vector<int >> construct2DArray(
        vector<int>& original,
        int limit,
        int quantity
    ) {
        if (original.size() != limit * quantity) {
            return {};
        }

        vector<vector<int >> answer(limit, vector<int>(quantity));

        int index = 0;

        for (int idx = 0; idx < limit; idx++) {
            for (int inner = 0; inner < quantity; inner++) {
                answer[idx][inner] = original[index];
                index++;
            }
        }

        return answer;
    }
};