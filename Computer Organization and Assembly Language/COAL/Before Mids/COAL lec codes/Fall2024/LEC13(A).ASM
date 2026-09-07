.MODEL SMALL
.STACK 100H
.DATA

NEWLINE DB 0AH,0DH,"$"

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
    CMP CH,4
    JA NEW
    
    MOV AH,02  
    MOV DL,"*"
    INT 21H 
    
    INC CH
    JMP INNER    
    
    
    NEW:
    MOV AH,09  
    MOV DX,OFFSET NEWLINE
    INT 21H
    
    INC CL
    JMP OUTER
    
    EXIT:
    MOV AH,4CH
    INT 21H
    
MAIN ENDP
END MAIN
    
    