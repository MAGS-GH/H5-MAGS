#!/bin/bash

# Opret en midlertidig fil til manualen
MANUAL_FILE=$(mktemp)

# Skriv manualens indhold til den midlertidige fil
cat << EOF > $MANUAL_FILE
NAVN
    lcdDriverinput1 - vis tekst på en LCD-skærm

BESKRIVELSE
    lcdDriverinput1 er et bash-script, der giver brugerne mulighed for at vise tekstbeskeder på en LCD-skærm. Det tager et enkelt argument, beskeden der skal vises på LCD'en.

BRUG
    lcdDriverinput1 <besked>

ARGUMENTER
    <besked>  Tekstbeskeden, der skal vises på LCD'en.

EKSEMPLER
    Vis "Hej verden!" på LCD'en:
        lcdDriverinput1 "Hej verden!"

FORFATTER
    Skrevet af MAGS

FEJL
    Ingen kendte fejl, men der er sikkert mange!
    
DATO
    April 2024
EOF

# Installer manualen
sudo mv $MANUAL_FILE /usr/share/man/man1/lcdDriverinput1.1

# Opdater manual-søgningsindekset
sudo mandb

echo "Manualen for lcdDriverinput1 er nu installeret. Du kan se den med kommandoen 'man lcdDriverinput1'"
