class Grafo():

	def __init__(self, vertices): 
		self.V = vertices 
		self.grafo = [[0 for column in range(vertices)]
					for row in range(vertices)] 

	def printMST(self, pai):
		print("Aresta \tPeso")
		for i in range(1,self.V): 
			print(pai[i],"-",i,"\t",self.grafo[i][ pai[i] ])

	def minKey(self, key, mstSet):

		# Initilaize min value 
		min = float('inf')

		for v in range(self.V): 
			if key[v] < min and mstSet[v] == False: 
				min = key[v] 
				min_index = v 

		return min_index 

	def primMST(self):

		chave = [float('inf')] * self.V
		pai = [None] * self.V
		chave[0] = 0
		mstSet = [False] * self.V 

		pai[0] = -1

		for cout in range(self.V): 
			u = self.minKey(chave, mstSet)
			mstSet[u] = True
			for v in range(self.V):
				if self.grafo[u][v] > 0 and mstSet[v] == False and chave[v] > self.grafo[u][v]:
						chave[v] = self.grafo[u][v]
						pai[v] = u

		self.printMST(pai)

g = Grafo(5)
g.grafo = [ [0, 2, 0, 6, 0],
			[2, 0, 3, 8, 5], 
			[0, 3, 0, 0, 7], 
			[6, 8, 0, 0, 9], 
			[0, 5, 7, 9, 0]] 

g.primMST();