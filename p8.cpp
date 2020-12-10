//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "p8.h"

using namespace std;

void pregunta_8_case_1() {
    graph_t g;
    // Vertices
    g.add_vertex("A");
    g.add_vertex("B");
    g.add_vertex("C");
    g.add_vertex("D");
    g.add_vertex("E");
    // Edges
    g.add_edge("A", "B", 10);
    g.add_edge("B", "E", 4);
    g.add_edge("B", "C", 7);
    g.add_edge("E", "C", 5);
    g.add_edge("E", "D", 8);
    g.add_edge("C", "D", 2);
    g.add_edge("A", "D", 1);
    // Arbol Expandido Maximo
    for (auto& [a, b, w] : g.kruskal_max())
        cout << a << " " << b << " " << w << endl;
    cout << endl << endl;
    for (auto& [a, b, w] : g.prim_max())
        cout << a << " " << b << " " << w << endl;
}