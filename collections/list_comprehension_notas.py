notas = [10.0, 8.5, 4.5, 6.7, 3.8, 7.8, 8.3]

aprovados = [x for x in notas if x >= 6]
reprovados = [x for x in notas if x < 6]

print(aprovados)
print(reprovados)