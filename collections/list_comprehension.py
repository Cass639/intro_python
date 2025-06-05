fabricantes = [
    'Samsung',
    'LG',
    'Apple',
    'Morola',
    'Apple',
    'Xaomi'
]

print(fabricantes)

fabricantes = [fabricante for fabricante in fabricantes if fabricantes != 'Apple']

print(fabricantes)
