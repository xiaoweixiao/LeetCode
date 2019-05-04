//求一个字符串的最长回文子串，我们可以将以每个字符为首的子串都遍历一遍，判断是否为回文，如果是回文，再判断最大长度的回文子串。
//算法简单，但是算法复杂度太高，O（n^3）

//动态规划，对于字符串str，假设dp[i,j]=1表示str[i...j]是回文子串，那个必定存在dp[i+1,j-1]=1。
//这样最长回文子串就能分解成一系列子问题，可以利用动态规划求解了。首先构造状态转移方程
//dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1])否则dp[i][j]=0;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())return "";
        if(s.size()==1)return s;
        int len=s.size();
        int longest=1,start=0;
        vector<vector<bool>> dp(len,vector<bool>(len,0));
        
        for(int i=0;i<len;i++){
            dp[i][i]=true;
            if(i<len-1&&s[i]==s[i+1]){
                start=i;
                longest=2;
                dp[i][i+1]=true;
            }
        }
        for(int len1=3;len1<=len;len1++){//子串长度
            for(int i=0;i+len1-1<len;i++){//起始点
                int j=i+len1-1;//终点
                if(s[i]==s[j]&&dp[i+1][j-1]==true){
                    start=i;
                    longest=len1;
                    dp[i][j]=true;
                }
            }
        }
        return s.substr(start,longest);
    }
};

//我们观察到回文中心的两侧互为镜像。因此，回文可以从它的中心展开，并且只有 2n - 1个这样的中心。
//你可能会问，为什么会是 2n - 1 个，而不是 n个中心？原因在于所含字母数为偶数的回文的中心可以处于两字母之间
//（例如 ：“abba” 的中心在两个b之间），时间复杂度也只有O(n*n)
class Solution {
public:
	string longestPalindrome(string s) {
		if (s == "" || s.size()== 1)
		{
			return s;
		}
		int size = s.size();
		int start = 0;
		int max = 1;
		int len1 = 0, len2 = 0;
		int len = 0;
		for (int i = 0; i < size; i++)
		{
			len1 = retRomeLen(s, i, i);
			len2 = retRomeLen(s, i, i + 1);//如果上面是长度为偶数时候以i为中心，那下面就是奇数个长度以i为中心。
			len = len1>len2 ? len1 : len2;
			if (len >= max)
			{	
				max = len;
				start = i - (len-1) / 2;
			}
		}
		
		return s.substr(start, max);
	}
	// 中心扩散的字符串的长度
	int retRomeLen(string s, int left, int right)
	{
		while (left >= 0 && right < s.size() && s[left] == s[right] )
		{	
			left--;
			right++;
		}
		return right - left -1;
	}
};
