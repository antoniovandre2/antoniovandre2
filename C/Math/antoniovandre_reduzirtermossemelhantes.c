// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes.

// Projeto Mathematical Ramblings.

// Retorna o polinômio com termos semelhantes reduzidos.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 01-07-2020.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define REDUZIRTERMOSSEMELHANTES_MENSAGEM_USO "Use antoniovandre_reduzirtermossemelhantes <MONÔMIO [MONÔMIO ...]>."
#define CABECALHO_ESTATISTICAS_MATHREDUZIRTERMOSSEMELHANTES "reduzirtermossemelhantes"

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
		printf (REDUZIRTERMOSSEMELHANTES_MENSAGEM_USO);
		printf ("\n");
		return -1;
		}

	if (argc == 2 && (! strcmp (argv [1], "sobre") || ! strcmp (argv [1], "--sobre")))
		{
		if (! antoniovandre_mathsobre ()) return -1;
		return 0;
		}

	strf = (char *) malloc (TAMANHO_BUFFER_PHRASE);

	strf = antoniovandre_reduzirtermossemelhantes (argvb);

	if (! strcmp (strf, STRINGSAIDAERRO))
		{
		printf (REDUZIRTERMOSSEMELHANTES_MENSAGEM_USO);
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

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHREDUZIRTERMOSSEMELHANTES)) return -1;

	return 0;
	}

