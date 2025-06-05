import os
from rich.console import Console
from rich.table import Table

console = Console()

def limpar_tela():
    """Limpa a tela do terminal e exibe o menu."""
    os.system('cls' if os.name == 'nt' else 'clear')
    MENU = f'''
    [bold green][1][/bold green] -> Tabuada de multiplicação de 1
    [bold green][2][/bold green] -> Tabuada de multiplicação de 2
    [bold green][3][/bold green] -> Tabuada de multiplicação de 3
    [bold green][4][/bold green] -> Tabuada de multiplicação de 4
    [bold green][5][/bold green] -> Tabuada de multiplicação de 5
    [bold green][6][/bold green] -> Tabuada de multiplicação de 6
    [bold green][7][/bold green] -> Tabuada de multiplicação de 7
    [bold green][8][/bold green] -> Tabuada de multiplicação de 8
    [bold green][9][/bold green] -> Tabuada de multiplicação de 9
    [bold blue][a][/bold blue] -> Tabuada de soma
    [bold magenta][d][/bold magenta] -> Tabuada de divisão
    [bold green][0][/bold green] -> Sair
'''
    console.print(MENU)
    return ('1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'd', '0')

def mostrar_tabuada(numero, operacao="multiplicacao"):
    """Mostra a tabuada do número escolhido em formato de tabela."""
    if operacao == "multiplicacao":
        table = Table(title=f"Tabuada de Multiplicação do {numero}")
        table.add_column("Operação", justify="right")
        table.add_column("Resultado", justify="right")
        for i in range(1, 11):
            table.add_row(f"{numero} x {i}", str(numero * i))
    elif operacao == "soma":
        table = Table(title=f"Tabuada de Soma do {numero}")
        table.add_column("Operação", justify="right")
        table.add_column("Resultado", justify="right")
        for i in range(1, 11):
            table.add_row(f"{numero} + {i}", str(numero + i))
    elif operacao == "divisao":
        table = Table(title=f"Tabuada de Divisão do {numero}")
        table.add_column("Operação", justify="right")
        table.add_column("Resultado", justify="right")
        for i in range(1, 11):
            resultado = round(numero / i, 2)
            table.add_row(f"{numero} ÷ {i}", str(resultado))
    console.print(table)

def main():
    opcoes = limpar_tela()
    while True:
        escolha = console.input("[bold yellow]Escolha uma opção: [/bold yellow]")
        if escolha == '0':
            console.print("[bold red]Saindo...[/bold red]")
            break
        elif escolha in ('1','2','3','4','5','6','7','8','9'):
            limpar_tela()
            mostrar_tabuada(int(escolha))
        elif escolha == 'a':
            limpar_tela()
            numero = int(console.input("[bold yellow]Digite o número para a tabuada de soma: [/bold yellow]"))
            mostrar_tabuada(numero, operacao="soma")
        elif escolha == 'd':
            limpar_tela()
            numero = int(console.input("[bold yellow]Digite o número para a tabuada de divisão: [/bold yellow]"))
            mostrar_tabuada(numero, operacao="divisao")
        else:
            console.print("[bold red]Opção inválida![/bold red]")

        console.input("\n[bold cyan]Pressione Enter para voltar ao menu...[/bold cyan]")
        limpar_tela()

if __name__ == "__main__":
    main()