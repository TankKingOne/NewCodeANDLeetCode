/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// 1.�ݹ鷨
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

// 2.��ջģ��ݹ鷨
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> ret;

		if (!root)
			return ret;

		TreeNode* p = root;//pָ��ǰ���ʽ��
		while (p || !st.empty())
		{
			while (p) {//����ǰ���ǿ�
				ret.push_back(p->val);//���ʸý��
				st.push(p);//��¼�ý�㵽ջ���������
				p = p->left;//��������������
			}
			// while���������ã���֤����st�ǿ�
			//��p�ǿգ���ôһ����ѹ����Ԫ�أ���ʱst�ǿա���pΪ�գ���stһ���ǿ�
			//������ģ���ʱ���ڵ��Ѿ����ʣ�ͨ�����õ��Һ��Ӻ�Ϳ����Ƴ�
			p = st.top(); 
			st.pop();
			p = p->right;//��������������
		}
		return ret;
	}
};