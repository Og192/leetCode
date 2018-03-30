#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s0 =0;
        int s1 =0x80000000;
        int temp;
        for (auto a : prices)
        {
            temp = s0;
            s0 = max(s0, s1 + a);
            s1 = max(s1, temp - a);
        }
        return s0;
    }
};