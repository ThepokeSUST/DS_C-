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
    void inorder(node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
    node *delete_ele_(int ele, node *root)
    {

        if (root->data < ele)
            root->right = delete_ele_(ele, root->right);
        else if (root->data > ele)
            root->left = delete_ele_(ele, root->left);
        else
        {
            // leaf node
            if (not root->left and not root->right)
            {
                delete (root);
                return NULL;
            }
            // left exist
            if (not root->right)
            {
                node *temp = root->left;
                delete (root);
                return temp;
            }
            // right exist
            if (not root->left)
            {
                node *temp = root->right;
                delete (temp);
                return temp;
            }
            // two child exit or left&right exist
            else
            {

                node *par = root;
                node *child = root->left;

                while (child->right)
                {
                    par = child;
                    child = child->right;
                }
                if (root == par)
                {
                    child->right = root->right;
                    delete (root);
                    return child;
                }
                else
                {
                    par->right = child->left;
                    child->right = root->right;
                    child->left = par;
                    delete (root);
                    return child;
                }
            }
        }
    }

public:
    void insert(int ele)
    {
        this->root = insert_(ele, root);
    }
    void delete_ele(int ele)
    {
        delete_ele_(ele, this->root);
    }
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

    cout << endl;
    int del;
    cin >> del;
    t.delete_ele(del);
    t.display();
}