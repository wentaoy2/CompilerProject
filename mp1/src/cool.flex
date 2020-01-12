/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>

#include <string.h>
using namespace std;

/* The compiler assumes these identifiers. */
#define yylval cool_yylval
#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
  if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
    YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;
bool bad_string = false;
bool too_much_string = false;


extern int curr_lineno;

extern YYSTYPE cool_yylval;

/*
 *  Add Your own definitions here
 */

void strcat_c (char *str, char c)
  {
    for (;*str;str++);
    *str++ = c;
    *str++ = 0;
  }

%}

%option noyywrap
%option stack


/*
 * Define names for regular expressions here.
 */

DIGIT       [0-9]+
DARROW        =>
ASSIGN        <-
LE            <=
SYMBOL      [-.(){}:@,;+*/~<=]

%x comment
%x string
%x unterm


%%
  /*extra layer to get line number correct after unterminated_string*/
<unterm>. {
curr_lineno++;
BEGIN(INITIAL);
unput(yytext[0]);
}

  /* handle space */
[ \t\r\f\v]+  {/*do nothing*/}


"--".*          {/*do nothing*/}


  /* count lines */
\n curr_lineno++;

{DIGIT} {
  yylval.symbol = inttable.add_string(yytext);
  return (INT_CONST);
}

  /* handle case insensitivity with ?i: */

(?i:class) {return (CLASS);}
(?i:else)  {return (ELSE);}
(?i:fi)  {return (FI);}
(?i:if)  {return (IF);}
(?i:in)  {return (IN);}
(?i:inherits)  {return (INHERITS);}
(?i:let)  {return (LET);}
(?i:loop)  {return (LOOP);}
(?i:pool)  {return (POOL);}
(?i:then)  {return (THEN);}
(?i:while)  {return (WHILE);}
(?i:case)  {return (CASE);}
(?i:esac)  {return (ESAC);}
(?i:of)  {return (OF);}
(?i:new)  {return (NEW);}
(?i:not)  {return (NOT);}
(?i:isvoid)  {return (ISVOID);}

  /* handle case insensitivity with ?i: and force first letter to be in lowercase */
t(?i:rue)     {cool_yylval.boolean = 1;
	            return BOOL_CONST;}

f(?i:alse)    {
              cool_yylval.boolean = 0;
	            return BOOL_CONST;
              }

  /* single character */
{SYMBOL}    {
    return (int) yytext[0];
}

  /* recognize ids, note that the first letter is case sensitive */
[A-Z][A-Za-z0-9_]* {
	cool_yylval.symbol = idtable.add_string(yytext);
	return TYPEID;
}
[a-z][A-Za-z0-9_]*  {
	cool_yylval.symbol = idtable.add_string(yytext);
	return OBJECTID;
}

  /* multiple characters */
{DARROW}    return (DARROW);
{LE}        return (LE);
{ASSIGN}    return (ASSIGN);


  /* scan comments, use stack to ensure they are nested */
"(*" {
  yy_push_state(comment);
}

<comment>{
  "*)" {
    yy_pop_state();
  }

    /* handle EOF error */
  <<EOF>> {
  BEGIN(INITIAL);
  cool_yylval.error_msg = "EOF appears in comment";
  return ERROR;
  }

  /* skip irrelevant char */
  .    {   }
  \n   { curr_lineno++; }
  "(*" {
    yy_push_state(comment);
  }
}

    /* handle unmatched error */
"*)"   {
    cool_yylval.error_msg = "Unmatched *)";
    return (ERROR);
}


  /* start to scan string */
"\""          { BEGIN(string); strcpy(string_buf,"");
              bad_string = false;
              too_much_string = false;

              }
  /* handle error */
<string>[\0]  {
                cool_yylval.error_msg = "String contains null character";
                bad_string = true;
                return ERROR;
}
  /* handle error */
<string>\\\0  {
                cool_yylval.error_msg = "String contains escaped null character";
                bad_string = true;
                return ERROR;
}
  /* handle normal char */
<string>[^\\\"\n\0]*    {
                /* test too many chars */
                if(strlen(string_buf) + strlen(yytext) < MAX_STR_CONST){
                    strcat(string_buf, yytext);
                }else{
                bad_string = true;
                too_much_string = true;
                }

            }
 /* handle EOF error */
<string><<EOF>> {
      cool_yylval.error_msg = "EOF in string";
      BEGIN(INITIAL);
      return (ERROR);
}


  /* handle special escape characters */
<string>\\\n     {
if(strlen(string_buf)+1 < MAX_STR_CONST){
    strcat_c(string_buf, '\n');
    curr_lineno++;
  }
  else{
  bad_string = true;
  too_much_string = true;
  }
  }

  /* handle escape characters */
<string>\\.     {
if(strlen(string_buf)+1 < MAX_STR_CONST){
    switch (yytext[1])
  {
    case 'n': strcat_c(string_buf, '\n'); break;
    case 't': strcat_c(string_buf, '\t'); break;
    case 'b': strcat_c(string_buf, '\b'); break;
    case 'f': strcat_c(string_buf, '\f'); break;
    default: strcat_c(string_buf, yytext[1]);
  }
  }
  else{
  bad_string = true;
  too_much_string = true;
  }
  }

  /* next line in string */
<string>\n  {


  bad_string = true;

  BEGIN(unterm);

  cool_yylval.error_msg = "Unterminated string";
  return (ERROR);
}

  /* end of string, if we have too many chars we just continue because the error has been printed */
<string>\"      {
                BEGIN(INITIAL);
                if(bad_string){
                if(too_much_string){
                cool_yylval.error_msg = "String too long";
                return (ERROR);
                }}
                else{


                yylval.symbol = stringtable.add_string(string_buf);
                return (STR_CONST);
                }
            }
  /* handle strange char error */
.	{ cool_yylval.error_msg = strdup(yytext); return ERROR; }


 /* need to do error handling for comment and string
  * Define regular expressions for the tokens of COOL here. Make sure, you
  * handle correctly special cases, like:
  *   - Nested comments
  *   - String constants: They use C like systax and can contain escape
  *     sequences. Escape sequence \c is accepted for all characters c. Except
  *     for \n \t \b \f, the result is c.
  *   - Keywords: They are case-insensitive except for the values true and
  *     false, which must begin with a lower-case letter.
  *   - Multiple-character operators (like <-): The scanner should produce a
  *     single token for every such operator.
  *   - Line counting: You should keep the global variable curr_lineno updated
  *     with the correct line number
  */

%%
