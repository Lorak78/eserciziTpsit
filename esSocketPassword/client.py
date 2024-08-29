import socket
import random
import time

SERVER_ADDRESS = ("localhost", 11000)
BUFF_SIZE = 4096

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(SERVER_ADDRESS)

    while True:
        s.sendall(f"".encode())
        time.sleep(2)
    s.close()

if __name__=="__main__":
    main()