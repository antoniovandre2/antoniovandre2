// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes.

// Projeto Mathematical Ramblings.

// Retorna a integral definida da função de uma variável, passados como argumentos a função, o limite inferior, e o limite superior.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 08-07-2024.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define INTEGRALDEFINIDA_MENSAGEM_USO "Use antoniovandre_integraldefinida <FUNÇÃO DE UMA VARIÁVEL NA VARIÁVEL DE SUBSTITUIÇÃO> <EXPRESSÃO PARA O LIMITE INFERIOR> <EXPRESSÃO PARA O LIMITE SUPERIOR>."
#define CABECALHO_ESTATISTICAS_MATHINTEGRALDEFINIDA "integraldefinida"

int main (int argc, char *argv [])
	{
	char * strf;
	char * argvb;
	long double a;
	long double b;
	int i;
	int j;
	char * err;
	int precisao = antoniovandre_precisao_real ();

	if (argc != 4 || (argc == 2 && (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help"))))
		{
		printf (INTEGRALDEFINIDA_MENSAGEM_USO);
		printf ("\n");
		printf ("Variável de substituição: %c.\n", VARIAVELDESUBSTITUICAO);
		return -1;
		}

	if (argc == 2 && (! strcmp (argv [1], "sobre") || ! strcmp (argv [1], "--sobre")))
		{
		if (! antoniovandre_mathsobre ()) return -1;
		return 0;
		}

	argvb = (char *) malloc (TAMANHO_BUFFER_PHRASE);

	strcpy (argvb, argv [1]);

	a = strtold (antoniovandre_eval (argv [2], precisao), & err);

	if (* err != 0)
		{
		printf (INTEGRALDEFINIDA_MENSAGEM_USO);
		printf ("\n");
		printf ("Variável de substituição: %c.\n", VARIAVELDESUBSTITUICAO);
		return -1;
		}

	b = strtold (antoniovandre_eval (argv [3], precisao), & err);
	if (* err != 0)
		{
		printf (INTEGRALDEFINIDA_MENSAGEM_USO);
		printf ("\n");
		printf ("Variável de substituição: %c.\n", VARIAVELDESUBSTITUICAO);
		return -1;
		}

	strf = (char *) malloc (TAMANHO_BUFFER_PHRASE);

	strf = antoniovandre_integraldefinida (argvb, a, b);

	if (! strcmp (strf, STRINGSAIDAERRO))
		{
		printf (INTEGRALDEFINIDA_MENSAGEM_USO);
		printf ("\n");
		printf ("Variável de substituição: %c.\n", VARIAVELDESUBSTITUICAO);
		return -1;
		}
	else if (! strcmp (strf, STRINGSAIDAERROOVER))
		{
		printf (MENSAGEM_ERRO_OVER);
		printf ("\n");
		return -1;
		}
	else
		{
		printf ("Trata-se de uma aproximação:\n");
		printf ("%s\n", strf);
		}

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHINTEGRALDEFINIDA)) return -1;

	return 0;
	}

