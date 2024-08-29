from threading import Thread
import time

class MyThread(Thread):
    def __init__(self, nome):
        super().__init__()
        self.nome = nome
        self.running = True
    def run(self):
        #IL CODICE DEL THREAD
        while self.running:
            print(f"Sono il thread {self.nome}")
            time.sleep(1)
    def kill(self):
        self.running = False

def main():#MAIN THREAD
    names_list = ["alice", "bob", "trudy"]
    thread_list = [MyThread(n) for n in names_list]
    for t in thread_list:
        t.start()
    for _ in range(4):
        print("sono il main")
        time.sleep(1)
    for t in thread_list:
        t.kill()
        t.join() #unione di flussi nel main thread
    print("sono il main e ho chiuso gli altri thread")
if __name__ == "__main__":
    main()