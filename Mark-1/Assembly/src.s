	AREA |.text|, CODE, READONLY 
	EXPORT __main
	ENTRY

__main
	LDR R2, =0x2009C054 ;LPC_GPIO2->FIOPIN address, see LPC1768 manual
	LDR R0, =0x2009C040 ;LPC_GPIO2->FIODIR address, see LPC1768 manual
	MOV R1, #0xFF
	STR R1, [R0]		;Set direction of all 8 pins to OUT
	MOV R5, #1
	MOV R6, #2
	MOV R8, #0 ;change mode
	MOV R9, 0x80
	MOV R11, #0 ; change frequency
	
	B MAIN
	;B main_loop

delay
	MOV R4, #0			; int R4;
delay_loop	
	ADD R4, R4, #1		; for(R4 = 0; R4 < R1; R4++);
	CMP R4, R1	
	BLT delay_loop
	MOV PC, LR 			;return

mode1         ;right to left then to right
	MOV R3, R5
	STR R3, [R2] 		;turn on LED - write 1 to FIOPIN
	BL delay	
	MOV R3, #0		
	STR R3, [R2]		;turn off LED - write 0 to FIOPIN
	BL delay
	LSL R5, #1
	CMP R5, 0x100 
	MOVEQ R5, #1
	BEQ MAIN
	B mode1

mode2           ;left to right then to left
	MOV R3, R9
	STR R3, [R2] 		;turn on LED - write 1 to FIOPIN
	BL delay			;delay(12000000)
	MOV R3, #0		
	STR R3, [R2]		;turn off LED - write 0 to FIOPIN
	BL delay
	LSR R9, #1
	CMP R9, #0 
	MOVEQ R9, 0x80
	BEQ MAIN
	B mode2

mode3          ;all light blink
	MOV R3, #255
	STR R3, [R2] 		;turn on LED - write 1 to FIOPIN
	BL delay			;delay(12000000)
	MOV R3, #0		
	STR R3, [R2]		;turn off LED - write 0 to FIOPIN
	BL delay
	BEQ MAIN

mode4_a      ;light blink back and forth
	MOV R3, R9
	STR R3, [R2] 		;turn on LED - write 1 to FIOPIN
	BL delay			;delay(12000000)
	MOV R3, #0		
	STR R3, [R2]		;turn off LED - write 0 to FIOPIN
	BL delay
	LSR R9, #1
	CMP R9, #0
	MOVEQ R9, 0x40
	BEQ mode4_b
	B mode4_a
mode4_b
	MOV R3, R6
	STR R3, [R2] 		;turn on LED - write 1 to FIOPIN
	BL delay			;delay(12000000)
	MOV R3, #0		
	STR R3, [R2]		;turn off LED - write 0 to FIOPIN
	BL delay
	LSL R6, #1
	CMP R6, 0x100
	MOVEQ R6, #2
	BEQ MAIN
	B mode4_b

Fmode1
	LDR R1, =12000000
	B MAIN_Continue
Fmode2
	LDR R1, =24000000
	B MAIN_Continue
Fmode3
	LDR R1, =3000000
	B MAIN_Continue
	
MAIN
	LDR R12, [R2]
	AND R12, R12, 0x1000  ; R12 = R12 & 0x1000
	CMP R12, #0      ;checks if bit 12 is pressed
	ADDEQ R11, #1
	
	CMP R11, #3
	MOVEQ R11, #0
	
	LDR R10, [R2]
	AND R10, R10, 0x800  ; R10 = R10 & 0x800
	CMP R10, #0      ;checks if bit 11 is pressed
	ADDEQ R8, #1
	
	CMP R8, #4
	MOVEQ R8, #0
	
	CMP R11, #0
	BEQ Fmode1
	CMP R11, #1
	BEQ Fmode2
	CMP R11, #2
	BEQ Fmode3
	
MAIN_Continue	
	CMP R8, #0
	BEQ mode1
	CMP R8, #1
	BEQ mode2
	CMP R8, #2
	BEQ mode3
	CMP R8, #3
	BEQ mode4_a
	
	B MAIN
	ALIGN
	END
