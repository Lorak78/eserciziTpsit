import socket
import threading

"""
3 lettere alfabeto anglosassone, fare bruteforcing della pass
mettendo tutte le possibili combinazioni in un file, poi
con più client, fare un bruteforce efficiente in modo da
impiegarci meno tempo più client ci sono.
"""

MY_ADDRESS = ("localhost", 11000)
BUFF_SIZE = 4096
ALPHABET = "abcdefghijklmnopqrstuvwxyz"
PASSWORD = "xas"

class Client_handler(threading.Thread):
    def __init__(self, connection):
        super().__init__()
        self.connection = connection
        self.temp = -1
        self.temp_prec = -1

    def run(self):
        while True:
            string = self.connection.recv(BUFF_SIZE)
            message = string.decode()

            
    
def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(MY_ADDRESS)
    s.listen()

    with open("pass.txt", "w") as file:
        for let1 in ALPHABET:
            for let2 in ALPHABET:
                for let3 in ALPHABET:
                    file.write(f"{let1}{let2}{let3}\n")
    

    while True:
        connection, _ = s.accept()
        client = Client_handler(connection)
        client.start()
    s.close()

if __name__ == "__main__":
    main()