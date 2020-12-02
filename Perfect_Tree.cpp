class TreeNode
{
public:
	static int depth(TreeNode* node)
	{
		int d = 0;
		while (node != NULL)
		{
			d++;
			node = node->left;
		}
		return d;
	}

	static bool isPerfectRecur(TreeNode* root, int d, int level = 0)
	{

		if (root == NULL)
			return true;


		if (root->left == NULL && root->right == NULL)
			return (d == level + 1);


		if (root->left == NULL || root->right == NULL)
			return false;

		return isPerfectRecur(root->left, d, level + 1) && isPerfectRecur(root->right, d, level + 1);

	}

	static bool isPerfect(TreeNode* root)
	{
		int d = depth(root);
		return isPerfectRecur(root, d);
	}

	static TreeNode* leaf()
	{
		return new TreeNode();
	}

	static TreeNode* join(TreeNode* left, TreeNode* right)
	{
		return (new TreeNode())->withChildren(left, right);
	}

	TreeNode* withLeft(TreeNode* left)
	{
		this->left = left;
		return this;
	}

	TreeNode* withRight(TreeNode* right)
	{
		this->right = right;
		return this;
	}

	TreeNode* withChildren(TreeNode* left, TreeNode* right)
	{
		this->left = left;
		this->right = right;
		return this;
	}

	TreeNode* withLeftLeaf()
	{
		return withLeft(leaf());
	}

	TreeNode* withRightLeaf()
	{
		return withRight(leaf());
	}

	TreeNode* withLeaves()
	{
		return withChildren(leaf(), leaf());
	}



private:
	TreeNode* left;
	TreeNode* right;
	TreeNode()
		:left(NULL), right(NULL)
	{

	}
};
