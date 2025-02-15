import math
G={
    'A':{'B':3,'C':1},
    'B':{'A':3,'C':7, 'D':5,'E':1},
    'C':{'A':1, 'B':7, 'D':2},
    'D':{'B':5, 'C':2, 'E':7},
    'E':{'B':1,'D':7}

}
def initialize(G,start):
    cost=dict()
    previous=dict()
    for vertex in G:
        cost[vertex]=math.inf
        previous[vertex]= " "
    cost[start]=0
    return cost,previous
def relax(G,u,v,cost,previous):
    if cost[v] > cost[u]+ G[u][v]:
     cost[v]= cost[u] + G[u][v]
     previous[v]=u
    return cost,previous
def compute_least_cost_vertext(cost,visited):
   leastCost=math.inf
   leastCostVertex=" "
   for vertex in cost:
       if vertex not in visited:
          if cost[vertex]<leastCost:
             leastCost=cost[vertex]
             leastCostVertex=vertex
   return leastCostVertex

def ShotestPath(G,start):
   cost,previous= initialize(  G,start)
   visited=[]
   while(len(visited)<len(G)):
      currentVertex=compute_least_cost_vertext(cost,visited)
      visited.append(currentVertex)
      for neighbor in G[currentVertex]:
         if neighbor not in visited:
            cost, previous=relax(G,currentVertex,neighbor,cost,previous)
   return cost, previous
def reconstructPath(previous,vertex):
   path=vertex
   while(previous[vertex]!=" "):
      path=previous[vertex]+"->"+path
      vertex=previous[vertex]
   return path
start='A'
cost,previous=ShotestPath(G,start)
print(cost)
print(previous)
for vertex in G:
   print(f'Shortest path from {start} to {vertex} is {reconstructPath(previous,vertex)}')
   print(f'Cost of path is {cost[vertex]}')