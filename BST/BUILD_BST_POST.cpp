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

node *build(vector<int> &post, int n, int low, int up)
{

    static int idx = n - 1;
    if (idx < 0 or (post[idx] < low or post[idx] > up))
    {
        return NULL;
    }
    node *newnode = new node(post[idx--]);
    newnode->right = build(post, n, newnode->data, up);
    newnode->left = build(post, n, low, newnode->data);

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
    vector<int> post(n);
    for (int i = 0; i < n; i++)
        cin >> post[i];
    node *root = NULL;
    root = build(post, n, INT_MIN, INT_MAX);
    display(root);
}