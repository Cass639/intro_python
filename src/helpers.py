import os
def limpar_tela():
    """Limpa a tela do console."""
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')
    