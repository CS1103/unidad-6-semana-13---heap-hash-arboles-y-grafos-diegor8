# Tarea #7: Estructura de datos fundamentales - Arboles y Grafos

Problemas del curso de Programación Orientada a Objetos 2 - CS1103

## Problema #1 - Obtener mediana - HEAP

Diseñar y desarrollar el template de clase **median** que permita la busqueda en tiempo constante del valor de la mediana de una colección de valores numéricos y que permita insertar en tiempo logarítmico y borrar en tiempo logarítmico los valores.

**Casos de uso**  
```cpp
    // Caso de uso #1
    int n = 0;
    cin >> n;
    mediana<int> m2;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        cin >> x;
        m2.push(x);
    }
    cout << "mediana = " << m2() << endl;
    // Caso de uso #2
    for (int i = 0; i < n/4; ++i)
        m2.pop();
    cout << "mediana = " << m2() << endl;
    // Caso de uso #3
    mediana<int> m1 = {1, 2, 4, 5, 6};
    cout << "mediana = " << m1();
```
## Problema #2 - Distancia al origen - HEAP

Diseñar y desarrollar el template de clase **distance** que por medio de un heap de puntos 𝑷(𝑿,𝒀) devuelva los n primeros valores cuya distancia euclidiana al punto 𝑷(𝟎,𝟎) sea la más corta. 

**Casos de uso**  
```cpp
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
```
## Problema #3 - Remover duplicados - HASH

Diseñar y desarrollar el template de función `remove_duplicates` que en un tiempo lineal O(n) permita remover los valores duplicados de un contenedor. 

```cpp
template <typename Container>
void remove_duplicates(Container& cnt);
```

**Casos de uso**  
```cpp
    int n = 0;
    cin >> n;
    vector<int> vec(n);
    for(auto& item: vec)
        cin >> item;
    remove_duplicates(vec);
    for(const auto& item: vec)
        cout << item << " ";
    cout << endl;
```
## Problema #4 - Par Equivalente - HASH
Diseñar y desarrollar el template de función `get_equivalent_pairs` que al recibir 2 colecciones de valores numéricas y un número k, retorne un par ordenado cuya suma sea igual al valor k. 

```cpp
template <typename T, template<typename...> class U>
U<pair<T, T>> get_equivalent_pairs(U<T>& cnt1, U<T>& cnt2, T sum);
```

**Casos de uso**  
```cpp
    int n = 0, m = 0, sum = 0;
    cin >> n >> m;
    cin >> sum;
    vector<int> vec1(n);
    vector<int> vec2(m);
    for(auto& item: vec1)
        cin >> item;
    for(auto& item: vec2)
        cin >> item;
    for (auto& [a, b]: get_equivalent_pair(vec1, vec2, sum))
        cout << a << " " << b << endl;
```
## Problema #5 - Diametro de un Arbol - ARBOL
Utilizando el arbol binario (**`binary_tree`**) desarrollado en clase, desarrollar el método `diametro` que permita calcular el diámetro de un árbol (es la distancia basada en vertice mas larga entre 2 hojas de un arbol).

**Casos de uso**  
```cpp
    // Caso de uso 1
    binary_tree<int> a(10);
    auto node = a.add_left(a.get_root(), 10);
    a.add_right(node, 20);
    a.add_left(node, 30);
    node = a.add_right(a.get_root(), 40);
    a.add_right(node, 50);
    a.add_left(node, 60);
    // Calcular Diametro
    cout << a.diametro() << endl;
    // Caso de uso 2
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
```

## Problema #6 - Hermanos - ARBOL
Utilizando el arbol binario (**`binary_tree`**) desarrollado en clase, desarrollar el método `are_sibling(node a, node b)` que confirme si 2 nodos son hermanos (se encuentran en un mismo nivel).

**Casos de uso**  
```cpp
    // Caso de uso #1
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
```
## Problema #7 - Conectado - GRAFO
Utilizando el grafo no dirigido  (**`grafo_t`**) desarrollado en clase, desarrollar el método `is_connected` que determine si el grafo es conectado.
 **NOTA**: Se sugiere implementar el método DFS.

**Casos de uso**  
```cpp
    // Caso de uso #1
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
```

## Problema #8 - Árbol Expandido Máximo - GRAFO
Utilizando el grafo no dirigido  (**`grafo_t`**) desarrollado en clase, crear los métodos Kruskal y Prim en reversa (`kruskal_max`, `prim_max`) de modo que permitan ubicar el Árbol Expandido Máximo.

**Casos de uso**  
```cpp
    // Caso de uso #1
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
```
