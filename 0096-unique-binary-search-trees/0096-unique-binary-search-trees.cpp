class Solution {
public:
    // Method 4: Catalan Number
    // This method uses the closed-form expression for Catalan numbers to count the number of unique BSTs.
    int numTrees(int n) {
        if (n <= 1) return 1; // Base case: a tree with 0 or 1 node has only 1 structure.
        unsigned long long catalan = 1;
        for (int i = 0; i < n; ++i) {
            catalan = catalan * 2 * (2 * i + 1) / (i + 2);
        }
        return static_cast<int>(catalan);
    }
};