import socket

SERVER_ADDRESS = ("127.0.0.1", 43211)
BUFFER_SIZE = 4096

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(SERVER_ADDRESS)

    s.sendall(f"Messaggio dal client".encode())

    message = s.recv(BUFFER_SIZE)

    print(f"ricevuto il mesaggio \"{message.decode()}\" dal server")

    s.close()

if __name__ == "__main__":
    main()