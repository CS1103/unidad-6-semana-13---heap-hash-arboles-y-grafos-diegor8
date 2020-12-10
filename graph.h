#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <tuple>
#include <queue>
#include <functional>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <numeric>
#include <limits>

using namespace std;

// - Keys
// - Vertices
// - Weights
// - Adjacents
// - Edges
// - priority_queue (stl)
using identify_t = string;
using vertex_t = size_t;
using weight_t = size_t;
using adjacent_t = tuple<vertex_t, weight_t>;
using edge_t = tuple<vertex_t, vertex_t, weight_t>;
using edge_priority_queue_t = priority_queue<edge_t,
        vector<edge_t>,
        function<bool(edge_t, edge_t)>>;

using distance_t = size_t;
const auto infinity_distance = numeric_limits<distance_t>::max();

// Lambda de comparacion
auto edge_compare = [](edge_t a, edge_t b) {
    return get<2>(a) > get<2>(b);
};

class find_union_t {
    vector<vertex_t> parent_;
public:
    explicit find_union_t(size_t n): parent_(n) {
        iota(begin(parent_), end(parent_), 0);
    }
    vertex_t find(vertex_t vx) {
        return (vx == parent_[vx])
               ? vx
               : (parent_[vx] = find(parent_[vx]));
    }
    void join(vertex_t a, vertex_t b) {
        parent_[find(a)] = find(b);
    }
};

// Undirected graph
class graph_t {
    // Tabla Hash
    unordered_map<identify_t, vertex_t> vertices_;
    // Adjacentes
    vector<list<adjacent_t>> adjacent_;
    // Priority Queue
    edge_priority_queue_t edge_priority_queue_;

public:
    graph_t() : edge_priority_queue_{edge_compare} {}

    // Adicionar los vertices
    void add_vertex(const identify_t &key) {
        if (vertices_.find(key) != end(vertices_)) return;
        vertices_[key] = vertices_.size();
        adjacent_.resize(vertices_.size());
    }

    // Adicionar las aristas
    void add_edge(const identify_t &a, const identify_t &b, weight_t w) {
        // validar los key
        if (vertices_.find(a) == end(vertices_)) return;
        if (vertices_.find(b) == end(vertices_)) return;
        // Adjacentes
        adjacent_[vertices_[a]].emplace_back(vertices_[b], w);
        adjacent_[vertices_[b]].emplace_back(vertices_[a], w);
        // Agregar en el priority queue
        edge_priority_queue_.push({vertices_[a], vertices_[b], w});
    }

    vector<edge_t> kruskal() {
        // Variables
        vector<edge_t> result;
        // Copia del priority queue
        auto pq = edge_priority_queue_;
        // Algoritmo de Find Union (A traves de un objeto)
        find_union_t fu(vertices_.size());
        // Recorrer el priority queue mientras tenga aristas (edge)
        while (!pq.empty()) {
            // Obtengo la arista de menor peso
            auto edge = pq.top();
            pq.pop();
            // Verificacion de Ciclos si son diferentes los une
            if (fu.find(get<0>(edge)) != fu.find(get<1>(edge))) {
                fu.join(get<0>(edge), get<1>(edge));
                result.push_back(edge);
            }
        }
        return result;
    }

    vector<edge_t> prim() {
        // Variables
        vector<edge_t> result;
        unordered_set<vertex_t> visited;
        edge_priority_queue_t available_edges(edge_compare);
        // lambda
        auto is_visited = [&visited](vertex_t vx) {
            return visited.find(vx) != end(visited);
        };
        // Partir de la arista menor
        auto[v, a, w] = edge_priority_queue_.top();
        // Agrego todos los adjacentes a la lista de disponibles
        for (const auto&[a, w]: adjacent_[v])
            available_edges.push({v, a, w});
        visited.insert(v);
        // Recorriendo aristas disponibles
        while (!available_edges.empty()) {
            auto[v, a, w] = available_edges.top();
            available_edges.pop();
            if (!is_visited(a)) {
                visited.insert(a);
                result.emplace_back(v, a, w);
                for (const auto&[a2, w]: adjacent_[a])
                    if (!is_visited(a2)) {
                        available_edges.push({a, a2, w});
                    }
            }
        }
        return result;
    }

    vector<pair<distance_t, vertex_t>> dijsktra(const identify_t &source) {
        // Almacenando los vertices adjacentes
        vector<pair<vertex_t, distance_t>> available_vertices;
        // Las distancias y los vertices previos
        vector<pair<distance_t, vertex_t>> distance(vertices_.size(),
                                                    {infinity_distance, 0});
        // Vertices visitados
        unordered_set<vertex_t> visited;
        // Lambda 
        auto is_visited = [&visited](vertex_t vx) {
            return visited.find(vx) != end(visited);
        };
        // Lambdas que me permiten simular el min-heap
        auto top = [&available_vertices]() {
            // Busca el minimo
            auto it = min_element(begin(available_vertices), end(available_vertices),
                                  [](pair<vertex_t, distance_t> a, pair<vertex_t, distance_t> b) {
                                      return a.second < b.second;
                                  });
            // Intercambio con el ultimo          
            swap(*it, available_vertices.back());
            // Obtiene el ultimo
            return available_vertices.back();
        };

        auto pop = [&available_vertices]() {
            available_vertices.pop_back();
        };

        auto push = [&available_vertices](vertex_t v, distance_t d) {
            available_vertices.emplace_back(v, d);
        };

        auto update = [&available_vertices](vertex_t v, distance_t d) {
            auto it = find_if(begin(available_vertices), end(available_vertices),
                              [v](pair<vertex_t, distance_t> a) { return v == a.first; });
            it->second = d;
        };

        distance[vertices_[source]] = {0, vertices_[source]};
        available_vertices.emplace_back(vertices_[source], 0);

        while (!available_vertices.empty()) {
            // Obtener y Remover el vertex
            auto[v, d] = top();
            pop();
            // Lo Marca como visitado
            visited.insert(v);
            // Obtener todos sus adjacentes
            for (auto[a, w]: adjacent_[v]) {
                if (!is_visited(a)) {
                    if (distance[a].first == infinity_distance) {
                        distance[a] = {d + w, v};
                        push(a, d + w);
                    } else if (d + w < distance[a].first) {
                        distance[a] = {d + w, v};
                        update(a, d + w);
                    }
                }
            }
        }
        return distance;
    }
};
#endif