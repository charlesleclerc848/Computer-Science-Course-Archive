.MODEL SMALL
.STACK 100H
.DATA
 NEWLINE DB 0DH,0AH,'$'
 STRING DB "Input Decimal Values With Multiple Digits: $"
 STRING_HEX DB "Input HEXADECIMAL Values With FOUR Digits : $"
 STRING_BIN DB "Input BINARY Values With SIXTEEN BITS : $"


 .CODE

MAIN PROC
    MOV AX,@DATA
    MOV DS,AX

     CALL INDEC
     CALL OUTDEC
     CALL INDHEX
     CALL OUTHEX
     CALL INBIN
     CALL OUTBIN
       
      MOV AH,4CH
      INT 21H   
MAIN ENDP
;END MAIN 




 
 INDEC PROC
    MOV AH,09H
    LEA DX, STRING
    INT 21H
              
    ;INITALIZE SI REGISTER TO POINT TO BEGNING OF VAR STRING          
    LEA SI,STRING
    
    JUMP:

    MOV AH,01H
    INT 21H

    CMP AL,'$'  ;CHECK END STRING
    
    JE END
    
    MOV [SI], AL      ;STORE CHAR IN ARRAY CALLED STRING
    INC SI          ;INC  TO STORE NEXT CHAR IN ARRAY
    JMP JUMP

      
     END:
         
     MOV BYTE PTR [SI],'$'     ;$ IS LAST CHAR OF ARRAY STRING
        
        
        
              MOV AH,09H
      MOV DX, OFFSET NEWLINE      ;NEWLINE DAH!
      INT 21H
    
         INDEC ENDP

         ;;;;;;;;;;;;;;

          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
          OUTDEC PROC   
      MOV AH,09H
      MOV DX, OFFSET STRING      ;NAMEA HAS STORED NAME STRING
      INT 21H                                                           ;PART A CONCLUSION
      
      
       MOV AH,09H                                            ;THIS BLOCK DISPLAY DIRECT USER INPUT                      
      MOV DX, OFFSET NEWLINE      ;NEWLINE DAH!
      INT 21H 
      OUTDEC ENDP 
        ;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          
      
      
      
       INDHEX PROC
    MOV AH,09H
    LEA DX, STRING_HEX
    INT 21H
              
    ;INITALIZE SI REGISTER TO POINT TO BEGNING OF VAR STRING          
    LEA SI,STRING_HEX
    
    JUMP_HEX:

    MOV AH,01H
    INT 21H

    CMP AL,'$'  ;CHECK END STRING
    
    JE END_HEX
    
    MOV [SI], AL      ;STORE CHAR IN ARRAY CALLED STRING
    INC SI          ;INC  TO STORE NEXT CHAR IN ARRAY
    JMP JUMP_HEX

      
     END_HEX:
         
     MOV BYTE PTR [SI],'$'     ;$ IS LAST CHAR OF ARRAY STRING
        
        
        
              MOV AH,09H
      MOV DX, OFFSET NEWLINE      ;NEWLINE DAH!
      INT 21H
    
         INDHEX ENDP

         ;;;;;;;;;;;;;;

          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
          OUTHEX PROC   
      MOV AH,09H
      MOV DX, OFFSET STRING_HEX      ;NAMEA HAS STORED NAME STRING
      INT 21H                                                           ;PART A CONCLUSION
      
      
      MOV AH,09H                                            ;THIS BLOCK DISPLAY DIRECT USER INPUT                      
      MOV DX, OFFSET NEWLINE      ;NEWLINE DAH!
      INT 21H 
      OUTHEX ENDP     
      ;; ;;; ;;;;;;;;    
          
          
       
              INBIN PROC
    MOV AH,09H
    LEA DX, STRING_BIN
    INT 21H
              
    ;INITALIZE SI REGISTER TO POINT TO BEGNING OF VAR STRING          
    LEA SI,STRING_BIN
    
    JUMP_BIN:

    MOV AH,01H
    INT 21H

    CMP AL,'$'  ;CHECK END STRING
    
    JE END_BIN
    
    MOV [SI], AL      ;STORE CHAR IN ARRAY CALLED STRING
    INC SI          ;INC  TO STORE NEXT CHAR IN ARRAY
    JMP JUMP_BIN

      
     END_BIN:
         
     MOV BYTE PTR [SI],'$'     ;$ IS LAST CHAR OF ARRAY STRING
        
        
        
              MOV AH,09H
      MOV DX, OFFSET NEWLINE      ;NEWLINE DAH!
      INT 21H
    
         INBIN ENDP

         ;;;;;;;;;;;;;;

          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
          OUTBIN PROC   
      MOV AH,09H
      MOV DX, OFFSET STRING_BIN      ;NAMEA HAS STORED NAME STRING
      INT 21H                                                           ;PART A CONCLUSION
      
      
      MOV AH,09H                                            ;THIS BLOCK DISPLAY DIRECT USER INPUT                      
      MOV DX, OFFSET NEWLINE      ;NEWLINE DAH!
      INT 21H 
      OUTBIN ENDP
          
          
          
          END MAIN 