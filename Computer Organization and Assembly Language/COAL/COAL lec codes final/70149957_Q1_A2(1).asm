.MODEL SMALL
.STACK 100H
.DATA
    INPUT_NAME DB 20 DUP("@") 
    CASE_CONVERTED DB 20 DUP("@")
    VOWEL_ARRAY DB 15 DUP("@") 
    CONSONENT_ARRAY DB 15 DUP("@")   
    BINARY_ARRAY DB 20 DUP("12345678")
    HEX_ARRAY DB 20 DUP("#")
    REVERSED_NAME DB 20 DUP("@")
    ARRAY_CONSONENT DB 20 DUP("@")
    ARRAY_VOWELS DB 20 DUP("@")
    
    T_ZEROS DB 0
    T_ONES DB 0
    INDEX_VOWELS DB 0
    INDEX_CONSONET DB 0
    T_CONSONENT DB 0
    T_VOWELS DB 0
    MAIN_INDEX DB 0
    
    MSG12 DB 0AH,0DH,0AH,0DH,"Part K: ", 0AH,0DH,"Without CONSONENT: ","$"
    MSG11 DB 0AH,0DH,0AH,0DH,"Part J: ", 0AH,0DH,"Without vowels: $"
    MSG10 DB 0AH,0DH,0AH,0DH,"Part I: ", 0AH,0DH,"Reversed Name: $"
    MSG9 DB 0AH,0DH,0AH,0DH,"Part H: ", 0AH,0DH,"Total number of 0's: ","$"
    MSG8 DB 0AH,0DH,0AH,0DH,"Part G: ", 0AH,0DH,"Total number of 1's: ","$"
    MSG7 DB 0AH,0DH,0AH,0DH,"Part F: ", 0AH,0DH,"Hexa Decimal Conversion: ",0AH,0DH,"$" 
    MSG6 DB 0AH,0DH,0AH,0DH,"Part E: ", 0AH,0DH,"Binaray Conversion: ",0AH,0DH,"$" 
    MSG5 DB 0AH,0DH,0AH,0DH,"Part D: ", 0AH,0DH,"Total number of Consonents: $" 
    MSG4 DB 0AH,0DH,0AH,0DH,"Part C: ", 0AH,0DH,"Total number of Vowels: $"
    MSG3 DB 0AH,0DH,0AH,0DH,"Part B: ", 0AH,0DH,"Case Converted: $"
    MSG2 DB 0AH,0DH,"Your Name is : $"
    MSG1 DB "Part A: ", 0AH,0DH,"Enter your name (use Dollar sign for termination) : $" 
    NEWLINE DB 0AH, 0DH, "$"
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    ;part 1 input your name and print it  
    LEA DX, MSG1
    MOV AH, 09H
    INT 21H
    
    LEA BX, INPUT_NAME
    XOR CX, CX 
    
    @INPUT_NAME:
    MOV AH, 01H
    INT 21H
    
    MOV [BX], AL
    
    CMP AL, "$"
    JZ PRINT_NAME
    
    INC BX
    INC CL
    JMP @INPUT_NAME  
    
    PRINT_NAME:
    LEA DX, MSG2
    MOV AH, 09H
    INT 21H
    
    XOR BX, BX  
    
    DEC CL
    MOV MAIN_INDEX, CL
    XOR CX, CX
    
    PRINT_NAME1:
    CMP CL, MAIN_INDEX
    JA PART_B
    
    MOV DX, [BX]
    MOV AH, 02H
    INT 21H
    
    INC BX
    INC CL
    JMP PRINT_NAME1  
    
    ;Part B convert the case
    PART_B:
    LEA DX, MSG3
    MOV AH, 09H
    INT 21H
    
    XOR BX, BX  
    XOR CX, CX 
    
    LEA BX, INPUT_NAME
    LEA SI, CASE_CONVERTED 
    
    MOV CL, MAIN_INDEX
    INC CL
    
    CONVERTED:
    
    MOV DL, [BX] 
    
    CMP DL, 020H
    JZ ADD_SPACE
    
    CMP DL, 061H
    JL GREATER
    
    CMP DL, 07BH
    JL TO_GREATER
       
    GREATER:
    CMP DL, 041H
    JL NEXT_CHAR
    
    CMP DL, 05BH
    JL TO_LOWER
    
    ADD_SPACE:
    MOV [SI], 020H
    JMP NEXT_CONVERTED
    
    TO_LOWER:
    ;ADD DL, 020H   
    OR DL, 20H
    MOV [SI], DL
    JMP NEXT_CONVERTED
    
    TO_GREATER:
    AND DL, 0DFH
    MOV [SI], DL
    JMP NEXT_CONVERTED 
    
    NEXT_CONVERTED: 
    MOV DX, [SI]
    MOV AH, 02H
    INT 21H
    
    INC SI
    NEXT_CHAR:
    INC BX 
    LOOP CONVERTED 
    
    ;part C: find vowels and consonents
    PART_C:
    XOR BX, BX
    XOR SI, SI
    XOR CX, CX
    
    MOV CL, MAIN_INDEX
    INC CL
    
    LEA BX, INPUT_NAME 
    LEA SI, VOWEL_ARRAY 
    LEA DI, CONSONENT_ARRAY
    
    CHECK_VOWEL: 
    CMP [BX], 020H
    JZ SPACE
    
    CMP [BX], "A" 
    JL NEXT_VALUE
    
    CMP [BX], "Z"
    JL IS_VOWEL 
    
    CMP [BX], "a" 
    JL NEXT_VALUE
    
    CMP [BX], "z"
    JL IS_VOWEL
    
    SPACE:
    MOV [SI], " "
    INC SI
    JMP NEXT_VALUE
    
    IS_VOWEL:
    CMP [BX], "A"
    JZ INCREAMENT_VOWEL
    
    CMP [BX], "a"
    JZ INCREAMENT_VOWEL
    
    CMP [BX], "E"
    JZ INCREAMENT_VOWEL
    
    CMP [BX], "e"
    JZ INCREAMENT_VOWEL
    
    CMP [BX], "I"
    JZ INCREAMENT_VOWEL
    
    CMP [BX], "i"
    JZ INCREAMENT_VOWEL
    
    CMP [BX], "O"
    JZ INCREAMENT_VOWEL
    
    CMP [BX], "o"
    JZ INCREAMENT_VOWEL 
    
    CMP [BX], "U"
    JZ INCREAMENT_VOWEL
    
    CMP [BX], "u"
    JZ INCREAMENT_VOWEL 
    
    MOV DL, [BX]
    MOV [DI], DL 
    INC DI
    INC T_CONSONENT
    JMP NEXT_VALUE
    
    INCREAMENT_VOWEL:
    MOV DL, [BX]
    MOV [SI], DL
    INC SI  
    INC T_VOWELS
    
    NEXT_VALUE:
    INC BX
    LOOP CHECK_VOWEL 
    
    LEA DX, MSG4
    MOV AH, 09H
    INT 21H 
    
    MOV DL, T_VOWELS
    ADD DL, 30H
    MOV AH, 02H
    INT 21H 
    
    LEA DX, MSG5
    MOV AH, 09H
    INT 21H 
    
    MOV DL, T_CONSONENT
    ADD DL, 30H
    MOV AH, 02H
    INT 21H
    
    ;part E: Binary Conversion
    PART_E:
    LEA DX, MSG6
    MOV AH, 09H
    INT 21H
    
    XOR BX, BX
    XOR SI, SI
    XOR DI, DI
    XOR CX, CX
    
    LEA BX, INPUT_NAME
    LEA SI, BINARY_ARRAY
    
    IN_BINARY:
    LEA DI, SI
    
    CMP CL, MAIN_INDEX
    JA PART_F
    
    XOR DH, DH
    MOV DH, [BX] 
    XOR CH, CH  
    
    CMP DH, " "
    JZ NEXT_BINARY 
    
    @LOOPS:
    CMP CH, 7
    JA NEXT_BINARY
    
    SHL DH, 1
    JC ONE
    
    MOV DL, "0"
    MOV AH, 02H 
    INT 21H
    MOV [DI], "0"
    INC DI
    INC T_ZEROS 
    INC CH
    JMP @LOOPS
    
    ONE:
    MOV DL, "1"
    MOV AH, 02H 
    INT 21H 
    MOV [DI], "1"
    INC T_ONES
    INC DI 
    INC CH
    JMP @LOOPS
    
    NEXT_BINARY: 
    INC BX
    INC SI
     
    MOV DL, 0AH
    MOV AH, 02H
    INT 21H
    
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    
    INC CL
    JMP IN_BINARY
        
;    MOV CL, MAIN_INDEX
;    INC CL
    
;    IN_BINARY:
;    
;    XOR DH, DH
;    MOV DH, [BX] 
;    XOR CH, CH  
;    
;    @LOOPS:
;    CMP CH, 7
;    JA NEXT_BINARY
;    
;    SHL DH, 1
;    JC ONE
;    
;    MOV DL, "0"
;    MOV AH, 02H 
;    INT 21H 
;    INC CH
;    JMP @LOOPS
;    
;    ONE:
;    MOV DL, "1"
;    MOV AH, 02H 
;    INT 21H 
;    INC CH
;    JMP @LOOPS
;    
;    NEXT_BINARY: 
;    INC BX
;     
;    MOV DL, 0AH
;    MOV AH, 02H
;    INT 21H
;    
;    MOV DL, 0DH
;    MOV AH, 02H
;    INT 21H
;    
;    LOOP IN_BINARY
    
    PART_F:
    LEA DX, MSG7
    MOV AH, 09H
    INT 21H
    
    XOR BX, BX
    XOR SI, SI
    XOR DI, DI
    XOR CX, CX
    XOR DX, DX
    
    LEA BX, INPUT_NAME
    LEA SI, HEX_ARRAY 
    
    
    PART_G:
    LEA DX, MSG8
    MOV AH, 09H
    INT 21H 
    
    XOR DX, DX
    MOV DL, T_ONES 
    ADD DL, "0"
    MOV AH, 02H
    INT 21H 
    
    PART_H:
    LEA DX, MSG9
    MOV AH, 09H
    INT 21H  
    
    XOR DX, DX
    MOV DL, T_ZEROS
    ADD DL, "0"
    MOV AH, 02H
    INT 21H 
    
    PART_I:
    LEA DX, MSG10
    MOV AH, 09H
    INT 21H   
    
    XOR CX, CX
    XOR DX, DX 
    XOR BX, BX
    XOR SI, SI
    
    LEA BX, INPUT_NAME
    LEA SI, REVERSED_NAME
    
    MOV DL, MAIN_INDEX
    ADD BX, DX  
    ADD CL, MAIN_INDEX
    INC CL
    
    REVERSED:
    MOV DL, [BX]
    MOV [SI], DL 
    
    DEC BX
    INC SI
    LOOP REVERSED
    
    LEA BX, REVERSED_NAME
    ADD CL, MAIN_INDEX
    INC CL
    
    PRINT_REVERSED:
    MOV DL, [BX]
    MOV AH, 02H
    INT 21H 
    
    INC BX
    
    LOOP PRINT_REVERSED
    
    PART_J: 
    LEA DX, MSG11
    MOV AH, 09H
    INT 21H   
    
    XOR CX, CX
    XOR DX, DX 
    XOR BX, BX
    
    LEA BX, INPUT_NAME
    LEA SI, ARRAY_VOWELS
    LEA DI, ARRAY_CONSONENT
    
    MOV CL, MAIN_INDEX
    INC CL
    
    MOVE_ALPHABET:
    CMP [BX], "A" 
    JL NEXT_ELEMENT
    
    CMP [BX], "Z"
    JL IS_ALPHABET 
    
    CMP [BX], "a" 
    JL NEXT_ELEMENT
    
    CMP [BX], "z"
    JL IS_ALPHABET
    
    IS_ALPHABET:
    CMP [BX], "A"
    JZ ADD_VOWELS
    
    CMP [BX], "a"
    JZ ADD_VOWELS
    
    CMP [BX], "E"
    JZ ADD_VOWELS
    
    CMP [BX], "e"
    JZ ADD_VOWELS
    
    CMP [BX], "I"
    JZ ADD_VOWELS
    
    CMP [BX], "i"
    JZ ADD_VOWELS
    
    CMP [BX], "O"
    JZ ADD_VOWELS
    
    CMP [BX], "o"
    JZ ADD_VOWELS 
    
    CMP [BX], "U"
    JZ ADD_VOWELS
    
    CMP [BX], "u"
    JZ ADD_VOWELS 
    
    MOV DL, [BX]
    MOV [DI], DL 
    INC DI 
    INC INDEX_CONSONET
    JMP NEXT_ELEMENT
    
    ADD_VOWELS:
    MOV DL, [BX]
    MOV [SI], DL
    INC INDEX_VOWELS
    INC SI  
    
    NEXT_ELEMENT:
    INC BX
    LOOP MOVE_ALPHABET
    
    LEA BX, ARRAY_CONSONENT

    MOV CL, INDEX_CONSONET
    
    PRINT_CONSONENT_ARRAY:
    MOV DL, [BX]
    MOV AH, 02H
    INT 21H
    
    INC BX
    LOOP PRINT_CONSONENT_ARRAY
    
    PART_K: 
    LEA DX, MSG12
    MOV AH, 09H
    INT 21H   
    
    XOR CX, CX
    XOR DX, DX 
    XOR BX, BX 
    
    LEA BX, ARRAY_VOWELS
    MOV CL, INDEX_VOWELS 
    
    PRINT_VOWELS_ARRAY:
    MOV DL, [BX]
    MOV AH, 02H
    INT 21H
    
    INC BX
    LOOP PRINT_VOWELS_ARRAY
    
    EXIT:  
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN