%option noyywrap
%option yylineno
%{
	#define YYSTYPE std::string
	#include <stdio.h>
	#include <string>
	#include "bison.tab.h"

	bool comment = false;
	bool tab = false;

	extern void yyerror (char const *);
	int yylex();
%}
%%

[\n\t ]		{}

\[			{
	if(comment)
		printf("Komentarz zagnieżdżony\n");
	else
		comment = true;
}
\]			{
	if(comment)
		comment = false;
	else
		printf("Zamknięcie komentarza bez otwarcia\n");
}

"("			{
	if(tab)
		printf("Niepoprawny znak \"(\"");
	else{
		tab = true;
		return OPEN;
	}
}
")"			{
	if(tab){
		tab = false;
		return CLOSE;
	}
	else
		printf("Niepoprawny znak \")\"");
}

":"		{
	if(tab){
		return RANGE;
	}
}

DECLARE		{if(!comment) return DECLARE; 	}
IN 			{if(!comment) return IN; 		}
END 		{if(!comment) return END; 		}
IF 			{if(!comment) return IF; 		}
THEN 		{if(!comment) return THEN; 		}
ELSE 		{if(!comment) return ELSE; 		}
ENDIF 		{if(!comment) return ENDIF; 	}
WHILE	 	{if(!comment) return WHILE; 	}
DO 			{if(!comment) return DO; 		}
ENDWHILE 	{if(!comment) return ENDWHILE; 	}
ENDDO 		{if(!comment) return ENDDO; 	}
FOR 		{if(!comment) return FOR; 		}
FROM 		{if(!comment) return FROM; 		}
TO 			{if(!comment) return TO; 		}
ENDFOR 		{if(!comment) return ENDFOR; 	}
DOWNTO 		{if(!comment) return DOWNTO; 	}
READ 		{if(!comment) return READ; 		}
WRITE 		{if(!comment) return WRITE; 	}
";"			{if(!comment) return SC;		}
"+"			{if(!comment) return PLUS;		}
"-"			{if(!comment) return MINUS;		}
"*"			{if(!comment) return MULTI;		}
"/"			{if(!comment) return DIV;		}
"%"			{if(!comment) return MOD;		}
"="			{if(!comment) return EQ;		}
"!="		{if(!comment) return NEQ;		}
"<"			{if(!comment) return LES;		}
">"			{if(!comment) return BIG;		}
"<="		{if(!comment) return LESEQ;		}
">="		{if(!comment) return BIGEQ;		}
":="		{if(!comment) return ASSIGN;	}
"."		{if(!comment) printf("Niepoprawny znak \".\"");}
"?"		{if(!comment) printf("Niepoprawny znak \"?\"");}
"^"		{if(!comment) printf("Niepoprawny znak \"^\"");}

[_a-z]+ 	{
	yylval = (yytext);
	if(!comment)
		return PIDENTIFIER;
}
[_A-Z]+		{
	yylval = (yytext);
	if(!comment)
		return PIDENTIFIER;
}

[0-9]+		{
	yylval = (yytext);
	if(!comment)
		return NUM;
}
