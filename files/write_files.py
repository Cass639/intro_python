with open ('./alunos.txt', 'w') as f:
    f.write('Fulano de Tal')

with open ('./alunos.txt') as f:
    print(f.read())