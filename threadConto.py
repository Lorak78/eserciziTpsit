"""
Progettare e implementare in linguaggio Python una classe 
base ContoBancario caratterizzata dai seguenti attributi: 
saldo e numero del conto. 
Implementare la gestione multithread per le operazioni di 
deposito e prelievo su ciascun conto bancario. Utilizzare 
le tecniche di sincronizzazione per garantire la coerenza 
dei dati durante le operazioni concorrenti, applicando il 
principio dell’ereditarietà, estendere la 
classe base ContoBancario in modo da ottenere due classi: 
ContoCorrente e ContoRisparmio.
Creare un'applicazione principale che simuli l'utilizzo dei 
conti da parte di più clienti, effettuando operazioni di 
deposito e prelievo concorrenti.
"""

import threading
import time

class ContoBancario(threading.Thread):
    def __init__(self, saldo, numero_conto):
        self.saldo = saldo
        self.numero_conto = numero_conto
    def deposito(self, depositato):
        self.saldo += depositato

    def prelievo(self, prelevato):
        if self.saldo < prelevato:
            print(f"Non e' possibile prelevare questi soldi (conto: {self.saldo})")
        else:
            self.saldo -= prelevato

class ContoCorrente(ContoBancario):
    def __init__(self, saldo, numero_conto):
        super().__init__(saldo, numero_conto)

class ContoRisparmio(ContoBancario):
    def __init__(self, saldo, numero_conto):
        super().__init__(saldo, numero_conto)

def main():
    cliente1 = ContoBancario(1000, 0)
    cliente2 = ContoBancario(5000, 1)

if __name__ == "__main__":
    main()