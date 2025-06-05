nome_usuario = input('Digite seu nome completo: ')
nascimento = input('Digite a sua data de nascimento(DD/MM/AAAA): ')

from datetime import datetime
ano_atual = datetime.now().year
ano_nascimento = int(nascimento.split('/')[2])
id = ano_atual - ano_nascimento

print(f'Seu nome é {nome_usuario} e você tem {id}')
