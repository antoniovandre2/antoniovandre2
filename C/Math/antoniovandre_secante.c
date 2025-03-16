// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes (bit.ly/antoniovandre_legadoontologico).

// Projeto Mathematical Ramblings (bit.ly/mathematicalramblings_github).

// Retorna a secante do primeiro argumento.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 03-07-2024.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define SECANTE_MENSAGEM_USO "Use antoniovandre_secante <NÚMERO REAL NO DOMÍNIO>."
#define CABECALHO_ESTATISTICAS_MATHSECANTE "secante"

int main (int argc, char *argv [])
	{
	long double resultado;
	long double arco;
	char * err;
	char * err2;

	int precisao = antoniovandre_precisao_real ();

	if (argc != 2 || (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help")))
		{
		printf (SECANTE_MENSAGEM_USO);
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
		printf (SECANTE_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	resultado = 1 / cosl ((long double) arco);

	int antoniovandre_precisao_real_valor = precisao; if (antoniovandre_precisao_real_valor != -1) printf ("%.*Lf\n", antoniovandre_precisao_real_valor, (long double) resultado); else return -1;

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHSECANTE)) return -1;

	return 0;
	}

