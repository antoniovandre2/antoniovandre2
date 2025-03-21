// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes.

// Projeto Mathematical Ramblings.

// Retorna a cotangente do primeiro argumento.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 09-07-2020.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define COTANGENTE_MENSAGEM_USO "Use antoniovandre_cotangente <NÚMERO REAL NO DOMÍNIO>."
#define CABECALHO_ESTATISTICAS_MATHCOTANGENTE "cotangente"

int main (int argc, char *argv [])
	{
	long double resultado;
	long double arco;
	char * err;

	if (argc != 2 || (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help")))
		{
		printf (COTANGENTE_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	if (! strcmp (argv [1], "sobre") || ! strcmp (argv [1], "--sobre"))
		{
		if (! antoniovandre_mathsobre ()) return -1;
		return 0;
		}

	arco = strtold (argv [1], & err);

	if (*err != 0 || (fmodl ((long double) arco, M_PIl) == 0))
		{
		printf (COTANGENTE_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	resultado = 1 / tanl ((long double) arco);

	int antoniovandre_precisao_real_valor = antoniovandre_precisao_real (); if (antoniovandre_precisao_real_valor != -1) printf ("%.*Lf\n", antoniovandre_precisao_real_valor, (long double) resultado); else return -1;

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHCOTANGENTE)) return -1;

	return 0;
	}

