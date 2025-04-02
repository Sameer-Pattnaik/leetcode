class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int index = -1;
        for (int i = 0; i < bank.size(); i++) {
            if (bank[i] == endGene) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return -1;
        }
        vector<bool> visited(bank.size(), false);
        visited[index] = true;
        queue<pair<string, int>> qu;
        qu.push({bank[index], index});
        int minMutation = 0;
        while (!qu.empty()) {
            int t = qu.size();
            while (t--) {
                pair<string, int> p = qu.front();
                string str = p.first;
                qu.pop();
                visited[p.second] = true;
                if (findDifference(str, startGene) <= 1) {
                    return minMutation + 1;
                }
                for (int i = 0; i < bank.size(); i++) {
                    if (!visited[i]) {
                        if (findDifference(str, bank[i]) == 1) {
                            qu.push({bank[i], i});
                        }
                    }
                }
            }
            minMutation++;
        }
        return -1;
    }

    int findDifference(string str1, string str2) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            if (str1[i] != str2[i]) {
                count++;
            }
        }
        return count;
    }
};