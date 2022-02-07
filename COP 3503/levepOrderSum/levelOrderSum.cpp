#include <iostream>
#include <vector>
#include <queue>
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

vector<int> levelOrder(TreeNode *root)
{
    vector<int> res;

    // create a queue
    queue<TreeNode *> q;

    // push root node to queue
    q.push(root);

    // loop until queue is not empty
    while (!q.empty())
    {
        // get size of queue
        int n = q.size();

        int sum = 0;
        while (n != 0)
        {
            n--;
            // get the first element of queue
            TreeNode *temp = q.front();

            // pop the first element from queue
            q.pop();

            // add value of node popped to sum
            sum += temp->val;

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            // push left and right childs
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            
        }

        // push sum to res
        res.push_back(sum);
    }

    return res;
}
int main()
{
    // create a tree
    TreeNode *root = new TreeNode(9);

    // add nodes to the tree
    root->left = new TreeNode(7);
    root->right = new TreeNode(12);
    root->right->left = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->left->left->right = new TreeNode(4);

    vector<int> res = levelOrder(root);

    // print the sum values for each level
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}