#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

// Предполагаем, что структура в tree.h такая:
struct Node 
{
    int value;  
    Node* left;
    Node* right;
};

// Изменение баланса в каждой вершине
int changebalance(Node* root) 
{
    if(root == nullptr) return 0;
    
    int leftH = changebalance(root->left);
    int rightH = changebalance(root->right);
    
    // ЗАМЕНЯЕМ значение на баланс
    root->value = rightH - leftH;
    
    return std::max(leftH, rightH) + 1;
}

// Поиск мин элемента и его родителя
Node* search(Node* root, Node* &parent) 
{
    if(root == nullptr) return nullptr;
    
    std::queue<std::pair<Node*, Node*>> q;
    q.push({root, nullptr});
    
    Node* minNode = root;
    parent = nullptr;
    
    while(!q.empty()) 
    {
        Node* v = q.front().first;
        Node* p = q.front().second;
        q.pop();
        
        // Ищем минимум по значению (которое теперь баланс)
        if(v->value < minNode->value) 
        {
            minNode = v;
            parent = p; 
        }
        
        // Добавляем потомков с правильным родителем
        if(v->left) q.push({v->left, v});
        if(v->right) q.push({v->right, v});
    }
    return minNode;
}

// Удаление поддерева
void del(Node* root) 
{
    if(root == nullptr) return;
    
    del(root->left);
    del(root->right);
    
    delete root;
}

int main() 
{
    // Предположим, root уже создан (в tmain.cpp)
    // Node* root = ...;
    
    // 1. Распечатать исходное дерево
    // printTree(root);
    
    // 2. Заменить значения на баланс
    changebalance(root);
    
    // 3. Распечатать преобразованное дерево
    // printTree(root);
    
    // 4. Найти минимальный элемент и удалить его поддерево
    Node* parent = nullptr;
    Node* minNode = search(root, parent);
    
    if(minNode != nullptr) 
    {
        if(parent == nullptr) 
        {
            // Минимум - корень
            del(root);
            root = nullptr;
        }
        else if(parent->left == minNode) 
        {
            del(parent->left);
            parent->left = nullptr;
        }
        else {
            del(parent->right);
            parent->right = nullptr;
        }
    }
    
    return 0;
}