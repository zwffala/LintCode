#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param sx: x for starting point
     * @param sy: y for starting point
     * @param tx: x for target point 
     * @param ty: y for target point
     * @return: if a sequence of moves exists to transform the point (sx, sy) to (tx, ty)
     */
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // write your code here
        vector<bool> results;
        reachingPointsHelper(sx, sy, tx, ty, results);
        for (const auto& result : results) {
            if (result) {
                return true;
            }
        }
        return false;
    }

private:
    void reachingPointsHelper(int curX, int curY, int tx, int ty, vector<bool>& results) {
        if (curX == tx && curY == ty) {
            results.emplace_back(true);
            return;
        }
        if (curX > tx || curY > ty) {
            results.emplace_back(false);
            return;
        }
        reachingPointsHelper(curX + curY, curY, tx, ty, results);
        reachingPointsHelper(curX, curX + curY, tx, ty, results);
    }
};

int main() {
    Solution s;
    cout<<s.reachingPoints(1,1,2,2)<<endl;
}