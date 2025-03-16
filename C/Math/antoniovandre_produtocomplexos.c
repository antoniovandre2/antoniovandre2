// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes (bit.ly/antoniovandre_legadoontologico).

// Projeto Mathematical Ramblings (bit.ly/mathematicalramblings_github).

// Retorna o produto dos números complexos passados como argumentos.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 03-07-2024.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define PRODUTOCOMPLEXO_MENSAGEM_USO "Use antoniovandre_produtocomplexos <<PARTE REAL> <PARTE IMAGINÁRIA> [<DELIMITADOR> <PARTE REAL> <PARTE IMAGINÁRIA> [...]]>."
#define CABECALHO_ESTATISTICAS_PRODUTOCOMPLEXO "produtocomplexos"

int main (int argc, char *argv [])
	{
	char * strf;
	char * strfreal;
	char * strfimg;
	NUMEROCOMPLEXO result;
	NUMEROCOMPLEXO numeroscomplexosbuffer [(int) (ceil ((argc - 2) / 3) + 1)];
	int shift = 0;
	int i;
	int j;
	int flag;
	int flag2;
	char * err;

	int precisao = antoniovandre_precisao_real ();

	if (argc == 1 || (argc == 2 && (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help"))))
		{
		printf (PRODUTOCOMPLEXO_MENSAGEM_USO);
		printf ("\nDelimitador: \"%c\".", DELIMITADORSTRING3);
		printf ("\n");
		return -1;
		}

	if (argc == 2 && (! strcmp (argv [1], "sobre") || ! strcmp (argv [1], "--sobre")))
		{
		if (! antoniovandre_mathsobre ()) return -1;
		return 0;
		}

	flag = 0;

	for (i = 1; i < argc; i++)
		{
		flag2 = 0;

		if ((flag == 0) && (i % 3 != 1))
			{
			printf (PRODUTOCOMPLEXO_MENSAGEM_USO);
			printf ("\nDelimitador: \"%c\".", DELIMITADORSTRING3);
			printf ("\n");
			return -1;
			}

		if (argv [i][0] == DELIMITADORSTRING3)
			{
			flag = 0;
			continue;
			}

		if (flag == 0)
			{
			numeroscomplexosbuffer [shift].real = strtold (argv [i], & err);

			if (* err != 0)
				{
				printf (PRODUTOCOMPLEXO_MENSAGEM_USO);
				printf ("\nDelimitador: \"%c\".", DELIMITADORSTRING3);
				printf ("\n");
				return -1;
				}

			if ((numeroscomplexosbuffer [shift].real > VALOR_MAX) || (numeroscomplexosbuffer [shift].real < (-1) * VALOR_MAX))
				{
				printf (MENSAGEM_ERRO_OVER);
				printf ("\n");
				return -1;
				}

			flag = 1;
			}
		else
			{
			numeroscomplexosbuffer [shift].img = strtold (argv [i], & err);

			if (* err != 0)
				{
				printf (PRODUTOCOMPLEXO_MENSAGEM_USO);
				printf ("\nDelimitador: \"%c\".", DELIMITADORSTRING3);
				printf ("\n");
				return -1;
				}

			if ((numeroscomplexosbuffer [shift].img > VALOR_MAX) || (numeroscomplexosbuffer [shift].img < (-1) * VALOR_MAX))
				{
				printf (MENSAGEM_ERRO_OVER);
				printf ("\n");
				return -1;
				}

			shift++;

			flag2 = 1;
			}
		}

	if (flag2 == 0)
		{
		printf (PRODUTOCOMPLEXO_MENSAGEM_USO);
		printf ("\nDelimitador: \"%c\".", DELIMITADORSTRING3);
		printf ("\n");
		return -1;
		}

	result = antoniovandre_produtocomplexo (numeroscomplexosbuffer, shift);

	strf = (char *) malloc (TAMANHO_BUFFER_PHRASE);
	strfreal = (char *) malloc (TAMANHO_BUFFER_PHRASE);
	strfimg = (char *) malloc (TAMANHO_BUFFER_PHRASE);

	strcpy (strfreal, antoniovandre_numeroparastring (result.real, precisao));
	strcpy (strfimg, antoniovandre_numeroparastring (fabsl (result.img), precisao));

	if ((! strcmp (strfreal, STRINGSAIDAERRO)) || (! strcmp (strfimg, STRINGSAIDAERRO)))
		{
		printf (PRODUTOCOMPLEXO_MENSAGEM_USO);
		printf ("\nDelimitador: \"%c\".", DELIMITADORSTRING3);
		printf ("\n");
		return -1;
		}
	else if ((! strcmp (strfreal, STRINGSAIDAERROOVER)) || (! strcmp (strfimg, STRINGSAIDAERROOVER)))
		{
		printf (MENSAGEM_ERRO_OVER);
		printf ("\n");
		return -1;
		}

	strcat (strf, strfreal);
	if (result.img >= 0) strcat (strf, " + "); else strcat (strf, " - ");
	strcat (strf, strfimg);
	strcat (strf, "i");

	printf ("%s\n", strf);

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_PRODUTOCOMPLEXO)) return -1;

	return 0;
	}
