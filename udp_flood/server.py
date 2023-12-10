import socket

IP = "192.168.1.9"
PORT = 5555
#creazione socket UDP
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((IP, PORT))
print("Listening on port 5555")

#ricezione dati da client
while True:
    msg, address = sock.recvfrom(1024)
    print(f"From {address}: {msg}")