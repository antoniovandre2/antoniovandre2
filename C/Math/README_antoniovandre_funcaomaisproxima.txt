Proprietário: Antonio Vandré Pedrosa Furtunato Gomes (bit.ly/antoniovandre_legadoontologico).

Projeto Mathematical Ramblings (mathematicalramblings.blogspot.com).

README do software "antoniovandre_funcaomaisproxima".

Última atualização: 19-06-2024.
________________________________________

O arquivo de pontos deve ser constituído por uma abscissa e uma ordenada, separadas por "DELIMITADORSTRING" (*), os pontos separados por "DELIMITADORSTRING2" (*) ou "CARACTEREFIMLINHA" (*).

Caso hajam dois "DELIMITADORSTRING2" (*) ou "CARACTEREFIMLINHA" (*) consecutivos, o último ponto é repetido nos cálculos. Por exemplo, se "DELIMITADORSTRING" é ',', "DELIMITADORSTRING2" é ';', e o conteúdo do arquivo de pontos é "1, 2; 3, 4;;", para os cálculos, a string será interpretada como "1, 2; 3, 4; 3, 4;".

No último ponto, o posterior "DELIMITADORSTRING2" (*) pode ser suprimido sem efeitos.

O arquivo de funcões deve ser constituído por funções de uma variável "VARIAVELPADRAO" (*) separadas por "DELIMITADORSTRING" (*).

Na última função, o posterior "DELIMITADORSTRING" (*) pode ser suprimido sem efeitos.
_____

(*) Consulte o source "antoniovandre.c" para saber quais são as macros.
