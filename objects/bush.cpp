//
// Created by Даниил Лесь on 06.01.2022.
//

#include "bush.h"
#include "../functions/additional_functions .h"

const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


int ReadInput(Bush* bush, FILE* input_file){
    int flowering_month;

    int argc = fscanf(input_file, "%d\n", &flowering_month);

    if (argc != 1){
        printf("Error: Could not read bush flowering month.\n");
        return 1;
    }

    if (flowering_month < 1 || flowering_month > 12){
        printf("Error: Incorrect bush flowering month.\n");
        return 1;
    }

    bush->flowering_month = (Bush::Flowering_month) flowering_month;

    return 0;
}

void RandomInput(Bush* bush){
    bush->flowering_month = (Bush::Flowering_month) RandomInt(13);
    printf("%d\n", bush->flowering_month);
}

void Out(const Bush* bush, FILE* output_file){
    fprintf(output_file, "flowering month - %s.\n", PrintFloweringMonth(bush->flowering_month));
}

const char* PrintFloweringMonth(Bush::Flowering_month flowering_month) {
    switch (flowering_month) {
        case Bush::Jan:
            return months[0];
        case Bush::Feb:
            return months[1];
        case Bush::Mar:
            return months[2];
        case Bush::Apr:
            return months[3];
        case Bush::May:
            return months[4];
        case Bush::Jun:
            return months[5];
        case Bush::Jul:
            return months[6];
        case Bush::Aug:
            return months[7];
        case Bush::Sep:
            return months[8];
        case Bush::Oct:
            return months[9];
        case Bush::Nov:
            return months[10];
        case Bush::Dec:
            return months[11];
    }
}