%% Regras

ministra(X,Y):-
        professor_preferencia(X,Y,1),
        disciplina_semestre(Y, 1); disciplina_semestre(Y, 3). %%Regra 6

ministra(X,Y):-
        professor_preferencia(X,Y,2),
        disciplina_semestre(Y, 1); disciplina_semestre(Y, 3). %%Regra 6

ministra(X,Y):-
        professor_preferencia(X,Y,3),
        disciplina_semestre(Y, 1); disciplina_semestre(Y, 3). %%Regra 6

ministra(X,Y):-
        professor_preferencia(X,Y,4),
        disciplina_semestre(Y, 1); disciplina_semestre(Y, 3). %%Regra 6

ministra(X,Y):-
        professor_preferencia(X,Y,5),
        disciplina_semestre(Y, 1); disciplina_semestre(Y, 3). %%Regra 6