class NumArray {
public:
    NumArray(vector<int>& nums):num(nums) {
        
    }
    
    int sumRange(int i, int j) {
        int ret=0;
        for(int x=i;x<=j;x++)
            ret+=num[x];
        return ret;
    }
private:
    vector<int> num;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
