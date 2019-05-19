class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int closest = target+1000000;
		int gap = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			int left = i + 1;
			int right = nums.size() - 1;
			if (left >= right) break;
			while (left<right)
			{
				if (nums[left] + nums[right] + nums[i] == target) return target;
				if (nums[left] + nums[right] + nums[i]<target)
				{
					gap = target - nums[i] - nums[right] - nums[left];
					if (gap<abs(closest - target))
						closest = nums[left] + nums[right] + nums[i];
					left++;
				}
				else if (nums[left] + nums[right] + nums[i]>target)
				{
					gap = nums[left] + nums[right] + nums[i] - target;
					if (gap<abs(closest - target))
						closest = nums[left] + nums[right] + nums[i];
					right--;
				}
			}
		}
		return closest;
	}
};
