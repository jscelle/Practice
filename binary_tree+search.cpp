// поиск в двоичном дереве

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int key;
    
    struct node *left, *right;
    
    // рекурсивный поиск 
    node* search(struct node* root, int key) 
    {
        // корень нулевой, или по ключу у нас корень
        if (root == NULL || root->key == key)
           return root;
        
        // ключ больше чем ключ корня (правая часть дерева)
        if (root->key < key)
           return search(root->right, key);
     
        // ключ меньше чем ключ корня (левая часть дерева)
        return search(root->left, key);
    }
    
    node* searchAndPrint(struct node* root, int key, vector<string>& path) 
    {
        // корень нулевой, или по ключу у нас корень
        if (root == NULL || root->key == key)
           return root;
        
        // ключ больше чем ключ корня (правая часть дерева)
        if (root->key < key) {
            path.push_back("right");
            return searchAndPrint(root->right, key, path);
        }
        // ключ меньше чем ключ корня (левая часть дерева)
        path.push_back("left");
        return searchAndPrint(root->left, key, path);
    }
    
    // создание 
    node* newNode(int item) 
    {
        // malloc аллоцирует нужное количество в памяти, возращает указатель 
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->key = item;
        // нулим указатели на предков
        temp->left = temp->right = NULL;
        return temp;
    }
    
    node* insert(struct node* node, int key) 
    {
        // если дерево пусто, вернем node
        if (node == NULL)
            return newNode(key);
     
        // сортируем ключи, вставляем в нужное место 
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
     
        // возращаем не изменное дерево, если не прошли условия
        return node;
    }
    
    void print(const string& prefix, node* node, bool isLeft)
    {
        if (node != nullptr)
        {
            cout << prefix;
            cout << (isLeft ? "R--" : "L--");
            // выводим значение
            cout << node->key << endl;
            // рекурсно выводим значения дальше
            print(prefix + (isLeft ? "|   " : "    "), node->right, true);
            print(prefix + (isLeft ? "|   " : "    "), node->left, false);
        }
    }
};

void printPath(vector<string> path) {
    for (auto string : path) { 
        cout << string << endl;
    }
}

int main() {
    struct node* root = NULL;
    
    root = root->insert(root, 50);
    
    root = root->insert(root, 30);
    root = root->insert(root, 20);
    root = root->insert(root, 40);
    root = root->insert(root, 70);
    root = root->insert(root, 60);
    root = root->insert(root, 80);
    root = root->insert(root, 100);
    
    root->print("", root, false);
    
    vector<string> path;
    
    root->searchAndPrint(root, 40, path)->key;
    
    printPath(path);
    
    return 0;
}
