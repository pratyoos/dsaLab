G = {
    'A': ['M', 'Q'],
    'M': ['A', 'Z', 'C'],
    'Q': ['A', 'Y', 'R'],
    'Z': ['M'],
    'C': ['M'],
    'Y': ['Q'],
    'R': ['Q']
}

def DFT(G, start):
    stack = [start]
    visited = []

    while stack:
        poppedVertex = stack.pop()
        if poppedVertex not in visited:
            visited.append(poppedVertex)
            for neighbor in reversed(G[poppedVertex]):  
                if neighbor not in visited:
                    stack.append(neighbor)
    return visited
start = 'A'
print(DFT(G, start))