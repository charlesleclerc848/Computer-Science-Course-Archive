.MODEL SMALL
.STACK 100H
.DATA 
    STRING_1 DB 0AH, 0DH, "$"  
    STRING_2 DB 0AH, 0DH, "$"
    
.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    XOR CX, CX
    @INPUT:
    MOV AH, 01H
    INT 21H
    
    MOV BX, OFFSET STRING_1
    ADD BL, CL
    MOV [BX], AL
    
    CMP [BX], "$"
    JZ NEXT
    
    INC CL
    JMP @INPUT
    
    NEXT:
    XOR AX, AX
    XOR CX, CX 
    JMP @COPY
    
    @COPY:
    MOV BX, OFFSET STRING_1
    ADD BL, CL
    
    MOV AH, [BX] 
    PUSH BX
    POP BX
    
    MOV BX, OFFSET STRING_2 
    ADD BL, CL
    MOV [BX], AH 
    
    CMP [BX], "$"
    JZ PRINT
    
    INC CL
    JMP @COPY
    
    PRINT:
    MOV DL, OFFSET STRING_1 
    MOV AH, 09H
    INT 21H
    
    MOV DL, OFFSET STRING_2 
    MOV AH, 09H
    INT 21H
    
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN