// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes (bit.ly/antoniovandre_legadoontologico).

// Projeto Mathematical Ramblings (bit.ly/mathematicalramblings_github).

// Retorna a derivada da função de uma variável, passados como argumentos a função e a expressão para o ponto.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 08-07-2024.

#include "/home/antoniovandre/software_sources/C/antoniovandre.c"

#define DERIVADA_MENSAGEM_USO "Use antoniovandre_derivada <FUNÇÃO DE UMA VARIÁVEL NA VARIÁVEL DE SUBSTITUIÇÃO, DIFERENCIÁVEL NO PONTO> <EXPRESSÃO PARA O PONTO>."
#define DERIVADA_MENSAGEM_ERRO_SECUNDARIA "Erro interno em decorrência de erros de maus parâmetros ou valores elevados."
#define CABECALHO_ESTATISTICAS_MATHDERIVADA "derivada"

int main (int argc, char *argv [])
	{
	char * strf;
	char * argvb;
	long double ponto;
	int i;
	int j;
	char * err;
	int precisao = antoniovandre_precisao_real ();

	if (argc != 3 || (argc == 2 && (! strcmp (argv [1], "h") || ! strcmp (argv [1], "help") || ! strcmp (argv [1], "-h") || ! strcmp (argv [1], "--help"))))
		{
		printf (DERIVADA_MENSAGEM_USO);
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

	ponto = strtold (antoniovandre_eval (argv [2], precisao), & err);

	if (* err != 0)
		{
		printf (DERIVADA_MENSAGEM_USO);
		printf ("\n");
		printf ("Variável de substituição: %c.\n", VARIAVELDESUBSTITUICAO);
		return -1;
		}

	strf = (char *) malloc (TAMANHO_BUFFER_PHRASE);

	strf = antoniovandre_derivada (argvb, ponto);

	if (! strcmp (strf, STRINGSAIDAERRO))
		{
		printf (DERIVADA_MENSAGEM_ERRO_SECUNDARIA);
		printf ("\n");
		printf (DERIVADA_MENSAGEM_USO);
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

	if (! antoniovandre_salvarmathestatisticas (CABECALHO_ESTATISTICAS_MATHDERIVADA)) return -1;

	return 0;
	}

