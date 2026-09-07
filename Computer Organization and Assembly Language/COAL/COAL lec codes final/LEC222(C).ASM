.MODEL SMALL
.STACK 100H
.DATA

ARRAY DB 40H,47H,32H,33H,34H,35H


.CODE 
MAIN PROC       
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AX,SP
    MOV BP,AX
    
    
    MOV SI,1
    MOV BX,OFFSET ARRAY
    
    MOV DL,ARRAY[SI]
    ;PUSH DX
    MOV AH,02H
    INT 21H
     
    
    
    
    
    
    
    
    
     
    
    MOV AH,4CH
    INT 21H
    
MAIN ENDP
END MAIN