G={
    'A':['M','Q'],

    'M':['A','Z','C'],
    'Q':['A','Y','R'],
    'Z':['M'],

    'C':['M'],

    'Y':['Q'],
    'R':['Q']
}
def BFT(G,start):
    stack=[]
    visited=[]
    stack.append(start)
    while(stack):
        popedVertex=stack.pop(0)
        visited.append(popedVertex)
        for neighbor in G[popedVertex]:
            if neighbor not in visited and neighbor not in stack:
                stack.append(neighbor)
    return visited
start= 'A'
print(BFT(G,start))