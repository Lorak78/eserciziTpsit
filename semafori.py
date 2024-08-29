import threading
import time
#lock = threading.Lock() #lock è un Semaphore(1)
semaforo = threading.Semaphore(1) #il semaforo fa accedere alla sezione critica del codice n thread (parametro)

class StampaNome(threading.Thread):
    def __init__(self, nome):
        super().__init__()
        self.nome = nome
    
    def run(self):
        with semaforo:
            for _ in range(5):
                print("ciao ", end="")
                print(self.nome)
                time.sleep(1)

def main():
    
    nomi = ["Mario", "Luca", "Alice", "Bob"]
    listaThread = [StampaNome(nome) for nome in nomi]

    for thread in listaThread:
        thread.start()

    for thread in listaThread:
        thread.join()
    
if __name__ == "__main__":
    main()