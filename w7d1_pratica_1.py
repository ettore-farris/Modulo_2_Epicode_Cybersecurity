words = ["linux", "programmazione", "processore", "array", "python", "epicode"]

def len_word(words):
    lenght = []
    for word in words:
        lenght.append(len(word))
    return lenght

print(len_word(words))