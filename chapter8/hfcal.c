//
// Created by weipeng2k on 2022/7/21.
//

#include <stdio.h>
#include <hfcal.h>

void display_calories(float weight, float distance, float coeff) {
    printf("WEIGHT:%3.2f kg\n", weight);
    printf("Distance:%3.2f miles\n", distance);
    printf("Effective Calories: %4.2f cal\n", coeff * weight * distance);
}