//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include <vector>
#include "p3.h"

using namespace std;

void pregunta_3_case_1() {
    int n = 0;
    cin >> n;
    vector<int> vec(n);
    for(auto& item: vec)
        cin >> item;
    remove_duplicates(vec);
    for(const auto& item: vec)
        cout << item << " ";
    cout << endl;
}

