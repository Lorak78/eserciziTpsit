import math

class Node():
    def __init__(self, val):
        self.val = val
        self.sinistro = None
        self.destro = None
        
    def inserisci(self, valore):
        if self.val is not None:
            if valore < self.val:
                if self.sinistro == None:
                    self.sinistro = Node(valore)
                else:
                    self.sinistro.inserisci(valore)
            
            elif valore > self.val:
                if self.destro == None:
                    self.destro = Node(valore)
                else:
                    self.destro.inserisci(valore)
        else:
            self.val = valore
            
    def stampa(self):
        if self.destro is not None:
            self.destro.stampa()
        print(f"{self.val} ")
        if self.sinistro is not None:
            self.sinistro.stampa()
            
    def findNode(self, val):
        if self.val is not None:
            if val == self.val:
                return True
            elif val < self.val and self.sinistro is not None:
                return self.sinistro.findNode(val)
            elif val > self.val and self.destro is not None:
                return self.destro.findNode(val)
            else:
                return False
        else:
            return False  
    
    def totalNodes(self, contNod=-1):
        contNod+=1
        if self.sinistro is not None:
            contNod=self.sinistro.totalNodes(contNod)
        if self.destro is not None:
            contNod=self.destro.totalNodes(contNod)
        return contNod
    
    def treeHeight(self, contL=-1, contR=-1):
        if self.sinistro is not None:
            contL=self.sinistro.treeHeight(contL+1, contR)
        if self.destro is not None:
            contR=self.destro.treeHeight(contL, contR+1)
        return max(contL, contR)
        
    def isBilanciato(self):
        return self.treeHeight() == int(math.log2(self.totalNodes()))
        
def returnMidpoint(x):
    return (len(x)//2)

def inserisciBilanciato(lista, n):    
    centro = len(lista) // 2
    print(lista)
    n.inserisci(lista[centro])
    if centro != 0:
        listaSx = lista[0: centro]
        listaDx = lista[centro + 1:]
        if len(listaSx) > 0:
            inserisciBilanciato(listaSx, n)
        if len(listaDx) > 0:
            inserisciBilanciato(listaDx, n)    
    else:
        return None
        
def main():
    lista=[10,3,7,21,9,4,2]
    lista.sort()
    tree=Node(None)
    inserisciBilanciato(lista, tree)
    print(tree.isBilanciato())
        
if __name__ == '__main__':
    main()