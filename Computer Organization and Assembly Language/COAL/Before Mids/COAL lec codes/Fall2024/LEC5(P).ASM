.MODEL SMALL
.STACK 100H
.DATA
;define variables here
VAR DB 15H
VAR2 DB 00010101B



.CODE
MAIN PROC 
    MOV AX,@DATA
    MOV DS,AX
    
    ;Input a single character
    MOV AH,01
    INT 21H
    MOV BL,AL   
    
    ;Add new line
    MOV AH,02
    MOV DL,0AH
    INT 21H
    
    ;MOV AH,02
    MOV DL,0DH
    INT 21H
    
    ;Display a single character
    ;MOV AH,02
    MOV DL,BL
    INT 21H
    
    
    
    
    
    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN
