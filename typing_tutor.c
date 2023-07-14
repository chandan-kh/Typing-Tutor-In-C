#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct report {
    int timetaken;
    int accuracy;
    struct report *next;
} report;

report *head = NULL;

void calculate(int, int, int);
void begin();
void nextwork();
void choices();
void store(report *);

void store(report *ptr)
{
    head = ptr;
    head = NULL;
}

int homepage(void)
{
    printf("WELCOME TO THE TYPING TUTOR!!");
    sleep(2);
    printf("\n\nHere, we will work on your typing speed make you a better typist.");
    printf("\n\nLet's start our journey to rise as the best typist of all times.");
    printf("\n\nAre you ready to begin?\n");
    choices();
}

void choices()
{
    int c;

    printf("\n\nPress 1 to begin.\n");
    scanf("%d", &c);
    switch (c) {
        case 1:
            begin();
            break;
        default:
            printf("Please enter a valid number");
            choices();
    }
}

void begin()
{
    int correct = 0, wrong = 0, i, x, timetaken;
    clock_t start, end;
    char a[500], c;

    // Array of paragraphs
    const char *paragraphs[] = {
        "Sir, you will undoubtedly end up in a drunkard's grave",
        "I glared as I pushed the glass across the table.",
        "Yes, she was now the first person ever to land on Venus.",
        "She looked at the control panel and knew there was nothing that would ever get it back into working order.",
        "There was something beautiful in his hate.",
        "I tried it with dark chocolate chunks and I tried it with semi-sweet chocolate chips.",
        "It wasn't the hate itself as it was a disgusting display of racism and intolerance.",
        "It comes out pretty bad with just the dark chocolate.",
        "Enjoy the journey of becoming a fast typist.",
        "The best add-ins are crushed almonds and marshmallows -- what you get from that is Rocky Road."
    };

    // Get a random paragraph
    srand(time(NULL));
    const char *randomParagraph = paragraphs[rand() % (sizeof(paragraphs) / sizeof(paragraphs[0]))];

    printf("Enter the following paragraph as it is as fast as you can:\n");
    sleep(2);
    getchar();
    printf("%s\n", randomParagraph);
    start = clock();
    scanf(" %[^\n]s", a);
    end = clock();
    x = strlen(randomParagraph);
    for (i = 0; i < x; i++) {
        if (a[i] == randomParagraph[i])
            correct++;
        else
            wrong++;
    }
    timetaken = (int)(end - start) / CLOCKS_PER_SEC;
    calculate(correct, wrong, timetaken);
    nextwork();
}

void calculate(int correct, int wrong, int timetaken)
{
    int per;
    report *ptr;

    ptr = (report *)malloc(sizeof(report *));
    ptr->timetaken = timetaken;
    printf("Right letters: %d\n", correct);
    printf("Wrong letters: %d\n", wrong);
    printf("Time taken: %d\n", timetaken);
    ptr->accuracy = (100 * correct) / (correct + wrong);
    printf("Accuracy: %d%%", ptr->accuracy);
    printf("\n\n");
    store(ptr);
}

void nextwork()
{
    int c;

    printf("Do you want to continue? (1=Yes/0=No)");
    scanf("%d", &c);
    switch (c) {
        case 1:
            begin();
            break;
        case 0:
            choices();
            break;
        default:
            printf("Wrong input");
            nextwork();
    }
}

int main(void)
{
    homepage();
    return 0;
}
