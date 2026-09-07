.MODEL SMALL
.STACK 100H
.DATA 



.CODE 
MAIN PROC 
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,01
    INT 21H
    
    MOV BL,AL     ; 41H=01000001
    

    
    CALL PROC1 
   
    
    MOV AH,4CH ; 00FE=sp
    INT 21H
MAIN ENDP
;PROCEDURES ARE SAME AS FUNCTIONS IN c++ LANGAUGE 
PROC1 PROC
    
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    
    
    MOV CX,8
@LOOP:    
    SHL BL,1
    JC ONE
    MOV AH,02
    MOV DL,"0"
    INT 21H
    JMP ENDL
    ONE:
    MOV AH,02
    MOV DL,"1"
    INT 21H 
    ENDL:
    LOOP @LOOP
    
    
    POP DX
    POP CX
    POP BX
    POP AX
    RET
PROC1 ENDP

END MAIN
