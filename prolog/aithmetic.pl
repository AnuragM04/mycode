
calculate(add, X, Y, Result) :-
    Result is X + Y,
    format('~w + ~w = ~w~n', [X, Y, Result]).

calculate(subtract, X, Y, Result) :-
    Result is X - Y,
    format('~w - ~w = ~w~n', [X, Y, Result]).

calculate(multiply, X, Y, Result) :-
    Result is X * Y,
    format('~w * ~w = ~w~n', [X, Y, Result]).

calculate(divide, X, Y, Result) :-
    Y \= 0,
    Result is X // Y,
    format('~w // ~w = ~w~n', [X, Y, Result]).

calculate(divide, _, 0, 'Error: Division by zero') :-
    format('Error: Division by zero~n').

calculate(Operation, _, _, 'Error: Unknown operation') :-
    \+ member(Operation, [add, subtract, multiply, divide]),
    format('Error: Unknown operation "~w"~n', [Operation]).
