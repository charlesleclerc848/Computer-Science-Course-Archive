.MODEL SMALL
.STACK 100H
.DATA



.CODE 
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX  
    
    MOV AX,23EBH
    MOV BX,35ABH
    MOV CX,56FFH
    
    ADD AX,BX
    SUB AX,CX
    INC BX
    DEC AX
    
    
    
    
    
    
    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN