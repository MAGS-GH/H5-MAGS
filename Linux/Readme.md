# Noter til Linux

## Dag 1

cd -> Change dir

pwd -> Print working directory

ls -> List - List dir

cat -> Vis indhold i fil

grep -> Søge funktion lignende Regular-Expressions

heth:x:1000:1000:Henrik Thomsen:/home/heth:/bin/bash

Bliver opdelt med ":"

heth er brugernavnet - bliver kun brugt, når vi skal vise noget på skærmen

x er indikation på at der er et hashed+saltet password som vi ikke kan læse, af sikkerhedsmæssige årsage

1000 er bruger id (Int er hurtigere at arbejde med end strings)

1000 er en gruppe som personen er en del af - det kunne være salgsgruppen

Henrik Thomsen er det fulde navn af brugeren. Her kan man også indeholde andre informationer, såsom telefon og mail. Værdierne skal være kommaseperet

/home/heth home folderen for brugeren

/bin/bash er stien eller programmer som skal åbne ved opstart

'|'
pipe kommanden i Linux, Opdeller kommandoen i n kommandoer, vi binder altså flere kommandoer sammen i en sekvens.

BASH - Born Again SHell

cat /etc/passwd | grep heth | cut -d':' -f5 | cut -d"," -f1

Ny bruger

IP: 93.166.84.21
User: ny
Pw: Easter2024.

User: mags
Pw: *************************************

## Dag 2
