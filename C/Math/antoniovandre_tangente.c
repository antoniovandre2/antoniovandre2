// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes.

// Projeto Mathematical Ramblings.

// Retorna a tangente do primeiro argumento.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 03-07-2024.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define TANGENTE_MENSAGEM_USO "Use antoniovandre_tangente <NÚMERO REAL NO DOMÍNIO>."
#define CABECALHO_ESTATISTICAS_MATHTANGENTE "tangente"

int main (int argc, char *argv [])
	{
	long double arco;
	char * err;
	char * err2;

	int precisao = antoniovandre_precisao_real ();

	if (argc != 2 || (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help")))
		{
		printf (TANGENTE_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	if (! strcmp (argv [1], "sobre") || ! strcmp (argv [1], "--sobre"))
		{
		if (! antoniovandre_mathsobre ()) return -1;
		return 0;
		}

	arco = strtold (argv [1], & err);

	if ((*err != 0) || (fmodl ((long double) arco, M_PIl) == strtold (antoniovandre_numeroparastring (M_PI_2l, precisao), & err2)))
		{
		printf (TANGENTE_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	int antoniovandre_precisao_real_valor = precisao; if (antoniovandre_precisao_real_valor != -1) printf ("%.*Lf\n", antoniovandre_precisao_real_valor, tanl ((long double) arco)); else return -1;

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHTANGENTE)) return -1;

	return 0;
	}

