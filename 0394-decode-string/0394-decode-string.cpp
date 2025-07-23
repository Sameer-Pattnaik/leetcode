class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> countStack;
        string currentStr = "";
        int currentCount = 0;

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                currentCount = currentCount * 10 + (s[i] - '0');
            }
            else if (s[i] == '[') {
                countStack.push(currentCount);
                strStack.push(currentStr);
                currentCount = 0;
                currentStr = "";
            }
            else if (s[i] == ']') {
                int repeatCount = countStack.top();
                countStack.pop();
                string temp = strStack.top();
                strStack.pop();
                while (repeatCount--) {
                    temp += currentStr;
                }
                currentStr = temp;
            }
            else {
                currentStr += s[i];
            }
        }

        return currentStr;
    }
};