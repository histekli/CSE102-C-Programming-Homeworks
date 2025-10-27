#include <stdio.h>
#include <string.h>
#include <math.h>
#define max_values_numbers 100
#define max_length_of_a_line 1001

int main()
{
    int y = 1, i = 0, z = 0, check = 0, num; // i == number of values, z ==  index of values[] , (the_part example ax^b) 'check' returns a and b exist or not
    double a, b, result = 0;                 // result == result value
    char polynom[max_length_of_a_line], search_arr[max_length_of_a_line];
    double values[max_values_numbers];
    const char sep[] = "+-";

    FILE *values_txt, *polynomials_txt, *evaluations_txt; // file operations
    values_txt = fopen("values.txt", "r");
    polynomials_txt = fopen("polynomials.txt", "r");
    evaluations_txt = fopen("evaluations.txt", "w");
    if ((values_txt == NULL) || (polynomials_txt == NULL))
        return 1;
    while (y == 1) // the process of keeping the values in an array
    {
        y = fscanf(values_txt, "%lf", &values[i]);
        i++;
    }
    i--;
    while (!feof(polynomials_txt)) // main loop
    {
        fgets(polynom, max_length_of_a_line, polynomials_txt); // The process of keeping polynomial values ​​row by row
        for (z = 0; z < i; z++)                                // repeated result calculation and printing for each index
        {
            result = 0;
            strcpy(search_arr, polynom);
            char *the_part = strtok(polynom, sep);
            while (the_part != NULL)
            {
                char sign = search_arr[the_part - polynom - 1];
                check = sscanf(the_part, "%lfx^%lf", &a, &b); //  a.x^b is the equation
                if (check == 2)
                {
                    if (sign == '-')
                        result -= a * (pow(values[z], b));
                    else
                        result += a * (pow(values[z], b));
                }
                else if (check == 1)
                {
                    if (sign == '-')
                        result -= a * (values[z]);
                    else
                        result += a * (values[z]);
                }
                else if (check == 0) // check == 0 means the value a is not present
                {
                    if (sscanf(the_part, "x^%lf", &b) == 1) // the value b may be present so check for b value
                    {
                        if (sign == '-')
                            result -= pow(values[z], b);
                        else
                            result += pow(values[z], b);
                    }
                    else
                    {
                        if (sign == '-')
                            result -= values[z];
                        else
                            result += values[z];
                    }
                }

                the_part = strtok(NULL, sep); // take the next part
            }

            fprintf(evaluations_txt, "%.2lf ", result);
            strcpy(polynom, search_arr);
        }
        fprintf(evaluations_txt, "\n");
    }

    fclose(evaluations_txt); // close files
    fclose(polynomials_txt);
    fclose(values_txt);
    return 0;
}