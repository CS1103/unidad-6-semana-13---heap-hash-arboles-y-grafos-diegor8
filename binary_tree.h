#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <memory>   // shared_ptr, unique_ptr, weak_ptr
#include <queue>
#include <stack>
#include <vector>

using namespace std;

template<typename T>    // Template Forward Declaration
struct node_impl;

template<typename T>
using node = shared_ptr<node_impl<T>>;

template<typename T>
node<T> make_node(T value) { return make_shared<node_impl<T>>(value); }

template<typename T>
struct node_impl {
    T data;
    node<T> parent;
    node<T> left;
    node<T> right;
    node_impl() = default;
    explicit node_impl(T data): data{data} {}
};

template <typename T>
class binary_tree {
    node<T> root;
public:
    explicit binary_tree(T data): root{make_node(data)} {}

    // Gets
    node<T> get_root() { return root; }
    node<T> get_parent(node<T> n) { return n->parent; }
    node<T> get_left_child(node<T> n) { return n->left; }
    node<T> get_right_child(node<T> n) { return n->right; }
    // Sets (Adds)
    node<T> add_left(node<T> n, T data) {
        // verificar si existe el nodo left
        if (!n->left) {
            n->left = make_node(data);
        }
        else {
            auto temp = make_node(data);
            temp->left = n->left;
            n->left = temp;
        }
        n->left->parent = n;
        return n->left;
    }

    node<T> add_right(node<T> n, T data) {
        if (!n->right) {
            n->right = make_node(data);
        }
        else {
            auto temp = make_node(data);
            temp->right = n->right;
            n->right = temp;
        }
        n->right->parent = n;
        return n->right;
    }

    template <typename UnaryFunction>
    void bfs(UnaryFunction func) {
        // un queue
        queue<node<T>> q;
        // 1. push de la raiz
        q.push(root);
        // 2. verifica si la cola tiene valores
        while (!q.empty()) {
            // 3. obtener el nodo del front del queue
            auto value = q.front();
            func(value);    // Llamado al callable
            // 4. retirar el valor del queue
            q.pop();
            // 5. Agregar (push) de todos los hijos al queue
            if (value->left) q.push(value->left);
            if (value->right) q.push(value->right);
        }
    }
};

#endif