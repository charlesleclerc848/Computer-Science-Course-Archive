.MODEL SMALL
.STACK 100H
.DATA

 STRING DB "ENTER YOUR NAME : $"
 NAMEA DB 20 DUP('$')
 NEWLINE DB 0DH,0AH,'$'
 CASE_CONVERTED  DB 20 DUP('$')
 VOWEL_COUNT DB 0 
 STRING0 DB "Vowel count =  $"
 STRING1 DB "CONSONANT count =  $" 
 CONSONANT_COUNT DB 0
 BINARY_CONVERTED DB 20 DUP('$')
 HEX_CONVERTED DB 40 DUP('$')
 ONE_COUNT DB 0
 ONE_COUNT_MESSAGE DB "Number of 1's bits : $"
 ZERO_COUNT DB 0
 ZERO_COUNT_MESSAGE DB "Number of 0's bits : $"
 REVERSED DB 20 DUP('$') 
 WITHOUT_VOWELS DB 20 DUP ('$')
 WITHOUT_CONSONANTS DB 20 DUP('$')
 
 
 
.CODE

MAIN PROC
    MOV AX,@DATA
    MOV DS,AX

    
   CALL PROC1 ;;;;;;;;;;;;;;;;;;
     
   CALL PROC2 ;;;;;;;;;;;;;;
        
   CALL PROC3;;;;;;;;;;;;;;;;;
   
   CALL PROC4 
   
   CALL PROC5
   
   CALL PROC6

   CALL PROC7   

   CALL PROC8

   CALL PROC9
   
   CALL PROC10
    
   CALL PROC11 
    
   CALL PROC12 
        
       
      MOV AH,4CH
      INT 21H   
MAIN ENDP
;END MAIN    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
         
 
 
 
 
 
 
 PROC1 PROC
     MOV AH,09H
    LEA DX, STRING
    INT 21H
              
    ;INITALIZE SI REGISTER TO POINT TO BEGNING OF VAR NAME          
    LEA SI,NAMEA
    
    JUMP:

    MOV AH,01H
    INT 21H

    CMP AL,'$'  ;CHECK END STRING
    
    JE END
    
    MOV [SI], AL      ;STORE CHAR IN ARRAY CALLED NAME
    INC SI          ;INC  TO STORE NEXT CHAR IN ARRAY
    JMP JUMP

      
     END:
         
     MOV BYTE PTR [SI],'$'     ;$ IS LAST CHAR OF ARRAY NAME
        
        
        
              MOV AH,09H
      MOV DX, OFFSET NEWLINE      ;NEWLINE DAH!
      INT 21H
      ;PRINT NAME IN NEW LINE
      
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;    
      MOV AH,09H
      MOV DX, OFFSET NAMEA      ;NAMEA HAS STORED NAME STRING
      INT 21H                                                           ;PART A CONCLUSION
      
      
       MOV AH,09H                                            ;THIS BLOCK DISPLAY DIRECT USER INPUT                      
      MOV DX, OFFSET NEWLINE      ;NEWLINE DAH!
      INT 21H   
      
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;     
       
        
         
         PROC1 ENDP
 
 
       PROC2 PROC 
 
           
           
           
                   
    LEA SI, NAMEA                    ;GIVING ADDRESS'S TO POINTER FOR CONVERSION AND COPYING
    LEA DI, CASE_CONVERTED
                                
                                
     CASE_CONVERSION_LOOP:                           
                                
          ;CHECK FOR LOWER CASE
        
         ; CHECK:
          
          MOV AL,[SI]
          CMP AL,'$'   ; IF STRING ENDED
          JE CHECK_COMPLETE
           
           
          ;CHECK IF AL IS lower 
          CMP AL,'a'    ;if AL IS LOWER THAN A IT CAN BE UPPER
          JL CHECK_UPPER
          CMP AL,'z'
          JG CHECK_UPPER
                          
           ;CONVERT TO UPPER CASE    ;IF BOTH CONDITIONS ARE FALSE= AL IS LOWER           
             SUB AL,20H              
             JMP STORE             
                          
                          
      CHECK_UPPER:                
          CMP AL,'A'    
          JL STORE
          CMP AL,'Z'
          JG STORE              
                          
                          
           ; CONVERTING TO LOWER CASE 
          
          ADD AL,20H
           
           
           STORE:             ;STORING THE CONVERSION IN  CASE_CONVERTED USING DI POINTER
        
        MOV [DI],AL     
        INC DI      ;TO STORE NEXT CHECKED CHAR
        INC SI       ;TO GIVE TO CHECK NEXT CHAR
             
        JMP CASE_CONVERSION_LOOP     
             
        CHECK_COMPLETE:
          MOV BYTE PTR [DI],'$'     ;LAST CHAR $ IN  CASE_CONVERTED ARRAY                  
                                                                           
          ;NEWLINE 
          MOV AH,09H
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H                                                                 
                                       ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
            ;CONVERTED CONVERSION DISPLAY
           
           
           MOV AH,09H
          MOV DX, OFFSET CASE_CONVERTED                                                                
          INT 21H                                                                 
                                                               ;part b CONCLUSION            
           
       ;NEWLINE 
          MOV AH,09H
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H      
           
           
           
           
       PROC2 ENDP
        
        
        
       PROC3 PROC 
        
        
                   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;   
           
           XOR CL,CL     ;CL IS NOW 0 WHICH CAN BE USED TO COUNT VOWELS  
           
           
           XOR CH,CH     ; CH TO COUNT CONSONENT
              
           
           LEA SI,NAMEA   ; ADDRESS OF ARRAY TO REGISTER SI  
                
                
            VOWEL_LOOP:    
            
            MOV AL,[SI]     ;MOVING TARGET CHAR TO AL
            CMP AL,'$'      ; CHECKING IF STRING ENDED
            
            JE VOWEL_COUNT_COMPLETED
            
            CMP AL,'A'
            JE IS_VOWEL
            CMP AL,'E'
            JE IS_VOWEL
            CMP AL,'I'
            JE IS_VOWEL
            CMP AL,'O'
            JE IS_VOWEL
            CMP AL,'U'
            JE IS_VOWEL
            CMP AL,'a'
            JE IS_VOWEL
            CMP AL,'e'
            JE IS_VOWEL
            CMP AL,'i'
            JE IS_VOWEL
            CMP AL,'o'
            JE IS_VOWEL
            CMP AL,'u'
            JE IS_VOWEL

            NOT_VOWEL:    
            INC SI                     ;MOV TO NEXT CHAR
            INC  CH                    ;INCREMENT CONSONANT COUNT
            JMP VOWEL_LOOP   
            
            IS_VOWEL:
            INC CL           ;INCREMENT VOWEL COUNT
            INC SI            ;INCREMENT THE COUNTER & MOV TO NEXT CHAR
            JMP VOWEL_LOOP
             ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
            VOWEL_COUNT_COMPLETED:   
            MOV VOWEL_COUNT,CL              ;VOWEL COUNT IS STORED IN VARIABLE 
            
                       
                                                           
          MOV AH,09H                                      
          MOV DX, OFFSET STRING0      ;VOWEL COUNT VARIABLE                                                            
          INT 21H 
          
          
          
            
          MOV AL,VOWEL_COUNT
          ADD AL,'0'
          MOV DL,AL                  ;VOWEL COUNT DISPLAY AFTER CONVERSION
          
          MOV AH,02H
          INT 21H


                       ;NEWLINE                       ;PART C CONCLUSION
          MOV AH,09H                                      
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H   
                                                                       
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;                                                              
      
        
        
        
       PROC3 ENDP;;;;;;; 
        
       PROC4 PROC 
        
        
            MOV CONSONANT_COUNT,CH                ;CONSONANT_COUNT IS STORED IN VARIABLE 
                                
                                
          MOV AH,09H                                      
          MOV DX, OFFSET STRING1      ;CONSONANT COUNT VARIABLE                                                            
          INT 21H                   
                                
                                
          MOV BL,CONSONANT_COUNT
          ADD BL,'0'
          MOV DL,BL                  ;CONSONANT COUNT DISPLAY AFTER CONVERSION
          
          MOV AH,02H
          INT 21H
            
                                                                                        
                       ;NEWLINE                       ;PART D CONCLUSION
          MOV AH,09H                                      
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H   
                                                                       
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      
        
       PROC4 ENDP 
        
         
         
       PROC5 PROC  
         
              ;FOR BINARY CONVERSION TAKING ADDRESS'S
      
       LEA SI,NAMEA
       LEA DI,BINARY_CONVERTED
      
       BINARY_CONVERSION_LOOP:
      
       MOV AL,[SI]                        ;TARGET ADDRESS TO AL FORM SI
       CMP AL,'$'                         ;CHECK IF STRING ENDED
       JE CONVERSION_COMPLETED
      
       MOV BL,AL                          ;USING BL FOR CONVERSION
       MOV CX,8                           ;1 BYTE FOR EACH LETTER = 8 BIT'S
       
       COVERSION_TO_BINARY:
       ROR BL,1
       MOV DL,BL
       AND DL,01H
       ADD DL,'0'
       MOV [DI],DL
       INC DI
       LOOP COVERSION_TO_BINARY 
       
       INC SI
       JMP BINARY_CONVERSION_LOOP
       
       CONVERSION_COMPLETED:
       MOV BYTE PTR [DI],'$'                     ;$ TO THE END OF BINARY SEQUENCE
          
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;          
          ;NEWLINE
          MOV AH,09H                                      
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H   
                                                           ; PART E CONCLUSION
       
          MOV AH,09H                                      
          MOV DX, OFFSET BINARY_CONVERTED        ;A SEQUENCE OF BINARY CONVERION NUMBERS                                                          
          INT 21H  
          
          
          
          
                    ;NEWLINE
          MOV AH,09H                                      
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H 
                  
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;     
      
  
         
         
        PROC5 ENDP 
         
         
        PROC6 PROC 
         
           
              
   
      LEA SI,NAMEA
       LEA DI,HEX_CONVERTED          ; POINTING TO THE START OF ADDRESS'S OF THE STRING'S
          
          
       HEX_CONVERSION_LOOP:                   
          
       MOV AL,[SI]   
       CMP AL,'$'                           ; CHECKING IF STRING COMPLETED
       JE HEX_CONVERSION_COMPLETED   
          
       ;CONVERT HIGH NIBBLE(4 BITS)   
       MOV AH,AL   
       SHR AH,4                              ;MOV TO AH FROM AL AND THEN SHIFT RIGHT
       
       ;PROCESS HIGH NIBBLE   
          
       CMP AH,0AH   
       JL HEX_NIBBLE_HIGH   
       ADD AH,37H                               ;CONVERSION A---F
       JMP STORE_HIGH_DIGIT   
       
       HEX_NIBBLE_HIGH:
       ADD AH,30H                               ;CONVERSION 0---9
       
       
       STORE_HIGH_DIGIT:
                                                   ; STORING HIGH NIBBLE
       MOV [DI] ,AH   
       INC DI                                     ; MOVING TO NEXT CHAR
          
       
       
       ;CONVERT LOW NIBBLE
       
       MOV AL,[SI]
       AND AL,0FH
       
       ;PROCESS THE LOW NIBBLE
       
       CMP AL,0AH
       JL HEX_DIGIT_LOW
       ADD AL,37H                             ;CONVERSION A---F
       JMP STORE_LOW_DIGIT  
       
       
       HEX_DIGIT_LOW:
       ADD AL,30H                              ;CONVERSION 0---9
       
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;       
       STORE_LOW_DIGIT:
        MOV [DI] ,AL
        INC DI
        
        
        INC SI
        JMP HEX_CONVERSION_LOOP
                                                                        ;CONCLUSION PART F
       HEX_CONVERSION_COMPLETED:
        
       MOV BYTE PTR [DI],'$' 
        
       MOV AH,09H 
       LEA DX,HEX_CONVERTED           ;PRINTING HEXA CONVERSION
       INT 21H  
       
       
       
         ;NEWLINE                       
          MOV AH,09H                                      
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;        
        
           
           
        PROC6 ENDP   
       
       
       
       
       
       
       
       
        PROC7 PROC
       
                LEA SI, BINARY_CONVERTED
        XOR CX, CX
        
        COUNT_ONES_LOOP:
        
        MOV AL,[SI]
        CMP AL,'$'
        JE COUNT_ONES_COMPLETED
        
        CMP AL,'1'
        JNE SKIP_INCREMENT
        INC CL                   ;COUNT 1IN CL
        
        SKIP_INCREMENT:
        INC SI
        JMP COUNT_ONES_LOOP
        
      COUNT_ONES_COMPLETED:
        
        MOV ONE_COUNT, CL 

        
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;        
        ;DISPLAY COUNT OF 1 BIT'S
        
        MOV AH,09H
        LEA DX, ONE_COUNT_MESSAGE
        INT 21H
        
         ;CONVERT THE COUNT FOR READABILITY
        
        MOV AL,ONE_COUNT                            ;PART G CONCLUSION
        ADD AL,'0'
        MOV DL,AL
        MOV AH,02H
        INT 21H  
        
        ;NEWLINE                       
          MOV AH,09H                                      
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H
        
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;       
        
 
       
        PROC7 ENDP
       
           
         
         
         
        PROC8 PROC 
         
         
         
         
                LEA SI, BINARY_CONVERTED
        XOR CX, CX
        
        ZERO_ONES_LOOP:
        
        MOV AL,[SI]
        CMP AL,'$'
        JE COUNT_ZERO_COMPLETED
        
        CMP AL,'0'
        JNE SKIPE_INCREMENT
        INC CL                   ;COUNT 0 IN CL
        
        SKIPE_INCREMENT:
        INC SI
        JMP ZERO_ONES_LOOP
        
      COUNT_ZERO_COMPLETED:
        
        MOV ZERO_COUNT, CL 

        
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;        
        ;DISPLAY COUNT OF 0 BIT'S
        
        MOV AH,09H
        LEA DX, ZERO_COUNT_MESSAGE
        INT 21H
        
         ;CONVERT THE COUNT FOR READABILITY
        
        MOV AL,ZERO_COUNT                            ;PART H CONCLUSION
        ADD AL,'0'
        MOV DL,AL
        MOV AH,02H
        INT 21H  
        
        ;NEWLINE                       
          MOV AH,09H                                      
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H
        
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;       
         
         
         
           
         PROC8 ENDP  
            
            
          PROC9 PROC  
            
                  
        LEA SI,NAMEA
        LEA DI,REVERSED
         
        ;FINDING THE STRING LENGHT 
         
        MOV CX,0           ;RESET COUNTER
         
         
        FIND_END: 
         
         MOV AL,[SI]        ;TARGET CHAR ADDRESS
         CMP AL,'$'
         JE END_FOUND
         INC SI
         INC CX
         JMP FIND_END
         
       END_FOUND:          
         ADD CX,1          
         DEC CX       ;ADJUST POSITION OF 2ND LAST CHAR
         DEC SI       ;ADJUST SI TO POINT TO THE  2ND LAST CHAR
         
       REVERSE_LOOP:  
         
       MOV AL,[SI]  
       MOV [DI],AL  
       INC DI  
       DEC SI  
       LOOP REVERSE_LOOP  
   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;       
            
       MOV BYTE PTR [DI],'$'
       
       ;DISPLAYING REVERSED STRING
       
       
       MOV AH,09H
       LEA DX,REVERSED
       INT 21H                                                         ; PART I CONCLUDED
          
          
          
          ;NEWLINE                       
          MOV AH,09H                                      
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H
        
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;       
        
       
            
            
          PROC9 ENDP  
            
            
            
            
          PROC10  PROC
            
            
                 
     LEA SI, NAMEA
     LEA DI, WITHOUT_VOWELS      
        
     ;REMOVE VOWELS FROM ORIGNAL STRINGS     
              
    REMOVE_VOWELS_LOOP:
     MOV AL,[SI]
     CMP AL,'$'
     JE END_REMOVE_VOWELS         
              
              
     ;CHECK IF CHAR IS A VOWEL         
              
     CMP AL,'A'         
     JE SKIP_VOWEL         
     CMP AL,'E'         
     JE SKIP_VOWEL         
     CMP AL,'I'         
     JE SKIP_VOWEL         
     CMP AL,'O'         
     JE SKIP_VOWEL          
     CMP AL,'U'         
     JE SKIP_VOWEL         
     CMP AL,'a'         
     JE SKIP_VOWEL         
     CMP AL,'e'         
     JE SKIP_VOWEL         
     CMP AL,'i'         
     JE SKIP_VOWEL          
     CMP AL,'o'         
     JE SKIP_VOWEL         
     CMP AL,'u'         
     JE SKIP_VOWEL         
     
     ;IF NOT A VOWEL, COPY CHAR TO ARRAY         
              
     MOV [DI],AL         
     INC DI         
              
              
     SKIP_VOWEL:         
      INC SI        
      JMP REMOVE_VOWELS_LOOP 
           
     END_REMOVE_VOWELS:        
      
     ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;       
        
                 
     ;PRINT THE STRING WITHOUT VOWELS         
     
     MOV AH,09H         
     LEA DX,WITHOUT_VOWELS                       ;PART J CONCLUSION
     INT 21H
     
      ;NEWLINE                       
          MOV AH,09H                                      
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H
        
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;       
        
 PROC10 ENDP 
            
   
   
   
   PROC11 PROC
    
       
    
     LEA SI, NAMEA
     LEA DI, WITHOUT_CONSONANTS
     
     ;REMOVE CONSONANTS FROM ORIGNAL STRING
   
   REMOVE_CONSONANTS_LOOP:
     MOV AL,[SI]
     CMP AL,'$'
     JE END_REMOVE_CONSONANTS
   
     ;CHECK IF CHAR IS CONSONANT
   
   
     CMP AL,'A'         
     JE COPY_VOWEL         
     CMP AL,'E'         
     JE COPY_VOWEL         
     CMP AL,'I'         
     JE COPY_VOWEL         
     CMP AL,'O'         
     JE COPY_VOWEL          
     CMP AL,'U'         
     JE COPY_VOWEL         
     CMP AL,'a'         
     JE COPY_VOWEL         
     CMP AL,'e'         
     JE COPY_VOWEL         
     CMP AL,'i'         
     JE COPY_VOWEL          
     CMP AL,'o'         
     JE COPY_VOWEL         
     CMP AL,'u'         
     JE COPY_VOWEL  
   
     ;SKIP CONSONANTS
     JMP SKIP_CONSONANT
   
     COPY_VOWEL:
        ;IF NOT A CONSONANT COPY CHAR TO ARRAY
   
     MOV [DI], AL
     INC DI
   
     SKIP_CONSONANT:
     INC SI
     JMP REMOVE_CONSONANTS_LOOP
   
   
     END_REMOVE_CONSONANTS:
       ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;       
       
       MOV BYTE PTR [DI],'$'
       
       ;DISPLAYING STRING WITHOUT CONSONANTS
       
       
       MOV AH,09H
       LEA DX, WITHOUT_CONSONANTS
       INT 21H                                                         ; PART K CONCLUDED
          
          
          
          ;NEWLINE                       
          MOV AH,09H                                      
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H
   
  ;NEWLINE                       
          MOV AH,09H                                      
          MOV DX, OFFSET NEWLINE                                                                 
          INT 21H
        
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;       
         
   
   PROC11 ENDP
         
         
         
         
     PROC12 PROC       
           
           
       
      ;NAME    
 MOV AH,09H         
 MOV DX,OFFSET NAMEA
 INT 21H         
          
          
 ;NEWLINE                       
  MOV AH,09H                                      
  MOV DX, OFFSET NEWLINE                                                                 
  INT 21H        
  
       ;STRING WITH CASE CONVERTED  
 MOV AH,09H         
 MOV DX,OFFSET CASE_CONVERTED 
 INT 21H         
          
          
 ;NEWLINE                       
  MOV AH,09H                                      
  MOV DX, OFFSET NEWLINE                                                                 
  INT 21H
  
          
          
     ;REVESED STRING    
 MOV AH,09H         
 MOV DX,OFFSET REVERSED 
 INT 21H         
          
          
 ;NEWLINE                       
  MOV AH,09H                                      
  MOV DX, OFFSET NEWLINE                                                                 
  INT 21H          
          
          
       ;NAME WITHOUT VOWELS    
 MOV AH,09H         
 MOV DX,OFFSET WITHOUT_VOWELS
 INT 21H         
          
          
 ;NEWLINE                       
  MOV AH,09H                                      
  MOV DX, OFFSET NEWLINE                                                                 
  INT 21H        
          
          
     ;STRING WITHOUT CONSONANTS   
 MOV AH,09H         
 MOV DX,OFFSET WITHOUT_CONSONANTS 
 INT 21H         
          
          
 ;NEWLINE                       
  MOV AH,09H                                      
  MOV DX, OFFSET NEWLINE                                                                 
  INT 21H          
          
        
           
           
     PROC12 ENDP       
            
            
END MAIN         