// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes.

// Projeto Mathematical Ramblings.

// Retorna o arcocosseno do primeiro argumento.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 09-07-2020.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define ARCOCOSSENO_MENSAGEM_USO "Use antoniovandre_arcocosseno <NÚMERO REAL ENTRE -1 E 1 INCLUSIVE>."
#define CABECALHO_ESTATISTICAS_MATHARCOCOSSENO "arcocosseno"

int main (int argc, char *argv [])
	{
	long double cosseno;
	char * err;

	if (argc != 2 || (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help")))
		{
		printf (ARCOCOSSENO_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	if (! strcmp (argv [1], "sobre") || ! strcmp (argv [1], "--sobre"))
		{
		if (! antoniovandre_mathsobre ()) return -1;
		return 0;
		}

	cosseno = strtold (argv [1], & err);

	if (*err != 0 || cosseno < -1 || cosseno > 1)
		{
		printf (ARCOCOSSENO_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	int antoniovandre_precisao_real_valor = antoniovandre_precisao_real (); if (antoniovandre_precisao_real_valor != -1) printf ("%.*Lf\n", antoniovandre_precisao_real_valor, acosl ((long double) cosseno)); else return -1;

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHARCOCOSSENO)) return -1;

	return 0;
	}

