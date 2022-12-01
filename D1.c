#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    // read the text file
    FILE *file = fopen("D1_input.txt","r");
    char *line = NULL;
    size_t lineSize = 0;
    ssize_t read;

    int top1 = 0;
    int top2 = 0;
    int top3 = 0;

    int current = 0;
    int cal = 0;
    
    if (file == NULL) {
        printf("Unable to read file: %s\n", "D1_input.txt");
        exit(1);
    } else {
        while ((read = getline(&line, &lineSize, file)) != -1) {
            if (line[0] == '\n') { //check if it's a blank line
                // printf("Blank line. End of this Elf.\n");
                if (cal > top1) {
                    top3 = top2;
                    top2 = top1;
                    top1 = cal;
                } else if (cal > top2) {
                    top3 = top2;
                    top2 = cal;
                } else if (cal > top3) {
                    top3 = cal;
                } 
                cal = 0; //reset cal for the next elf
            } else {
                sscanf(line, "%d", &current);
                cal += current;
            }
        
        }
    }
    fclose(file);
    printf("Top1 is %d, top2 is %d, top3 is %d, calories in total: %d\n", top1, top2, top3, (top1+top2+top3));
    return 0;
}
