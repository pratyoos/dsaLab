G = {
    'A': {'B': 3, 'C': 1},
    'B': {'A': 3, 'C': 7, 'D': 5, 'E': 1},
    'C': {'B': 7, 'D': 2, 'A': 1},
    'D': {'B': 5, 'C': 2, 'E': 7},
    'E': {'B': 1, 'D': 7}
}

edges = []
for u in G:
    for v, weight in G[u].items():
        if (v, u, weight) not in edges:
            edges.append((u, v, weight))
edges.sort(key=lambda x: x[2])

groups = {node: node for node in G}
mst = []
total_cost = 0

for u, v, weight in edges:
    if groups[u] != groups[v]:
        mst.append((u, v, weight))
        total_cost += weight
        old_group = groups[v]
        for node in groups:
            if groups[node] == old_group:
                groups[node] = groups[u]

print("Minimum Spanning Tree edges:")
for edge in mst:
    print(f"{edge[0]} -> {edge[1]} : {edge[2]}")
print(f"Total cost of MST: {total_cost}")