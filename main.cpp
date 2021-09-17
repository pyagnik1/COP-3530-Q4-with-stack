#include <iostream>
#include <vector>
#include <list>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *getNewNode(int val)
{
    TreeNode *newNode = new TreeNode;
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

TreeNode *insert(TreeNode *root, int val)
{
    /*
     * It will handle two cases,
     * 1. if the tree is empty, return new node in root
     * 2. if the tree traversal reaches NULL, it will return the new node
     */
    if (root == NULL)
        return getNewNode(val);
    /*
     * if given val is greater than root->key,
     * we should find the correct place in right subtree and insert the new node
     */
    if (root->val < val)
        root->right = insert(root->right, val);
    /*
     * if given val is smallar than root->key,
     * we should find the correct place in left subtree and insert the new node
     */
    else if (root->val > val)
        root->left = insert(root->left, val);
    /*
     * It will handle two cases
     * (Prevent the duplicate nodes in the tree)
     * 1.if root->key == val it will straight away return the address of the root node
     * 2.After the insertion, it will return the original unchanged root's address
     */
    return root;
}

vector<int> levelOrder(TreeNode *root)
{
    // your code

    vector<int> sum;
    int total;
    int currNode;
    list<TreeNode*> list;//store tree elemets
    int numElements;//count number of elemets
    TreeNode *tmp;//store total of 
		list.push_back(root);//


		//traverse untill list is empty
    while (!list.empty())
    {
				//reset total After each height calculation 
        total = 0;
				//list size should be number of elemets at given height
        numElements = list.size();

				cout<<"\n"<<list.size()<<"\n";

        for(int i = 0; i < numElements; i++){

					
					tmp = list.front();
					list.pop_front();
					cout<<"\ntmp->"<<tmp->val<<"\n";
					total += tmp->val;
					cout<<"\ntotal->"<<total<<"\n";

					if(tmp->right != NULL){
						//if there is something at right of the temp
						list.push_back(tmp->right);
						cout<<"\ntmp->right->"<<tmp->right->val<<"\n";
					}

					if(tmp->left != NULL){
						list.push_back(tmp->left);
						cout<<"\ntmp->left->"<<tmp->left->val<<"\n";
					}					
				}

				sum.push_back(total);
    }

    return sum;
}

void inorder(TreeNode *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

int main()
{

    TreeNode *root = NULL;

    root = insert(root, 3);
		root = insert(root, 9);
		root = insert(root, 8);
		root = insert(root, 2);
		root = insert(root, 5);
		root = insert(root, 4);
		root = insert(root, 11);
		inorder(root);

		vector<int> sum = levelOrder(root);

		for (auto i = sum.begin(); i != sum.end(); ++i)
        cout << *i << " \n";
    std::cout << "Hello World!\n";
}