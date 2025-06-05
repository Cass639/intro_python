n1 = 15
n2 = 8

print(f'Considerando que n1 vale {n1} e n2 vale {n2}, então:')
print(f'n1 == n2 ->{'Verdadeiro' if n1 == n2 else 'Falso'}')
print(f'n1 != n2 ->{'Verdadeiro' if n1 != n2 else 'Falso'}')
print(f'n1 > n2 ->{'Verdadeiro' if n1 > n2 else 'Falso'}')
print(f'n1 < n2 ->{'Verdadeiro' if n1 < n2 else 'Falso'}')
print(f'n1 >= n2 ->{'Verdadeiro' if n1 >= n2 else 'Falso'}')
print(f'n1 <= n2 ->{'Verdadeiro' if n1 <= n2 else 'Falso'}')

preco = 1500.9

tem_desconto = preco > 2000

if tem_desconto:
    print('Você recebeu um desconto de 15%')