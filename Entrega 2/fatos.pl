%% Fatos dependentes semestre
professor(Professor).

professor_preferencia(Professor, Disciplina, Semestre, Preferencia).

limite_maximo_professor(LimiteMaximoProfessor).

oferta_disciplina(Disciplina, (Semestre)).

%% Fatos independentes semestre
disciplina(Disciplina, Creditos)

%% Declaração fato horário
horario_1('18:30 - 20:20').
horario_2('20:30 - 22:20').

horario('Segunda', horario_1).
horario('Segunda', horario_2).
horario('Terça', horario_1).
horario('Terça', horario_2).
horario('Quarta', horario_1).
horario('Quarta', horario_2).
horario('Quinta', horario_1).
horario('Quinta', horario_2).
horario('Sexta', horario_1).
horario('Sexta', horario_2).

semestre('1º Semestre', 1).
semestre('3º Semestre', 3).

%% Declaração fato Preferencias Professor 
professor_preferencia('Professor 1', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 1', 'Análise e Projeto de Software', 3, 5).
professor_preferencia('Professor 1', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 5).
professor_preferencia('Professor 1', 'Resolução de Problemas III', 3, 5).
professor_preferencia('Professor 1', 'Algoritmos e Programação -- ES', 1, 2).
professor_preferencia('Professor 1', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 1', 'Estruturas de Dados -- ES', 3, 2).
professor_preferencia('Professor 1', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 1', 'Lógica Matemática -- ES', 1, 2).
professor_preferencia('Professor 1', 'Matemática Discreta -- ES', 1, 1).

professor_preferencia('Professor 2', 'Inovação e Criatividade', 3, 4).
professor_preferencia('Professor 2', 'Análise e Projeto de Software', 3, 5).
professor_preferencia('Professor 2', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 3).
professor_preferencia('Professor 2', 'Resolução de Problemas III', 3, 5).
professor_preferencia('Professor 2', 'Algoritmos e Programação -- ES', 1, 1).
professor_preferencia('Professor 2', 'Arquitetura e Organização de Computadores -- ES', 3, 1).
professor_preferencia('Professor 2', 'Estruturas de Dados -- ES', 3, 2).
professor_preferencia('Professor 2', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 2', 'Lógica Matemática -- ES', 1, 2).
professor_preferencia('Professor 2', 'Matemática Discreta -- ES', 1, 2).

professor_preferencia('Professor 3', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 3', 'Análise e Projeto de Software', 3, 5).
professor_preferencia('Professor 3', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 5).
professor_preferencia('Professor 3', 'Resolução de Problemas III', 3, 5).
professor_preferencia('Professor 3', 'Algoritmos e Programação -- ES', 1, 3).
professor_preferencia('Professor 3', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 3', 'Estruturas de Dados -- ES', 3, 5).
professor_preferencia('Professor 3', 'Linguagens Formais -- ES', 3, 1).
professor_preferencia('Professor 3', 'Lógica Matemática -- ES', 1, 1).
professor_preferencia('Professor 3', 'Matemática Discreta -- ES', 1, 1).

professor_preferencia('Professor 4', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 4', 'Análise e Projeto de Software', 3, 5).
professor_preferencia('Professor 4', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 5).
professor_preferencia('Professor 4', 'Resolução de Problemas III', 3, 3).
professor_preferencia('Professor 4', 'Algoritmos e Programação -- ES', 1, 1).
professor_preferencia('Professor 4', 'Arquitetura e Organização de Computadores -- ES', 3, 1).
professor_preferencia('Professor 4', 'Estruturas de Dados -- ES', 3, 1).
professor_preferencia('Professor 4', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 4', 'Lógica Matemática -- ES', 1, 4).
professor_preferencia('Professor 4', 'Matemática Discreta -- ES', 1, 3).

professor_preferencia('Professor 5', 'Inovação e Criatividade', 3, 4).
professor_preferencia('Professor 5', 'Análise e Projeto de Software', 3, 3).
professor_preferencia('Professor 5', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 2).
professor_preferencia('Professor 5', 'Resolução de Problemas III', 3, 4).
professor_preferencia('Professor 5', 'Algoritmos e Programação -- ES', 1, 1).
professor_preferencia('Professor 5', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 5', 'Estruturas de Dados -- ES', 3, 3).
professor_preferencia('Professor 5', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 5', 'Lógica Matemática -- ES', 1, 4).
professor_preferencia('Professor 5', 'Matemática Discreta -- ES', 1, 4).

professor_preferencia('Professor 6', 'Inovação e Criatividade', 3, 4).
professor_preferencia('Professor 6', 'Análise e Projeto de Software', 3, 3).
professor_preferencia('Professor 6', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 1).
professor_preferencia('Professor 6', 'Resolução de Problemas III', 3, 5).
professor_preferencia('Professor 6', 'Algoritmos e Programação -- ES', 1, 3).
professor_preferencia('Professor 6', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 6', 'Estruturas de Dados -- ES', 3, 3).
professor_preferencia('Professor 6', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 6', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 6', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 7', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 7', 'Análise e Projeto de Software', 3, 3).
professor_preferencia('Professor 7', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 5).
professor_preferencia('Professor 7', 'Resolução de Problemas III', 3, 5).
professor_preferencia('Professor 7', 'Algoritmos e Programação -- ES', 1, 1).
professor_preferencia('Professor 7', 'Arquitetura e Organização de Computadores -- ES', 3, 1).
professor_preferencia('Professor 7', 'Estruturas de Dados -- ES', 3, 2).
professor_preferencia('Professor 7', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 7', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 7', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 8', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 8', 'Análise e Projeto de Software', 3, 5).
professor_preferencia('Professor 8', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 5).
professor_preferencia('Professor 8', 'Resolução de Problemas III', 3, 5).
professor_preferencia('Professor 8', 'Algoritmos e Programação -- ES', 1, 1).
professor_preferencia('Professor 8', 'Arquitetura e Organização de Computadores -- ES', 3, 1).
professor_preferencia('Professor 8', 'Estruturas de Dados -- ES', 3, 1).
professor_preferencia('Professor 8', 'Linguagens Formais -- ES', 3, 4).
professor_preferencia('Professor 8', 'Lógica Matemática -- ES', 1, 1).
professor_preferencia('Professor 8', 'Matemática Discreta -- ES', 1, 4).

professor_preferencia('Professor 9', 'Inovação e Criatividade', 3, 1).
professor_preferencia('Professor 9', 'Análise e Projeto de Software', 3, 5).
professor_preferencia('Professor 9', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 3).
professor_preferencia('Professor 9', 'Resolução de Problemas III', 3, 5).
professor_preferencia('Professor 9', 'Algoritmos e Programação -- ES', 1, 5).
professor_preferencia('Professor 9', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 9', 'Estruturas de Dados -- ES', 3, 5).
professor_preferencia('Professor 9', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 9', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 9', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 10', 'Inovação e Criatividade', 3, 3).
professor_preferencia('Professor 10', 'Análise e Projeto de Software', 3, 5).
professor_preferencia('Professor 10', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 4).
professor_preferencia('Professor 10', 'Resolução de Problemas III', 3, 4).
professor_preferencia('Professor 10', 'Algoritmos e Programação -- ES', 1, 3).
professor_preferencia('Professor 10', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 10', 'Estruturas de Dados -- ES', 3, 3).
professor_preferencia('Professor 10', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 10', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 10', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 11', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 11', 'Análise e Projeto de Software', 3, 3).
professor_preferencia('Professor 11', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 1).
professor_preferencia('Professor 11', 'Resolução de Problemas III', 3, 5).
professor_preferencia('Professor 11', 'Algoritmos e Programação -- ES', 1, 5).
professor_preferencia('Professor 11', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 11', 'Estruturas de Dados -- ES', 3, 5).
professor_preferencia('Professor 11', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 11', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 11', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 12', 'Inovação e Criatividade', 3, 3).
professor_preferencia('Professor 12', 'Análise e Projeto de Software', 3, 1).
professor_preferencia('Professor 12', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 2).
professor_preferencia('Professor 12', 'Resolução de Problemas III', 3, 3).
professor_preferencia('Professor 12', 'Algoritmos e Programação -- ES', 1, 1).
professor_preferencia('Professor 12', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 12', 'Estruturas de Dados -- ES', 3, 2).
professor_preferencia('Professor 12', 'Linguagens Formais -- ES', 3, 4).
professor_preferencia('Professor 12', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 12', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 13', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 13', 'Análise e Projeto de Software', 3, 1).
professor_preferencia('Professor 13', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 1).
professor_preferencia('Professor 13', 'Resolução de Problemas III', 3, 4).
professor_preferencia('Professor 13', 'Algoritmos e Programação -- ES', 1, 2).
professor_preferencia('Professor 13', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 13', 'Estruturas de Dados -- ES', 3, 3).
professor_preferencia('Professor 13', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 13', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 13', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 14', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 14', 'Análise e Projeto de Software', 3, 2).
professor_preferencia('Professor 14', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 2).
professor_preferencia('Professor 14', 'Resolução de Problemas III', 3, 4).
professor_preferencia('Professor 14', 'Algoritmos e Programação -- ES', 1, 1).
professor_preferencia('Professor 14', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 14', 'Estruturas de Dados -- ES', 3, 1).
professor_preferencia('Professor 14', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 14', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 14', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 15', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 15', 'Análise e Projeto de Software', 3, 1).
professor_preferencia('Professor 15', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 1).
professor_preferencia('Professor 15', 'Resolução de Problemas III', 3, 1).
professor_preferencia('Professor 15', 'Algoritmos e Programação -- ES', 1, 3).
professor_preferencia('Professor 15', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 15', 'Estruturas de Dados -- ES', 3, 3).
professor_preferencia('Professor 15', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 15', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 15', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 16', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 16', 'Análise e Projeto de Software', 3, 5).
professor_preferencia('Professor 16', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 5).
professor_preferencia('Professor 16', 'Resolução de Problemas III', 3, 5).
professor_preferencia('Professor 16', 'Algoritmos e Programação -- ES', 1, 5).
professor_preferencia('Professor 16', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 16', 'Estruturas de Dados -- ES', 3, 5).
professor_preferencia('Professor 16', 'Linguagens Formais -- ES', 3, 1).
professor_preferencia('Professor 16', 'Lógica Matemática -- ES', 1, 1).
professor_preferencia('Professor 16', 'Matemática Discreta -- ES', 1, 1).

professor_preferencia('Professor 17', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 17', 'Análise e Projeto de Software', 3, 2).
professor_preferencia('Professor 17', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 1).
professor_preferencia('Professor 17', 'Resolução de Problemas III', 3, 3).
professor_preferencia('Professor 17', 'Algoritmos e Programação -- ES', 1, 5).
professor_preferencia('Professor 17', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 17', 'Estruturas de Dados -- ES', 3, 5).
professor_preferencia('Professor 17', 'Linguagens Formais -- ES', 3, 4).
professor_preferencia('Professor 17', 'Lógica Matemática -- ES', 1, 4).
professor_preferencia('Professor 17', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 18', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 18', 'Análise e Projeto de Software', 3, 5).
professor_preferencia('Professor 18', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 5).
professor_preferencia('Professor 18', 'Resolução de Problemas III', 3, 5).
professor_preferencia('Professor 18', 'Algoritmos e Programação -- ES', 1, 1).
professor_preferencia('Professor 18', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 18', 'Estruturas de Dados -- ES', 3, 1).
professor_preferencia('Professor 18', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 18', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 18', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 19', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 19', 'Análise e Projeto de Software', 3, 5).
professor_preferencia('Professor 19', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 5).
professor_preferencia('Professor 19', 'Resolução de Problemas III', 3, 5).
professor_preferencia('Professor 19', 'Algoritmos e Programação -- ES', 1, 1).
professor_preferencia('Professor 19', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 19', 'Estruturas de Dados -- ES', 3, 1).
professor_preferencia('Professor 19', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 19', 'Lógica Matemática -- ES', 1, 3).
professor_preferencia('Professor 19', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 20', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 20', 'Análise e Projeto de Software', 3, 2).
professor_preferencia('Professor 20', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 1).
professor_preferencia('Professor 20', 'Resolução de Problemas III', 3, 1).
professor_preferencia('Professor 20', 'Algoritmos e Programação -- ES', 1, 1).
professor_preferencia('Professor 20', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 20', 'Estruturas de Dados -- ES', 3, 3).
professor_preferencia('Professor 20', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 20', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 20', 'Matemática Discreta -- ES', 1, 4).

professor_preferencia('Professor 21', 'Inovação e Criatividade', 3, 5).
professor_preferencia('Professor 21', 'Análise e Projeto de Software', 3, 4).
professor_preferencia('Professor 21', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 4).
professor_preferencia('Professor 21', 'Resolução de Problemas III', 3, 4).
professor_preferencia('Professor 21', 'Algoritmos e Programação -- ES', 1, 1).
professor_preferencia('Professor 21', 'Arquitetura e Organização de Computadores -- ES', 3, 3).
professor_preferencia('Professor 21', 'Estruturas de Dados -- ES', 3, 2).
professor_preferencia('Professor 21', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 21', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 21', 'Matemática Discreta -- ES', 1, 5).

professor_preferencia('Professor 22', 'Inovação e Criatividade', 3, 2).
professor_preferencia('Professor 22', 'Análise e Projeto de Software', 3, 2).
professor_preferencia('Professor 22', 'Resolução de Problemas I (Eng. Requisitos - Extensão)', 1, 1).
professor_preferencia('Professor 22', 'Resolução de Problemas III', 3, 5).
professor_preferencia('Professor 22', 'Algoritmos e Programação -- ES', 1, 4).
professor_preferencia('Professor 22', 'Arquitetura e Organização de Computadores -- ES', 3, 5).
professor_preferencia('Professor 22', 'Estruturas de Dados -- ES', 3, 4).
professor_preferencia('Professor 22', 'Linguagens Formais -- ES', 3, 5).
professor_preferencia('Professor 22', 'Lógica Matemática -- ES', 1, 5).
professor_preferencia('Professor 22', 'Matemática Discreta -- ES', 1, 5).
