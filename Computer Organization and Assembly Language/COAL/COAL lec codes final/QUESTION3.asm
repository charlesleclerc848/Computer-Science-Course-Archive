.MODEL SMALL
.STACK 100H

.DATA
    
    VotesA DB 0       
    VotesB DB 0       
    VotesC DB 0       
    InvalidVotes DB 0 
    
    VoteCount DB 0    
    MaxVotes DB 9    

    InputPrompt DB 'Voting System: Enter your vote (1=A, 2=B, 3=C): $'
    TotalAMsg DB 0DH, 0AH, 'Total votes for Candidate A: $'
    TotalBMsg DB 'Total votes for Candidate B: $'
    TotalCMsg DB 'Total votes for Candidate C: $'
    InvalidMsg DB 'Total invalid votes: $'
    NewLine DB 0DH, 0AH, '$' 

.CODE
MAIN PROC
    MOV AX, @DATA      
    MOV DS, AX

  
    LEA DX, InputPrompt
    MOV AH, 09H
    INT 21H
  

VotingProcess:
    
    MOV AL, VoteCount
    CMP AL, MaxVotes
    JAE DisplayResults 

    
    MOV AH, 01H       
    INT 21H

    
    CMP AL, '1'        
    JE CandidateA
    CMP AL, '2'        
    JE CandidateB
    CMP AL, '3'       
    JE CandidateC

   
    INC InvalidVotes
    JMP CountVote

CandidateA:
    INC VotesA        
    JMP CountVote

CandidateB:
    INC VotesB         
    JMP CountVote

CandidateC:
    INC VotesC         
    JMP CountVote

CountVote:
    INC VoteCount      
    JMP VotingProcess  

DisplayResults:
    
    LEA DX, TotalAMsg
    MOV AH, 09H
    INT 21H
    MOV AL, VotesA
    ADD AL, '0'        
    MOV DL, AL
    MOV AH, 02H
    INT 21H
    LEA DX, NewLine
    MOV AH, 09H
    INT 21H

    
    LEA DX, TotalBMsg
    MOV AH, 09H
    INT 21H
    MOV AL, VotesB
    ADD AL, '0'       
    MOV DL, AL
    MOV AH, 02H
    INT 21H
    LEA DX, NewLine
    MOV AH, 09H
    INT 21H

    
    LEA DX, TotalCMsg
    MOV AH, 09H
    INT 21H
    MOV AL, VotesC
    ADD AL, '0'        
    MOV DL, AL
    MOV AH, 02H
    INT 21H
    LEA DX, NewLine
    MOV AH, 09H
    INT 21H

   
    LEA DX, InvalidMsg
    MOV AH, 09H
    INT 21H
    MOV AL, InvalidVotes
    ADD AL, '0'        
    MOV DL, AL
    MOV AH, 02H
    INT 21H
    LEA DX, NewLine
    MOV AH, 09H
    INT 21H

    
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
