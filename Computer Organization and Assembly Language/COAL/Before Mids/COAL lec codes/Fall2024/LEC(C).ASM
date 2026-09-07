.MODEL SMALL
.STACK 100H
.DATA
;variables here
VAR DB 1FH
VAR2 DB "A"
VAR3 DB 01100101B
VAR4 DW 23ABH


.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX 
    
    ;ask the user to input a single character
    MOV AH,01
    INT 21H  
    ;store the input in BL
    MOV BL,AL 
    ;add new line
    MOV DL,0AH
    MOV AH,02
    INT 21H
    
    MOV DL,0DH
    ;MOV AH,02
    INT 21H
    
    
    ;display a character
    
    ;MOV AH,02
    MOV DL,BL
    INT 21H
    
    
    
    MOV AH,4CH
    INT 21H
    
MAIN ENDP
END MAIN