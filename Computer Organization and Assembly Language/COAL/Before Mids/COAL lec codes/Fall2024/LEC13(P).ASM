.MODEL SMALL
.STACK 100H
.DATA



.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    XOR CL,CL
    OUTER:
    CMP CL,2
    JA EXIT
    
    XOR CH,CH
    
    INNER:
    CMP CH,5
    JA NEWLINE
    
    MOV DL,"*"
    MOV AH,02H
    INT 21H    
    
    INC CH
    JMP INNER
    
    NEWLINE:
    MOV AH,02
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    INC CL
    JMP OUTER
    

    
    EXIT:
    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN