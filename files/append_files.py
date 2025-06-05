with open ('./alunos.txt') as f:
    print(f.read())

with open ('./alunos.txt', 'a') as f:
    f.write('\nFernanda Miranda')