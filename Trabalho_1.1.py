import re
import numpy as np
import tkinter as tk
from tkinter import ttk

# ------ Funcoes --------------------------------------
def extrair_obj(obj):
    termos = re.findall(r'([-+]?\d*)x(\d+)', obj)
    num_variaveis = max(int(var) for _, var in termos) + 1
    coeficientes = [0] * num_variaveis

    for coeficiente, var in termos:
        if coeficiente == "":
            coeficiente = '1'
        indice = int(var) - 1
        coeficientes[indice] = int(coeficiente)

    return coeficientes[:-1]  # Removendo o zero extra no final

def extrair_Ax_e_b(restricao, num_variaveis):
    padrao = r'([-+]?\d*)x(\d+)'
    coeficientes = [0] * num_variaveis

    termos = re.findall(padrao, restricao)

    for termo in termos:
        coeficiente = termo[0] if termo[0] else '0'
        indice = int(termo[1]) - 1
        coeficientes[indice] = int(coeficiente)

    b = int(restricao.split('=')[-1])

    return coeficientes, b

def verificar_max(obj):
    return "max" in obj.lower()

def adicionar_variaveis_artificiais(Ax, b, objetivo):
    num_variaveis_artificiais = len(b)
    
    for i in range(num_variaveis_artificiais):
        nova_variavel_artificial = np.zeros(len(Ax))
        nova_variavel_artificial[i] = 1
        Ax[i] = np.concatenate((Ax[i], nova_variavel_artificial))
        objetivo = np.append(objetivo, 100 * objetivo[0])
    
    return Ax, objetivo


# ------ Variaveis ----------------------------------

Ax = []
b = []

# ------ Codigo --------------------------------------

# pegar objetivo
print("Digite a Função Objetivo no formato (max/min) 2x1 + 3x2 ...")
obj = input()
objetivo = extrair_obj(obj)
resultado = verificar_max(obj)

if resultado:
    objetivo = np.multiply(objetivo, -1)

# pegar restrições
n = int(input("Digite a quantidade de restrições: "))
print("Digite as restrições:")

for i in range(n):
    restricao = input()
    A, bb = extrair_Ax_e_b(restricao, len(objetivo))
    if bb < 0:
        bb = np.multiply(bb, -1)
        A = np.multiply(A, -1)
    Ax.append(A)
    b.append(bb)

# Transformar em forma padrão
num_variaveis = len(objetivo)

# Adicionar variáveis de folga
for i in range(len(Ax)):
    zero_vector = np.zeros(len(Ax))
    zero_vector[i] = 1
    Ax[i] = np.concatenate((Ax[i], zero_vector))

# Atualizar o vetor objetivo com zeros para variáveis de folga
objetivo = np.concatenate((objetivo, np.zeros(len(Ax))))

Ax, objetivo = adicionar_variaveis_artificiais(Ax, b, objetivo)

print("Função Objetivo:", objetivo)
print()
print("Matriz A:")
for linha_Ax, valor_b in zip(Ax, b):
    print(linha_Ax, " ", valor_b)