#include <string>
#include <iostream>

class TreeNode
{
public:
	TreeNode(const std::string& s, TreeNode* left = nullptr, TreeNode* right = nullptr) :
		value{ s }, left{ left }, right{ right }
	{
		count = 0;
		if (left != nullptr)
		{
			count += left->count;
		}
		if (right != nullptr)
		{
			count += right->count;
		}
	}

	TreeNode(const TreeNode& origin)
	{
		value = origin.value;
		count = origin.count;
		if (left != nullptr)
		{
			left = new TreeNode{ *origin.left };
		}

		if (right != nullptr)
		{
			right = new TreeNode{ *origin.right };
		}
	}

	TreeNode& operator=(const TreeNode& origin)
	{
		value = origin.value;
		count = origin.count;

		TreeNode* new_left{ nullptr };
		TreeNode* new_right{ nullptr };

		if (origin.left != nullptr)
		{
			new_left = new TreeNode{ *origin.left };
		}

		if (origin.right != nullptr)
		{
			new_right = new TreeNode{ *origin.right };
		}

		delete this->left;
		delete this->right;

		return *this;
	}

	~TreeNode()
	{
		delete left;
		delete right;
	}

private:
	std::string value;
	int count;
	TreeNode* left;
	TreeNode* right;
};

class BinStrTree
{
	BinStrTree(TreeNode* root) :
		root{ root }, use{ new std::size_t{1} } {}

	BinStrTree(const BinStrTree& origin)
	{
		root = origin.root;
		use = origin.use;
		++* use;
	}

	BinStrTree& operator=(const BinStrTree& origin)
	{
		++* origin.use;

		if (-- * use == 0)
		{
			delete root;
			delete use;
		}
		root = origin.root;
		use = origin.use;

		return *this;
	}

	~BinStrTree()
	{
		if (-- * use == 0)
		{
			delete root;
			delete use;
		}
	}

private:
	TreeNode* root;
	std::size_t* use;
};

int main()
{

	return 0;
}