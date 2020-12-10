//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "p5.h"

using namespace std;

void pregunta_5_case_1() {
    binary_tree<int> a(10);
    auto node = a.add_left(a.get_root(), 10);
    a.add_right(node, 20);
    a.add_left(node, 30);
    node = a.add_right(a.get_root(), 40);
    a.add_right(node, 50);
    a.add_left(node, 60);
    // Calcular Diametro
    cout << a.diametro() << endl;
    binary_tree<int> a2(1);
    // Izquierda
    auto left_branch = a2.add_left(a2.get_root(), 2);
    left_branch = a2.add_left(left_branch, 3);
    left_branch = a2.add_left(left_branch, 4);
    left_branch = a2.add_left(left_branch, 5);
    left_branch = a2.add_left(left_branch, 6);
    // Derecha
    auto right_branch = a2.add_right(a2.get_root(), 7);
    right_branch = a2.add_right(right_branch, 8);
    right_branch = a2.add_right(right_branch, 9);
    right_branch = a2.add_right(right_branch, 10);
    right_branch = a2.add_right(right_branch, 11);
    // Calcular Diametro
    cout << a2.diametro() << endl;
}