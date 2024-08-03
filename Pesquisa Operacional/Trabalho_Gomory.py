#----------------------------------------------------
# Trabalho 2 - Método de Resolução de P. L. I.
# Data: 12/12/2023
# Feito por: Enzo Paschoalini, Lucca Comerão e Thiago Gullo
#
# Método escolhido: Método de Gomory
#----------------------------------------------------

import re
import numpy as np
import tkinter as tk
import math
from tkinter import ttk, Scrollbar
from PIL import Image, ImageTk


#-------Struct----------------------------------------

class base:
    def __init__(self, id, cost):
        self.id = id
        self.cost = cost

class SimplexInterface(tk.Tk):

#-------Configurações da janela--------------------------------------------------

    def exibir_sobre_nos(self):
        
        # Limpa a janela antes de exibir o texto
        self.limpar_janela()

        # Adiciona a imagem
        imagem = Image.open("sobre.png")

        imagem = ImageTk.PhotoImage(imagem)
        label_imagem = ttk.Label(self, image=imagem)
        label_imagem.image = imagem
        label_imagem.pack()

        texto_sobre_nos = ttk.Label(self, text=self.sobre_nos_texto, wraplength=1000)
        texto_sobre_nos.pack(pady=10)



        voltar_btn = ttk.Button(self, text="Voltar à Tela Inicial", command=self.inicia)
        voltar_btn.pack(pady=10)

    def exibir_como_funciona(self):
        
        # Limpa a janela antes de exibir o texto
        self.limpar_janela()

        # Adiciona a imagem
        imagem = Image.open("como usar.png")
       
        imagem = ImageTk.PhotoImage(imagem)
        label_imagem = ttk.Label(self, image=imagem)
        label_imagem.image = imagem
        label_imagem.pack()

        texto_como_funciona = ttk.Label(self, text=self.como_funciona_texto, wraplength=1000)
        texto_como_funciona.pack(pady=10)

        voltar_btn = ttk.Button(self, text="Voltar à Tela Inicial", command=self.inicia)
        voltar_btn.pack(pady=10)

    def fechar_janela(self):
            
            # Fecha janela
            self.destroy()
        
    
    # Configuracao do ícone
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.title("Mukifo Solver") 
        self.geometry('1200x800')

        # Definindo o ícone da janela
        self.iconbitmap('ctx.ico') 

        self.sobre_nos_texto = '''
                                O trabalho foi realizado pelos alunos Enzo Campanholo Paschoalini, Lucca Comerão Stecca Almeida e 
                                Thiago Bigotte Gullo, no âmbito da disciplina de Pesquisa Operacional I, do segundo ano, quarto semestre 
                                do curso de Ciência da Computação da Unesp de Bauru. O projeto consiste em um interpretador capaz de 
                                receber e processar um conjunto de entradas representando os elementos de um problema de Programação 
                                Linear (P.P.L.). Após receber a entrada, o algoritmo aplica o Método Simplex, desenvolvido pelo 
                                matemático George B. Dantzig, com o objetivo de otimizar uma função objetivo específica. Ao finalizar os
                                cálculos, o programa exibe o resultado das operações e a solução ótima do problema linear, caso exista. 
                                Para proporcionar uma experiência mais confortável ao usuário, foi desenvolvida uma interface gráfica 
                                que apresenta as informações necessárias. Este projeto representa um passo significativo na aplicação 
                                prática dos conceitos estudados na disciplina, demonstrando a capacidade dos alunos em desenvolver 
                                soluções inovadoras para problemas complexos.'''
        
        self.como_funciona_texto = '''
                                        Para melhor compreensão de como utilizar o programa, aqui estão algumas dicas:

                                        Para o conjunto de entrada, o primeiro elemento diz respeito à função objetivo.

                                        Considere que o programa só deve receber parâmetros numéricos inteiros.

                                        Escolha o modelo de maximização/minimização usando os radio buttons ao lado da função objetivo.

                                        Insira a função objetivo ao lado das radio buttons de maximização/minimização

                                        Caso queira adicionar mais variáveis à função objetivo, basta clicar em “+X”.

                                        Para adicionar as restrições do problema, clique no botão “Adicionar Restrição”. Isso pode ser feito repetidas vezes.

                                        Para adicionar variáveis em cada restrição, é necessário apertar “+X” em cada linha na qual será adicionado a variável.

                                        O programa é capaz de somar os coeficientes de uma mesma variável na restrição.

                                        É possível selecionar, no final de cada restrição, as relações de igualdade (=) ou desigualdade (>=, <=).

                                        Selecione a variável usando os espaços de seleção na restrição. Poderá escolher a variável de acordo com a quantidade de variáveis inseridas na função objetivo.

                                        Para calcular a solução ótima do problema, basta clicar em “Calcular Simplex”.

                                        Caso queira recomeçar, o botão “Limpar Dados” retira as informações inseridas.
                                        
                                        Para sair do programa, aperte o botão “Fechar” localizado na parte superior da tela.'''

        self.inicia()
        
    def inicia(self):

            self.limpar_janela()

            # Add botao de aba
            button_frame = ttk.Frame(self)
            button_frame.pack(side="top", anchor="nw")

            self.sobre_nos_btn = ttk.Button(button_frame, text="Sobre Nós", command=self.exibir_sobre_nos)
            self.sobre_nos_btn.pack(side="left")

            self.como_funciona_btn = ttk.Button(button_frame, text="Como Funciona", command=self.exibir_como_funciona)
            self.como_funciona_btn.pack(side="left")
            

            self.simplex_photo = tk.PhotoImage(file="simplex2.png")      
            self.image_label = tk.Label(self, image=self.simplex_photo)
            self.image_label.pack(pady=10)

            self.problem_frame = ttk.LabelFrame(self, text="Modelagem de Problema", padding=(10, 5))
            self.problem_frame.pack(pady=10, padx=10, fill=tk.X)

            self.objective_frame = ttk.Frame(self.problem_frame)
            self.objective_frame.pack(pady=10, fill=tk.X)

            # Função objetivo de escolha min/máx
            self.min_max_var = tk.StringVar(value="min")
            tk.Radiobutton(self.objective_frame, text="Min", variable=self.min_max_var, value="min").grid(row=0, column=0)
            tk.Radiobutton(self.objective_frame, text="Max", variable=self.min_max_var, value="max").grid(row=0, column=1)

            # Agendar a alternância de texto
            self.textos = ["Para o conjunto de entrada, o primeiro elemento diz respeito à função objetivo.", 
                           "Considere que o programa só deve receber parâmetros numéricos inteiros.", 
                           "Escolha o modelo de maximização/minimização usando os radio buttons ao lado da função objetivo.",
                           "Insira a função objetivo ao lado das radio buttons de maximização/minimização.",
                           "Caso queira adicionar mais variáveis à função objetivo, basta clicar em “+X”.",
                           "Para adicionar as restrições do problema, clique no botão “Adicionar Restrição”. Isso pode ser feito repetidas vezes.",
                           "Para adicionar variáveis em cada restrição, é necessário apertar “+X” em cada linha na qual será adicionado a variável.",
                           "O programa é capaz de somar os coeficientes de uma mesma variável na restrição.",
                           "É possível selecionar, no final de cada restrição, as relações de igualdade (=) ou desigualdade (>=, <=).",
                           "Selecione a variável usando os espaços de seleção na restrição. Poderá escolher a variável de acordo com a quantidade de variáveis inseridas na função objetivo.",
                           "Para calcular a solução ótima do problema, basta clicar em “Calcular Simplex”.",
                           "Caso queira recomeçar, o botão “Limpar Dados” retira as informações inseridas.",
                           "Para sair do programa, aperte o botão “Fechar” localizado na parte superior direito da tela."]

    #--------Variáveis---------------------------------------------------------------------

            self.variable_entries = []
            self.variable_labels = []
            self.operation_labels = []
            self.add_var_to_restriction_buttons = []
            self.restricoes_entries = []

            self.Ax = []
            self.b = []
            self.Base = []
            self.id_Base = int(0)

            self.objetivo = []
            self.sinal = []

            # Variável auxiliar para contar a quantidade de restrições
            self.contador = 0                            

            self.contador_obj_inicial = 0
            self.valor_artificial = 0


    #-------Adicionar textos na interface-------------------------------------------------------------------
    
            # Add botao add variavel
            self.add_x_btn = ttk.Button(self.objective_frame, text="+X", command=self.add_variable)      
            self.add_variable(initial=True)

            # Add texto de restricao
            self.sujeito_label = ttk.Label(self.objective_frame, text="Sujeito à:")
            self.sujeito_label.grid(row=1, column=0, columnspan=2, sticky=tk.W)

            # Add botao de restricao 
            self.add_restriction_btn = ttk.Button(self.objective_frame, text="Adicionar Restrição", command=self.add_restricao)
            self.add_restriction_btn.grid(row=2, column=0, sticky=tk.W)

            #Add botao para calcular simplex
            self.solve_simplex_btn = ttk.Button(self, text="Calcular Simplex", command=self.Central)
            self.solve_simplex_btn.pack(pady=15)

            # Add botao para clinar a janela
            self.clear_data_btn = ttk.Button(self, text="Limpar Dados", command=self.clear_data)
            self.clear_data_btn.pack(pady=5)

            # Adiciona a faixa de texto
            self.faixa_texto = ttk.Label(self, text="", font=("Arial", 12), anchor="center")
            self.faixa_texto.pack(side="bottom", fill="x")

            self.indice_texto_atual = 0
            self.alternar_texto()

#---------Funções Gerais-----------------------------------------------------------

    #-----------Funções Interface--------------
    
    def alternar_texto(self):
        texto_atual = self.textos[self.indice_texto_atual]
        self.faixa_texto.config(text=texto_atual)

        self.indice_texto_atual += 1
        if self.indice_texto_atual >= len(self.textos):
            self.indice_texto_atual = 0

        self.faixa_texto.after(5000, self.alternar_texto)

    def limpar_janela(self):
        for widget in self.winfo_children():
            widget.destroy()

    def clear_data(self):
        
        # Remover restrições
        for entry_group in self.restricoes_entries:
            for widget_group in entry_group:
                for widget in widget_group:
                    widget.destroy()

        self.restricoes_entries = []

        # Remover Radio Button das restricoes
        for btn in self.add_var_to_restriction_buttons:
            btn.destroy()

        self.add_var_to_restriction_buttons = []

        # Reseta varaivel
        for lbl in self.variable_labels[1:]:
            lbl.destroy()
        
        # Reseta valores da varaivel
        for entry in self.variable_entries[1:]:
            entry.destroy()

        # Reseta 
        for lbl in self.operation_labels:
            lbl.destroy()
       
        self.contador = 0
        self.variable_entries = self.variable_entries[:1]
        self.variable_labels = self.variable_labels[:1]
        self.operation_labels = []

        # Resetar botão de adicionar X na posição correta
        self.add_x_btn.grid(row=0, column=len(self.variable_entries) * 3 + 3)

        # Resetar a opção min
        self.min_max_var.set("min")

        # Resetar os dados do simplex
        self.Ax = []
        self.b = []
        self.Base = []
        self.id_Base = int(0)

        self.objetivo = []
        self.sinal = []
        self.contador = 0 

    def add_variable(self, initial=False):

        # Distancia entre elas por linha
        col_index = len(self.variable_entries) * 3 + 2

        # Opção min/máx
        op_obj = ttk.Entry(self.objective_frame, width=5)
        op_obj.grid(row=0, column=col_index)

        # Objeto com quantidade de objetivo
        self.variable_entries.append(op_obj) 


        x_label = ttk.Label(self.objective_frame, text=f"X{len(self.variable_entries)}")
        x_label.grid(row=0, column=col_index + 1)

        # Objeto com coeficiente do objetivo
        self.variable_labels.append(x_label)          


        if not initial:
            operation_label = ttk.Label(self.objective_frame, text="+")
            operation_label.grid(row=0, column=col_index - 1)
            self.operation_labels.append(operation_label)

        # Atualiza a posicao do botao de add_x
        self.add_x_btn.grid(row=0, column=len(self.variable_entries) * 3 + 3)   

        # Atualiza a opção de escolha de qual variável quer alterar 
        for group in self.restricoes_entries:
            for coef_entry, variable_combobox, _, _, _ in group:
                variable_combobox.configure(values=[f"X{i + 1}" for i in range(len(self.variable_entries))])

    def add_restricao(self):

        # Distancia por coluna == pular 1 linha
        row = 3 + len(self.restricoes_entries)

        add_var_to_restriction_btn = ttk.Button(self.objective_frame, text="+X", command=lambda: self.add_variable_to_restricao(row))
        add_var_to_restriction_btn.grid(row=row, column=0)

        # Add botão de add X na linha
        self.add_var_to_restriction_buttons.append(add_var_to_restriction_btn)

        # Cada coeficiente de X
        coef_entry = ttk.Entry(self.objective_frame, width=5)
        coef_entry.grid(row=row, column=2)

        # Combobox para escolha de variável
        variable_combobox = ttk.Combobox(self.objective_frame, values=[f"X{i + 1}" for i in range(len(self.variable_entries))], width=3)
        variable_combobox.grid(row=row, column=3)

        if len(self.variable_entries) > 0:
            variable_combobox.set(f"X1")

        # '+' separando cada coeficiente de X
        sign_label = ttk.Label(self.objective_frame, text="+")
        sign_label.grid(row=row, column=4)

        # Inequação de cada linha
        inequality_combobox = ttk.Combobox(self.objective_frame, values=[">=", "<=", "="], width=3)
        inequality_combobox.grid(row=row, column=5)

        # Define igual ("=") como padrao
        inequality_combobox.set("=")     

        result_entry = ttk.Entry(self.objective_frame, width=7)
        result_entry.grid(row=row, column=6)

        # Faz um objeto com cada linha
        self.restricoes_entries.append([(coef_entry, variable_combobox, sign_label, inequality_combobox, result_entry)])
        self.contador += 1

    def add_variable_to_restricao(self, row):
        
        group = self.restricoes_entries[row-3]
        col_start = 5 + len(group) * 3

        coef_entry = ttk.Entry(self.objective_frame, width=5)
        coef_entry.grid(row=row, column=col_start)

        variable_combobox = ttk.Combobox(self.objective_frame, values=[f"X{i + 1}" for i in range(len(self.variable_entries))], width=3)
        variable_combobox.grid(row=row, column=col_start + 1)
        if len(self.variable_entries) > 0:
            variable_combobox.set(f"X1")

        new_sign_label = ttk.Label(self.objective_frame, text="+")
        new_sign_label.grid(row=row, column=col_start + 2)

        group.append((coef_entry, variable_combobox, new_sign_label, group[0][-2], group[0][-1]))

        # Move os últimos elementos (combobox da inequação e entrada dos resultados)
        group[0][-2].grid(row=row, column=col_start + 3)
        group[0][-1].grid(row=row, column=col_start + 4)
        
    def encontrar_maior_valor_absoluto(self):
        
        maior_valor = 0
        
        # Verifica o maior valor absoluto na função objetivo
        for entry in self.variable_entries:
            valor = abs(float(entry.get()))
            if valor > maior_valor:
                maior_valor = valor

        # Verifica o maior valor absoluto nas restrições
        for entry_group in self.restricoes_entries:
            for coef_entry, _, _, _, _ in entry_group:
                valor = abs(float(coef_entry.get()))
                if valor > maior_valor:
                    maior_valor = valor

        # Retorna o maior valor encontrado mais 100
        return maior_valor + 600


    #----------Funçõs De Simplex------------
    
    def Central(self):
        self.valor_artificial = self.encontrar_maior_valor_absoluto()

        #------Funções Janela Resultado--------------------------------------------------------

        def Mostra_X_Z(self):
            x_z_frame = tk.Label(self.master_frame)
            x_z_frame.pack(side="top", padx=10, anchor="c")

            z_otimo = 0
            x_otimo = [0.0] * len(self.objetivo)

            for base, valor_b in zip(self.Base, self.b):
                z_otimo += base.cost * valor_b 
                indice1 = base.id
                x_otimo[indice1] = valor_b
                

            print("z* : ", z_otimo)
            print("x* : ", x_otimo)


            z_otimo_label = tk.Label(x_z_frame, text=f"z* = {z_otimo}")
            z_otimo_label.grid(row=3, column=0, columnspan=2, sticky=tk.W)


            x_otimo_limitado = [f'x{i+1} = {x:.3f}' for i, x in enumerate(x_otimo) if i < self.contador_obj_inicial]

            linha = 5
            x_otimo_label = tk.Label(x_z_frame, text=f"x* = [")
            x_otimo_label.grid(row=4, column=0, columnspan=2, sticky=tk.W)

            for x in x_otimo_limitado:
                x_otimo_label = tk.Label(x_z_frame, text=f"\t{x}")
                x_otimo_label.grid(row=linha, column=1, columnspan=2, sticky=tk.W)
                linha += 1

            x_otimo_label = tk.Label(x_z_frame, text=f"]")
            x_otimo_label.grid(row=linha, column=0, columnspan=2, sticky=tk.W)

        def Mostra_Forma_Padrao(self):

            forma_padrao_frame = tk.Label(self)
            forma_padrao_frame.pack(side="left",padx=10, anchor="nw")

        
            objective_image = Image.open("forma padrao.png")
            objective_image = objective_image.resize((300, 80))
            objective_photo = ImageTk.PhotoImage(objective_image)
            objective_label = tk.Label(forma_padrao_frame, image=objective_photo)
            objective_label.image = objective_photo
            objective_label.grid(row=0, column=0, sticky=tk.W)

            objetivo_label = tk.Label(forma_padrao_frame, text="Min ", anchor="w")
            objetivo_label.grid(row=2, column=0, columnspan=2, sticky=tk.W)

            for i, coeficiente in enumerate(self.objetivo):
                if i > 0:
                    objetivo_label["text"] += f" + {coeficiente} * x{i + 1}"
                else:
                    objetivo_label["text"] += f"{coeficiente} * x{i + 1}"

            matriz_a_label = tk.Label(forma_padrao_frame, text="Sa: ", anchor="w")
            matriz_a_label.grid(row=4, column=0, sticky=tk.W)

            linha = 5

            for linha_Ax, valor_b in zip(self.Ax, self.b):
                linha_label = tk.Label(forma_padrao_frame, text=" ", anchor="w")
                
                for i, coeficiente in enumerate(linha_Ax):
                    if i > 0:
                        linha_label["text"] += f" + {coeficiente} * x{i + 1}"
                    else:
                        linha_label["text"] += f"{coeficiente} * x{i + 1}"
                
                linha_label["text"] += f"  =  {valor_b}"
                
                linha_label.grid(row=linha, column=0, columnspan=2, sticky=tk.W)
                linha += 1

        def Mostra_Resultado(self, erro, cr):

            resultado_frame = tk.Label(self)
            resultado_frame.pack(side="right", padx=10, anchor="nw")


            result_image = Image.open("resultado.png")
            result_image = result_image.resize((220, 100))
            result_photo = ImageTk.PhotoImage(result_image)
            result_label = tk.Label(resultado_frame, image=result_photo)
            result_label.image = result_photo
            result_label.grid(row=0, column=0, sticky=tk.W)

            if erro == 2:
                resultado_label = tk.Label(resultado_frame, text="Não foi possível achar a solução ótima:", anchor="e")
                resultado_label.grid(row=2, column=0, columnspan=2, sticky=tk.W)
            else:   

                objetivo_label = tk.Label(resultado_frame, text="\t  " + " ".join([f"{x:.3f}" for x in self.objetivo]), anchor="w")
                objetivo_label.grid(row=1, column=0, sticky=tk.W)


                linha = 2

                for base_atual, linha_Ax, valor_b in zip(self.Base, self.Ax, self.b):

                    formatted_line_Ax = [f"{float(x):.3f}" for x in linha_Ax]
                    formatted_line_Ax_str = " ".join(formatted_line_Ax)

                    linha_label = tk.Label(resultado_frame, text=f"{base_atual.cost:.4f} x{base_atual.id + 1} | {formatted_line_Ax_str} | {valor_b:.4f}", anchor="w")
                    linha_label.grid(row=linha, column=0, columnspan=2, sticky=tk.W)
                    linha +=1

                cr_label = tk.Label(resultado_frame, text="\t  " + " ".join([f"{x:.3f}" for x in cr]), anchor= "w")
                cr_label.grid(row = linha + 1 , column = 0, sticky=tk.W )

        #-----Funções auxiliares do cálculo de Simplex--------------------------------
      
        def adicionar_variavel_artificial_igual(coeficientes, objetivo, Base, id_Base):
            
            # Adiciona 1 na matriz (representando a variável artificial)
            coeficientes.append(1.0)

            # Custo [maior valor] +100 na Artificial
            objetivo = np.append(objetivo, self.valor_artificial)

            # Cria nova base
            nova_base = base(id= len(objetivo) -1, cost = self.valor_artificial)

            # Adiciona a nova base aos objetos
            Base.insert(id_Base, nova_base)
            id_Base = id_Base + 1
           
            return coeficientes, objetivo, Base, id_Base
        
        def adicionar_variavel_folga(coeficientes, objetivo, Base, id_Base):
            
            # Adiciona -1 na matriz (representando para a igualdade)
            coeficientes.append(1.0)

            # Custo 0 para igualdade
            objetivo = np.append(objetivo, 0.0) 

            # Cria nova base
            nova_base = base(id= len(objetivo) -1 , cost = 0)

            # Adiciona a nova base aos objetos
            Base.insert(id_Base, nova_base)
            id_Base = id_Base + 1
           
            return coeficientes, objetivo, Base, id_Base
        
        def adicionar_variaveis_artificiais (coeficientes, objetivo, Base, id_Base):

            # Adiciona -1 na matriz (representando para a igualdade)
            coeficientes.append(-1.0) 

            # Adiciona 1 na matriz (representando a variável artificial)
            coeficientes.append(1.0)
            
            # Custo 0 para igualdade
            objetivo = np.append(objetivo, 0.0) 

            # Custo [maior valor] +100 na Artificial
            objetivo = np.append(objetivo, self.valor_artificial)

            # Cria nova base
            nova_base = base(id= len(objetivo) -1, cost = self.valor_artificial)

            # Adiciona a nova base aos objetos
            Base.insert(id_Base, nova_base)
            id_Base = id_Base + 1
           
            return coeficientes, objetivo, Base, id_Base
        
        def adicionar_zeros_iniciais (Ax, coeficientes):

            # Adiciona zeros nas linhas acima para conseguir base identidade
            max_len = len(coeficientes)

            for linha_Ax in Ax:

                num_zeros = max_len - len(linha_Ax)
                linha_Ax.extend([0.0] * num_zeros)

            return Ax
            
        # Função de encontrar nova base a cada iteração
        def find_new_base(Ax, new_indice, b, n): 

            bb = []

            for i in range(n):
                
                try:
                    # Procura qual base deve ser substituída
                    new_bb = b[i]/Ax[i][new_indice]

                 # Se o novo caminho for x/0 
                except ZeroDivisionError:
                    
                     #-1 é um valor irreal
                    new_bb = -1
                
                # valor negativo é irreal
                if new_bb < 0:
                    
                    #-1 é um valor irreal              
                    new_bb = -1
                
                # Acrescenta no auxiliar para o vetor b
                bb.append(new_bb)

            try:
                
                # Encontra o valor mínimo em bb sendo != -1 (valor irreal)
                valor = min(filter(lambda x: x != -1, bb))

            # Se não tiver nenhum valor    
            except ValueError:      

                # Retorna irreal e nulo; -2 significa que nao há substituição
                return -1, None          
            
            # Encontra o índice da nova base
            indice = bb.index(valor)  

            # Adiciona características da nova base
            new_base = base(id = new_indice , cost= self.objetivo[new_indice]) 
            
            # Retorna o índice e a nova base
            return indice, new_base

        def verificar_base(Base):

            for base_element in Base:

                 # Se tiver na base final a variável articial retorna erro == 2
                if base_element.cost == self.valor_artificial:      
                    return 2
                
            return 1
        
        def get_nova_restricao(Ax, b, indice_gomory):                                              # função que encontra restrição nova, parte de gomory
            restricao_gomory_Ax = []                                                               # novo vetor para guardar novos valores 
            restricao_gomory_b = 0                                                                 # para armazenar novo valor de b
            aux_dif_restricao = 0                                                                  # variavel auxiliar para calcular parte fracionaria                                           

            for i in range(len(Ax[indice_gomory])):                                                # percorre elementos na linha específica de Ax
                
                aux_dif_restricao = 0                                                              # variavel auxiliar para calcular parte fracionaria

                if (Ax[indice_gomory][i] == 0):
                    restricao_gomory_Ax.append(0.0)                                                # caso for igual a zero, incluir valor zero na restricao     

                elif (Ax[indice_gomory][i] > 0):                                                     # verifica se valor na matriz é positivo
                    aux_dif_restricao = Ax[indice_gomory][i] - int(Ax[indice_gomory][i])           # se positivo, subtrair parte inteira para restar parte fracionaria
                    restricao_gomory_Ax.append(aux_dif_restricao)                                  # adiciona parte fracionaria na restricao

                elif (Ax[indice_gomory][i] < 0):                                                     # verifica se valor na matriz é negativo
                    aux_dif_restricao = Ax[indice_gomory][i] + int(Ax[indice_gomory][i])           # se negativo, somar parte inteira para restar parte fracionaria negativa
                    restricao_gomory_Ax.append(aux_dif_restricao)                                  # adiciona parte fracionaria negativa na restrição



            restricao_gomory_b = b[indice_gomory] - int(b[indice_gomory])                          # armazena valor do chao do indice b

            return restricao_gomory_Ax, restricao_gomory_b                                         # retorna novo vetor Ax e b
        
        def adicionar_variavel_artificial_gomory(coeficientes, objetivo, Base, id_Base, Ax):       # adicionar a variável de folga para caso de gomory
            coeficientes.append(-1.0)                                                              # adiciona -1 no penultimo valor do novo vetor restricao gomory - excesso
            coeficientes.append(1.0)                                                               # adiciona 1 no ultimo valor do novo vetor restricao gomory - artificial

            objetivo = np.append(objetivo, 0.0)                                                    # adiciona zero a função objetivo
            objetivo = np.append(objetivo, self.valor_artificial)                                  # adiciona mais um zero a função objetivo - dois zeros, um de excesso e outro para artificial

            nova_base = base(id=(len(objetivo)-1) , cost = self.valor_artificial)                  # função nova base

            Base.insert(id_Base, nova_base)                                                        # função nova base
            id_Base = id_Base + 1                                                                  # função nova base

            for i in range(len(Ax)):                                                               # função insere os valores zero nas restrições antigas
                Ax[i].append(0.0)                                                                    # append nos zeros
                Ax[i].append(0.0)

            return coeficientes, objetivo, Base, id_Base                                           # retorna

       
        #-----Cálculo do Simplex---------------------------------------------------------

        #----------------Forma padrao --------------------------


        # Extração coeficientes objetivo
        self.objetivo = [float(entry.get()) for entry in self.variable_entries]                    

         # Verifica modelo máx/min
        valor_selecionado = self.min_max_var.get()                                                 

        # Se máx, multiplicar objetivo por -1                                  
        if valor_selecionado == "max":                                                             
                self.objetivo = np.multiply(self.objetivo, -1)                        
        
        # Passa valor de self.contador para var aux
        aux = self.contador                       

        self.contador_obj_inicial = len(self.objetivo)

        for entry_group in self.restricoes_entries:
            
            coeficientes = [0.0] * len(self.objetivo)
            
            for coef_entry, variable_combobox, _, inequality_combobox, result_entry in entry_group:

                # Pega os coeficientes
                coeficiente = coef_entry.get()
                variavel = variable_combobox.get()

                # Para converter "X1" para 0, "X2" para 1, etc.
                indice = int(variavel[1:]) - 1                                                      

                # Soma se tiverem 2 combobox da mesma variável
                coeficientes[indice] = coeficientes[indice] + float(coeficiente)  

                # Pega vetor b
                bb = float(result_entry.get())

                # Pega sinal 
                sinalal = inequality_combobox.get()

            # Se b for negativo então multiplica por -1 e troca o sinal
            if bb < 0:
                bb = -bb
                coeficientes = [-x for x in coeficientes]

                if sinalal == ">=":
                    sinalal = "<="

                elif sinalal == "<=":
                    sinalal = ">="


            # Precisa de variável de folga (<=)
            if sinalal == "<=":
                coeficientes, self.objetivo, self.Base, self.id_Base = adicionar_variavel_folga(coeficientes, self.objetivo, self.Base, self.id_Base)

            # Precisa de variável artificial  (>=)
            elif sinalal == ">=":
                coeficientes, self.objetivo, self.Base, self.id_Base = adicionar_variaveis_artificiais(coeficientes, self.objetivo, self.Base, self.id_Base)

            # Precisa de variável artificial ( = )      
            else: 
                coeficientes, self.objetivo, self.Base, self.id_Base = adicionar_variavel_artificial_igual(coeficientes, self.objetivo, self.Base, self.id_Base)

            self.Ax.append(coeficientes)
            self.b.append(bb)
            self.sinal.append(sinalal[0])

            self.Ax = adicionar_zeros_iniciais(self.Ax, coeficientes)

        qtd_restricao = len(self.objetivo)
        
        self.limpar_janela()
        self.simplex_photo = tk.PhotoImage(file="simplex2.png")      
        self.image_label = tk.Label(self, image=self.simplex_photo)
        self.image_label.pack(pady=10)

        self.master_frame = tk.Frame(self)
        self.master_frame.pack(side="top", padx=10, pady=10)

        Mostra_Forma_Padrao(self)


        #---------------Cálculo Simplex------------------
        
        # Supõe sem erro
        erro = 0
        cr = []
        contador_de_iteracoes_simplex = 0
        flag_resultado_inteiro = 0
        
        while(contador_de_iteracoes_simplex < 10):
            erro = 0
            while(erro == 0):
           
                # Supõe sem erro
                erro = 0          

                # Vetor cr inicia com tudo 0
                cr = [0] * qtd_restricao    

                for i in range (qtd_restricao): # Vetor cr inicia com tudo 0
                    cr[i] = 0     

                print(cr)

                for i in range (qtd_restricao):     

                    # Calcula o cr de cada linha                              
                    cr[i] = self.objetivo[i] - sum(self.Base[j].cost * self.Ax[j][i] for j in range(aux)) 

                print(cr)      

                # Encontra o valor mínimo de cr
                valor = min(cr)        

                print("Cr\t", cr)

                # Se o valor mínimo é negativo então continua
                if valor < 0:

                    # Pega qual coluna deve entrar na base
                    new_indice = cr.index(valor)
          
                    # Retorna a linha e a coluna respectivamente
                    indice, new_base = find_new_base(self.Ax, new_indice, self.b, aux)

                    # Se existir
                    if indice >= 0:

                        # Substitui nova base
                        self.Base[indice] = new_base        

                        pivo = self.Ax[indice][new_indice]

                        # Pivoteia a linha da nova base
                        self.Ax[indice] = [x / pivo for x in self.Ax[indice]]
    
                        # Pivoteia o b
                        self.b[indice] = self.b[indice] / pivo                

                        for i, linha in enumerate(self.Ax):

                            # Se for diferente da linha da base
                            if i != indice:

                                # Encontra o multiplicador
                                m = linha[new_indice] / self.Ax[indice][new_indice]         

                                # Pivoteia linha
                                self.Ax[i] = [self.Ax[i][j] - m * self.Ax[indice][j] for j in range(len(linha))]      
                            
                                # Pivoteia b
                                self.b[i] = self.b[i] - m * self.b[indice]                     
                    
                        print()
                        print("Tablo")
                        for base_atual, linha_Ax, valor_b in zip(self.Base, self.Ax, self.b):
                            print(base_atual.cost, " x" , base_atual.id + 1, " | ",   linha_Ax, " ", valor_b)

                    else:
                        # Sem substituição de base
                        erro = 2
            
                else:
                    # cr > 0
                    erro = 1

            if erro == 1:
                if (flag_resultado_inteiro == 1 or contador_de_iteracoes_simplex == 0):
                    erro = verificar_base(self.Base)

            if erro == 2:
                print()
                print("Não foi possível achar a solução ótima")

        
            # Se sem erro
            else:
                # print()
                # print("Resultado final:")
                # for linha_Ax, valor_b in zip(self.Ax, self.b):
                #     print(linha_Ax, " ", valor_b)
                print("cr", cr)

                # Verifica se há numeros racionais na solução ótima inicial
            
                # Identificador da primeira linha que tem valor racional
                racional_guarda = 0                                                

                # Flag para dizer se achou ou nao valores racionais
                racional_flag = 0                                              

                # Loop que percorre vetor b para encontrar resultados não inteiros
                for i in range(len(self.b)):                                        

                    # Casting para transformar valor float em inteiro
                    aux_diferenca_inteira = int(self.b[i])                    

                    # Se valor float menos valor inteiro for diferente de zero, entao valor é racional
                    if (self.b[i] - aux_diferenca_inteira) != 0:      

                        # Armazena primeira linha que se encontra valor racional        
                        racional_guarda = self.b[i]  
            

                        if (self.Base[i].cost != 0):                  
                            # Flag sinaliza que encontrou valor 
                            racional_flag = 1

                            # Break no loop
                            break                                                      

                # Se não encontrou valor racional, programa terminou
                if racional_flag == 0:                                             
                    print()                                                         
                    print("Resultado final, ótimo e inteiro:")                     
                    for linha_Ax, valor_b in zip(self.Ax, self.b):                  
                        print(linha_Ax, " ", valor_b)
                    flag_resultado_inteiro = 1                               

                # Caso encontrou valores racionais, inicia-se gomory
                else:                                                               
                
                    # Guarda índice da posição do primeiro valor não racional do vetor b
                    novo_indice_gomory = self.b.index(racional_guarda)

                    # Novo vetor restrição do Ax
                    nova_restricao_gomory_Ax = []

                    # Novo vetor restrição do b                             
                    nova_restricao_gomory_b = 0   

                    # Novas variáveis com seus valores                                 
                    nova_restricao_gomory_Ax, nova_restricao_gomory_b = get_nova_restricao(self.Ax, self.b, novo_indice_gomory)

                    # Adiciona novo b inteiro
                    self.b.append(nova_restricao_gomory_b)  

                    # Adiciona variavel de folga para calculo de gomory                       
                    nova_restricao_gomory_Ax, self.objetivo, self.Base, self.id_Base = adicionar_variavel_artificial_gomory(nova_restricao_gomory_Ax, self.objetivo, self.Base, self.id_Base, self.Ax)

                    # Adiciona nova restricao gomory a Ax
                    self.Ax.append(nova_restricao_gomory_Ax)

                    print()
                    print("Tablo")
                    for base_atual, linha_Ax, valor_b in zip(self.Base, self.Ax, self.b):
                        print(base_atual.cost, " x" , base_atual.id + 1, " | ",   linha_Ax, " ", valor_b)

                    # Preparativo que aumenta tamanho do CR
                    qtd_restricao = qtd_restricao + 2
                    cr.append(0.0)
                    cr.append(0.0)
                    aux = aux + 1

            contador_de_iteracoes_simplex = contador_de_iteracoes_simplex + 1

            if (flag_resultado_inteiro == 1):
                break

        if (flag_resultado_inteiro == 1):
            Mostra_Resultado(self, erro, cr)
            if erro == 1:
                Mostra_X_Z(self)

        else:
            print("Não foi possível achar a solução ótima")

        
            

        voltar_btn = ttk.Button(self, text="Calcular Novamente", command=self.inicia)
        voltar_btn.pack(side="top", padx=10, pady=10, anchor="c")


if __name__ == "__main__":
    app = SimplexInterface()
    app.mainloop()
