alunos = ['Victor', ' Lyssa', 'Fernanda', 'Ricardo']

novos_alunos = alunos.copy()
alunos_ref= alunos

print(novos_alunos)
print(alunos is novos_alunos)
print(alunos is alunos_ref)

alunos_ref[2] = 'Marta'

print(alunos)