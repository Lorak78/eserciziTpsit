import socket
import threading

MY_ADDRESS = ("localhost", 11000)
BUFF_SIZE = 4096

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
            list_mess = message.split(":")
            self.temp = float(list_mess[1])
            uid = list_mess[0]
            if self.temp >= 70 and self.temp_prec < 70:
                print(f"Allarme per {uid}")
            if self.temp < 70 and self.temp_prec >= 70: 
                print(f"Allarme rientrato per {uid} ")
            self.temp_prec = self.temp
    
def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(MY_ADDRESS)
    s.listen()

    while True:
        connection, _ = s.accept()
        client = Client_handler(connection)
        client.start()
    s.close()

if __name__ == "__main__":
    main()