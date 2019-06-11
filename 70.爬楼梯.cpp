//爬n阶楼梯，每次可以爬1阶或者2阶，总共的方式
//爬到n阶：
class Solution {
public:
    int climbStairs(int n) {
        if(n<3)return n;
        int n1=1,n2=2;
        for(int i=3;i<=n;i++)
        {
            int n=n2;
            n2=n1+n2;
            n1=n;
        }
        return n2;
    }
};
