#include <iostream>
#include <queue>

using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

public:
    node(int val)
    {
        // cout << "ok\n";
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void display(node *root)
{
    if (root == NULL)
        return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main()
{

    queue<node *> q;

    int n;
    cin >> n;
    node *root = new node(n);
    q.push(root);

    while (not q.empty())
    {
        node *cur = q.front();
        q.pop();

        int ele;
        cin >> ele;

        if (ele != -1)
        {
            cur->left = new node(ele);
            q.push(cur->left);
        }

        cin >> ele;
        if (ele != -1)
        {
            cur->right = new node(ele);
            q.push(cur->right);
        }
    }

    display(root);
}
