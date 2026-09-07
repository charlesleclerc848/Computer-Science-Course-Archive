;jcxz, loop
.MODEL SMALL
.STACK 100H
.DATA 




.CODE
MAIN PROC 
    MOV AX,@DATA
    MOV DS,AX
    XOR CH,CH
    MOV CL,08
    
@INPUT:
    JCXZ EXIT
    MOV AH,01
    INT 21H
    
    DEC CX
    
    JMP @INPUT
    
    
    EXIT:
    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN