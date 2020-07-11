%{
    #include<stdio.h>
    #include "label.c"

    int parse;
    int line;
    int newlineAfterLabel;
    char* labelName;
    FILE* targetFile;
%}

%%

[L][0-9]+":"            {
                            if(parse == 0)
                            {
                                yytext[yyleng - 1] = '\0';
                                labelName = strdup(yytext);
                                printf("read: %s %d\n", yytext, line);
                                insertLabel(labelName, line);
                                line-=2;
                            }
                            else
                            {
                                newlineAfterLabel = 1;
                            }
                        }

[L][0-9]+[^:]           {
                            if(parse == 1)
                            {
                                yytext[yyleng - 1] = '\0';
                                printf("find: %s %d\n", yytext, getLabelAddress(yytext));
                                fprintf(targetFile, "%d\n", getLabelAddress(yytext));
                            }
                            else
                            {
                                line += 2;
                            }
                        }

"MAIN:"                 {
                            if(parse == 0)
                            {
                                yytext[yyleng - 1] = '\0';
                                labelName = strdup(yytext);
                                printf("read: %s %d\n", yytext, line);
                                insertLabel(labelName, line);
                                line-=2;
                            }
                            else
                            {
                                newlineAfterLabel = 1;
                            }
                        }

"MAIN"[^:]              {
                            if(parse == 1)
                            {
                                yytext[yyleng - 1] = '\0';
                                printf("find: %s %d\n", yytext, getLabelAddress(yytext));
                                fprintf(targetFile, "%d\n", getLabelAddress(yytext));
                            }
                            else
                            {
                                line += 2;
                            }
                        }

[F][0-9]+":"            {
                            if(parse == 0)
                            {
                                yytext[yyleng - 1] = '\0';
                                labelName = strdup(yytext);
                                printf("read: %s %d\n", yytext, line);
                                insertLabel(labelName, line);
                                line-=2;
                            }
                            else
                            {
                                newlineAfterLabel = 1;
                            }
                        }

[F][0-9]+[^:]           {
                            if(parse == 1)
                            {
                                yytext[yyleng - 1] = '\0';
                                printf("find: %s %d\n", yytext, getLabelAddress(yytext));
                                fprintf(targetFile, "%d\n", getLabelAddress(yytext));
                            }
                            else
                            {
                                line += 2;
                            }
                        }

[\n]                    {
                            if(parse == 1)
                            {
                                if(newlineAfterLabel == 1)
                                    newlineAfterLabel = 0;
                                else
                                    fprintf(targetFile, "\n");
                            }
                            else
                            {
                                if(line < 2056)
                                    line++;
                                else
                                    line += 2;
                            }
                        }

.                       {
                            if(parse == 1)
                            {
                                fprintf(targetFile, "%s", yytext);
                            }
                        }
\"(\\.|[^\\"])*\"       {
                            if(parse == 1)
                            {
                                fprintf(targetFile, "%s", yytext);
                            }
                        }

%%

int yywrap()
{
    if(parse == 1)
    {
        return 1;
    }
    else
    {
        yyin = fopen("../test.xsm", "r");
        parse = 1;
        return 0;
    }
}

int main()
{
    head = NULL;
    parse = 0;
    line = 2048;
    newlineAfterLabel = 0;
    targetFile = fopen("../test.o", "w");
    yyin = fopen("../test.xsm", "r");
    yylex();
    return 0;
}