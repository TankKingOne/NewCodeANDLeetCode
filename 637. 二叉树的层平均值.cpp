/*
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
 

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> ret;
		
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
			double sum = 0;
			for (size_t i = 0; i < v.size(); ++i)
			{
				sum += v[i];
			}
			sum /= v.size();
			ret.push_back(sum);
		}
		return ret;
	}
};
