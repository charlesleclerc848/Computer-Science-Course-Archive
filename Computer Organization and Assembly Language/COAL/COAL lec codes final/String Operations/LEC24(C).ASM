.MODEL SMALL
.STACK 100H
.DATA

STRING2 DB "YASIN$"
LEN EQU $-STRING2

.CODE
MAIN PROC 
    MOV AX,@DATA
    MOV DS,AX
    MOV ES,AX
    MOV CX,LEN-1
    
    
    LEA SI,STRING2 
    MOV AH,02
 @LOOP:   
    LODSB    
    MOV DL,AL    
    INT 21H
    
    LOOP @LOOP
    
    
    
    
    
    
    
    
    
    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN