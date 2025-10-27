#include <stdio.h>
#define max_grams 100
int digit(int a);
int main()
{
    int a, b, c, d = 0, condition; // various variable definitions
    int two_grams[max_grams][2];
    int count[max_grams] = {0};
    FILE *file, *outfile; // file operations
    file = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");
    if (file == NULL || outfile == NULL) // file controls
    {
        return -1;
    }
    while (1)
    {
        c = fscanf(file, "%d %d", &a, &b);
        if (c != 2 || d == 100)
            break;
        fseek(file, (-1) * digit(b), SEEK_CUR); // after getting 2 values,going back in the file as many digits as the last value to get the last value again
        condition = 0;
        for (int j = 0; j < d; j++)
        {
            if ((two_grams[j][0] == a) && (two_grams[j][1] == b)) // operations for repeating 2-grams
            {
                count[j] += 1;
                condition = 1;
                break;
            }
        }
        if (condition == 1) // if the repeat condition is 1, use continue to avoid printing as a new value
            continue;
        two_grams[d][0] = a;
        two_grams[d][1] = b;
        count[d] += 1;
        d++;
    }
    for (int i = 0; i < d; i++)
    {
        fprintf(outfile, "%d %d:%d\n", two_grams[i][0], two_grams[i][1], count[i]); // writing operations to file
    }
    fclose(file);
    fclose(outfile);
    return 0;
}
int digit(int second_number) // this function returns the number of digits of the value sent as argument
{
    int b = 0;
    while (1)
    {
        second_number /= 10;
        if (second_number == 0)
        {
            b += 1;
            break;
        }
        b++;
    }
    return b;
}