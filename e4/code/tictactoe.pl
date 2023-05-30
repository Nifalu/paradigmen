% Tic Tac Toe game in Prolog

:- dynamic(board/1).

init :- retractall(board(_)), assert(board([n, n, n, n, n, n, n, n, n])).

display(Board) :-
    write('  1 2 3'), nl,
    display_row(1, Board), nl,
    display_row(2, Board), nl,
    display_row(3, Board), nl.

display_row(Row, Board) :-
    RowIndex is (Row - 1) * 3,
    Index1 is RowIndex,
    Index2 is RowIndex + 1,
    Index3 is RowIndex + 2,
    nth0(Index1, Board, E1),
    nth0(Index2, Board, E2),
    nth0(Index3, Board, E3),
    write(Row), write(' '), display_elem(E1), write(' '), display_elem(E2), write(' '), display_elem(E3).

display_elem(n) :- write('_').
display_elem(x) :- write('X').
display_elem(o) :- write('O').

full(Board) :- \+ member(n, Board).

win(Board, Player) :-
    (member([Player, Player, Player], Board));
    (nth0(0, Board, Player), nth0(4, Board, Player), nth0(8, Board, Player));
    (nth0(2, Board, Player), nth0(4, Board, Player), nth0(6, Board, Player)).

play :-
    init,
    board(Board),
    display(Board),
    play_turn(x).

play_turn(Player) :-
    board(Board),
    (win(Board, o) -> writeln('Player O wins!'), display(Board);
     win(Board, x) -> writeln('Player X wins!'), display(Board);
     full(Board) -> writeln('Draw!'), display(Board);
     write('Player '), write(Player), writeln(', enter row (1-3) and column (1-3), separated by a space:'),
     read(Move),
    Move = (Row, Col),
     Index is (Row - 1) * 3 + (Col - 1),
     (nth0(Index, Board, n) ->
         replace(Board, Index, Player, NewBoard),
         retract(board(_)),
         assertz(board(NewBoard)),
         display(NewBoard),
         (Player = x -> play_turn(o); play_turn(x));
     write('Invalid move'), nl, play_turn(Player)
     )).


replace([_|T], 0, X, [X|T]).
replace([H|T], I, X, [H|R]) :- I > -1, NI is I-1, replace(T, NI, X, R), !.
replace(L, _, _, L).

