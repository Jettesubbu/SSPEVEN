% Medical Diagnosis Expert System

:- dynamic yes/1, no/1.

% Entry point
start :-
    write('Welcome to the medical diagnosis expert system.'), nl,
    write('Please answer with Yes or No followed by a dot (e.g. Yes.),'), nl,
    diagnose(Disease),
    nl, write('The possible diagnosis is: '), write(Disease), nl, undo.

% Diagnosis rules
diagnose(flu) :-
    verify(fever),
    verify(headache),
    verify(cough),
    verify(chills),
    verify(body_pain), !.

diagnose(cold) :-
    verify(sneezing),
    verify(runny_nose),
    verify(sore_throat), !.

diagnose(malaria) :-
    verify(fever),
    verify(chills),
    verify(sweating), !.

diagnose(typhoid) :-
    verify(fever),
    verify(headache),
    verify(cough),
    verify(vomiting), !.

diagnose(covid19) :-
    verify(fever),
    verify(dry_cough),
    verify(loss_of_smell),
    verify(breathing_difficulty), !.

diagnose(unknown).

% Ask the user about a symptom
ask(Question) :-
    write('Do you have '), write(Question), write('? '),
    read(Response), nl,
    ( (Response == yes) ->
        assert(yes(Question)) ;
        assert(no(Question)), fail).

% Verify symptom (from memory or ask)
verify(Symptom) :-
    yes(Symptom), !.

verify(Symptom) :-
    no(Symptom), !, fail.

verify(Symptom) :-
    ask(Symptom).

% Undo: retract memory after diagnosis
undo :-
    retract(yes(_)), fail.
undo :-
    retract(no(_)), fail.
undo.
