#include <stdio.h>
#include <math.h>
#define numofclassmember 10
#define EPSILON 0.001

float distance(float x, float x1, float y, float y1);
int main()
{
    float total_class1_x_values = 0, // required variable definitions
        total_class1_y_values = 0,
          total_class2_x_values = 0,
          total_class2_y_values = 0,
          average_point_C1_x,
          average_point_C1_y,
          average_point_C2_x,
          average_point_C2_y,
          midpoint_x,
          midpoint_y,
          slope_midline,
          slope_sepline,
          x = 0, y = 0;

    for (int i = 0; i < numofclassmember; i++)
    {
        scanf("%f %f", &x, &y);
        total_class1_x_values += x; // all class_1 x values ​​collected
        total_class1_y_values += y; // all class_1 y values ​​collected
    }
    for (int j = 0; j < numofclassmember; j++)
    {
        scanf("%f %f", &x, &y);
        total_class2_x_values += x; // all class_2 x values ​​collected
        total_class2_y_values += y; // all class_2 y values ​​collected
    }
    average_point_C1_x = total_class1_x_values / numofclassmember; // midpoint calculation
    average_point_C1_y = total_class1_y_values / numofclassmember;
    average_point_C2_x = total_class2_x_values / numofclassmember;
    average_point_C2_y = total_class2_y_values / numofclassmember;
    midpoint_x = (average_point_C1_x + average_point_C2_x) / 2;
    midpoint_y = (average_point_C1_y + average_point_C2_y) / 2;
    printf("midpoint = %.1f %.1f\n", midpoint_x, midpoint_y);
    if (average_point_C1_x == average_point_C2_x) // using epsilon to avoid situations where slope values ​​are zero or infinite
        slope_midline = (average_point_C2_y - average_point_C1_y) / (average_point_C2_x - average_point_C1_x + EPSILON);
    else if (average_point_C2_y == average_point_C1_y)
        slope_midline = (average_point_C2_y - average_point_C1_y + EPSILON) / (average_point_C2_x - average_point_C1_x);
    else
        slope_midline = (average_point_C2_y - average_point_C1_y) / (average_point_C2_x - average_point_C1_x);

    slope_sepline = (-1) / slope_midline;
    printf("separating line slope = %.1f\n", slope_sepline);
    int status, cond = 1;
    do
    {
        status = scanf("%f %f", &x, &y);
        if (status == 2)
        {
            if ((y - midpoint_y) - ((slope_sepline)*x - slope_sepline * midpoint_x) < 0)
            {
                printf("class 1, ");
                printf("distance = %.1f \n", distance(x, average_point_C1_x, y, average_point_C1_y));
            }

            else
            {
                printf("class 2, ");
                printf("distance = %.1f \n", distance(x, average_point_C2_x, y, average_point_C2_y));
            }
        }
        else
            cond = 0;

    } while (cond);
}
float distance(float x, float x1, float y, float y1) // function that calculates the distance between two points
{
    float distance = 0;
    distance = sqrt(pow((x - x1), 2) + pow((y - y1), 2));
    return distance;
}