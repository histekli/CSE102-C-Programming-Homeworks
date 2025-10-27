#include <stdio.h>
#include <string.h>
#define CARB_CAL_1G 4    // Number of calories in 1g carbohydrate
#define PROTEIN_CAL_1G 4 // Number of calories in 1g protein
#define FAT_CAL_1G 9     // Number of calories in 1g fat
#define WATER_CAL_1G 0   // Number of calories in 1g water
typedef struct leaf_node
{
    float gram;
    float carbohydrate;
    float protein;
    float fat;
    char name[30];
} leaf_node;

void f(char *meal, leaf_node *total_values)
{
    char component_list[20][30];
    const char sep[] = ",";
    int c, i = 0;
    float a, a1, b1, c1;
    char input[620], macro_nutriens[15];

    printf("what is the %s?:\n", meal);
    fgets(input, sizeof(input), stdin);
    if (total_values->name[0] == '\0')
        strncpy(total_values->name, input, strlen(input) + 1);
    char *component = strtok(input, sep);
    while (component != NULL)
    {
        strcpy(component_list[i], component);
        component = strtok(NULL, sep);

        i++;
    }
    for (int j = 0; j < i; j++)
    {

        c = sscanf(component_list[j], "%[a-z A-Z](%f)", meal, &a);
        if (c == 2)
        {
            printf("List the amount macro nutriens in %s:", meal);
            fgets(macro_nutriens, sizeof(macro_nutriens), stdin);
            sscanf(macro_nutriens, "%f %f %f", &a1, &b1, &c1);
            total_values->carbohydrate += (a * a1 * 0.01);
            total_values->protein += (a * b1 * 0.01);
            total_values->fat += (a * c1 * 0.01);
            total_values->gram += a;
        }
        else if (c == 1)
        {

            f(meal, total_values);
        }
    }
}
int main()
{
    char meal[30] = "meal";
    leaf_node total_values = {0, 0, 0, 0};
    f(meal, &total_values);
    float total_cal = (total_values.carbohydrate * CARB_CAL_1G) + (total_values.protein * PROTEIN_CAL_1G) + (total_values.fat * FAT_CAL_1G);
    float carb_ratio = (total_values.carbohydrate * CARB_CAL_1G) / total_cal;
    float prot_ratio = (total_values.protein * PROTEIN_CAL_1G) / total_cal;
    float fat_ratio = (total_values.fat * FAT_CAL_1G) / total_cal;

    printf("Total calories is %.1f in %.1fg %s. %%%.1f calories from carbs, %%%.1f from proteins, %%%.1f from fats.", total_cal, total_values.gram, total_values.name, 100 * carb_ratio, 100 * prot_ratio, 100 * fat_ratio);
}