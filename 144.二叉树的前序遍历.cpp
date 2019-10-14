/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// 1.递归法
class Solution {
public:
	vector<int> ret;
	vector<int> preorderTraversal(TreeNode* root) {
		if (root == nullptr)
			return ret;

		_preorderTraversal(root);
		return ret;
	}

	void _preorderTraversal(TreeNode* root) {
		if (root) {
			ret.push_back(root->val);
			_preorderTraversal(root->left);
			_preorderTraversal(root->right);
		}
	}
};

// 2.用栈模拟递归法
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> ret;

		if (!root)
			return ret;

		TreeNode* p = root;//p指向当前访问结点
		while (p || !st.empty())
		{
			while (p) {//若当前结点非空
				ret.push_back(p->val);//访问该结点
				st.push(p);//记录该结点到栈，后面回退
				p = p->left;//进入左子树访问
			}
			// while条件的设置，保证下面st非空
			//若p非空，那么一定会压入新元素，此时st非空。若p为空，则st一定非空
			//按先序的，此时父节点已经访问，通过它拿到右孩子后就可以移除
			p = st.top(); 
			st.pop();
			p = p->right;//进入右子树访问
		}
		return ret;
	}
};