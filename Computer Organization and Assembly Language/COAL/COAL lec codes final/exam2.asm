.MODEL SMALL
.STACK 100H

.DATA
    msgStart    DB 'Voting System: Enter your vote (1=A, 2=B, 3=C): $'
    msgA        DB 'Total votes for Candidate A: $'
    msgB        DB 'Total votes for Candidate B: $'
    msgC        DB 'Total votes for Candidate C: $'
    msgInvalid  DB 'Total invalid votes: $'
    newline     DB 13, 10, '$' ; Newline for output formatting

    ; Counters for votes and invalid entries
    countA      DW 0
    countB      DW 0
    countC      DW 0
    countInvalid DW 0

    voterLimit  DW 9 ; Max voters allowed
    voterCount  DW 0 ; Tracks number of votes processed

.CODE
START:
    MOV AX, @DATA       ; Load data segment
    MOV DS, AX

    ; Display welcome message
    LEA DX, msgStart
    MOV AH, 09H
    INT 21H

VotingLoop:
    ; Check if voter limit reached
    MOV AX, voterCount
    CMP AX, voterLimit
    JAE DoneVoting      ; If voterCount >= voterLimit, finish voting

    ; Get single-digit input
    MOV AH, 01H         ; Keyboard input function
    INT 21H
    SUB AL, '0'         ; Convert ASCII to decimal
    CMP AL, 1
    JE VoteA            ; If input = 1, vote for Candidate A
    CMP AL, 2
    JE VoteB            ; If input = 2, vote for Candidate B
    CMP AL, 3
    JE VoteC            ; If input = 3, vote for Candidate C

    ; If input is invalid
    INC countInvalid
    JMP CountVote       ; Skip to increment voterCount

VoteA:
    INC countA          ; Increment Candidate A's counter
    JMP CountVote

VoteB:
    INC countB          ; Increment Candidate B's counter
    JMP CountVote

VoteC:
    INC countC          ; Increment Candidate C's counter
    JMP CountVote

CountVote:
    INC voterCount      ; Increment total votes cast
    JMP VotingLoop      ; Go back to the voting loop

DoneVoting:
    ; Display results
    ; Candidate A votes
    LEA DX, newline
    MOV AH, 09H
    INT 21H
    LEA DX, msgA
    MOV AH, 09H
    INT 21H
    MOV AX, countA
    CALL DisplayNumber  ; Display numeric count

    ; Candidate B votes
    LEA DX, newline
    MOV AH, 09H
    INT 21H
    LEA DX, msgB
    MOV AH, 09H
    INT 21H
    MOV AX, countB
    CALL DisplayNumber

    ; Candidate C votes
    LEA DX, newline
    MOV AH, 09H
    INT 21H
    LEA DX, msgC
    MOV AH, 09H
    INT 21H
    MOV AX, countC
    CALL DisplayNumber

    ; Invalid votes
    LEA DX, newline
    MOV AH, 09H
    INT 21H
    LEA DX, msgInvalid
    MOV AH, 09H
    INT 21H
    MOV AX, countInvalid
    CALL DisplayNumber

    ; Exit program
    MOV AH, 4CH
    INT 21H

; Subroutine to display a number
DisplayNumber PROC
    PUSH AX             ; Save AX
    PUSH DX             ; Save DX
    MOV CX, 0           ; Initialize digit count
    MOV BX, 10          ; Divisor for decimal numbers

ConvertLoop:
    XOR DX, DX          ; Clear DX
    DIV BX              ; Divide AX by 10, remainder in DX
    PUSH DX             ; Save remainder (digit)
    INC CX              ; Increment digit count
    CMP AX, 0
    JNE ConvertLoop     ; Repeat until AX == 0

PrintDigits:
    POP DX              ; Get digit from stack
    ADD DL, '0'         ; Convert to ASCII
    MOV AH, 02H         ; Print character function
    INT 21H
    LOOP PrintDigits    ; Repeat for all digits

    POP DX              ; Restore DX
    POP AX              ; Restore AX
    RET
DisplayNumber ENDP

END START
