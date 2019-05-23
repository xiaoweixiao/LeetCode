class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++)
            nums1[i+m]=nums2[i];
        sort(nums1.begin(),nums1.end());
    }
};


//自己去实现插入排序
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int sum = m + n;
		int pos = 0;//指向nums2准备存入的nums1的元素下标
		if (n>0)
		{
			for (int i = 0; i<sum&&n; i++)
			{
				if (nums2[pos] <= nums1[i] || i >= m)
				{
					for (int k = nums1.size() - 1; k>i; k--)//将元素后移一位
						nums1[k] = nums1[k - 1];
					nums1[i] = nums2[pos];//插入元素
					pos++,n--,m++;
				}
			}
		}
	}
};
