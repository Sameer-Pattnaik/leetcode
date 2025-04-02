
Node* zero = new Node(false, true);
Node* one = new Node(true, true);

class Solution {
public:
    Node* create(vector<vector<int>>& grid, int x, int y, int n) {
        if (n == 1) {
            return grid[x][y] == 1 ? one : zero;
        }
        int mid = n / 2;
        Node *topLeft = create(grid, x, y, mid);
        Node *topRight = create(grid, x, y+mid, mid);
        Node *botLeft = create(grid, x+mid, y, mid);
        Node *botRight = create(grid, x+mid, y+mid, mid);
        if (topLeft == topRight and botLeft == botRight and topLeft == botLeft) {
            return topLeft;
        }
        return new Node(false, false, topLeft, topRight, botLeft, botRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return create(grid, 0, 0, grid.size());    
    }
};