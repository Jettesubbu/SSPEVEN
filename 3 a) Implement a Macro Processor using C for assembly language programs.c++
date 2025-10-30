#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 80
#define MAX_MACROS 10

char nameTable[MAX_MACROS][MAX_LEN];
char defTable[MAX_MACROS][MAX_LINES][MAX_LEN];
int defCount[MAX_MACROS];
int macroCount = 0;

int findMacro(char *name) {
    int i;
    for (i = 0; i < macroCount; i++) {
        if (strcmp(nameTable[i], name) == 0)
            return i;
    }
    return -1;
}

void process_macro(char input[][MAX_LEN], int n) {
    char label[MAX_LEN], opcode[MAX_LEN], operand[MAX_LEN];
    int i, j;

    printf("\n--- Expanded Program ---\n");

    for (i = 0; i < n; i++) {
        char line[MAX_LEN];
        strcpy(line, input[i]);

        label[0] = opcode[0] = operand[0] = '\0';
        sscanf(line, "%s %s %s", label, opcode, operand);

        if (strcmp(opcode, "MACRO") == 0) {
            i++;
            if (i == n) break;

            sscanf(input[i], "%s", nameTable[macroCount]);
            int idx = macroCount;
            defCount[idx] = 0;

            while (++i < n) {
                if (strcmp(input[i], "MEND") == 0)
                    break;
                strcpy(defTable[idx][defCount[idx]++], input[i]);
            }
            macroCount++;
        } 
        else {
            int idx = findMacro(opcode);
            if (idx != -1) {
                for (j = 0; j < defCount[idx]; j++)
                    printf("%s\n", defTable[idx][j]);
            } 
            else {
                printf("%s\n", line);
            }
        }
    }

    printf("--- End of Expansion ---\n");
}

int main() {
    char program[][MAX_LEN] = {
        "COPY MACRO", "COPYDEF",
        "MOV A,B",
        "ADD A,C",
        "MEND",
        "START COPYDEF",
        "END"
    };

    int n = sizeof(program) / sizeof(program[0]);
    process_macro(program, n);
    return 0;
}
