import random

def jogo_adivinhacao():
    numero_secreto = random.randint(1, 10)
    tentativas_restantes = 3
    
    print("\n=== JOGO DE ADIVINHAÇÃO ===")
    print("Tente adivinhar o número entre 1 e 10")
    print(f"Você tem {tentativas_restantes} tentativas\n")

    while tentativas_restantes > 0:
        try:
            # Recebe o palpite do usuário
            palpite = int(input(f"Tentativa {4 - tentativas_restantes} - Digite seu palpite (1-10): "))
            
            # Valida se o número está entre 1 e 10
            if palpite < 1 or palpite > 10:
                print("Por favor, digite um número entre 1 e 10.\n")
                continue
                
            # Verifica se acertou
            if palpite == numero_secreto:
                print(f"\n Parabéns! Você acertou! O número era {numero_secreto}.")
                return
            else:
                tentativas_restantes -= 1
                if tentativas_restantes > 0:
                    # Dá dicas
                    if palpite < numero_secreto:
                        print(f"O número secreto é MAIOR que {palpite}")
                    else:
                        print(f"O número secreto é MENOR que {palpite}")
                    print(f"Tentativas restantes: {tentativas_restantes}\n")
                
        except ValueError:
            print("Entrada inválida! Por favor, digite um número.\n")
    
    # Se chegou aqui, esgotou as tentativas
    print(f"\n✖ Suas tentativas acabaram. O número secreto era {numero_secreto}.")

# Inicia o jogo
jogo_adivinhacao()