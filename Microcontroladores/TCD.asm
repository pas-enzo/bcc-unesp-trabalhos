
;--------------------------------------
; Enzo Campanholo Paschoalini
; Curso: Ciência da Computação - Unesp Bauru - 4° termo
; Disciplina: MICROCONTROLADORES - PEREA
; 16/11/2023 - Apresentação
; RA: 221026215
;--------------------------------------

#include <p16f873a.inc>													; Diretiva do compilador

CBLOCK 0x20																; Início do espaço para armazenamento de variáveis
		DELCONT															; Contador auxiliar para delay
		ROTATER															; Variável auxiliar para configuração do CCPR1H
ENDC																	; Fim do espaço

;------------------------------------------------------------------------------------------------------------------------------------------------------------
;------------------------------------------------------------------------------------------------------------------------------------------------------------

ORG 0x00																; Diretiva início do programa
		
		GOTO CONFIGURA													; Vai para a configuração dos elementos utilizados

MAIN_LOOP:																; Label loop principal

		BANKSEL ADCON0													; Seleciona banco do ADCON0
		BSF ADCON0, GO													; Inicia conversão analógica/digital setando registrador GO em 1

LOOP_ADC:																; Loop que aguarda a conversão analógica/digital

		BTFSC ADCON0, GO												; Testa se conversão já terminou, se não, volta para o loop
		GOTO LOOP_ADC													; Retorna ao loop se não terminou

;--------------------------------------------------------------------------------------------------------------------------------------------

		BANKSEL ADRESH													; Seleciona banco do ADRESH
		MOVF ADRESH, W													; Move os bits mais significativos para W

		BANKSEL CCPR1L													; Seleciona banco do CCPR1L
		MOVWF CCPR1L													; Move valor contido em W para registrador CCPR1L, atualiza bit do duty-cycle

		BANKSEL ADRESL													; Seleciona banco do ADRESL
		MOVF ADRESL, W													; Move os bits menos significativos para W
		
		BANKSEL 0x20													; Seleciona banco das variáveis CBLOCK
		MOVWF ROTATER													; Armazena os bits faltantes para alteração do duty-cycle

		RLF ROTATER														; Rotaciona variavel ROTATER, 1a vez
		RLF ROTATER														; Rotaciona variavel ROTATER, 2a vez
		RLF ROTATER														; Rotaciona variavel ROTATER, 3a vez
		RLF ROTATER														; Rotaciona variavel ROTATER, 4a vez

		MOVF ROTATER, W													; Move valor de ROTATER para W
		
		BANKSEL CCP1CON 												; Seleciona banco do CCP1CON
		BCF CCP1CON, 5													; Limpa bit de CCP1CON<5>
		BCF CCP1CON, 4													; Limpa bit de CCP1CON<4>
		
		BANKSEL CCP1CON													; Seleciona banco do CCP1CON
		IORWF CCP1CON 													; OR inclusivo de W com CCP1CON, valor novo de CCPR1H armazenado

;--------------------------------------------------------------------------------------------------------------------------------------------

		BANKSEL 0x20													; Seleciona banco das variáveis CBLOCK
		MOVLW d'100'													; Move valor decimal para W para configuração do contador
		MOVWF DELCONT													; Move valor contido em W para registrador

		GOTO DELAY_MS													; Vai para loop do delay

;------------------------------------------------------------------------------------------------------------------------------------------------------------
;------------------------------------------------------------------------------------------------------------------------------------------------------------

CONFIGURA:																; Label para seção de configuração

		BANKSEL TRISA													; Seleciona banco do PORTA
		MOVLW b'11111111'   											; Move valor binário para W para configuração de PORTA
		MOVWF TRISA														; Move valor contido em W para registrador PORTA
		
		BANKSEL ADCON0													; Seleciona banco do ADCON0
		MOVLW b'01000001'												; Move valor binário para W para configuração do ADCON0
		MOVWF ADCON0 													; Move valor contido em W para registrador ADCON0
		
		BANKSEL ADCON1													; Seleciona banco do ADCON1
		MOVLW b'00000000'												; Move valor binário para W para configuração do ADCON1
		MOVWF ADCON1 													; Move valor contido em W para registrador ADCON1
		
		BANKSEL PR2                                                    	; Seleciona banco do PR2
		MOVLW 0xFF														; Move valor hexadecimal para W para configuração do PR2
		MOVWF PR2														; Move valor contido em W para registrador PR2, para controlar frequência do PWM (1.22 kHz)

		BANKSEL CCPR1L													; Seleciona banco do CCPR1L
		MOVLW d'128'													; Move valor decimal para W para configuração do CCPR1L
		MOVWF CCPR1L													; Move valor contido em W para registrador CCPR1L, configurando duty-cycle padrão em 50% 

		BANKSEL CCP1CON													; Seleciona banco do CCPR1L
		BSF CCP1CON, 5													; Coloca CCP1CON<5> em alto
		BSF CCP1CON, 4													; Coloca CCP1CON<4> em alto, configurando bits CCPR1H

		BANKSEL TRISC													; Seleciona banco do TRISC
		BCF TRISC, 2													; Coloca TRISC<2> em baixo, configurando RC2 como saída
		
		BANKSEL T2CON													; Seleciona banco do T2CON
		MOVLW b'00000111'												; Move valor binário para W para configuração do T2CON
		MOVWF T2CON														; Move valor contido em W para registrador T2CON, prescaler em 16 

		BANKSEL CCP1CON													; Seleciona banco do CCP1CON
		MOVLW b'00001100'												; Move valor binário para W para configuração do CCP1CON
		MOVWF CCP1CON													; Move valor contido em W para registrador CCP1CON, configurando módulo Capture/Compare/PWM em PWM

		GOTO MAIN_LOOP													; Encerra a seção de configuração e pula para o loop principal

;------------------------------------------------------------------------------------------------------------------------------------------------------------
;------------------------------------------------------------------------------------------------------------------------------------------------------------

DELAY_MS:
		DECFSZ DELCONT, F												; Decrementa enquanto for diferente de zero
		GOTO DELAY_MS													; Volta para o loop do delay caso contador não seja zero
		GOTO MAIN_LOOP													; Volta para o loop principal

;------------------------------------------------------------------------------------------------------------------------------------------------------------
;------------------------------------------------------------------------------------------------------------------------------------------------------------

END																		; Fim do programa
		
