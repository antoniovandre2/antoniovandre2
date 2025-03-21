// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes.

// Projeto Mathematical Ramblings.

// Retorna o arcocotangente do primeiro argumento.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 09-07-2020.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define ARCOCOTANGENTE_MENSAGEM_USO "Use antoniovandre_arcocotangente <NÚMERO REAL>."
#define CABECALHO_ESTATISTICAS_MATHARCOCOTANGENTE "arcocotangente"

int main (int argc, char *argv [])
	{
	long double resultado;
	long double cotangente;
	char * err;

	if (argc != 2 || (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help")))
		{
		printf (ARCOCOTANGENTE_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	if (! strcmp (argv [1], "sobre") || ! strcmp (argv [1], "--sobre"))
		{
		if (! antoniovandre_mathsobre ()) return -1;
		return 0;
		}

	cotangente = strtold (argv [1], & err);

	if (*err != 0)
		{
		printf (ARCOCOTANGENTE_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	if (cotangente == 0) resultado = M_PI_2l; else if (cotangente < 0) resultado = atanl (1 / (long double) cotangente) + M_PIl; else resultado = atanl (1 / (long double) cotangente);

	int antoniovandre_precisao_real_valor = antoniovandre_precisao_real (); if (antoniovandre_precisao_real_valor != -1) printf ("%.*Lf\n", antoniovandre_precisao_real_valor, (long double) resultado); else return -1;

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHARCOCOTANGENTE)) return -1;

	return 0;
	}

