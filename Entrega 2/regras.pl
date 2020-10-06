%% Regras

ministra(X,Y):-
		professor_preferencia(X,Y,1).

ministra(X,Y):-
		professor_preferencia(X,Y,2).

ministra(X,Y):-
		professor_preferencia(X,Y,3).

ministra(X,Y):-
		professor_preferencia(X,Y,4).

ministra(X,Y):-
		professor_preferencia(X,Y,5).
