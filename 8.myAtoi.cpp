class Solution {
public:
	inline int Digital(char c)
	{
		if (c >= '0' && c <= '9') {
			return c - '0';
		}
		else {
			return -1;
		}
	}

	int myAtoi(string str){
		bool sign = false;
		int result = 0;
		int digital;

		string::iterator it = str.begin();
		/* 跳过开头无效的空格. */
		while (it!=str.end()&&*it == ' ') 
			it++;

		/* 识别符号. */
		if (*it == '+') 
			it++;
		else if (*it == '-') {
			it++;
			sign = true;
		}

		/* 识别每一个数字. */
		while ((digital = Digital(*it++)) >= 0) {
			/*　添加符号. */
			if (sign == true)
				digital = -digital;

			if ((result > INT_MAX / 10)
				|| (result == INT_MAX / 10 && digital > INT_MAX % 10)) 
				return INT_MAX;
			if ((result < INT_MIN / 10)
				|| (result == INT_MIN / 10 && digital < INT_MIN % 10)) 
				return INT_MIN;

			result = result * 10 + digital;
		}
		return result;
	}
};
