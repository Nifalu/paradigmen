
lst([2, 4, 6, 8]).

rev([], []).
rev([H|T], Reversed) :-
    rev(T, ReversedTail),
    (   H mod 2 =:= 0
    ->  Reversed = ReversedTail
    ;   append(ReversedTail, [H], Reversed)
    ).

listLength(List, CubedLength) :-
    length(List, Length),
    CubedLength is Length * Length * Length.

popLast(List, Last, NewList) :-
    append(NewList, [Last], List).


isPrime(N) :-
    N > 1,
    \+ has_divisor(N, 2).

has_divisor(N, Divisor) :-
    Divisor =< sqrt(N),
    (N mod Divisor =:= 0 ; NextDivisor is Divisor + 1, has_divisor(N, NextDivisor)).



