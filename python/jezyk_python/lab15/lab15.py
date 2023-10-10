import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np
import requests
import random
from bs4 import BeautifulSoup


# Proszę utworzyć graf połączeń pomiędzy stronami internetowymi - startujemy od wybranej strony, odnajdujemy na niej wszystkie linki. Postępujemy analogicznie dla wszystkich odnalezionych stron, aż rozmiar sieci przekroczy 150 węzłów. Na potrzeby zadania tworzymy graf nieskierowany.
# Po utworzeniu grafu implementujemy błądzenie losowe na sieci. Startujemy z losowo wybranego wierzchołka i przechodzimy z jednakowym prawdopodobieństwem do jednego z jego sąsiadów, zliczamy liczbę odwiedzin danego wierzchołka.
# Dodanie powyższych elementów do pliku anim.py powinno pozwolić za zobrazowanie częstości odwiedzin poszczególnych węzłów.
 
network=nx.Graph()
#network.add_edge(a,b)

start_point = 'https://www.python.org/'
i = 0
links = []

while network.size() < 150:
 reqs=requests.get(start_point)
 soup=BeautifulSoup(reqs.text, 'html.parser')
 for line in soup.find_all('a'): 
  link = line.get("href")
  if link.startswith("htt"):
   links.append(link)
   network.add_edge(start_point,link)
 try:
  start_point = links[i]
 except:
  pass
 print(network.size())
 i+=1

print(links)

 
#generator zwracający listę o rozmiarze równym liczbie wierzchołków grafu zawierającą info o liczbie ich odwiedzin 
def randomWalk(gr):
 arr = [0 for i in gr.size()]
 start_node = random.randint(0,gr.size())
 while True:
  node = random.randint(0,gr.size())
  arr[node] += 1
  node = gr.nodes[random.randint(0,gr.size())]
  #arr[]
  yield arr
  

def animate(ns, graph, fun):
 N=nx.number_of_nodes(graph)
 pos=nx.fruchterman_reingold_layout(graph)
 nodes=nx.draw_networkx_nodes(graph, pos, node_size=ns, node_color=np.fromiter((1/el for el in range(1,N+1)), float))
 nx.draw_networkx_edges(graph, pos,)

 def _animate(ns,gr):
  nodes.set_array(np.array([el/256 for el in ns]))
  nodes.set_sizes(np.array([el for el in ns]))
  return nodes

 fig = plt.gcf()
 anim = FuncAnimation(fig, func=_animate, frames=fun, fargs=(graph,), interval=10, repeat=False)
 plt.show()

N=nx.number_of_nodes(network)
node_size=[10 for _ in range(N)],
animate(node_size, network, randomWalk(network))