//暴力破解O(n*n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for(size_t i=0;i<nums.size();i++){
            for(size_t j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};

//两次hash
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		vector<int> ret(2);

		for (int i = 0; i<nums.size(); i++)
			hash.insert({ nums[i], i });

		for (int i = 0; i < nums.size(); i++)
		{
			if (hash.count(target - nums[i])>0 && hash[target - nums[i]] != i)
			{
				ret[0] = i;
				ret[1] = hash[target - nums[i]];
				break;
			}
		}

		return ret;
	}
};


//hash改进，一次hash
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		vector<int> ret(2);

		for (int i = 0; i < nums.size(); i++)
		{
			if (hash.count(target - nums[i])>0 && hash[target - nums[i]] != i)
			{
				ret[0] = hash[target - nums[i]]; 
				ret[1] = i;
				break;
			}
			hash.insert({ nums[i], i });
		}

		return ret;
	}
};
