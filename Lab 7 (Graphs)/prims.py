import math
G = {
    'A': {'B': 3, 'C': 1},
    'B': {'A': 3, 'C': 7, 'D': 5, 'E': 1},
    'C': {'B': 7, 'D': 2, 'A': 1},
    'D': {'B': 5, 'C': 2, 'E': 7},
    'E': {'B': 1, 'D': 7}
}

def initialize(G, start):
    cost = dict()
    previous = dict()
    for vertex in G:
        cost[vertex] = math.inf
        previous[vertex] = ""
    cost[start] = 0
    return cost, previous

def computeLeastCostVertex(cost, visited):
    leastCost = math.inf
    leastCostVertex = None
    for vertex in cost:
        if vertex not in visited and cost[vertex] < leastCost:
            leastCost = cost[vertex]
            leastCostVertex = vertex
    return leastCostVertex

def prim(G, start):
    cost, previous = initialize(G, start)
    visited = []
    total_cost = 0
    mst_edges = []
    
    while len(visited) < len(G):
        currentVertex = computeLeastCostVertex(cost, visited)
        if currentVertex is None:
            break
            
        visited.append(currentVertex)
        
        if previous[currentVertex]:
            edge_cost = G[currentVertex][previous[currentVertex]]
            mst_edges.append((previous[currentVertex], currentVertex, edge_cost))
            total_cost += edge_cost
        
        for neighbor in G[currentVertex]:
            if neighbor not in visited:
                weight = G[currentVertex][neighbor]
                if weight < cost[neighbor]:
                    cost[neighbor] = weight
                    previous[neighbor] = currentVertex
    
    return mst_edges, total_cost

start = 'A'
mst_edges, total_cost = prim(G, start)

print(f"Minimum Spanning Tree edges (starting from {start}):")
for edge in mst_edges:
    print(f"{edge[0]} -> {edge[1]} : {edge[2]}")
print(f"Total cost of MST: {total_cost}")