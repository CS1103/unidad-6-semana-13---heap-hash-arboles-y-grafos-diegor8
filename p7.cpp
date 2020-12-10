//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "p7.h"

using namespace std;

void pregunta_7_case_1() {
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
    // Verificar si esta conectado
    cout << boolalpha << g.is_connected() << endl;
    // Caso de uso #2
    graph_t g2;
    // Vertices
    g2.add_vertex("A");
    g2.add_vertex("B");
    g2.add_vertex("C");
    // Edges
    g2.add_edge("A", "B", 10);
    // Verificar si esta conectado
    cout << boolalpha << g2.is_connected() << endl;
}