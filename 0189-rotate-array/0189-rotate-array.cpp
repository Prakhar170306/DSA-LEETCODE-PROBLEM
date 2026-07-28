class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k = k % n;

        vector<int> temp(n);

        for(int i = 0; i < n; i++) {
            int newIndex = (i + k) % n;
            temp[newIndex] = nums[i];
        }

        nums = temp;
    }
};