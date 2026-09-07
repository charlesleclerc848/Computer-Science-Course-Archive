.MODEL SMALL    
.STACK 100H

.DATA

.CODE

MAIN PROC
    MOV AX,@DATA
    MOV DS,AX   
    
    MOV AX,017H
    MOV AX,023FH
    MOV AX,0FAB3H 
    
    MOV AH,18H
    MOV BX,AX
    
    
    ;INTERRUPTS
    
    
    
    
    
    
    
    
    MOV AH,4CH
    INT 21H
    
MAIN ENDP
END MAIN
