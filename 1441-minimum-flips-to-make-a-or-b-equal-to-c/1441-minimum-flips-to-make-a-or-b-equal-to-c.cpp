class Solution {
public:
    int minFlips(int a, int b, int c) {
        return popcount<uint>((a | b) ^ c) + popcount<uint>(a & b & ((a | b) ^ c));
    }
};