import os
from rich import print

altura = float(input('Digite a sua altura:'))
peso = float(input('Digite o seu peso:'))
imc = peso/(altura ** 2)

if imc > 40.0:
    classificacao = '[bold red]Obesidade grau 3[/bold red]'
elif 35.0 <= imc <= 39.9:
    classificacao = '[bold red]Obesidade grau 2[/bold red]'
elif 30.0 <= imc <= 34.9:
    classificacao = '[bold red]Obesidade grau 1[/bold red]'
elif 25.0 <= imc <= 29.9:
    classificacao = '[bold red]Sobrepeso[/bold red]'
elif 18.6 <= imc <= 24.9:
    classificacao = 'Normal'
else:
    classificacao = '[bold red]Abaixo do peso[/bold red]'

print(f'Seu imc é {imc} e você está {classificacao}')