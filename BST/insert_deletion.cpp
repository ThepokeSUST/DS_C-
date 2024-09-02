#include <iostream>

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
class tree
{

    node *root;

public:
    tree()
    {
        this->root = NULL;
    }

private:
    node *insert_(int ele, node *root)
    {
        if (!root)
        {
            node *newnode = new node(ele);
            return newnode;
        }

        if (root->data < ele)
            root->right = insert_(ele, root->right);
        else
            root->left = insert_(ele, root->left);
    }

public:
    void insert(int ele)
    {
        this->root = insert_(ele, root);
    }

private:
    void inorder(node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

public:
    void display()
    {

        node *temp = root;
        inorder(temp);
    }
};

int main()
{
    cout << "enter data size ";
    int n;
    cin >> n;
    tree t;
    while (n--)
    {
        int ele;
        cin >> ele;
        t.insert(ele);
    }
    t.display();
}