#include <stdio.h>
#include <string.h>
#include <math.h>

void calculate_freq(float bi_grams[][27], FILE *file) // Calculating the frequencies of all bi-grams
{
    int count = 0;
    char a, b;
    while (fscanf(file, "%c%c", &a, &b) == 2)
    {
        if ((a < 'a' || a > 'z') && (b < 'a' || b > 'z')) // section where exceptions such as double spaces are ignored
        {
        }
        else if (a < 'a' || a > 'z') // cases for spaces and other characters
        {
            bi_grams[26][b - 97] += 1;
            count++;
        }
        else if (b < 'a' || b > 'z')
        {
            bi_grams[a - 97][26] += 1;
            count++;
        }
        else
        {
            bi_grams[a - 97][b - 97] += 1;
            count++;
        }
        fseek(file, -1, SEEK_CUR);
    }
    for (int i = 0; i < 27; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            if (bi_grams[i][j] != 0)
                bi_grams[i][j] /= count;
        }
    }
}
float dissimilarity(float bi_grams_x[][27], float bi_grams_others[][27]) // the function where the frequency difference is calculated
{
    float total = 0;
    for (int i = 0; i < 27; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            total += fabs(bi_grams_x[i][j] - bi_grams_others[i][j]); // abs is function that calculates absolute value
        }
    }
    printf("%f\n", total);
}

int main()
{
    FILE *language_x = fopen("language_x.txt", "r"); // file operations
    FILE *language_1 = fopen("language_1.txt", "r");
    FILE *language_2 = fopen("language_2.txt", "r");
    FILE *language_3 = fopen("language_3.txt", "r");
    FILE *language_4 = fopen("language_4.txt", "r");
    FILE *language_5 = fopen("language_5.txt", "r");

    float bi_grams_x[27][27], bi_grams_others[27][27];

    memset(bi_grams_x, 0, sizeof(bi_grams_x)); // function used to fill arrays with zeros
    memset(bi_grams_others, 0, sizeof(bi_grams_others));

    calculate_freq(bi_grams_x, language_x);
    calculate_freq(bi_grams_others, language_1);
    dissimilarity(bi_grams_x, bi_grams_others);

    memset(bi_grams_others, 0, sizeof(bi_grams_others));
    calculate_freq(bi_grams_others, language_2);
    dissimilarity(bi_grams_x, bi_grams_others);

    memset(bi_grams_others, 0, sizeof(bi_grams_others));
    calculate_freq(bi_grams_others, language_3);
    dissimilarity(bi_grams_x, bi_grams_others);

    memset(bi_grams_others, 0, sizeof(bi_grams_others));
    calculate_freq(bi_grams_others, language_4);
    dissimilarity(bi_grams_x, bi_grams_others);

    memset(bi_grams_others, 0, sizeof(bi_grams_others));
    calculate_freq(bi_grams_others, language_5);
    dissimilarity(bi_grams_x, bi_grams_others);

    fclose(language_x);
    fclose(language_1);
    fclose(language_2);
    fclose(language_3);
    fclose(language_4);
    fclose(language_5);
}