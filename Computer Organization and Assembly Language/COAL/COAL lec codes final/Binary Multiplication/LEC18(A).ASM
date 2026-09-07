;2 values in binary format. We need to multiply them and show the resultant in binary format. 
;    BL  00001010  --> 00010100 ---> 00101000 ---> 
;    DL  00001101  --> 00000110 ---> 00000011 ---> 00000001 ---> 000000000
;____________________
;       00001010
;       00000000
;       00101000
;
;
;____________________
;AX
;  BH= 00001100
;      00000001
;

.MODEL SMALL
.STACK 100H
.DATA



.CODE
MAIN PROC 
    MOV AX,@DATA
    MOV DS,AX
             
    MOV BL,00001010B
    MOV DL,00001101B
    
    CALL MULTIPLY
             
    ;AX WILL RECIVE THE RESULT 
    MOV BX,AX
    
    CALL CHARCTER_TO_BINARY        
    
    MOV AH,4CH 
    INT 21H 
MAIN ENDP

MULTIPLY PROC 
    
    ;input 
    ;first operand in BL 
    ;second operand in DL
    
    XOR DH,DH
    XOR BH,BH
    XOR AX,AX
    
     @REPEAT:
    TEST DL,00000001 ;00000000
    JZ SHIFTING
    
    ADD AX,BX
    
    SHIFTING:
    
    SHL BL,1
    SHR DL,1
    
    JNZ @REPEAT
    
    ; result stored in AX 
    RET
MULTIPLY ENDP

CHARCTER_TO_BINARY PROC
    ;INPUT , BX
    
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    
      
    MOV CX,16
@LOOP:    
    SHL BX,1
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
CHARCTER_TO_BINARY ENDP               
END MAIN

