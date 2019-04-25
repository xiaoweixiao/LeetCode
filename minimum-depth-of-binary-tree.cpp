class Solution {
public:
	int run(TreeNode *root) {
		if (root == nullptr)return 0;

		int level = 1, length = 0;
		queue<TreeNode*> que;
		que.push(root);
		TreeNode* front = root;
		TreeNode* back = root;
		while (!que.empty())
		{
			front = que.front();
			que.pop();
			length = que.size();
			if (front->left)que.push(front->left);
			if (front->right)que.push(front->right);
			if (que.size() - length == 0)break;//左右孩子均没有了
			if (back == front)
			{
				level++;
				if (!que.empty())
					back = que.back();
			}
		}
		return level;
	}
};