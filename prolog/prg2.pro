%Production rules
%ctof
%f is c*9/5 + 32
%freezing f<=32

ctof(C,F):-
    F is (C*(9/5))+32.
freezing(F):-
    F=<32.

