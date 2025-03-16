// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes (bit.ly/antoniovandre_legadoontologico).

// Projeto Mathematical Ramblings (bit.ly/mathematicalramblings_github).

// Retorna o produto numérico dos argumentos.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 09-07-2020.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define PRODUTO_MENSAGEM_USO "Use antoniovandre_produto <NÚMERO REAL [NÚMERO REAL] ...>."
#define CABECALHO_ESTATISTICAS_MATHPRODUTO "produto"

int main (int argc, char *argv [])
	{
	long double produto = 1;
	int i;
	char * err;

	if (argc == 1 || (argc == 2 && (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help"))))
		{
		printf (PRODUTO_MENSAGEM_USO);
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
		produto *= strtold (argv [i], & err);

		if (*err != 0)
			{
			printf (PRODUTO_MENSAGEM_USO);
			printf ("\n");
			return -1;
			}
		}

	int antoniovandre_precisao_real_valor = antoniovandre_precisao_real (); if (antoniovandre_precisao_real_valor != -1) printf ("%.*Lf\n", antoniovandre_precisao_real_valor, (long double) produto); else return -1;

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHPRODUTO)) return -1;

	return 0;
	}

