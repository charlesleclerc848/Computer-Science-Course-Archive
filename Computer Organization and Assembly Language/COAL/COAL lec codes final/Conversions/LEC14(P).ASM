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
    JC ONE
    
    MOV AH,02
    MOV DL,"0"
    INT 21H
    INC CL
    JMP @LOOP
    ONE:
    MOV AH,02
    MOV DL,"1"; "1"=31H
    INT 21H
    INC CL
    
    JMP @LOOP
    
    EXIT:
    MOV AH,4CH
    INT 21H
MAIN ENDP 
END MAIN
    