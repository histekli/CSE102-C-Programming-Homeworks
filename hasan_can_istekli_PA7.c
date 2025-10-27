#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define OUTPUT 0   //* type 0 = OUTPUT
#define INPUT 1    //* type 1 = INPUT
#define AND 2      //* type 2 = AND
#define OR 3       //* type 3 = OR
#define NOT 4      //* type 4 = NOT
#define FLIPFLOP 5 //* type 5 = FLIPFLOP
typedef struct gate
{
    int type;          /* type of the gate*/
    char name[20];     /* name of the gate*/
    struct gate *inp1; /* points to input gate1*/
    struct gate *inp2; /* points to input gate2*/
    int output;        /* stores the current output. this may be useful if the gate is connected to more than one gate.*/
    int former_out;    /* only for flipflop*/

} gateNode;
int evaluate(gateNode *g)
{
    int input1;
    switch (g->type)
    {
    case OUTPUT:
        g->output = evaluate(g->inp1);
        return g->output;
        break;
    case INPUT:
        return g->output;
        break;
    case AND:
        g->output = evaluate(g->inp1) & evaluate(g->inp2);
        return g->output;
        break;
    case OR:
        g->output = evaluate(g->inp1) | evaluate(g->inp2);
        return g->output;
        break;
    case NOT:
        g->output = !evaluate(g->inp1);
        return g->output;
        break;
    case FLIPFLOP:
        g->output = evaluate(g->inp1) ^ evaluate(g->inp2);
        return g->output;
        break;
    default:
        break;
    }
}

int main()
{
    FILE *circiut_txt = fopen("circiut.txt", "r");
    FILE *input_txt = fopen("input.txt", "r");

    int num_of_gates = 0, x = 0;
    char str[80], gate_or_connect[20], gate_name_or_connection2[20], type_or_connection1[20], input[20];
    while (!feof(circiut_txt))
    {
        fgets(str, sizeof(str), circiut_txt);
        sscanf(str, "%s", gate_or_connect);
        if (strcmp(gate_or_connect, "GATE") == 0)
        {
            num_of_gates++;
        }
    }
    rewind(circiut_txt);

    gateNode **all_gates = (gateNode **)malloc(sizeof(gateNode *) * (num_of_gates));
    gateNode *out_gate;
    int current_num_of_gate = 0;
    while (!feof(circiut_txt))
    {

        fgets(str, sizeof(str), circiut_txt);
        sscanf(str, "%s %s %s", gate_or_connect, type_or_connection1, gate_name_or_connection2);

        if (strcmp("GATE", gate_or_connect) == 0)
        {
            current_num_of_gate++;
            all_gates[x] = (gateNode *)malloc(sizeof(gateNode));
            all_gates[x]->former_out = 0;
            all_gates[x]->inp1 = NULL;
            all_gates[x]->inp2 = NULL;

            if (strcmp(type_or_connection1, "OUTPUT") == 0)
            {
                all_gates[x]->type = OUTPUT;
                out_gate = all_gates[x];
            }
            else if (strcmp(type_or_connection1, "INPUT") == 0)
            {
                all_gates[x]->type = INPUT;
            }
            else if (strcmp(type_or_connection1, "AND") == 0)
            {
                all_gates[x]->type = AND;
            }
            else if (strcmp(type_or_connection1, "OR") == 0)
            {
                all_gates[x]->type = OR;
            }
            else if (strcmp(type_or_connection1, "NOT") == 0)
            {
                all_gates[x]->type = NOT;
            }
            else if (strcmp(type_or_connection1, "FLIPFLOP") == 0)
            {
                all_gates[x]->type = FLIPFLOP;
            }
            strcpy(all_gates[x]->name, gate_name_or_connection2);
            x++;
        }
        else if (strcmp(gate_or_connect, "CONNECTION") == 0)
        {

            int pre, next;
            for (int i = 0, j = 0; i < current_num_of_gate; i++, j++)
            {

                if (strcmp(type_or_connection1, all_gates[i]->name) == 0)
                {
                    pre = i;
                }
                if (strcmp(gate_name_or_connection2, all_gates[j]->name) == 0)
                {
                    next = j;
                }
            }
            if (all_gates[next]->inp1 == NULL)
            {
                all_gates[next]->inp1 = all_gates[pre];
            }
            else if (all_gates[next]->inp2 == NULL)
            {
                all_gates[next]->inp2 = all_gates[pre];
            }
        }
    }

    while (!feof(input_txt))
    {
        fgets(input, sizeof(input), input_txt);
        int i = 0;
        for (int j = 0; j < num_of_gates; j++)
        {
            if (all_gates[j]->type == INPUT)
            {
                if (input[i] == '0')
                {
                    all_gates[j]->output = 0;
                }
                if (input[i] == '1')
                {
                    all_gates[j]->output = 1;
                }
                i++;
            }
        }
        printf("%d\n", evaluate(out_gate));
    }
    fclose(input_txt);
    fclose(circiut_txt);
    for (int i = 0; i < num_of_gates; i++)
    {
        free(all_gates[i]);
    }
    free(all_gates);
}