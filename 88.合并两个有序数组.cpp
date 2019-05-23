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
		int i = 0;//标记nums2将要插入的数的下标
		if (n>0)
		{
			for (int pos = 0; (pos<n + m&&n>0); pos++)//pos表示nums2[i]将要被插入的坑位
			{
				if (nums2[i]<nums1[pos]||pos>=m)//我比你还矮，往后站,pos都到了队尾了
				{
					for (int j = m-1; j >=pos; j--)
						nums1[j+1] = nums1[j];
					nums1[pos] = nums2[i];
					i++, n--, m++;
				}
				
			}
		}
	}
};
