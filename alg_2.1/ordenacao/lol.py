import random

# Criar uma lista de números de 1 até 100000
numeros = list(range(1, 10001))

# Embaralhar a lista
random.shuffle(numeros)

# Escrever os números no arquivo
with open("numeros.txt", "w") as arquivo:
    for numero in numeros:
        arquivo.write(f"{numero}, ")

print("Arquivo 'numeros.txt' criado com sucesso.")

