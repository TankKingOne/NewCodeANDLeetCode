/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// ����һ�����д��浱ǰ����㣬����ѹ�뵱ǰ�ڵ�ĺ��ӽڵ㣬������ǰ�ڵ�
/*
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;

		if (root == nullptr)
			return ret;

		queue<TreeNode*> nodeA;

		nodeA.push(root);
		while (!nodeA.empty())
		{
			queue<TreeNode*> nodeB;
			vector<int> v;

			int size = nodeA.size();
			while (size--)
			{
				TreeNode* tmp = nodeA.front();
				if (tmp->left)
					nodeB.push(tmp->left);
				if (tmp->right)
					nodeB.push(tmp->right);
				v.push_back(tmp->val);
				nodeA.pop();
			}
			nodeA = nodeB;
			ret.push_back(v);
		}
		return ret;
	}
};
*/
// �������뷢����һ�����ж��࣬���иĽ�

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;

		if (root == nullptr)
			return ret;

		queue<TreeNode*> node;

		node.push(root);
		while (!node.empty())
		{
			vector<int> v;

			int size = node.size();
			while (size--)
			{
				TreeNode* tmp = node.front();
				if (tmp->left)
					node.push(tmp->left);
				if (tmp->right)
					node.push(tmp->right);
				v.push_back(tmp->val);
				node.pop();
			}
			ret.push_back(v);
		}
		return ret;
	}
};