class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maximum = 0;

        for (const string& str : strs) {
            bool onlyDigits = true;
            int value = 0;

            for (char ch : str) {
                if (ch < '0' || ch > '9') {
                    onlyDigits = false;
                    break;
                }

                value = value * 10 + (ch - '0');
            }

            if (!onlyDigits) {
                value = str.length();
            }

            maximum = max(maximum, value);
        }

        return maximum;
    }
};