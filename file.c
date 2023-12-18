#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void removerVirgulas(char *palavra){
    int i, j;
    for (i = 0, j = 0; i < strlen(palavra); i++) {
        if (palavra[i] != ',' && palavra[i] != '.' && palavra[i] != '-' && palavra[i] != '['
            && palavra[i] != ']' && palavra[i] != '(' && palavra[i] != ')' && palavra[i] != '1' && palavra[i] != '2'
            && palavra[i] != '3' && palavra[i] != '4' && palavra[i] != '5' && palavra[i] != '6' && palavra[i] != '7'
            && palavra[i] != '8' && palavra[i] != '9' && palavra[i] != '“' && palavra[i] != '”') {
            palavra[j++] = palavra[i];
        }}
    palavra[j] = '\0';
}

char substituirAcentos(char ch) {
    char Acentuadas[] = {'á', 'é', 'í', 'ó', 'ú', 'â', 'ê', 'î', 'ô', 'û', 'ã', 'õ', 'ç', 'ü', 'à'};
    char naoAcentuadas[] = {'a', 'e', 'i', 'o', 'u', 'a', 'e', 'i', 'o', 'u', 'a', 'o', 'c', 'u', 'a'};
    int i;
    for (i = 0; i < 15; i++) {
        if (ch == Acentuadas[i]) {
            return naoAcentuadas[i];
        }
    }
    return ch;
}

int palavravalido(char *palavra, int x) {
    int tam = strlen(palavra);
    int i, j;
    if (x == 1){
        if (tam < 9) return 0;}
    else {
        if(tam < 4) return 0;}

    for (i = 0; i < tam - 1; i++) {
        for (j = i + 1; j < tam; j++) {
            if (palavra[i] == palavra[j]) {
                return 0;}}}
    return 1;
}

int funcVogal(char *palavra){
    int cont = 0;
    int i;
    removerVirgulas(palavra);
    for(i=0;i<strlen(palavra);i++){
        palavra[i] = substituirAcentos(palavra[i]);
        palavra[i] = tolower(palavra[i]);
        if(palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u'){
            cont++;
        }
    }
    return cont;
}

//12
void achar3(char *arquivo1, char *arquivo2) {
    int i, tam, cont;
    FILE *file1 = fopen(arquivo1, "r");
    FILE *file2 = fopen(arquivo2, "r");
    FILE *wordsvalidas = fopen("12.txt", "w");
    char palavra[30];

    while (fscanf(file1, "%s", palavra) != EOF) {
        tam = strlen(palavra);
        cont = funcVogal(palavra);
        if (cont >= (float)tam/ 2) {
            fprintf(wordsvalidas, "%s\n", palavra);
        }}

     while (fscanf(file2, "%s", palavra) != EOF) {
        tam = strlen(palavra);
        cont = funcVogal(palavra);
        if (cont >= (float)tam / 2) {
            fprintf(wordsvalidas, "%s\n", palavra);
        }}

    if (wordsvalidas == NULL) {
        printf("Erro ao criar o arquivo de palavras válidas.\n");
        return;}

    fclose(file1);
    fclose(file2);
    fclose(wordsvalidas);
}

//11
void achar2(char *arquivo1, char *arquivo2) {
    int i;
    FILE *file1 = fopen(arquivo1, "r");
    FILE *file2 = fopen(arquivo2, "r");
    FILE *wordsvalidas = fopen("11.txt", "w");
    char palavra[30];

    while (fscanf(file1, "%s", palavra) != EOF) {
        removerVirgulas(palavra);
        for(i=0;i<strlen(palavra);i++){
        palavra[i] = substituirAcentos(palavra[i]);
        if (isalpha(palavra[i])) {
            palavra[i] = tolower(palavra[i]);}}
        if (palavravalido(palavra, 2)) {
            fprintf(wordsvalidas, "%s\n", palavra);}}

    while (fscanf(file2, "%s", palavra) != EOF) {
        removerVirgulas(palavra);
        for(i=0;i<strlen(palavra);i++){
        palavra[i] = substituirAcentos(palavra[i]);
        if (isalpha(palavra[i])) {
            palavra[i] = tolower(palavra[i]);}}
        if (palavravalido(palavra, 2)) {
            fprintf(wordsvalidas, "%s\n", palavra);}}

    if (wordsvalidas == NULL) {
        printf("Erro ao criar o arquivo de palavras válidas.\n");
        return;}

    fclose(file1);
    fclose(file2);
    fclose(wordsvalidas);
}

//10
void calcNpalavras(char *arquivo1, char *arquivo2){
    FILE *file1 = fopen(arquivo1, "r");
    FILE *file2 = fopen(arquivo2, "r");
    FILE *fileFinal = fopen("10.txt", "w");

    int contPalavras[18] = {0};
    char palavra[30];

    while (fscanf(file1, "%s", palavra) != EOF) {
        removerVirgulas(palavra);
        int tam = strlen(palavra);
        if (tam >= 3 && tam <= 20) {
            contPalavras[tam - 3]++;}}

    while (fscanf(file2, "%s", palavra) != EOF) {
        removerVirgulas(palavra);
        int tam = strlen(palavra);
        if (tam >= 3 && tam <= 20) {
            contPalavras[tam - 3]++;}}

    fclose(file1);
    fclose(file2);

    for (int i = 3; i <= 20; i++) {
        fprintf(fileFinal, "%d palavras com %d letras\n", contPalavras[i-3], i);}
    fclose(fileFinal);
}

//7
void calcNletras(char *arquivo1, char *arquivo2, int N){
    FILE *file1 = fopen(arquivo1, "r");
    FILE *file2 = fopen(arquivo2, "r");
    FILE *fileFinal = fopen("7.txt", "w");
    char palavra[30];
    int i;

    while (fscanf(file1, "%s", palavra) != EOF) {
        for(i=0;i<strlen(palavra);i++){
            if(isdigit(palavra[i])) return;}
        removerVirgulas(palavra);
        if (strlen(palavra) == N) {
            fprintf(fileFinal, "%s\n", palavra);}}

    while (fscanf(file2, "%s", palavra) != EOF) {
        for(i=0;i<strlen(palavra);i++){
            if(isdigit(palavra[i])) return;}
        removerVirgulas(palavra);
        if (strlen(palavra) == N) {
            fprintf(fileFinal, "%s\n", palavra);}}

    if (fileFinal == NULL) {
        printf("Erro ao criar o arquivo de palavras válidas.\n");
        return;}
    fclose(file1);
    fclose(file2);
    fclose(fileFinal);
}

struct Digrama{
    char Digrama[3];
    int contDigrama;
    };

//6
void calcDigrama(char *arquivo1, char *arquivo2){
    FILE *file1 = fopen(arquivo1, "r");
    FILE *file2 = fopen(arquivo2, "r");
    char palavra[30];
    char texto[100000];
    int i;
    while(fscanf(file1, "%s", palavra) != EOF){
        removerVirgulas(palavra);
        for(i=0;i<strlen(palavra);i++){
            palavra[i] = tolower(palavra[i]);
            palavra[i] = substituirAcentos(palavra[i]);}
        strcat(texto, palavra);
        strcat(texto, "-");}
    while(fscanf(file2, "%s", palavra) != EOF){
        removerVirgulas(palavra);
        for(i=0;i<strlen(palavra);i++){
            palavra[i] = tolower(palavra[i]);
            palavra[i] = substituirAcentos(palavra[i]);}
        strcat(texto, palavra);
        strcat(texto, "-");}

    int tam = strlen(texto) - 1;
    int totalDigramas = 0;

    struct Digrama top1;
    struct Digrama top2;
    struct Digrama top3;
    struct Digrama top4;
    struct Digrama top5;

    printf("Os cinco digramas mais frequentes:\n");
    int j;
    for (int i = 0; i < tam - 1; i++) {
        if(texto[i+1] == '-'){
            i=i+2;}
        char auxDigrama1[3] = {texto[i], texto[i + 1], '\0'};
        int cont = 0;
            for (j = i; j < tam - 1; j++) {
                if(texto[j+1] == '-'){
                    j=j+2;}
                char auxDigrama2[3] = {texto[j], texto[j + 1], '\0'};
                if(!strcmp(auxDigrama1, top5.Digrama) || !strcmp(auxDigrama1, top4.Digrama) || !strcmp(auxDigrama1, top3.Digrama)
                || !strcmp(auxDigrama1, top2.Digrama) || !strcmp(auxDigrama1, top1.Digrama)) break;
                else if (strcmp(auxDigrama1, auxDigrama2) == 0) {
                    cont++;}}
            if (cont > top1.contDigrama){
                top5.contDigrama = top4.contDigrama;
                top4.contDigrama = top3.contDigrama;
                top3.contDigrama = top2.contDigrama;
                top2.contDigrama = top1.contDigrama;
                strcpy(top5.Digrama, top4.Digrama);
                strcpy(top4.Digrama, top3.Digrama);
                strcpy(top3.Digrama, top2.Digrama);
                strcpy(top2.Digrama, top1.Digrama);
                strcpy(top1.Digrama, auxDigrama1);
                top1.contDigrama = cont;
            }
            else if(cont > top2.contDigrama){
                top5.contDigrama = top4.contDigrama;
                top4.contDigrama = top3.contDigrama;
                top3.contDigrama = top2.contDigrama;
                strcpy(top5.Digrama, top4.Digrama);
                strcpy(top4.Digrama, top3.Digrama);
                strcpy(top3.Digrama, top2.Digrama);
                strcpy(top2.Digrama, auxDigrama1);
                top2.contDigrama = cont;
            }
            else if(cont > top3.contDigrama){
                top5.contDigrama = top4.contDigrama;
                top4.contDigrama = top3.contDigrama;
                strcpy(top5.Digrama, top4.Digrama);
                strcpy(top4.Digrama, top3.Digrama);
                strcpy(top3.Digrama, auxDigrama1);
                top3.contDigrama = cont;
            }
            else if(cont > top4.contDigrama){
                top5.contDigrama = top4.contDigrama;
                strcpy(top5.Digrama, top4.Digrama);
                strcpy(top4.Digrama, auxDigrama1);
                top4.contDigrama = cont;
            }
            else if(cont > top5.contDigrama){
                strcpy(top5.Digrama, auxDigrama1);
                top5.contDigrama = cont;
            }
        }
        printf("O digrama que mais aparece é %s com %d aparições\n", top1.Digrama ,top1.contDigrama);
        printf("O digrama que mais aparece é %s com %d aparições\n", top2.Digrama ,top2.contDigrama);
        printf("O digrama que mais aparece é %s com %d aparições\n", top3.Digrama ,top3.contDigrama);
        printf("O digrama que mais aparece é %s com %d aparições\n", top4.Digrama ,top4.contDigrama);
        printf("O digrama que mais aparece é %s com %d aparições\n", top5.Digrama ,top5.contDigrama);
}

//5
void calcularPercentualLetraFinal(char *arquivo1, char *arquivo2) {
    FILE *file1 = fopen(arquivo1, "r");
    FILE *file2 = fopen(arquivo2, "r");
    FILE *fileFinal;
    char palavra[30];
    int totalPalavras = 0;
    int contagemLetraFinal[26] = {0};
    int i;

    file1 = fopen(arquivo1, "r");
    file2 = fopen(arquivo2, "r");

    while (fscanf(file1, "%s", palavra) == 1) {
        totalPalavras++;
        removerVirgulas(palavra);
        int tam = strlen(palavra)-1;
        palavra[tam] = substituirAcentos(palavra[tam]);
        if (isalpha(palavra[tam])) {
            palavra[tam] = tolower(palavra[tam]);
            contagemLetraFinal[tolower(palavra[tam]) - 'a']++;}}

    while (fscanf(file2, "%s", palavra) == 1) {
        totalPalavras++;
        removerVirgulas(palavra);
        int tam = strlen(palavra)-1;
        palavra[tam] = substituirAcentos(palavra[tam]);
        if (isalpha(palavra[tam])) {
            palavra[tam] = tolower(palavra[tam]);
            contagemLetraFinal[tolower(palavra[tam]) - 'a']++;}}

    fclose(file1);
    fclose(file2);
    fileFinal = fopen("5.txt", "w");

    if (fileFinal == NULL) {
        printf("Erro ao criar o arquivo de palavras válidas.\n");
        return;}

    for (i = 0; i < 26; i++) {
        if (contagemLetraFinal[i] > 0) {
            fprintf(fileFinal, "%c: %.2f%%\n", 'a' + i, (contagemLetraFinal[i] / (float)totalPalavras) * 100);}}
    fclose(fileFinal);
}

//4
void calcularPercentualLetraInicial(char *arquivo1, char *arquivo2) {
    FILE *file1 = fopen(arquivo1, "r");
    FILE *file2 = fopen(arquivo2, "r");
    FILE *fileFinal;
    char palavra[30];
    int totalPalavras = 0;
    int contagemLetraInicial[26] = {0};
    int i;

    file1 = fopen(arquivo1, "r");
    file2 = fopen(arquivo2, "r");

    while (fscanf(file1, "%s", palavra) == 1) {
        totalPalavras++;
        removerVirgulas(palavra);
        palavra[0] = substituirAcentos(palavra[0]);
        if (isalpha(palavra[0])) {
            palavra[0] = tolower(palavra[0]);
            contagemLetraInicial[tolower(palavra[0]) - 'a']++;}}

    while (fscanf(file2, "%s", palavra) == 1) {
        totalPalavras++;
        removerVirgulas(palavra);
        palavra[0] = substituirAcentos(palavra[0]);
        if (isalpha(palavra[0])) {
            palavra[0] = tolower(palavra[0]);
            contagemLetraInicial[tolower(palavra[0]) - 'a']++;}}

    fclose(file1);
    fclose(file2);
    fileFinal = fopen("4.txt", "w");

    if (fileFinal == NULL) {
        printf("Erro ao criar o arquivo de palavras válidas.\n");
        return;}

    for (i = 0; i < 26; i++) {
        if (contagemLetraInicial[i] > 0) {
            fprintf(fileFinal, "%c: %.2f%%\n", 'a' + i, (contagemLetraInicial[i] / (float)totalPalavras) * 100);}}
    fclose(fileFinal);
}

//3
void calcPercentual(char *arquivo1, char *arquivo2) {
    FILE *file1 = fopen(arquivo1, "r");
    FILE *file2 = fopen(arquivo2, "r");
    FILE *fileFinal;
    char palavra[30];
    int totalPalavras = 0;
    int contagemLetras[26] = {0};
    int i;

    while (fscanf(file1, "%s", palavra) == 1) {
        totalPalavras++;
        for(i = 0; palavra[i] != '\0'; i++){
            palavra[i] = substituirAcentos(palavra[i]);}
        for (i = 0; palavra[i] != '\0'; i++) {
            if (isalpha(palavra[i])) {
                palavra[i] = tolower(palavra[i]);
                contagemLetras[palavra[i] - 'a']++;}}}

    while (fscanf(file2, "%s", palavra) == 1) {
        totalPalavras++;
        for(i = 0; palavra[i] != '\0'; i++){
            palavra[i] = substituirAcentos(palavra[i]);}
        for (i = 0; palavra[i] != '\0'; i++) {
            if (isalpha(palavra[i])) {
                palavra[i] = tolower(palavra[i]);
                contagemLetras[palavra[i] - 'a']++;}}}

    fclose(file1);
    fclose(file2);
    fileFinal = fopen("3.txt", "w");
    if (fileFinal == NULL) {
        printf("Erro ao criar o arquivo de palavras válidas.\n");
        return;}
    for (i = 0; i < 26; i++) {
        if (contagemLetras[i] > 0) {
            fprintf(fileFinal, "%c: %.2f%%\n", 'a' + i, (contagemLetras[i] / (float)totalPalavras) * 100);}}

    fclose(fileFinal);
}

//2 e 8 e 9
void calcfreq(char *arquivo1, char *arquivo2) {
    FILE *file1 = fopen(arquivo1, "r");
    FILE *file2 = fopen(arquivo2, "r");
    FILE *freqFile;
    int CONTletra[26] = {0};
    int totalLetras = 0;
    int c, i, j, maiorconsoant;
    float maiorconsoantpercent = 0;

    while ((c = fgetc(file1)) != EOF) {
        c = substituirAcentos(c);
        if (isalpha(c)) {
            c = tolower(c);
            CONTletra[c - 'a']++;
            totalLetras++;}}

    while ((c = fgetc(file2)) != EOF) {
        c = substituirAcentos(c);
        if (isalpha(c)) {
            c = tolower(c);
            CONTletra[c - 'a']++;
            totalLetras++;}}

    fclose(file1);
    fclose(file2);

    freqFile = fopen("2.txt", "w");
    if (freqFile == NULL) {
        printf("Erro ao criar o arquivo de frequência de letras.\n");
        return;}

    for (i = 0; i < 26; i++) {
        if(i != 0 && i != 4 && i != 8 && i != 14 && i != 20){
            if(((float)CONTletra[i] / totalLetras * 100) > maiorconsoantpercent){
                maiorconsoant = i;
                maiorconsoantpercent = (float)CONTletra[i] / totalLetras * 100;}}
        if (CONTletra[i] > 0) {
            fprintf(freqFile, "%c: %.2f%%\n", 'a' + i, (float)CONTletra[i] / totalLetras * 100);}}
    float total = (CONTletra[0]+CONTletra[4]+CONTletra[8]+CONTletra[14]+CONTletra[20]);
    printf("a: %.2f%%\n", (float)CONTletra[0] / totalLetras * 100);
    printf("e: %.2f%%\n", (float)CONTletra[4] / totalLetras * 100);
    printf("i: %.2f%%\n", (float)CONTletra[8] / totalLetras * 100);
    printf("o: %.2f%%\n", (float)CONTletra[14] / totalLetras * 100);
    printf("u: %.2f%%\n", (float)CONTletra[20] / totalLetras * 100);
    printf("Total de todas as vogais: %.2f%%\n", (total / totalLetras * 100) );
    printf("A consoante que mais aparece é a %c com %.2f%%\n", maiorconsoant+97, maiorconsoantpercent);
    fclose(freqFile);
}

//1
void achar1(char *arquivo1, char *arquivo2) {
    int i;
    FILE *file1 = fopen(arquivo1, "r");
    FILE *file2 = fopen(arquivo2, "r");

    FILE *wordsvalidas = fopen("1.txt", "w");
    char palavra[30];
    while (fscanf(file1, "%s", palavra) != EOF) {
        removerVirgulas(palavra);
        for(i=0;i<strlen(palavra);i++){
        palavra[i] = substituirAcentos(palavra[i]);
        if (isalpha(palavra[i])) {
            palavra[i] = tolower(palavra[i]);}}
        if (palavravalido(palavra, 1)) {
            fprintf(wordsvalidas, "%s\n", palavra);}}

    while (fscanf(file2, "%s", palavra) != EOF) {
        removerVirgulas(palavra);
        for(i=0;i<strlen(palavra);i++){
        palavra[i] = substituirAcentos(palavra[i]);
        if (isalpha(palavra[i])) {
            palavra[i] = tolower(palavra[i]);}}
        if (palavravalido(palavra, 1)) {
            fprintf(wordsvalidas, "%s\n", palavra);}}

    if (wordsvalidas == NULL) {
        printf("Erro ao criar o arquivo de palavras válidas.\n");
        return;}

    fclose(file1);
    fclose(file2);
    fclose(wordsvalidas);
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    char arq1[20], arq2[20];
    int N = 0;

    printf("Informe o nome do primeiro arquivo de texto: ");
    scanf("%s", arq1);

    printf("Informe o nome do segundo arquivo de texto: ");
    scanf("%s", arq2);

    printf("Digite um número inteiro N: ");
    while(N < 3 || N > 20){
       scanf("%d", &N);
       if(N < 3 || N > 20){
        printf("Erro, Digite um número entre 3 a 20: ");}}

    if ((fopen(arq1,"r")) == NULL || (fopen(arq2,"r")) == NULL) {
        printf("Erro ao abrir os arquivos de entrada");
        return;}
    calcDigrama(arq1, arq2);
    achar1(arq1, arq2);
    calcfreq(arq1, arq2);
    calcPercentual(arq1, arq2);
    calcularPercentualLetraInicial(arq1, arq2);
    calcularPercentualLetraFinal(arq1, arq2);
    calcNletras(arq1, arq2, N);
    calcNpalavras(arq1, arq2);
    achar2(arq1, arq2);
    achar3(arq1, arq2);
    return 0;
}
