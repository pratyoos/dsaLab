import math

G = {
    'A': {'B': 3, 'C': 1},
    'B': {'A': 3, 'C': 7, 'D': 5, 'E': 1},
    'C': {'B': 7, 'D': 2, 'A': 1},
    'D': {'B': 5, 'C': 2, 'E': 7},
    'E': {'B': 1, 'D': 7}
}

# Helper class for disjoint set data structure
class DisjointSet:
    def __init__(self, vertices):
        self.parent = {vertex: vertex for vertex in vertices}
        self.rank = {vertex: 0 for vertex in vertices}
    
    def find(self, item):
        if self.parent[item] != item:
            self.parent[item] = self.find(self.parent[item])  # Path compression
        return self.parent[item]
    
    def union(self, set1, set2):
        root1 = self.find(set1)
        root2 = self.find(set2)
        
        if root1 != root2:
            if self.rank[root1] < self.rank[root2]:
                self.parent[root1] = root2
            elif self.rank[root1] > self.rank[root2]:
                self.parent[root2] = root1
            else:
                self.parent[root2] = root1
                self.rank[root1] += 1

def kruskal(G):
    # Create list of all edges with weights
    edges = []
    for u in G:
        for v, weight in G[u].items():
            if (v, u, weight) not in edges:  # Avoid duplicates
                edges.append((u, v, weight))
    
    # Sort edges by weight
    edges.sort(key=lambda x: x[2])
    
    # Initialize disjoint set
    ds = DisjointSet(G.keys())
    
    # Initialize MST
    mst = []
    total_cost = 0
    
    # Process each edge
    for edge in edges:
        u, v, weight = edge
        if ds.find(u) != ds.find(v):  # If including this edge doesn't create a cycle
            ds.union(u, v)
            mst.append((u, v, weight))
            total_cost += weight
    
    return mst, total_cost

# Run Kruskal's algorithm
mst, total_cost = kruskal(G)

# Print results
print("Minimum Spanning Tree edges:")
for edge in mst:
    print(f"{edge[0]} -> {edge[1]} : {edge[2]}")
print(f"Total cost of MST: {total_cost}")