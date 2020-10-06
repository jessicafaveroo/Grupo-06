%% Regras

ministra(X,Y,H):-
        professor_preferencia(X,Y,1),
        disciplina_semestre(Y, 1); disciplina_semestre(Y, 3), %%Regra 6
				disc_mesmo_horario :- disciplina_semestre(Y, 1), disciplina_semestre(Y, 3) :- horario(U, H) < 1. %%Regra 2

ministra(X,Y,H):-
        professor_preferencia(X,Y,2),
        disciplina_semestre(Y, 1); disciplina_semestre(Y, 3), %%Regra 6
				disc_mesmo_horario :- disciplina_semestre(Y, 1), disciplina_semestre(Y, 3) :- horario(U, H) < 1. %%Regra 2

ministra(X,Y,H):-
        professor_preferencia(X,Y,3),
        disciplina_semestre(Y, 1); disciplina_semestre(Y, 3), %%Regra 6
				disc_mesmo_horario :- disciplina_semestre(Y, 1), disciplina_semestre(Y, 3) :- horario(U, H) < 1. %%Regra 2

ministra(X,Y,H):-
        professor_preferencia(X,Y,4),
        disciplina_semestre(Y, 1); disciplina_semestre(Y, 3), %%Regra 6
				disc_mesmo_horario :- disciplina_semestre(Y, 1), disciplina_semestre(Y, 3) :- horario(U, H) < 1. %%Regra 2

ministra(X,Y,H):-
        professor_preferencia(X,Y,5),
        disciplina_semestre(Y, 1); disciplina_semestre(Y, 3), %%Regra 6
				disc_mesmo_horario :- disciplina_semestre(Y, 1), disciplina_semestre(Y, 3) :- horario(U, H) < 1. %%Regra 2