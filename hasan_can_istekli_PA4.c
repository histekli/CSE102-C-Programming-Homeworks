#include <stdio.h>
#include <string.h>
#define max_word_length 12
#define max_rows 251
#define max_cols 100

char arr[max_cols][max_rows];

int is_horizontal(char arr[max_rows], char *word)
{
    for (int m = 0; m < strlen(word); m++)
    {
        if (arr[m] != word[m])
        {
            return 0;
        }
    }
    return 1;
}
int is_vertical(char arr[][max_rows], int i, int j, char *word)
{
    for (int m = 0; m < strlen(word); m++)
    {
        if (arr[i + m][j] != word[m])
            return 0;
    }
    return 1;
}
int is_diagonal(char arr[][max_rows], int i, int j, char *word)
{
    for (int m = 0; m < strlen(word); m++)
    {
        if (arr[i + m][j + m] != word[m])
            return 0;
    }
    return 1;
}

int main()
{
    char c, word[max_word_length];
    int m = 0, n = 0, j = 0, find = 0;
    FILE *input1, *input2, *output; //! file operations
    input1 = fopen("input1.txt", "r");
    input2 = fopen("input2.txt", "r");
    output = fopen("output.txt", "w");
    while (fscanf(input2, "%c", &c) != EOF) //! keeping the characters in the input2.txt file in an array
    {
        if (c == '\n')
        {
            arr[m][n] = '\0';
            m++;
            n = 0;
        }
        else
        {
            arr[m][n] = c;
            n++;
        }
    }
    while (fgets(word, max_word_length, input1) != NULL) //! taking the words in input1.txt one by one until the end of the file and using
    {
        if (word[strlen(word) - 1] == '\n')
            word[strlen(word) - 2] = '\0';
        for (int i = 0; i < m + 1; i++)
        {
            while (arr[i][j] != '\0') //! searching for the first letter of a word in an array
            {
                if (arr[i][j] == word[0]) //! if the first letter is found, search for the remaining letters with functions
                {
                    if (is_horizontal(&arr[i][j], word))
                    {
                        fprintf(output, "%s (%d,%d) Horizontal\n", word, i + 1, j + 1);
                        find = 1;
                        break;
                    }
                    else if (is_vertical(arr, i, j, word))
                    {
                        fprintf(output, "%s (%d,%d) Vertical\n", word, i + 1, j + 1);
                        find = 1;
                        break;
                    }
                    else if (is_diagonal(arr, i, j, word))
                    {
                        fprintf(output, "%s (%d,%d) Diagonal\n", word, i + 1, j + 1);
                        find = 1;
                        break;
                    }
                }
                j++;
            }
            j = 0;
            if (find) //! if the word is found, end the search for the same word
            {
                find = 0;
                break;
            }
        }
    }
    fclose(input1);
    fclose(input2);
    fclose(output);
}