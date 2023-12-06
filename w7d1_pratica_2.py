from random import choice
from string import punctuation, digits, ascii_letters
SIMPLE_PASSWORD = 8
COMPLEX_PASSWORD = 20

#generatore di password
def password_generator(answer):
    all_characters = ascii_letters + digits + punctuation
    weak_password_list = [choice(ascii_letters) for char in range (SIMPLE_PASSWORD)]
    strong_password_list = [choice(all_characters) for sym in range(COMPLEX_PASSWORD)]
    weak_password = "".join(weak_password_list)
    strong_password = "".join(strong_password_list)
    if answer == "a":
        return weak_password
    elif answer == "b":
        return strong_password

#loop prompt utente
while True:
    answer = input("""Che password vuoi generare? (Scegli A, B o X)
            A) Semplice
            B) Complessa
            X) Esci dal programma\n""").lower()
    if(answer in ["a", "b"]):
        print(password_generator(answer))
        break
    elif(answer == "x"):
        print("Alla prossima")
        break
    else:
        print("Inserisci un valore valido")