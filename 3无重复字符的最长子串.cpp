//暴力破解时间复杂度为O(n*n*n)，超时，代码不写了。

//滑动窗口，时间复杂度O(n*n)
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int  size = s.size();
		int i = 0, ret = 0;
		for (int j = 0; j<size; j++)//[i,j]是不重复子串区间，j每向后移动一位，判断一次
		{
			for (int k = i; k < j; k++)
			{
				if (s[k] == s[j])
				{
					i = k + 1;
					break;
				}
            }
			ret = max(j - i + 1, ret);
		}
		return ret;
	}
};

//
