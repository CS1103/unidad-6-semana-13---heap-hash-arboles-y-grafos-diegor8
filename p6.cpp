//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "p6.h"

using namespace std;

void pregunta_6_case_1() {
    binary_tree<int> a(1);
    // Izquierda
    auto left_branch = a.add_left(a.get_root(), 2);
    left_branch = a.add_left(left_branch, 3);
    left_branch = a.add_left(left_branch, 4);
    left_branch = a.add_left(left_branch, 5);
    left_branch = a.add_left(left_branch, 6);
    // Derecha
    auto right_branch = a.add_right(a.get_root(), 7);
    right_branch = a.add_right(right_branch, 8);
    right_branch = a.add_right(right_branch, 9);
    right_branch = a.add_right(right_branch, 10);
    right_branch = a.add_right(right_branch, 11);
    auto na = a.add_right(right_branch, 12);
    auto nb = a.add_left(right_branch, 14);
    // Calcular Diametro
    cout << boolalpha << a.are_sibling(left_branch, right_branch) << endl;
    cout << boolalpha << a.are_sibling(na, nb) << endl;
}