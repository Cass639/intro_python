def calcular_media():
    print("Calculadora de Média do Aluno")
    print("Digite as notas uma por uma. Quando terminar, digite '-1' para calcular a média.\n")
    
    notas = []
    while True:
        entrada = input("Digite uma nota (ou -1 para terminar): ")
        
        try:
            nota = float(entrada)
            if nota == -1:
                break
            if nota < 0 or nota > 10:
                print("Por favor, digite uma nota entre 0 e 10.")
                continue
            notas.append(nota)
        except ValueError:
            print("Por favor, digite um número válido.")
    
    if not notas:
        print("Nenhuma nota foi inserida. Não é possível calcular a média.")
        return
    
    media = sum(notas) / len(notas)
    print(f"\nQuantidade de notas inseridas: {len(notas)}")
    print(f"Soma das notas: {sum(notas):.2f}")
    print(f"Média do aluno: {media:.2f}")
    
    if media >= 7:
        print("Situação: Aprovado")
    else:
        print("Situação: Reprovado")

# Chamando a função para executar o programa
calcular_media()


