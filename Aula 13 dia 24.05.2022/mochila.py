import numpy as np

listaPesos = []
listaValores = []
capacidade = 0

def geraMatriz(pesos,valores):
    global capacidade
    n=len(pesos)
    funcaoValores=np.zeros([n+1,capacidade+1])
    matrizConteudo=np.zeros([n+1,capacidade+1])
    for i in range(1,n+1):
        for x in range(0,capacidade+1):
            if(x-pesos[i-1]>=0):
                funcaoValores[i,x]=max(funcaoValores[i-1,x],funcaoValores[i-1,x-pesos[i-1]]+valores[i-1])
                if(funcaoValores[i-1,x]<funcaoValores[i-1,x-pesos[i-1]]+valores[i-1]):
                    matrizConteudo[i,x]=1
            else:
                funcaoValores[i,x]=funcaoValores[i-1,x]
    return funcaoValores,matrizConteudo

def removeItensCarregados(matrizConteudo,pesos):
    global listaPesos
    [n,capac]=np.shape(matrizConteudo)
    n=n-1
    capac=capac-1
    k=capac
    for i in range(n,0,-1):
        if(matrizConteudo[i,k]==1):
            k=capac-pesos[i-1]
            del listaPesos[i-1]
            del listaValores[i-1]

if __name__ == '__main__':
    caminhoes = 2
    capacidade = 15
    listaPesos = [4, 7, 5, 3, 3, 3, 3, 3, 3, 10]
    listaValores = [40, 42, 25, 25, 25, 25, 25, 25, 12, 24]

    for i in range(caminhoes):
        [matrizValores,matrizConteudo]= geraMatriz(listaPesos,listaValores)
        removeItensCarregados(matrizConteudo,listaPesos)

print("Os itens"," ".join(str(x) for x in listaPesos)," não foram entregues")
print("Prejuízo de R$",sum(listaValores))
