#include <iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;

/*
    Sets the cursor to specified (x,y) position in console
    params:
    x - x position of the cursor
    y - y position of the cursor
*/
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

struct node {
    int key;
    node* left;
    node* right;
};

class binary_tree {
private:
    node* root = 0;
public:
    node* get_root() {
        return root;
    }
    void insert(const int key, const int value) {
        if (!root) {
            root = new node{ key,0,0 };
            root->left = new node{ value,0,0 };
            return;
        }
        node* n = find(root, key);
        if (!n) return;
        if (!n->left) {
            n->left = new node{ value,0,0 };
            return;
        }
        n->right = new node{ value,0,0 };
    }
    node* find(node* n, const int key) {
        if (!root || !n) return 0;
        if (n->key == key) return n;
        node* r1 = find(n->left, key);
        if (r1) return r1;
        node* r2 = find(n->right, key);
        return r2;
    }
    ~binary_tree() {
        clear_nodes(root);
    }
private:
    void clear_nodes(node* node) {
        if (node) {
            clear_nodes(node->left);
            clear_nodes(node->right);
            delete node;
        }
    }
};

/*
   Returns the depth of the binary tree
   params:
   root - pointer to root of the binary tree
   lvl - current level of the binary tree (by default lvl = 0)
*/
int get_tree_level(node* root, const int lvl = 0) {
    if (!root) return lvl;
    int l1 = get_tree_level(root->left, lvl + 1);
    int l2 = get_tree_level(root->right, lvl + 1);
    return max(l1, l2);
}

/*
    Prints node's key and its left and right branches
    params:
    n - pointer to node that we need to print
    x - x position of cursor in console
    y - y position of cursor in console
    h - height of left and right branches
*/
void print_node(node* n, const int x, const int y, const int h) {
    if (!n) return;
    gotoxy(x, y); cout << n->key;
    for (int i = 1; i <= h; ++i) {
        if (n->left) { gotoxy(x - i, y + i); cout << '/'; }
        if (n->right) { gotoxy(x + i, y + i); cout << "\\"; }
    }
    if (n->left) print_node(n->left, x - h - 1, y + h + 1, (h - 1) >> 1);
    if (n->right) print_node(n->right, x + h + 1, y + h + 1, (h - 1) >> 1);
}

/*
    Prints binary tree node by node
    params:
    root - root node of the binary tree
*/
void print_binary_tree(node* root,const int startY) {
    int lvl = get_tree_level(root);
    int h = 1;
    for (int i = 0; i < lvl - 2; ++i) h = (h << 1) + 1;
    print_node(root, 20, startY, h);
}

int main() {

    binary_tree tree;

    cout << "Enter number of vertexes : ";
    int count; cin >> count;

    for (int i = 0; i < count - 1; ++i) {
        cout << "(key,value) : ";
        int key; cin >> key;
        int value; cin >> value;
        tree.insert(key, value);
    }

    print_binary_tree(tree.get_root(),count + 1);

    return 0;
}
