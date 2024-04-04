#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *from_file = fopen(argv[1], "r"); // "r" er for at læse
    FILE *to_file = fopen(argv[2], "w"); // "w" er for at skrive
    int ch; //Vi bruger følgende til at indeholde hvert cifre i vores fil
    while (fgetc(from_file) != EOF) { 
    // EOF er End Of File, som holder øje med hvornår,
    // vi er færdige med vores loop
        ch = fgetc(from_file);
        printf("%c", ch);
        printf("\n -- \n");
        fputc(ch, to_file);
    }
    fprintf(to_file, "\n\n\n Jeg er en kopi!😯");
    fclose(from_file);
    fclose(to_file);
    
    printf("Filen er kopieret succesfuldt.\n");

    return 0;
}
