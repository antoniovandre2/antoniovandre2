// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes (bit.ly/antoniovandre_legadoontologico).

// Projeto Mathematical Ramblings (bit.ly/mathematicalramblings_github).

// Retorna o primeiro argumento numérico elevado ao segundo argumento numérico.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 09-07-2020.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define POTENCIA_MENSAGEM_USO "Use antoniovandre_potencia <NÚMERO REAL> <NÚMERO REAL DE MODO À POTENCIA RETORNAR UM NÚMERO REAL>."
#define CABECALHO_ESTATISTICAS_MATHPOTENCIA "potencia"

int main (int argc, char *argv [])
	{
	long double resultado;
	long double base;
	long double expoente;
	char * err1;
	char * err2;

	if (argc == 2 && (! strcmp (argv [1], "sobre") || ! strcmp (argv [1], "--sobre")))
		{
		if (! antoniovandre_mathsobre ()) return -1;
		return 0;
		}

	if (argc != 3 || (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help")))
		{
		printf (POTENCIA_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	base = strtold (argv [1], & err1);
	expoente = strtold (argv [2], & err2);

	if (*err1 != 0)
		{
		printf (POTENCIA_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	if (*err2 != 0)
		{
		printf (POTENCIA_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	resultado = powl (base, expoente);

	if (isnan (resultado) || isinf (resultado))
		{
		printf (POTENCIA_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	int antoniovandre_precisao_real_valor = antoniovandre_precisao_real (); if (antoniovandre_precisao_real_valor != -1) printf ("%.*Lf\n", antoniovandre_precisao_real_valor, (long double) resultado); else return -1;

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHPOTENCIA)) return -1;

	return 0;
	}

