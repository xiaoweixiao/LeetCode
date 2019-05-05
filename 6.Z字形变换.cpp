//按行排序，将字符串存储在vector<string>中，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        string ret;
        vector<string> row(min(numRows,(int)s.size()));
        bool down=false;
        int cur=0;
        for(char c:s){
            row[cur]+=c;
            if(cur==0||cur==numRows-1)down=!down;
            cur+=down?1:-1;
        }
        for(string& x:row)
            ret+=x;
        return ret;
    }
};


//按行访问，时间复杂度O(n),空间复杂度O(1)
//行 0 中的字符位于索引k(2*numRows-2)处;
//行numRows-1中的字符位于索引k(2*numRows-2+numRows-1)处;
//内部的 行 ii 中的字符位于索引k(2*numRows-2+i)以及(k+1)(2*numRows-2-i)处;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        string ret;
        int n=s.size();
        int groupLen=2*numRows-2;//按照|/这样的结构将元素分组，特殊点：拐点和终点
        for(int i=0;i<numRows;i++){//行下标
            for(int j=0;j+i<n;j+=groupLen){
                int cur=j+i;//第i行的第j组元素
                int next=j+groupLen-i;//第i行cur的下一个元素
                ret+=s[cur];
                if(i!=0&&i!=numRows-1&&next<n)
                    ret+=s[next];
            }
        }
        return ret;
    }
};
