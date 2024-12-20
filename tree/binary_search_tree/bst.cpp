#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void insert(Node *&root, int data)
{
    Node *newNode = new Node(data);
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (newNode->data <= temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

void prinTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        // inorder traversal
        prinTree(root->left);
        cout << root->data << " ";
        prinTree(root->right);
    }
}
int main()
{
    Node *root = nullptr;
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);
    // printTree
    prinTree(root);
    return 0;
}