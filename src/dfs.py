class Graph:
    def __init__(self):
        self.vertices = []
        self.edges = {}

    def add_vertex(self, vertex):
        if vertex not in self.vertices:
            self.vertices.append(vertex)
            self.edges[vertex] = []

    def add_edge(self, vertex1, vertex2):
        if vertex1 in self.vertices and vertex2 in self.vertices:
            self.edges[vertex1].append(vertex2)
            self.edges[vertex2].append(vertex1)

    def dfs(self, start_vertex):
        visited = []
        stack = [start_vertex]

        while stack:
            vertex = stack.pop()
            if vertex not in visited:
                visited.append(vertex)
                stack.extend(set(graph.edges[vertex]) - set(visited))
        return visited

    def __iter__(self):
        self._dfs_stack = [self.vertices[0]] if self.vertices else []
        self._dfs_visited = []
        return self

    def __next__(self):
        while self._dfs_stack:
            vertex = self._dfs_stack.pop()
            if vertex not in self._dfs_visited:
                self._dfs_visited.append(vertex)
                self._dfs_stack.extend(set(self.edges[vertex]) - set(self._dfs_visited))
                return vertex
        raise StopIteration


graph = Graph()
graph.add_vertex(1)
graph.add_vertex(2)
graph.add_vertex(3)
graph.add_vertex(4)
graph.add_edge(1, 2)
graph.add_edge(1, 3)
graph.add_edge(2, 4)
graph.add_edge(3, 4)
for vertex in graph:
    print(vertex)
