#include <stdlib.h>
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

#ifdef _WIN32
#include <windows.h>
#endif

int Summa(int n)
{
    int summa = 0;
    for (int i = 1; i <= n / 2; ++i)
    {
        summa += i;
    }
    return summa;
}

int CalculateSizeAllocatedMemory(int n)
{
    return (n + 1) * n - 2 * Summa(n);
}

void String(int numberSpace, int numberStar, int* i, char* array)
{

    int k = *i;
    for (int f = k; f < k + numberSpace; ++f)
    {
        array[f] = ' ';
        *i = *i + 1;
    }
    k = *i;

    for (int f = k; f < k + numberStar; ++f)
    {
        array[f] = '*';
        *i = *i + 1;
    }
    array[*i] = '\n';
    *i = *i + 1;

}

void diamond(int n)
{

    if (n <= 0 || n % 2 == 0)
    {
        return ;
    }
    int g = 0;
    if (CalculateSizeAllocatedMemory(n) == 2)
    {
        g = CalculateSizeAllocatedMemory(n);
    }
    else
    {
        g = ((CalculateSizeAllocatedMemory(n) - n - 1) / 2) + n + 1;
    }
    char* array = (char*)calloc(g, 1);
    int i = 0;
    int r = 1;
    for (int w = n / 2; w >= 0; w--)
    {
        String(w, r, &i, array);
        r = r + 2;
    }
    for (int i = 0; i < g; ++i)
    {
        printf("%c",array[i]);
    }
    free(array);
//    return array;
}

int main()
{
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif    
    int height = 0;
    
#ifdef _WIN32
    do
    {
        printf("Введите высоту пирамиды ");
        scanf_s("%d", &height);
    } while (height < 1 || height > 30);
    
#else
    do
    {
        printf("Введите высоту пирамиды ");
        scanf("%d", &height);
    } while (height < 1 || height > 30);
#endif
    diamond((height - 1) * 2 + 1);
//    printf("hello word");
    return 0;
}