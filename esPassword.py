""" Password
* lettere minuscole dell'alfabeto ITA (21)
* password fatta da N lettere (N=3)
* (combinazioni possibili: 21 ** n)
"""
from threading import Thread
import time

PASSWORD = "zzz"
N = 3
LETTERE_ITA = "abcdefghilmnopqrstuvz"
trovata = False

class MyThread(Thread):
    def __init__(self, lettera):
        super().__init__()
        self.lett = lettera
    def run(self):
        global trovata
        for lett1 in LETTERE_ITA:
            for lett2 in LETTERE_ITA:
                password = self.lett + lett1 + lett2
                if password == PASSWORD:
                    print(f"password trovata: {password}")
                    trovata = True
                if trovata:
                    return

def main():
    threads = [MyThread(lettera) for lettera in LETTERE_ITA]
    for t in threads:
        t.start()
    
    for t in threads:
        t.join()
    
    
if __name__ == "__main__":
    main()