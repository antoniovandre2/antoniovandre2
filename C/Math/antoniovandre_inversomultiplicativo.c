// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes (bit.ly/antoniovandre_legadoontologico).

// Projeto Mathematical Ramblings (bit.ly/mathematicalramblings_github).

// Retorna o inverso multiplicativo numérico do primeiro argumento.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 09-07-2020.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define INVERSO_MULTIPLICATIVO_MENSAGEM_USO "Use antoniovandre_inversomultiplicativo <NÚMERO REAL NÃO NULO>."
#define CABECALHO_ESTATISTICAS_MATHINVERSOMULTIPLICATIVO "inversomultiplicativo"

int main (int argc, char *argv [])
	{
	long double resultado;
	long double divisor;
	char * err;

	if (argc != 2 || (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help")))
		{
		printf (INVERSO_MULTIPLICATIVO_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	if (! strcmp (argv [1], "sobre") || ! strcmp (argv [1], "--sobre"))
		{
		if (! antoniovandre_mathsobre ()) return -1;
		return 0;
		}

	divisor = strtold (argv [1], & err);

	if (*err != 0 || divisor == 0)
		{
		printf (INVERSO_MULTIPLICATIVO_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	resultado = 1 / (long double) divisor;

	int antoniovandre_precisao_real_valor = antoniovandre_precisao_real (); if (antoniovandre_precisao_real_valor != -1) printf ("%.*Lf\n", antoniovandre_precisao_real_valor, (long double) resultado); else return -1;

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHINVERSOMULTIPLICATIVO)) return -1;

	return 0;
	}

