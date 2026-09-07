.MODEL SMALL
.STACK
.DATA 

    NEW_LINE DB 0DH,0AH,'Enter a number: $'
    DECISION DB 0DH,0AH,'1 FOR Addition and 2 for subtraction: $'
    RESULT DB 0DH,0AH,'The Result is: $' 
    VAR DB 'ADD $' 
    VAR2 DB 'SUB $'

.CODE 

MAIN PROC
    MOV AX,@DATA
    MOV DS,AX 
    
    MOV DX,OFFSET NEW_LINE
    MOV AH,09H
    INT 21H 
    
    ;Taking input from user
    
    MOV AH,01H
    INT 21H 
    MOV CL,AL
    
    MOV DX,OFFSET NEW_LINE
    MOV AH,09H
    INT 21H
       
    
    ;Taking 2nd input from user
    MOV AH,01H
    INT 21H 
    MOV BL,AL
    
    MOV DX,OFFSET DECISION
    MOV AH,09H
    INT 21H 
    
    ;making decisions
    MOV AH,01H
    INT 21H
    
    CMP AL,'1'
    JZ ADDT 
    
    CMP AL,'2'
    JZ SUBT
     
    SUBT:
    MOV DX,OFFSET RESULT
    MOV AH,09H
    INT 21H 
    MOV DX,OFFSET VAR2
    MOV AH,09H
    INT 21H 
              
    SUB CL,BL
    MOV DL,CL
    ADD DL,30H
    MOV AH,02H
    INT 21H
    JMP EXIT
    
    ADDT: 
    MOV DX,OFFSET RESULT
    MOV AH,09H
    INT 21H
    MOV DX,OFFSET VAR
    MOV AH,09H
    INT 21H 
    ADD BL,CL
    MOV DL,BL
    SUB DL,30H
    MOV AH,02H
    INT 21H
    JMP EXIT 
    
    
    
    
EXIT:    
MOV AX,4CH
INT 21H

MAIN ENDP
END MAIN