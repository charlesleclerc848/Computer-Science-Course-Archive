.MODEL SMALL  
.STACK
.DATA 

VAR1 DB 45H
VAR2 DB "D"
VAR3 DB 67
VAR4 DW 34ABH



.CODE

MAIN PROC 
    MOV AX,@DATA
    MOV DS,AX 
    
    MOV AH,01
    INT 21H
    MOV CL,AL
          
    MOV DL,0AH
    MOV AH,02
    INT 21H
    
    MOV DL,0DH
    ;MOV AH,02 ; THIS LINE CAN BE ERASED AS AH=02 ALREADY
    INT 21H
    
          
          
    MOV DL,CL  ;AL
    ;MOV AH,02 ;THIS LINE CAN BE ERASED AS AH=02 ALREADY
    INT 21H   
    
    
    
    MOV AH,4CH
    INT 21H
    
MAIN ENDP
END MAIN
    
    
    
