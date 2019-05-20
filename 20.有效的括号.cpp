class Solution {
public:
	bool isValid(string s) {
		if (s.length() % 2 != 0) return false;//一但是奇数说明不是有效的括号
		stack<char> mystack;//建立栈
		for (size_t i = 0; i<s.length(); i++)
		{
			if (s[i] == '[' || s[i] == '{' || s[i] == '(')//匹配到左括号
				mystack.push(s[i]);//放入栈中
			else
			{
				if (mystack.empty()) return false;//匹配到右括号，栈中应该存在左括号。否则就是无效的括号
				if ((s[i] == ')'&&mystack.top() == '(') ||s[i] == ']'&&mystack.top() == '[' ||s[i] == '}'&&mystack.top() == '{')
				{
					mystack.pop();//匹配成功删除栈顶元素
					continue;
				}
				else return false;
			}
		}
		if (mystack.empty()) return true;//有效的括号到最后检测结束栈中应没有元素
		else return false;
	}
};
