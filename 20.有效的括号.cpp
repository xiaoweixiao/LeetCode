//利用栈的性质，先进后出，遇到左括号则压入栈，遇到右括号则与栈顶元素匹配，若匹配成功则将栈顶元素弹出，反之返回false。
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


//使用map，减少判断次数，时间快了许多
class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0) return false;//一但是奇数说明不是有效的括号
        map<char,char> wordbook;//建立哈希表
        wordbook.insert(map<char,char>::value_type(')','('));
        wordbook.insert(map<char,char>::value_type(']','['));
        wordbook.insert(map<char,char>::value_type('}','{'));
        stack<char> mystack;//建立栈
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='['||s[i]=='{'||s[i]=='(')//匹配到左括号
                mystack.push(s[i]);//放入栈中
            else if(s[i]==']'||s[i]=='}'||s[i]==')')//匹配到右括号
            {
                if(mystack.empty()) return false;
                //匹配到右括号，栈中应该存在左括号。否则就是无效的括号
                if(wordbook[s[i]]==mystack.top())//与栈顶元素进行匹配
                {
                    mystack.pop();//匹配成功删除栈顶元素
                    continue;
                }
                else return false;
            }
        }
        if(mystack.empty()) return true;//有效的括号到最后检测结束栈中应没有元素
        else return false;
    }
};
