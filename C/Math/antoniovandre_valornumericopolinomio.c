// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes (bit.ly/antoniovandre_legadoontologico).

// Projeto Mathematical Ramblings (bit.ly/mathematicalramblings_github).

// Retorna o valor numérico de um polinômio para dados valores das variáveis, que pode ser uma constante ou outro polinômio.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 12-07-2020.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define VALORNUMERICOPOLINOMIO_MENSAGEM_USO "Use antoniovandre_valornumericopolinomio <MONÔMIO [MONÔMIO ...] [<VARIÁVEL>=<VALOR> [<VARIÁVEL>=<VALOR> ...]]>."
#define CABECALHO_ESTATISTICAS_MATHVALORNUMERICOPOLINOMIO "valornumericopolinomio"

int main (int argc, char *argv [])
	{
	char * strf;
	char * argvb;
	int i;
	int j;
	int shiftb = 0;

	argvb = (char *) malloc (TAMANHO_BUFFER_PHRASE);

	for (i = 1; i < argc; i++)
		{
		for (j = 0; j < strlen (argv [i]); j++) argvb [shiftb++] = argv [i][j];

		if (i < argc - 1) argvb [shiftb++] = DELIMITADORSTRING;
		}

	if (argc == 1 || (argc == 2 && (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help"))))
		{
		printf (VALORNUMERICOPOLINOMIO_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	if (argc == 2 && (! strcmp (argv [1], "sobre") || ! strcmp (argv [1], "--sobre")))
		{
		if (! antoniovandre_mathsobre ()) return -1;
		return 0;
		}

	strf = (char *) malloc (TAMANHO_BUFFER_PHRASE);

	strf = antoniovandre_valornumericopolinomio (argvb);

	if (! strcmp (strf, STRINGSAIDAERRO))
		{
		printf (VALORNUMERICOPOLINOMIO_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}
	else if (! strcmp (strf, STRINGSAIDAERROOVER))
		{
		printf (MENSAGEM_ERRO_OVER);
		printf ("\n");
		return -1;
		}
	else
		printf ("%s\n", strf);

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHVALORNUMERICOPOLINOMIO)) return -1;

	return 0;
	}

