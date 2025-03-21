// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes.

// Projeto Mathematical Ramblings.

// Retorna o determinante da matriz passada como argumento.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 07-12-2020.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define DETERMINANTE_MENSAGEM_USO "Use antoniovandre_determinante <<ELEMENTO , ELEMENTO , ...> / <ELEMENTO , ELEMENTO , ...> / ...>."
#define CABECALHO_ESTATISTICAS_MATHDETERMINANTE "determinante"

int main (int argc, char *argv [])
	{
	TIPONUMEROREAL ** matriz;
	TIPONUMEROREAL det;
	TIPONUMEROREAL elemento;
	int linhas = 1;
	int colunas = 1;
	int colunasp;
	int i;
	int shift = 0;
	int flag = 0;
	char * err;

	if (argc == 1 || (argc == 2 && (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help"))))
		{
		printf (DETERMINANTE_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	if (argc == 2 && (! strcmp (argv [1], "sobre") || ! strcmp (argv [1], "--sobre")))
		{
		if (! antoniovandre_mathsobre ()) return -1;
		return 0;
		}

	for (i = 1; i < argc; i++)
		{
		if (! strcmp (argv [i], ",")) colunas++;
		if (! strcmp (argv [i], "/"))
			{
			if ((colunas != colunasp) && (flag == 1))
				{
				printf (DETERMINANTE_MENSAGEM_USO);
				printf ("\n");
				return -1;
				}

			linhas++;

			colunasp = colunas; colunas = 1;
			flag = 1;
			}
		}

	if (linhas != colunas)
		{
		printf (DETERMINANTE_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}
	else
		{
		matriz = (TIPONUMEROREAL **) malloc ((linhas + 1) * sizeof (TIPONUMEROREAL *));
		matriz [linhas] = NULL;

		for (i = 0; i < linhas; i++)
			{
			matriz [i] = (TIPONUMEROREAL *) malloc ((colunas + 1) * sizeof (TIPONUMEROREAL));
			matriz [i] [colunas] = MARCADORREAL;
			}

		for (i = 0; i < argc; i++)
			{
			elemento = strtold (argv [i], & err);

			if (* err == NUMEROZERO)
				{
				if ((elemento > VALOR_MAX) || (elemento < (-1) * VALOR_MAX))
					{
					printf (MENSAGEM_ERRO_OVER);
					printf ("\n");
					return -1;
					}

				matriz [(int) (shift / colunas)] [shift % colunas] = elemento;
				shift++;
				}
			}

		det = antoniovandre_determinante (matriz);

		if (isnan (det))
			{
			printf (DETERMINANTE_MENSAGEM_USO);
			printf ("\n");
			return -1;
			}
		else if (isinf (det))
			{
			printf (MENSAGEM_ERRO_OVER);
			printf ("\n");
			return -1;
			}
		else
			printf ("%LG\n", det);
		}

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHDETERMINANTE)) return -1;

	return 0;
	}

