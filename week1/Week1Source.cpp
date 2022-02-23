#include "Week1Header.h"

int Sum(int a, int b)
{
    return a + b;
}
int Dif(int a, int b)
{
    return a - b;
}
int Mul(int a, int b)
{
    return a * b;
}
int Div(int a, int b)
{
    return a / b;
}

void ParseSources()
{
    char input[38]    = "---H***E+++L+++L///O---P+++O/+-**O---";
    func Operatori[4] = { Mul, Sum, Dif, Div };
	int S = 0, V;
	Content x;
	int idx;

	for (int i = 0; i < strlen(input); i++)
	{
        char c = input[i] - 42;
		switch (c)
		{
			case INMULTIRE:
				idx = 0;
                x.p1 = 3;
                x.p2 = 3;
                break;
			case SUMA:
				idx = 1;
				x.p1 = 7;
				x.p2 = 5;
                break;
			case DIFERENTA:
				idx = 2;
				x.p1 = 10;
				x.p2 = 1;
                break;
			case IMPARTIRE:
				idx = 3;
				x.p1 = 8;
				x.p2 = 4;
                break;            
		}

		S = S + Operatori[idx](x.p1, x.p2);
	}

	//S=337
    printf("S = %d\n", S);
}

// Week 1 - using C API
void ReadTopScore()
{
    FILE* file = fopen("UserScores.txt", "r");
    if (file == NULL)
    {
        printf("Nu am gasit fisierul");
        return;
    }
    int max_score        = 0;
    char* line           = (char*) malloc((sizeof(char) * 50));
    char* max_score_name = (char*) malloc((sizeof(char) * 50));
    while (fscanf(file, "%[^\n] ", line) != EOF)
    {
        char* p    = strtok(line, " ");
        char* name = (char*) malloc((sizeof(char) * 50));
        strcpy(name, p);
        p = strtok(NULL, " ");

        int scor = atoi(p);
        if (scor > max_score)
        {
            max_score = scor;
            strcpy(max_score_name, name);
        }
    }
    printf("%s\n", max_score_name);
    fclose(file);
}