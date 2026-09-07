.MODEL SMALL
.STACK 100H
.DATA

STRING1 DB 10 DUP("$")


.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    
    MOV CL,8 
    XOR CH,CH
    LEA BX,STRING1
    
    
    @INPUT:
    JCXZ EXIT
    MOV AH,01
    INT 21H
    
    MOV [BX],AL
    INC BX 
    DEC CX
    JMP @INPUT 
    
    EXIT:
    MOV AH,4CH 
    INT 21H
    
MAIN ENDP
END MAIN
    
    
    