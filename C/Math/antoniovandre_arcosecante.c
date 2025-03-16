// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes (bit.ly/antoniovandre_legadoontologico).

// Projeto Mathematical Ramblings (bit.ly/mathematicalramblings_github).

// Retorna o arcosecante do primeiro argumento.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 09-07-2020.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define ARCOSECANTE_MENSAGEM_USO "Use antoniovandre_arcosecante <NÚMERO REAL NÃO PERTENCENTE AO INTERVALO (-1, 1)>."
#define CABECALHO_ESTATISTICAS_MATHARCOCOSSECANTE "arcosecante"

int main (int argc, char *argv [])
	{
	long double secante;
	char * err;

	if (argc != 2 || (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help")))
		{
		printf (ARCOSECANTE_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	if (! strcmp (argv [1], "sobre") || ! strcmp (argv [1], "--sobre"))
		{
		if (! antoniovandre_mathsobre ()) return -1;
		return 0;
		}

	secante = strtold (argv [1], & err);

	if (*err != 0 || (secante < 1 && secante > -1))
		{
		printf (ARCOSECANTE_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	int antoniovandre_precisao_real_valor = antoniovandre_precisao_real (); if (antoniovandre_precisao_real_valor != -1) printf ("%.*Lf\n", antoniovandre_precisao_real_valor, acosl (1 / (long double) secante)); else return -1;

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHARCOCOSSECANTE)) return -1;

	return 0;
	}

