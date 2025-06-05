from helpers import limpar_tela
from rich.console import Console
from rich.table import Table

console = Console()

def calcular_tabuada(numero, operacao) -> Table:
    limpar_tela()
    """Função de Tabuada."""
    table = Table(title=f'Tabuada do {numero}: ({operacao})', show_lines=True, title_justify="center")
    table.add_column("Operação", justify="center", style='cyan')
    table.add_column("Resultado", justify="center", style='magenta')
    for i in range(1, 11):
        if operacao == '+':
            resultado = i + numero
        elif operacao == '-':
            i = i + numero
            resultado = i - numero
        elif operacao == '*':
            resultado = i * numero
        elif operacao == '/':
            i = i * numero
            resultado = i / numero
                
        table.add_row(f'{i} {operacao} {numero}', f'{int(resultado)}')
    return table