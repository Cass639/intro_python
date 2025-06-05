# def soma(*numbers): # Argumentos arbritrários
#     result = 0
#     for number in numbers:
#         result += number # result = result + number
#     return result

def soma(*numbers):
    return sum(numbers)

print(soma(10))
print(soma(20, 7))
print(soma(44, 56, 1))
print(soma(4, 2, 67, 4))
