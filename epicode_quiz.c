#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
// costanti
#define QUESTIONS 10
#define OPTIONS 3
#define BENCHMARK 6

// dichiarazione funzioni
void quiz();
bool new_game();

// main
int main()
{
    char domande[QUESTIONS][100] = {
        "1. Che comando Linux si usa per mostrare i processi in esecuzione?\n",
        "2. Quanti livelli ha il modello ISO/OSI?\n",
        "3. Quale fra questi e' un tool usato per scansionare un target?\n",
        "4. Nel linguaggio C, che funzione si usa per chiedere un input all'utente?\n",
        "5. Quale fra questi e' un linguaggio interpretato?\n",
        "6. Quale tra questi protocolli e' usato per assegnare gli indirizzi IP in modo dinamico?\n",
        "7. Qual e' il comando windows usato per scoprire l'indirizzo MAC della propria NIC?\n",
        "8. Quale tra questi dispositivi serve a far comunicare reti diverse?\n",
        "9. Nel linguaggio C, un puntatore e':\n",
        "10. Quale tra queste affermazioni su VirtualBox e' vera:\n"};

    char opzioni[QUESTIONS][OPTIONS][100] = {
        {"A. ls", "B. cd", "C. ps"},
        {"A. 5", "B. 7", "C. 10"},
        {"A. nmap", "B. netcat", "C. inetsim"},
        {"A. printf", "B. scanf", "C. putchar"},
        {"A. C", "B. C++", "C. Python"},
        {"A. ARP", "B. DNS", "C. DHCP"},
        {"A. ipconfig /all", "B. ipconfig", "C. ifconfig /all"},
        {"A. Switch", "B. Router", "C. Modem"},
        {"A. Una variabile che contiene l'indirizzo in memoria di un'altra variabile", "B. L'indirizzo di memoria di una variabile", "C. Il valore di una variabile in un certo indirizzo di memoria"},
        {"A. Le VM delle reti interne possono comunicare con l'host", "B. Le VM delle reti interne non possono comunicare con l'host", "C. Le VM delle reti interne possono collegarsi ad internet"}

    };
    char risposte_corrette[10] = {'C', 'B', 'A', 'B', 'C', 'C', 'A', 'B', 'A', 'B'};
    int punti;
    char nome[100];
    bool run_game;
    punti = 0;

    printf("Benvenuto su Epicode Super Quiz.Devi rispondere al maggior numero di risposte corrette\nSe azzecchi almeno il 60%% delle risposte hai vinto.\n\n");
    printf("Innanzi tutto, come ti chiami?\n");
    scanf("%99s", &nome);
    fflush(stdin);

    run_game = new_game();
    while (run_game)
    {
        printf("Bene %s, iniziamo con la prima domanda.\n", nome);
        quiz(punti, domande, opzioni, risposte_corrette);
    }

    return 0;
}

// funzione new game
bool new_game()
{
    char answer[20];

    while (true)
    {
        printf("Vuoi iniziare una nuova partita? (y/n)\n");
        scanf("%s", &answer);
        fflush(stdin);

        if (answer[0] == 'n' || answer[0] == 'N')
        {
            printf("Alla prossima!\n");
            exit(0);
        }
        else if (answer[0] == 'y' || answer[0] == 'Y')
        {
            return true;
        }
        else
        {
            printf("Risposta non valida, riprova!\n");
        }
    }
}

// funzione quiz
void quiz(int punti, char domande[QUESTIONS][100], char opzioni[QUESTIONS][OPTIONS][100], char risposte_corrette[10])
{
    char risposta[20];
    int i, j;

    for (i = 0; i < QUESTIONS; i++)
    {
        printf("**************\n");
        printf("%s\n", domande[i]);
        for (j = 0; j < OPTIONS; j++)
        {
            printf("%s\n", opzioni[i][j]);
        }
        scanf("%s", &risposta);
        fflush(stdin);
        risposta[0] = toupper(risposta[0]);

        if (risposta[0] == risposte_corrette[i])
        {
            punti++;
            printf("Corretta!\n\n");
        }
        else
        {
            printf("Mannaggia, hai sbagliato!\n\n");
        }
    }

    printf("\nHai totalizzato %d punti\n", punti);
    if (punti < BENCHMARK)
    {
        printf("Niente, non ce la puoi fare. Ritenta!\n");
    }
    else
    {
        printf("Sei un king! Hai vinto!\n");
    }

    new_game();
}