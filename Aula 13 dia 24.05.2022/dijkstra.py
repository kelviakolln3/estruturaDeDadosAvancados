from collections import deque, namedtuple

# infinito para os nós
inf = float('inf')
Aresta = namedtuple('Aresta', 'inicio, fim, distancia, pedagio')

def gera_aresta(inicio, fim, distancia=1, pedagio=0):
  return Aresta(inicio, fim, distancia, pedagio)

class Grafo:
    def __init__(self, arestas):
        self.arestas = [gera_aresta(*aresta) for aresta in arestas]

    @property
    def vertices(self):
        return set(
            sum(
                ([aresta.inicio, aresta.fim] for aresta in self.arestas), []
            )
        )

    def get_pares(self, n1, n2, finais=True):
        if finais:
            pares = [[n1, n2], [n2, n1]]
        else:
            pares = [[n1, n2]]
        return pares

    def remove_aresta(self, n1, n2, finais=True):
        pares = self.get_pares(n1, n2, finais)
        arestas = self.arestas[:]
        for aresta in arestas:
            if [aresta.start, aresta.end] in pares:
                self.arestas.remove(aresta)

    def adiciona_aresta(self, n1, n2, cost=1, finais=True):
        pares = self.get_pares(n1, n2, finais)
        for aresta in self.arestas:
            if [aresta.inicio, aresta.fim] in pares:
                return ValueError('Edge {} {} already exists'.format(n1, n2))

        self.arestas.append(Aresta(inicio=n1, fim=n2, custo=cost))
        if finais:
            self.arestas.append(Aresta(inicio=n2, fim=n1, custo=cost))

    @property
    def vizinhos(self):
        vizinhos = {vertice: set() for vertice in self.vertices}
        for aresta in self.arestas:
            vizinhos[aresta.inicio].add((aresta.fim, aresta.distancia, aresta.pedagio))
        return vizinhos

    def dijkstra(self, origem, destino):
        assert origem in self.vertices, 'Such source node doesn\'t exist'
        distances = {vertice: inf for vertice in self.vertices}
        vertice_anterior = {
            vertice: None for vertice in self.vertices
        }
        distances[origem] = 0
        vertices = self.vertices.copy()

        while vertices:
            vertice_atual = min(
                vertices, key=lambda vertice: distances[vertice])
            vertices.remove(vertice_atual)
            if distances[vertice_atual] == inf:
                break
            for vizinho, distancia, pedagio in self.vizinhos[vertice_atual]:
                alternative_route = distances[vertice_atual] + distancia + pedagio
                if alternative_route < distances[vizinho]:
                    distances[vizinho] = alternative_route
                    vertice_anterior[vizinho] = vertice_atual

        caminho, vertice_atual = deque(), destino
        while vertice_anterior[vertice_atual] is not None:
            caminho.appendleft(vertice_atual)
            vertice_atual = vertice_anterior[vertice_atual]
        if caminho:
            caminho.appendleft(vertice_atual)
        return caminho


grafo = Grafo([
    ("a", "b", 7, 3),  ("a", "c", 9, 3),  ("a", "f", 7, 2), ("b", "c", 10, 4),
    ("b", "d", 15, 5), ("c", "d", 11, 1), ("c", "f", 2, 2),  ("d", "e", 6, 1),
    ("e", "f", 9, 3), ("f", "e", 9, 23)])

print(grafo.dijkstra("a", "e"))
