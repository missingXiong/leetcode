
class Codec 
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) 
	{
		ostringstream out;
		serialize(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) 
	{
		istringstream in(data);
		return deserialize(in);
	}
private:
	void serialize(TreeNode* root, ostringstream& out)
	{
		if(root == nullptr) 
		{
			out << "# ";
			return;
		}
		
		out << root->val << ' ';
		serialize(root->left, out);
		serialize(root->right, out);
	}
	
	TreeNode* deserialize(istringstream& in)
	{
		string str;
		in >> str;
		if(str == "#") return nullptr;
		TreeNode* node = new TreeNode(stoi(str));
		node->left = deserialize(in);
		node->right = deserialize(in);
		return node;
	}
};

428. Serialize and Deserialize N-ary Tree
class Codec 
{
public:
	// Encodes a tree to a single string.
	string serialize(Node* root) 
	{
		ostringstream oss;
		serialize(root, oss);
		return oss.str();
	}

	// Decodes your encoded data to tree.
	Node* deserialize(string data) 
	{
		istringstream iss(data);
		return deserialize(iss);
	}
private:
	void serialize(Node* root, ostringstream& oss)
	{
		if(root == nullptr)
		{
			oss << "# ";
			return;
		}
		
		string s = to_string(root->val) + " " + to_string(root->children.size()) + " ";
		oss << s;
		for(Node* child : root->children)
			serialize(child, oss);
	}
	
	Node* deserialize(istringstream& iss)
	{
		string str, ssize;
		iss >> str;
		if(str == "#") return nullptr;
		iss >> ssize;
		Node* newNode = new Node(stoi(str));
		int size = stoi(ssize);
		for(int i = 0; i < size; i++)
			newNode->children.push_back(deserialize(iss));
		
		return newNode;
	}
};











































