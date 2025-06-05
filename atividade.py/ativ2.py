import os
os.system('cls')

def calcular_desconto(valor, desconto):
    if desconto < 0 or desconto > 100:
      raise ValueError('O desconto deve estar entre 0 e 100')
    
    valor_desconto = (valor * desconto/100)
    com_desconto = valor - valor_desconto
    return com_desconto 

valor = int(input('Qual o valor do produto: '))
desconto = int(input('Qual o valor do desconto: '))

print(f'O valor do produto com o desconto é R${calcular_desconto(valor, desconto)}')

