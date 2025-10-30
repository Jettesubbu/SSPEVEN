% Facts
parent(john, mary).
parent(john, david).
parent(susan, mary).
parent(susan, david).

male(john).
male(david).
female(susan).
female(mary).

% Rules
father(X, Y) :- parent(X, Y), male(X).
mother(X, Y) :- parent(X, Y), female(X).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.


queries:

?- father(john, mary).
?- mother(susan, david).
?- sibling(mary, david).



Program 2: Animal Classification (Facts & Rules)

% Facts
animal(dog).
animal(cat).
animal(tiger).

mammal(dog).
mammal(cat).
carnivore(tiger).

% Rules
is_mammal(X) :- mammal(X).
is_carnivore(X) :- carnivore(X).

sample queries:

?- is_mammal(dog).
?- is_carnivore(tiger).
?- animal(cat).


Program 3: Student Grades (Facts & Rules):

% Facts
student(ahmed).
student(ravi).
student(sara).

score(ahmed, 85).
score(ravi, 72).
score(sara, 91).

% Rules
passed(X) :- score(X, Marks), Marks >= 40.
distinction(X) :- score(X, Marks), Marks >= 85.

sample queries:
?- passed(ahmed).
?- distinction(sara).
?- score(ravi, Marks).

