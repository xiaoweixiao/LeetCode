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

//改进版本的滑动窗口，O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size(),ret=0,arr[128]={0};
        for(int i=0,j=0;j<len;j++)//i~j的区间为无重复字符串区间
        {
            if(arr[s[j]]==0||arr[s[j]]<i)//当前字符未出现||区间i被更新之后，又来了新字符
                ret = max(ret, j - i + 1);
            else
                i=arr[s[j]];//arr[s[j]]统计i以前的字符，也就是出现过的重复字符个数
            arr[s[j]] = j + 1;
        }
        return ret;
    }
};
