class Solution {
public:
    int findKthNumber(int n, int k) {
        int currentNumber = 1;  // Start with 1 as the smallest lexicographical number
        k--;  // Decrement k because we are considering 1 as the first number already
        
        while (k > 0) {
            long long steps = countSteps(n, currentNumber, currentNumber + 1);
            
            if (steps <= k) {
                // We can skip this whole range
                currentNumber += 1;
                k -= steps;
            } else {
                // Move down the tree by multiplying by 10
                currentNumber *= 10;
                k--;
            }
        }
        
        return currentNumber;
    }
    
    // Function to count the number of lexicographical numbers between 'curr' and 'next'
    long long countSteps(int n, long long curr, long long next) {
        long long steps = 0;
        
        while (curr <= n) {
            steps += std::min((long long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        
        return steps;
    }
};