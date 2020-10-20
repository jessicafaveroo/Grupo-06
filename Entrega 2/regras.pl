%% Regras

:- [fatos].

ministra(PROFESSOR, MATERIA):-
    professor_preferencia(PROFESSOR, MATERIA, 1),
    disciplina(MATERIA, CREDITOS, 1),
    horario(DIA, horario_1),
    horario(DIA, horario_2).

ministra(PROFESSOR, MATERIA):-
    professor_preferencia(PROFESSOR, MATERIA, 1),
    disciplina(MATERIA, CREDITOS, 1),
    horario(DIA, horario_3),
    horario(DIA, horario_4).

ministra(PROFESSOR, MATERIA):-
    professor_preferencia(PROFESSOR, MATERIA, 2),
    disciplina(MATERIA, CREDITOS, 1),
    horario(DIA, horario_1),
    horario(DIA, horario_2).

ministra(PROFESSOR, MATERIA):-
    professor_preferencia(PROFESSOR, MATERIA, 2),
    disciplina(MATERIA, CREDITOS, 1),
    horario(DIA, horario_3),
    horario(DIA, horario_4).

ministra(PROFESSOR, MATERIA):-
    professor_preferencia(PROFESSOR, MATERIA, 3),
    disciplina(MATERIA, CREDITOS, 1),
    horario(DIA, horario_1),
    horario(DIA, horario_2).

ministra(PROFESSOR, MATERIA):-
    professor_preferencia(PROFESSOR, MATERIA, 3),
    disciplina(MATERIA, CREDITOS, 1),
    horario(DIA, horario_3),
    horario(DIA, horario_4).

ministra(PROFESSOR, MATERIA):-
    professor_preferencia(PROFESSOR, MATERIA, 4),
    disciplina(MATERIA, CREDITOS, 1),
    horario(DIA, horario_1),
    horario(DIA, horario_2).

ministra(PROFESSOR, MATERIA):-
    professor_preferencia(PROFESSOR, MATERIA, 4),
    disciplina(MATERIA, CREDITOS, 1),
    horario(DIA, horario_4),
    horario(DIA, horario_3).

ministra(PROFESSOR, MATERIA):-
    professor_preferencia(PROFESSOR, MATERIA, 5),
    disciplina(MATERIA, CREDITOS, 1),
    horario(DIA, horario_1),
    horario(DIA, horario_2).

ministra(PROFESSOR, MATERIA):-
    professor_preferencia(PROFESSOR, MATERIA, 5),
    disciplina(MATERIA, CREDITOS, 1),
    horario(DIA, horario_3),
    horario(DIA, horario_4).

ministra(PROFESSOR, MATERIA):-
    professor_preferencia(PROFESSOR, MATERIA, 'Resolução de Problemas I (Eng. Requisitos - Extensão'),
    disciplina(MATERIA, CREDITOS, 1),
    horario(DIA, horario_1),
    horario(DIA, horario_2),
    horario(DIA, horario_3),
    horario(DIA, horario_4).

ministra(PROFESSOR, MATERIA):-
    professor_preferencia(PROFESSOR, MATERIA, 'Resolução de Problemas III'),
    disciplina(MATERIA, CREDITOS, 3),
    horario(DIA, horario_1),
    horario(DIA, horario_2),
    horario(DIA, horario_3),
    horario(DIA, horario_4).


ministra(PROFESSOR, MATERIA) :-
    professor_preferencia(PROFESSOR, MATERIA, 1),
    disciplina(MATERIA, CREDITOS, 3).
    
ministra(PROFESSOR, MATERIA) :-
    professor_preferencia(PROFESSOR, MATERIA, 2),
    disciplina(MATERIA, CREDITOS, 3).
    
ministra(PROFESSOR, MATERIA) :-
    professor_preferencia(PROFESSOR, MATERIA, 3),
    disciplina(MATERIA, CREDITOS, 3).
    
ministra(PROFESSOR, MATERIA) :-
    professor_preferencia(PROFESSOR, MATERIA, 4),
    disciplina(MATERIA, CREDITOS, 3).
    
ministra(PROFESSOR, MATERIA) :-
    professor_preferencia(PROFESSOR, MATERIA, 5),
    disciplina(MATERIA, CREDITOS, 3).

%Regra 2
ministra_no_horario(DIA, HORARIO_ESCOLHIDO):-
	horario(DIA, horario_1), %seleciona pelo horario_1
	write(professor_preferencia(PROFESSOR, MATERIA, 1)), nl. %pega o prof com maior preferência para dar aula.

ministra_no_horario(DIA, HORARIO_ESCOLHIDO):-
	horario(DIA, horario_2), %seleciona pelo horario_2
	write(professor_preferencia(PROFESSOR, MATERIA, 1)), nl. %pega o prof com maior preferência para dar aula.

ministra_no_horario(DIA, HORARIO_ESCOLHIDO):-
	horario(DIA, HORARIO_ESCOLHIDO), %seleciona pelo horario_3
	professor_preferencia(write(PROFESSOR), MATERIA, 1), nl.%pega o prof com maior preferência para dar aula

ministra_no_horario(DIA, HORARIO_ESCOLHIDO):-
	horario(DIA, horario_4), %seleciona pelo horario_4
	write(professor_preferencia(PROFESSOR, MATERIA, 1)), nl. %pega o prof com maior preferência para dar aula.

/* OBS sobre regra 2
Se o argumento contém variáveis não instanciadas, estas serão
impressas com seus nomes internos, geralmente consistindo de um “_” seguido
de um código interno alfanumérico. Além de write, existe em Prolog o predicado pré-definido nl, sem arugmento, que causa mudança de linha na impressão
(newline). Assim, se quisermos dividir a saída em várias linhas, devemos usar nl:*/

limite_maximo_creditos(Professor, Disciplina, NumCreditosAlocados):-
professor(Professor),
limite_maximo_professor(Limite),
disciplina(Disciplina, Creditos),
N is NumCreditosAlocados + Creditos,
N =< Limite.