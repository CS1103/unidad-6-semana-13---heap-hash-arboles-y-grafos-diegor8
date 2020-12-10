//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "p2.h"

using namespace std;

void pregunta_2_case_1() {
    int n = 0, x0 = 0, y0 = 0;
    cin >> n;
    cin >> x0 >> y0;
    distancia<int> d1(x0, y0);
    for (int i = 0; i < n; ++i) {
        int x = 0, y = 0;
        cin >> x >> y;
        d1.push({x, y});
    }
    // Caso de uso #1
    for (const auto& p: d1(n/4))
        cout << "punto = " << p.first << ", " << p.second << endl;
    // Caso de uso #2
    for (int i = 0; i < n/4; ++i)
        d1.pop();
    for (const auto& p: d1(n/4))
        cout << "punto = " << p.first << ", " << p.second << endl;
    // Caso de uso #3
    distancia<int> d2(0, 0);
    d2 = {{1,1}, {10, 20}, {30, 30}, {4, 5}, {11, 22}};
    for (auto p: d2(2))
        cout << "punto = " << p.first << ", " << p.second << endl;
}
