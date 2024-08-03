import re
import numpy as np
import tkinter as tk
from tkinter import ttk, Scrollbar
from PIL import Image, ImageTk


#-------Struct----------------------------------------

class base:
    def __init__(self, id, cost):
        self.id = id
        self.cost = cost

class SimplexInterface(tk.Tk):

#-------Configuracoes da janela--------------------------------------------------

    def exibir_sobre_nos(self):
        self.limpar_janela()  # Limpa a janela antes de exibir o texto

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
        self.limpar_janela()  # Limpa a janela antes de exibir o texto

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
            self.destroy()
        
    #configuracao do icone
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.title("Mukifo Solver") 
        self.geometry('1200x800')
        self.iconbitmap('ctx.ico')  # Definindo o ícone da janela

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

            #add botao de aba
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

            #funcao objetivo escolha min/max
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

    #-----------------------------------------------------------------------------
            #variaveis

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
            self.contador = 0                                                                              #variável auxiliar para contar a quantidade de restrições
            self.contador_obj_inicial = 0
            self.valor_artificial = 0

    #--------------------------------------------------------------------------
            
            #adicionar textos na interface
    
            #add botao add variavel
            self.add_x_btn = ttk.Button(self.objective_frame, text="+X", command=self.add_variable)      
            self.add_variable(initial=True)

            #add texto de restricao
            self.sujeito_label = ttk.Label(self.objective_frame, text="Sujeito à:")
            self.sujeito_label.grid(row=1, column=0, columnspan=2, sticky=tk.W)

            #add botao de restricao 
            self.add_restriction_btn = ttk.Button(self.objective_frame, text="Adicionar Restrição", command=self.add_restricao)
            self.add_restriction_btn.grid(row=2, column=0, sticky=tk.W)

            #add botao para calcular simplex
            self.solve_simplex_btn = ttk.Button(self, text="Calcular Simplex", command=self.Central)
            self.solve_simplex_btn.pack(pady=15)

            #add botao para clinar a janela
            self.clear_data_btn = ttk.Button(self, text="Limpar Dados", command=self.clear_data)
            self.clear_data_btn.pack(pady=5)

            # Adiciona a faixa de texto
            self.faixa_texto = ttk.Label(self, text="", font=("Arial", 12), anchor="center")
            self.faixa_texto.pack(side="bottom", fill="x")

            self.indice_texto_atual = 0
            self.alternar_texto()

#---------Funcoes-----------------------------------------------------------

    #funcoes Interface--------------
    
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

        # Resetar função objetivo

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

        # distancia entre elas por linha
        col_index = len(self.variable_entries) * 3 + 2

        #opcao min/max
        op_obj = ttk.Entry(self.objective_frame, width=5)
        op_obj.grid(row=0, column=col_index)
        self.variable_entries.append(op_obj)        #objeto com quantidade de objetivo


        x_label = ttk.Label(self.objective_frame, text=f"X{len(self.variable_entries)}")
        x_label.grid(row=0, column=col_index + 1)
        self.variable_labels.append(x_label)           #objeto com coeficiente do objetivo


        if not initial:
            operation_label = ttk.Label(self.objective_frame, text="+")
            operation_label.grid(row=0, column=col_index - 1)
            self.operation_labels.append(operation_label)

        #atualiza a posicao do botao de add_x
        self.add_x_btn.grid(row=0, column=len(self.variable_entries) * 3 + 3)   

        #atualiza a opcao de escolha de qual variavel quer alterar 
        for group in self.restricoes_entries:
            for coef_entry, variable_combobox, _, _, _ in group:
                variable_combobox.configure(values=[f"X{i + 1}" for i in range(len(self.variable_entries))])

    def add_restricao(self):

        #distancia por coluna == pular 1 linha
        row = 3 + len(self.restricoes_entries)

        add_var_to_restriction_btn = ttk.Button(self.objective_frame, text="+X", command=lambda: self.add_variable_to_restricao(row))
        add_var_to_restriction_btn.grid(row=row, column=0)

        #add botao de add X na linha
        self.add_var_to_restriction_buttons.append(add_var_to_restriction_btn)

        #cada coeficiente de X
        coef_entry = ttk.Entry(self.objective_frame, width=5)
        coef_entry.grid(row=row, column=2)

        #combobox para escolha de variavel
        variable_combobox = ttk.Combobox(self.objective_frame, values=[f"X{i + 1}" for i in range(len(self.variable_entries))], width=3)
        variable_combobox.grid(row=row, column=3)

        if len(self.variable_entries) > 0:
            variable_combobox.set(f"X1")

        # '+' separando cada coeficiente de X
        sign_label = ttk.Label(self.objective_frame, text="+")
        sign_label.grid(row=row, column=4)

        #inequacao de cada linha
        inequality_combobox = ttk.Combobox(self.objective_frame, values=[">=", "<=", "="], width=3)
        inequality_combobox.grid(row=row, column=5)
        inequality_combobox.set("=")        #seta igual ("=") como padrao

        #? 
        result_entry = ttk.Entry(self.objective_frame, width=7)
        result_entry.grid(row=row, column=6)

        #faz um objeto com cada linha
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

        # Move the last elements (inequality combobox and result entry)
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


    #Funcoes De Simplex------------
    
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
            coeficientes.append(1.0)   #adiciona 1 na matriz (representando a Variavel Artificial)

            objetivo = np.append(objetivo, self.valor_artificial)  #custo [maior valor] +100 na Artificial

            nova_base = base(id= len(objetivo) -1, cost = self.valor_artificial)  #cria nova base

            Base.insert(id_Base, nova_base)  #adiciona a nova base aos objetos
            id_Base = id_Base + 1
           
            return coeficientes, objetivo, Base, id_Base
        
        def adicionar_variavel_folga(coeficientes, objetivo, Base, id_Base):
            coeficientes.append(1.0)  #adiciona -1 na matrix (representando para a igualdade)

            objetivo = np.append(objetivo, 0.0)   #custo 0 para igualdade 

            nova_base = base(id= len(objetivo) -1 , cost = 0)  #cria nova base

            Base.insert(id_Base, nova_base)   #adiciona a nova base aos objetos
            id_Base = id_Base + 1
           
            return coeficientes, objetivo, Base, id_Base
        
        def adicionar_variaveis_artificiais (coeficientes, objetivo, Base, id_Base):

            coeficientes.append(-1.0)  #adiciona -1 na matrix (representando para a igualdade)
            coeficientes.append(1.0)   #adiciona 1 na matriz (representando a Variavel Artificial)
            
            objetivo = np.append(objetivo, 0.0)     #custo 0 para igualdade 
            objetivo = np.append(objetivo, self.valor_artificial)    #custo [maior valor] +100 na Artificial

            nova_base = base(id= len(objetivo) -1, cost = self.valor_artificial)       #cria nova base

            Base.insert(id_Base, nova_base)     #adiciona a nova base aos objetos
            id_Base = id_Base + 1
           
            return coeficientes, objetivo, Base, id_Base
        
        def adicionar_zeros_iniciais (Ax, coeficientes):

            #adiciona zeros nas linhas acima para conseguir base identidade
            max_len = len(coeficientes)

            for linha_Ax in Ax:

                num_zeros = max_len - len(linha_Ax)
                linha_Ax.extend([0.0] * num_zeros)

            return Ax
            
        def find_new_base(Ax, new_indice, b, n):
            
            #funcao de econtrar nova base a cada iteração 

            bb = []

            for i in range(n):
                
                try:
                    new_bb = b[i]/Ax[i][new_indice]         #procura qual base deve ser substituida
                except ZeroDivisionError:         # se o novo caminho for x/0 
                    new_bb = -1             #-1 eh um valor irreal
                
                
                if new_bb < 0:              # valor negativo eh irreal
                    new_bb = -1             #-1 eh um valor irreal
                
                bb.append(new_bb)       #acrescenta no auxiliar para o vetor b

            try:
                valor = min(filter(lambda x: x != -1, bb))      #encontra o valor minimo em bb sendo != -1 (valor irreal)
            except ValueError:              #se nao tiver nenhum valor
                return -1, None             #retorna irreal e nulo          -2 significa que nao ha substituicao
           
            indice = bb.index(valor)        #encontra o indice da nova base

            new_base = base(id = new_indice , cost= self.objetivo[new_indice])       #adiciona caracteristicas da nova base 
            
            return indice, new_base         #retorna o indice e a nova base

        def verificar_base(Base):
            for base_element in Base:
                if base_element.cost == self.valor_artificial:       #se tiver na base final a variavel articial retorna erro == 2
                    return 2
            return 1

       
        #-----Calculo do Simplex---------------------------------------------------------

        #----------------Forma padrao --------------------------


        #extracao coeficientes objetivo
        self.objetivo = [float(entry.get()) for entry in self.variable_entries]                     #vetor objetivo extraído

        valor_selecionado = self.min_max_var.get()                                                  #verifica modelo max/min
                                          
        if valor_selecionado == "max":                                                              #verifica modelo de max/min
                self.objetivo = np.multiply(self.objetivo, -1)                                      #se max, multiplicar objetivo por -1

        aux = self.contador                                                                         #passa valor de self.contador para var aux

        self.contador_obj_inicial = len(self.objetivo)

        for entry_group in self.restricoes_entries:
            
            coeficientes = [0.0] * len(self.objetivo)
            
            for coef_entry, variable_combobox, _, inequality_combobox, result_entry in entry_group:

                #pega os coeficientes
                coeficiente = coef_entry.get()
                variavel = variable_combobox.get()
                indice = int(variavel[1:]) - 1                                                      # Para converter "X1" para 0, "X2" para 1, etc.

                #soma se tiverem 2 combobox da mesma variavel
                coeficientes[indice] = coeficientes[indice] + float(coeficiente)  

                #pega vetor b
                bb = float(result_entry.get())

                #pega sinal 
                sinalal = inequality_combobox.get()

            
            if bb < 0:      #se b for negativo entao multiplica por -1 e troca o sinal
                bb = -bb
                coeficientes = [-x for x in coeficientes]

                if sinalal == ">=":
                    sinalal = "<="

                elif sinalal == "<=":
                    sinalal = ">="


            if sinalal == "<=":      # precisa de variável de folga (<=)
                coeficientes, self.objetivo, self.Base, self.id_Base = adicionar_variavel_folga(coeficientes, self.objetivo, self.Base, self.id_Base)

            elif sinalal == ">=":               # precisa de variável artificial  (>=)
                coeficientes, self.objetivo, self.Base, self.id_Base = adicionar_variaveis_artificiais(coeficientes, self.objetivo, self.Base, self.id_Base)
                        
            else:            #precisa de variavel articial ( = )
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


        #---------------Calculo Simplex------------------
        erro = 0 #supoe sem erro
        cr = []
   

        while(erro == 0):
            erro = 0          #supoe sem erro                                                                      #suposição de que não há erros
            cr = [0] * qtd_restricao        #vetor cr começa com tudo 0


            for i in range (qtd_restricao):                                   
                cr[i] = self.objetivo[i] - sum(self.Base[j].cost * self.Ax[j][i] for j in range(aux))       #calcula o cr de cada linha

            valor = min(cr)         #encontra o valor minimo de cr

            print("Cr\t", cr)

            if valor < 0:       #se o valor minimo eh negativo entao continua

                new_indice = cr.index(valor)                #pega qual coluna deve entrar na base
          
                indice, new_base = find_new_base(self.Ax, new_indice, self.b, aux)      #retorna a linha e a coluna respectivamente

                if indice >= 0:               #se existir
                    self.Base[indice] = new_base        #substitui nova base

                    pivo = self.Ax[indice][new_indice]

                    self.Ax[indice] = [x / pivo for x in self.Ax[indice]]     #pivoteia a linha da nova base
                    self.b[indice] = self.b[indice] / pivo                    #pivoteia o b

                    for i, linha in enumerate(self.Ax):
                        if i != indice:                 #se for diferente da linha da base
                            m = linha[new_indice] / self.Ax[indice][new_indice]          #encontra o multiplicador 
                            self.Ax[i] = [self.Ax[i][j] - m * self.Ax[indice][j] for j in range(len(linha))]      #pivoteia linha
                            self.b[i] = self.b[i] - m * self.b[indice]                        #pivoteia b
                    
                    print()
                    print("Tablo")
                    for base_atual, linha_Ax, valor_b in zip(self.Base, self.Ax, self.b):
                        print(base_atual.cost, " x" , base_atual.id + 1, " | ",   linha_Ax, " ", valor_b)

                else:
                    erro = 2 # sem substituição de base
            
            else:
                erro = 1  # cr > 0

        if erro == 1:
            erro = verificar_base(self.Base)

        if erro == 2:
            print()
            print("Não foi possível achar a solução ótima")


        else:       #se sem erro
            print()
            print("Resultado final:")
            for linha_Ax, valor_b in zip(self.Ax, self.b):
                print(linha_Ax, " ", valor_b)
            print("cr", cr)
            
        print("====================================================================")
        print("\n\n")
        Mostra_Resultado(self, erro, cr)

        if erro == 1:      # se sem erro ( foi colcoado aqui por causa do layout do print na janela)
            Mostra_X_Z(self)

        voltar_btn = ttk.Button(self, text="Calcular Novamente", command=self.inicia)
        voltar_btn.pack(side="top", padx=10, pady=10, anchor="c")


if __name__ == "__main__":
    app = SimplexInterface()
    app.mainloop()
