import socket
import threading

class client_handler(threading.Thread):
    def __init__(self, connection):
        super().__init__()
        self.connection = connection
    def run(self):
        message = self.connection.recv(BUFFER_SIZE)

        print(message.decode())

        self.connection.sendall(message)

      

MY_ADDRESS = ("127.0.0.1", 43211)
BUFFER_SIZE = 4096

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(MY_ADDRESS)
    s.listen()
    list = []

    while True:
        connection, client_address = s.accept()#bloccante
        thread = client_handler(connection)
        thread.start()

        list.append(thread)
        print(list)

        
        

    connection, client_address = s.accept()#bloccante
    print(f"Il client {client_address} è  connesso")

    message = connection.recv(BUFFER_SIZE)

    print(message.decode())

    connection.sendall(message)

    s.close()

if __name__ == "__main__":
    main()