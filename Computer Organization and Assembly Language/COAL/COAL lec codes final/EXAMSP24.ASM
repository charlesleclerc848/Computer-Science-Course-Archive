.MODEL SMALL
.STACK 100H
.DATA

STRING1 DB "5 Quick Brown Fox Jumps Over The 3 Lazy Dogs :) $"

.CODE 
MAIN PROC 
    MOV AX,@DATA
    MOV DS,AX
    
    XOR DX,DX
    MOV BX,OFFSET STRING1
@REPEAT:    
    MOV AL,[BX]
    CMP AL,"0"
    JB RWS
    CMP AL,"9"
    JBE AARWS
    
    CMP AL,"A"
    JB RWS
    CMP AL,"Z"
    JBE CCARMWCC
    
    CMP AL,"a"
    JB RWS
    CMP AL,"z"
    JBE CCARMWCC
RWS:
    
    MOV [BX]," "
    JMP TOEND 
AARWS:
    ADD DL,AL
    MOV [BX]," "
    JMP TOEND
CCARMWCC:
    XOR AL,20H
    MOV [BX],AL
TOEND:
    INC BX
    CMP [BX],"$"
    JNE @REPEAT

    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN