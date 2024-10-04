#include <stdio.h>
#include <string.h>

int main()
{
    float nums[5][3];
    float prom_estudiante[5];
    float prom_materia[3];
    char nombre[5][20];
    char materia[3][20];
    float max_estudiante[5];
    float min_estudiante[5];
    float max_materia[3];
    float min_materia[3];
    int i, j;
    float sum;
    int aprobado = 0;
    int reprobado = 0;

    for (i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre del alumno %d: ", i + 1);
        fgets(nombre[i], 20, stdin);
        nombre[i][strcspn(nombre[i], "\n")] = 0;
    }

    for (i = 0; i < 3; i++)
    {
        printf("Ingrese el nombre de la materia %d: ", i + 1);
        fgets(materia[i], 20, stdin);
        materia[i][strcspn(materia[i], "\n")] = 0;
    }

    //Nota: La función strscspn la usamos para poder eliminar el salto de linea, nos ayudamos mediante una IA como apoyo para la creación de esa linea de codigo

    for (i = 0; i < 5; i++)
    {
        printf("\nAlumno: %s\n", nombre[i]);
        for (j = 0; j < 3; j++)
        {
            printf("Ingrese la calificacion para la materia %s: ", materia[j]);
            scanf("%f", &nums[i][j]);
            while (nums[i][j] < 0 || nums[i][j] > 10)
            {
                printf("El valor ingresado es incorrecto, ingrese nuevamente la calificacion de la materia %s: ", materia[j]);
                scanf("%f", &nums[i][j]);
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        sum = 0;
        max_estudiante[i] = 0;
        min_estudiante[i] = 10;

        for (j = 0; j < 3; j++)
        {
            sum += nums[i][j];
            if (nums[i][j] > max_estudiante[i])
            {
                max_estudiante[i] = nums[i][j];
            }
            if (nums[i][j] < min_estudiante[i])
            {
                min_estudiante[i] = nums[i][j];
            }
        }
        prom_estudiante[i] = sum / 3;

        if (prom_estudiante[i] >= 6)
        {
            aprobado++;
        }
        else
        {
            reprobado++;
        }
    }

    for (j = 0; j < 3; j++)
    {
        sum = 0;
        max_materia[j] = 0;
        min_materia[j] = 10;

        for (i = 0; i < 5; i++)
        {
            sum += nums[i][j];
            if (nums[i][j] > max_materia[j])
            {
                max_materia[j] = nums[i][j];
            }
            if (nums[i][j] < min_materia[j])
            {
                min_materia[j] = nums[i][j];
            }
        }
        prom_materia[j] = sum / 5;
    }

    printf("\nCalificaciones por estudiante y materia:\n");
    printf("%-20s", "Alumno/Materia");
    for (j = 0; j < 3; j++)
    {
        printf("%-15s", materia[j]);
    }
    printf("\n");

    for (i = 0; i < 5; i++)
    {
        printf("%-20s", nombre[i]);
        for (j = 0; j < 3; j++)
        {
            printf("%-15.2f", nums[i][j]);
        }
        printf("\n");
    }

    printf("\nPromedio de calificaciones por estudiante:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%-20s: %.2f\n", nombre[i], prom_estudiante[i]);
    }

    printf("\nPromedio de calificaciones por materia:\n");
    for (j = 0; j < 3; j++)
    {
        printf("%-20s: %.2f\n", materia[j], prom_materia[j]);
    }

    printf("\nCalificacion mas alta por estudiante:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%-20s: %.2f\n", nombre[i], max_estudiante[i]);
    }

    printf("\nCalificacion mas baja por estudiante:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%-20s: %.2f\n", nombre[i], min_estudiante[i]);
    }

    printf("\nCalificacion mas alta por materia:\n");
    for (j = 0; j < 3; j++)
    {
        printf("%-20s: %.2f\n", materia[j], max_materia[j]);
    }

    printf("\nCalificacion mas baja por materia:\n");
    for (j = 0; j < 3; j++)
    {
        printf("%-20s: %.2f\n", materia[j], min_materia[j]);
    }

    printf("\nNumero de estudiantes aprobados: %d\n", aprobado);
    printf("Numero de estudiantes reprobados: %d\n", reprobado);

    return 0;
}