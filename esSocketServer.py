import socket
from threading import Thread

MY_ADDRESS = ("127.0.0.1", 9000)
BUFFER_SIZE = 4096

class Receive(Thread):
    def __init__(self, s):
        super().__init__()
        self.s = s
        self.running = True
        self.sender_address= None
    def run(self):
        while self.running:
            data, self.sender_address = self.s.recvfrom(BUFFER_SIZE)
            string = data.decode()
            print(f"{self.sender_address}: {string}")
            if string == "exit":
                self.running = False
            
    def kill(self):
        self.running = False

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind(MY_ADDRESS)
    
    # Starting thread
    receiver = Receive(s)
    receiver.start()

    while True:
        string = input("-> ")
        if receiver.sender_address != None:
            s.sendto(string.encode(), receiver.sender_address)

        if not receiver.running:
            receiver.join()
            break

if __name__ == "__main__":
    main()