import os

alunos = []

os.system('cls' if os.name == 'nt' else 'clear')

MENU = f'''[1] -> Cadastrar Aluno(a)
[2] -> Relatório Geral
[0] -> Sair
'''
        
opcoes = ('1', '2', '0')
opçãoEscolhida = ''

while opçãoEscolhida != '0':
    print(MENU)
    opçãoEscolhida = input('Escolha uma opção: ')
    
    if opçãoEscolhida in opcoes:
        if opçãoEscolhida == '1':
            os.system('cls')
            quantidadeNotas = 0  
            notas = []
            soma = 0
            notas_str = ''
                
            nomeAluno = input(f'Aluno(a): ')
                        
            try:
                quantidadeNotas = int(input('Defina a quantidade de notas que deseja processar: '))
                if quantidadeNotas <= 0:
                    print('A quantidade deve ser maior que 0.')
                else:
                    i = 0
                    while i < quantidadeNotas:
                        try:
                            nota = float(input(f'{len(notas) + 1}º nota: '))
                            if 0 <= nota <= 10:
                                notas.append(nota)
                                soma += nota
                                notas_str += str(nota) + '|'
                                i += 1
                            else:
                                print('Nota inválida! Insira uma nota entre 0 e 10.')
                        except ValueError:
                            print('Nota inválida! Insira um número válido.')
                                
                    media = soma / len(notas)

                    if media >= 7:
                        statusAlunos = ('Aprovado(a)')
                    elif 5 <= media < 7:
                        statusAlunos = ('Recuperação')
                    else:
                        statusAlunos = ('Reprovado(a)')

                    aluno = {
                        'nome': nomeAluno,
                        'notas': notas_str,
                        'media': media,
                        'status': statusAlunos
                    }
                    alunos.append(aluno)
            except ValueError:
                print('Quantidade de notas inválida! Insira um número válido.')
            
            print(f'-' * 30)
            print('Aluno cadastrado com sucesso!')
            input('Pressione Enter para voltar ao menu...')

        elif opçãoEscolhida == '2':
            os.system('cls')
                
            if len(alunos) == 0:
                print('Nenhum aluno cadastrado ainda.')
            else:
                print('\n--- Relatório Final ---')
                for aluno in alunos:
                    print(f"Aluno: {aluno['nome']}")
                    print(f"Notas: {aluno['notas']}")
                    print(f"Média: {aluno['media']:.2f}")
                    print(f"Situação: {aluno['status']}")
                    print('-' * 30)
                input('Pressione Enter para voltar ao menu...')
        else:
            os.system('cls' if os.name == 'nt' else 'clear')
            print('Opção inválida, tente novamente!')

os.system('cls' if os.name == 'nt' else 'clear')
