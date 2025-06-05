import os
from rich.console import Console

console = Console()

def limpar_tela():
    """Limpa a tela do terminal."""
    console.print(f'[bold red]LIMPANDO A TELA...[/bold red]')
    os.system('cls' if os.name == 'nt' else 'clear')