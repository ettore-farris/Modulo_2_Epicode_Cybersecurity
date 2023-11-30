from math import pi

while True:
    try:
        figura = str(input("""Scegli una figura geometrica ("A","B" o "C". "X" per uscire):
                           
    A) Quadrato
    B) Rettangolo 
    C) Circonferenza
    X) Esci dal programma
    """)).lower()  
        if figura == "a":
            l = float(input("Inserisci il valore del lato: "))
            perimetro_quadrato = l*4
            print(f"Il perimetro del nostro quadrato vale {round(perimetro_quadrato, 2)}")
            break
        elif figura == "b":
            b = float(input("Inserisci il valore della base: "))
            a = float(input("Inserisci il valore dell'altezza: "))
            perimetro_rettangolo = b*2 + a*2
            print(f"Il perimetro del nostro rettangolo vale {round(perimetro_rettangolo, 2)}")
            break
        elif figura == "c":
            r = float(input("Inserisci il valore del raggio: "))
            circ = 2*pi*r
            print(f"Il valore della circonferenza vale {round(circ, 2)}")
            break
        elif figura == "x":
            print("Ci vediamo in giro!")
            break
    except(ValueError):
        print("Scelta non valida")
