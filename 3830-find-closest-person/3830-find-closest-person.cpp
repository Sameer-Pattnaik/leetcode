class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d = (x - y) * (x + y - 2 * z);
        return (d != 0) << (d > 0);
    }
};