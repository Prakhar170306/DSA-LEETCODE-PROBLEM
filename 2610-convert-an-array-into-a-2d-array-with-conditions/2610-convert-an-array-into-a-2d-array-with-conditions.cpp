class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> frequency(nums.size() + 1, 0);
        vector<vector<int>> answer;

        for (int value : nums) {
            int row = frequency[value];

            if (row == answer.size()) {
                answer.push_back({});
            }

            answer[row].push_back(value);
            frequency[value]++;
        }

        return answer;
    }
};