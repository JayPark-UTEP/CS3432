#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // malloc & free
#include <stdint.h> // use guaranteed 64-bit integers
//#include "tokenizer.h" // Create header file and reference that
#include "memory.h" // built-in functions to read and write to a specific file
#include "string.h"

int main(){
    char add[100] = "ADD X16 X17 X08";
    char addi[100] = "ADDI X16 X07 08";
    char lw[100] = "LW X05 08(X06)";
    char sw[100] = "SW X06 08(X08)";

    char* token = strtok(sw, " ");

        if((token[0] == 'A') && (token[1] == 'D') && (token[2] == 'D') && (token[3] == 'I')){
            printf("ADDI\n");
            printf("%c\n", token[7]);
            printf("%c\n", token[11]);
            printf("%c\n", token[14]);

            int x = ((int)(token[6]-48)*10 + (int)(token[7])-48);
            int y = ((int)(token[10]-48)*10 + (int)(token[11])-48);
            int z = ((int)(token[13]-48)*10 + (int)(token[14])-48);

            if ((x > -1) && (x < 32) && (y > -1) && (y < 32) && (z > -1) && (z < 32)){

                printf("%d\n", x);
                printf("%d\n", y);
                printf("%d\n", z);

            }

            x = y + z;

            printf("%d\n", x);

        }else if((token[0] == 'A') && (token[1] == 'D') && (token[2] == 'D')){
            //"ADD X16 X17 X08"
            printf("ADD\n");
            printf("%c\n", token[5]);
            printf("%c\n", token[9]);
            printf("%c\n", token[13]);

            int x = ((int)(token[5]-48)*10 + (int)(token[6])-48);
            int y = ((int)(token[9]-48)*10 + (int)(token[10])-48);
            int z = ((int)(token[13]-48)*10 + (int)(token[14])-48);

            if ((x > -1) && (x < 32) && (y > -1) && (y < 32) && (z > -1) && (z < 32)){

                printf("%d\n", x);
                printf("%d\n", y);
                printf("%d\n", z);

            }
            
            x = y + z;

            printf("%d\n", x);
        
        //Lw X5 8(X6) => 8+6 = 14
		//finding 14 in Hexa in memory
		//put memory address into the X5
        }else if((token[0] == 'L') && (token[1] == 'W')){
            printf("loading\n"); //"LW X05 08(X06)"

            printf("%c\n", token[4]);
            printf("%c\n", token[7]);
            printf("%c\n", token[11]);

		int x = ((int)(token[4]-48)*10 + (int)(token[5])-48);
		int y = ((int)(token[7]-48)*10 + (int)(token[8])-48);
		int z = ((int)(token[11]-48)*10 + (int)(token[12])-48);

            int offSet = y + z;

            printf("%d\n", offSet);
            //call memory
            //int32_t read_address(int32-t address, char* mem.txt);
            //return read_address
            // reg[x] = read_address;

        //Lw X5 8(X6) => 8+6 = 14
		//finding 14 in Hexa in memory - offset
		//X5 -> 5 will be stored into the memmory offest
        }else if((token[0] == 'S') && (token[1] == 'W')){
            printf("Storing\n"); //"SW X6 8(X8)"

            printf("%c\n", token[4]);
            printf("%c\n", token[7]);
            printf("%c\n", token[11]);

		int x = ((int)(token[4]-48)*10 + (int)(token[5])-48);
		int y = ((int)(token[7]-48)*10 + (int)(token[8])-48);
		int z = ((int)(token[11]-48)*10 + (int)(token[12])-48);

            int offSet = y + z;

            printf("%d\n", offSet);
            //memory = x;


        }

}