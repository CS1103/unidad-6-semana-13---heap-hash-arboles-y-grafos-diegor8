//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "p1.h"

using namespace std;

void pregunta_1_case_1() {
    int n = 0;
    cin >> n;
    mediana<int> m2;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        cin >> x;
        m2.push(x);
    }
    cout << "mediana = " << m2() << endl;
    for (int i = 0; i < n/4; ++i)
        m2.pop();
    cout << "mediana = " << m2() << endl;

    mediana<int> m1 = {1, 2, 4, 5, 6};
    cout << "mediana = " << m1();
}
