%% Regras

ministra(PROFESSOR, MATERIA, H):-
        professor_preferencia(PROFESSOR, MATERIA, 1),
        disciplina_semestre(MATERIA, 1); disciplina_semestre(MATERIA, 3), %%Regra 6
				disc_mesmo_horario :- disciplina_semestre(MATERIA, 1), disciplina_semestre(MATERIA, 3) :- horario(U, H) < 1. %%Regra 2

ministra(PROFESSOR, MATERIA, H):-
        professor_preferencia(PROFESSOR, MATERIA, 2),
        disciplina_semestre(MATERIA, 1); disciplina_semestre(Y, 3), %%Regra 6
				disc_mesmo_horario :- disciplina_semestre(MATERIA, 1), disciplina_semestre(MATERIA, 3) :- horario(U, H) < 1. %%Regra 2

ministra(PROFESSOR, MATERIA, H):-
        professor_preferencia(PROFESSOR, MATERIA, 3),
        disciplina_semestre(MATERIA, 1); disciplina_semestre(MATERIA, 3), %%Regra 6
				disc_mesmo_horario :- disciplina_semestre(MATERIA, 1), disciplina_semestre(MATERIA, 3) :- horario(U, H) < 1. %%Regra 2

ministra(PROFESSOR, MATERIA, H):-
        professor_preferencia(PROFESSOR, MATERIA, 4),
        disciplina_semestre(MATERIA, 1); disciplina_semestre(MATERIA, 3), %%Regra 6
				disc_mesmo_horario :- disciplina_semestre(MATERIA, 1), disciplina_semestre(MATERIA, 3) :- horario(U, H) < 1. %%Regra 2

ministra(PROFESSOR, MATERIA, H):-
        professor_preferencia(PROFESSOR, MATERIA, 5),
        disciplina_semestre(MATERIA, 1); disciplina_semestre(MATERIA, 3), %%Regra 6
				disc_mesmo_horario :- disciplina_semestre(MATERIA, 1), disciplina_semestre(MATERIA, 3) :- horario(U, H) < 1. %%Regra 2