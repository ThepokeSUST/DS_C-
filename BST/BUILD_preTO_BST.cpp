#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *build(vector<int> &pre, int n, int low, int up)
{

    static int idx = 0;
    if (idx == n or (pre[idx] < low or pre[idx] > up))
    {
        return NULL;
    }
    node *newnode = new node(pre[idx++]);
    newnode->left = build(pre, n, low, newnode->data);
    newnode->right = build(pre, n, newnode->data, up);

    return newnode;
}

void display(node *root)
{
    if (not root)
        return;

    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main()
{
    int n;
    cin >> n;
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    node *root = NULL;
    root = build(pre, n, INT_MIN, INT_MAX);
    display(root);
}