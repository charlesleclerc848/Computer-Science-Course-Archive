.MODEL SMALL
.STACK 100H
.DATA


.CODE
MAIN PROC 
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,01
    INT 21H
    
    MOV BL,AL
    XOR CL,CL
    
    @LOOP:
    CMP CL,7
    JA EXIT
    
    SHL BL,1
    JC NEWLINE
    MOV DL,"0"
    MOV AH,02H
    INT 21H
    INC CL
    JMP @LOOP
    
    
    
    
    NEWLINE:
    MOV DL,"1"
    MOV AH,02H
    INT 21H
    INC CL
    JMP @LOOP
    
    EXIT:
    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN