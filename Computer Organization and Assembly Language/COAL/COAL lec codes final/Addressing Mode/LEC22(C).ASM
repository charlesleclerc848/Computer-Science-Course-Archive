.MODEL SMALL
.STACK 100H
.DATA

ARRAY DB 30H,31H,32H,33H,34H,35H


.CODE 
MAIN PROC       
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AX,SP
    MOV BP,AX
    
    
    MOV CX,6
    MOV SI,OFFSET ARRAY
@LOOP:    
    MOV DX,[SI]
    PUSH DX
    MOV AH,02H
    INT 21H
    INC SI 
    
    LOOP @LOOP
    
    
    
    
    
    
     
    
    MOV AH,4CH
    INT 21H
    
MAIN ENDP
END MAIN