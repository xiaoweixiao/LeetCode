//直接从原数由后至前取数来由前至后构建新数
//注意越界判断
class Solution {
public:
	int reverse(int x) {
		int ret = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			//检查ret*10是否大于INT_MAX，应该采用下列方式，因为ret*10越界无法和INT_MAX比较
            //MAX_VALUE : 2147483647 MIN_VALUE : -2147483648 
			if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop > 7)) return 0;
			if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && pop < -8)) return 0;
			ret = ret * 10 + pop;
		}
		return ret;
	}
};
