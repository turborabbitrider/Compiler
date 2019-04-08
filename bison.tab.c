/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bison.y" /* yacc.c:339  */

	#define YYSTYPE std::string
	#include <stdio.h>
	#include <iostream>
	#include <stack>
	#include <vector>
	#include <sstream>


	using namespace std;

	struct var{
		string name;
		long long int value;
	};

	struct tab{
		string name;
		vector<long long int> table;
		int min;
		int max;
	};
	
	void yyerror(const char *);
	int yylex();
	extern int yylineno;

	void finish();
	int find_var(string, vector<var>);
	int find_tab(string, vector<tab>);
	tab tab_cons(const char*, const char*, string);
	void cng_var(string, long long int, vector<var> *);
	long long int *get_var_tab(string, string, vector<tab>, vector<var>);
	long long int *get_var_tab_old(string, vector<tab>, vector<var>);
	long long int get_var_val(string, vector<var>);
	long long int get_num(string);
	long long int sanitize_val(string, vector<var>, vector<tab>, string);
	long long int adder(string, string);
	long long int subber(string, string);
	void multiplier(string, string);
	void divider(string, string);
	void modder(string, string);
	void is_equal(string, string);
	void is_nequal(string, string);
	void is_less(string, string);
	void is_bigg(string, string);
	void is_lesseq(string, string);
	void is_biggeq(string, string);
	void reset(string);
	int decrypt_reg(string);
	int read_in(string, vector<tab>, vector<var>);
	void write_out(string);
	string get_tab_name(string);
	void tab_write(string, string);
	void var_write(string, string);
	long long int get_val_num(string);
	void get_val_mem(string, string);
	string next_load_reg();
	int setup_val(string, long long int);
	void set_last_count_reg();
	void free_last_count_reg();
	int get_val_from_mem(string);
	void load_var_to_reg(string, string);
	int calc_addr(string);
	string encrypt_reg(int);

	void get(string);
	void put(string);
	void load(string);
	void store(string);
	void copy(string, string);
	void add(string, string);
	void sub(string, string);
	void half(string);
	void inc(string);
	void dec(string);
	void jump(int);
	void jzero(string, int);
	void jodd(string, int);
	void halt();

	long long int k = 0;
	vector<string> commands;
	vector<var> variables;
	vector<tab> tables;
	vector<var> for_variables;
	int tab_mode = 0;
	vector<long long int> regs = vector<long long int>(8,0);
	long long int last_calculated = -1;
	int last_loaded = 0;
	string last_reg = "G";
	string last_count_reg = "F";
	int count_check = 0;
	int read_var_check = 0;
	vector<long long int> if_beginers;
	vector<long long int> if_enders;
	vector<long long int> while_beginers;
	vector<long long int> while_middlers;
	vector<long long int> while_enders;
	vector<long long int> for_markers;
	vector<long long int> for_enders;
	int if_counter = -1;
	long long int for_counter;

#line 171 "bison.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison.tab.h".  */
#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DECLARE = 258,
    IN = 259,
    END = 260,
    IF = 261,
    THEN = 262,
    ELSE = 263,
    ENDIF = 264,
    WHILE = 265,
    DO = 266,
    ENDWHILE = 267,
    ENDDO = 268,
    FOR = 269,
    FROM = 270,
    TO = 271,
    DOWNTO = 272,
    ENDFOR = 273,
    READ = 274,
    WRITE = 275,
    SC = 276,
    PLUS = 277,
    MINUS = 278,
    MULTI = 279,
    DIV = 280,
    MOD = 281,
    EQ = 282,
    NEQ = 283,
    LES = 284,
    BIG = 285,
    LESEQ = 286,
    BIGEQ = 287,
    ASSIGN = 288,
    OPEN = 289,
    CLOSE = 290,
    RANGE = 291,
    NUM = 292,
    PIDENTIFIER = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 261 "bison.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   127,   138,   151,   154,   155,   158,   228,
     228,   241,   243,   241,   254,   254,   261,   300,   320,   261,
     370,   405,   429,   370,   498,   502,   526,   526,   541,   541,
     556,   557,   574,   590,   609,   637,   658,   673,   688,   703,
     718,   733,   750,   751,   762,   770,   784
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DECLARE", "IN", "END", "IF", "THEN",
  "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "ENDDO", "FOR", "FROM", "TO",
  "DOWNTO", "ENDFOR", "READ", "WRITE", "SC", "PLUS", "MINUS", "MULTI",
  "DIV", "MOD", "EQ", "NEQ", "LES", "BIG", "LESEQ", "BIGEQ", "ASSIGN",
  "OPEN", "CLOSE", "RANGE", "NUM", "PIDENTIFIER", "$accept", "program",
  "declarations", "commands", "command", "$@1", "$@2", "$@3", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "ifcommands", "$@11", "$@12",
  "expression", "condition", "value", "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -27

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-27)))

#define YYTABLE_NINF -29

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -27,    17,    -1,   -27,   148,   -12,    -4,   -27,   -15,
      -8,    -4,    -7,     1,   -27,    16,    18,   -27,    20,   -27,
     -27,   143,   -27,   148,    23,    11,    21,     9,   -27,   -27,
      -4,    -4,    19,    52,    -4,    -4,    -4,    -4,    -4,    -4,
      30,    -4,   -27,   -27,    25,    28,   -27,    44,    48,    39,
     148,   -27,   -27,   -27,   -27,   -27,   -27,    -4,    50,   -27,
     -27,    73,   -27,    -4,    -4,    -4,    -4,    -4,    51,     5,
     -27,    72,    71,    75,   148,   -27,   -27,   -27,   -27,   -27,
      77,    81,    84,   -27,    -4,    -4,    42,   -27,   148,   -27,
     -27,   -27,   -27,   102,    89,    90,   -27,   -27,   -27,   148,
     148,   106,   131,   -27,   -27
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     1,    11,     0,     0,    14,     0,
       0,     0,    44,    11,     7,     0,     0,     3,     0,    42,
       9,     0,    43,    11,     0,     0,     0,     0,     2,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,     0,     0,    12,     0,    30,     0,
      11,    36,    37,    38,    39,    40,    41,     0,    16,    46,
      45,     0,     8,     0,     0,     0,     0,     0,     0,    11,
      10,     0,     0,     0,    11,    31,    32,    33,    34,    35,
       0,     0,     0,    15,     0,     0,    11,     4,    11,    29,
      17,    21,    13,    11,     0,     0,    27,    18,    22,    11,
      11,    11,    11,    19,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -27,   -27,   -27,   -22,   -11,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -26,
      68,    -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    13,    14,    33,    15,    61,    23,    72,
      94,    99,    73,    95,   100,    70,    81,    82,    47,    20,
      21,    22
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      16,    40,    29,     5,    46,    25,    28,     7,    16,    17,
       1,     7,     8,   -26,   -28,     9,     8,     4,    16,     9,
      10,    11,    18,    24,    10,    11,    30,    27,    69,    29,
      12,    71,    42,    19,    12,    16,     7,     6,    41,    12,
      57,     8,    43,    12,     9,    16,    44,    45,     7,    10,
      11,    31,    86,     8,    92,    49,     9,    32,    29,    50,
      59,    10,    11,    60,    16,    62,    93,   -20,    12,    16,
      63,    64,    65,    66,    67,    29,    68,   101,   102,    26,
      12,    16,    29,    16,    74,    83,    80,    84,    16,    88,
      29,    29,    85,    89,    16,    16,    16,    16,    87,    48,
      97,    98,    51,    52,    53,    54,    55,    56,     7,    58,
       0,    96,     7,     8,     0,     0,     9,     8,     0,     0,
       9,    10,    11,     0,   103,    10,    11,     0,     0,     0,
       0,    75,    76,    77,    78,    79,     0,     7,     0,     0,
      12,     0,     8,     0,    12,     9,     0,     0,     0,   104,
      10,    11,    90,    91,     7,     0,     0,     0,     0,     8,
       0,     0,     9,     0,     0,     0,     0,    10,    11,    12,
      34,    35,    36,    37,    38,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12
};

static const yytype_int8 yycheck[] =
{
       5,    23,    13,     4,    30,    10,     5,     6,    13,    21,
       3,     6,    11,     8,     9,    14,    11,     0,    23,    14,
      19,    20,    34,    38,    19,    20,    10,    34,    50,    40,
      38,    57,    21,    37,    38,    40,     6,    38,    15,    38,
      10,    11,    21,    38,    14,    50,    37,    38,     6,    19,
      20,    33,    74,    11,    12,    36,    14,    37,    69,     7,
      35,    19,    20,    35,    69,    21,    88,    17,    38,    74,
      22,    23,    24,    25,    26,    86,    37,    99,   100,    11,
      38,    86,    93,    88,    11,    13,    35,    16,    93,     8,
     101,   102,    17,     9,    99,   100,   101,   102,    21,    31,
      11,    11,    34,    35,    36,    37,    38,    39,     6,    41,
      -1,     9,     6,    11,    -1,    -1,    14,    11,    -1,    -1,
      14,    19,    20,    -1,    18,    19,    20,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    -1,     6,    -1,    -1,
      38,    -1,    11,    -1,    38,    14,    -1,    -1,    -1,    18,
      19,    20,    84,    85,     6,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    20,    38,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    40,    41,     0,     4,    38,     6,    11,    14,
      19,    20,    38,    42,    43,    45,    60,    21,    34,    37,
      58,    59,    60,    47,    38,    60,    59,    34,     5,    43,
      10,    33,    37,    44,    27,    28,    29,    30,    31,    32,
      42,    15,    21,    21,    37,    38,    58,    57,    59,    36,
       7,    59,    59,    59,    59,    59,    59,    10,    59,    35,
      35,    46,    21,    22,    23,    24,    25,    26,    37,    42,
      54,    58,    48,    51,    11,    59,    59,    59,    59,    59,
      35,    55,    56,    13,    16,    17,    42,    21,     8,     9,
      59,    59,    12,    42,    49,    52,     9,    11,    11,    50,
      53,    42,    42,    18,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    42,    42,    43,    44,
      43,    45,    46,    43,    47,    43,    48,    49,    50,    43,
      51,    52,    53,    43,    43,    43,    55,    54,    56,    54,
      57,    57,    57,    57,    57,    57,    58,    58,    58,    58,
      58,    58,    59,    59,    60,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     8,     0,     2,     1,     4,     0,
       5,     0,     0,     7,     0,     6,     0,     0,     0,    12,
       0,     0,     0,    12,     3,     3,     0,     5,     0,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 120 "bison.y" /* yacc.c:1646  */
    {//cout <<"ggggg";
halt();
finish(); 
//printf("HALT\n");
}
#line 1425 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 127 "bison.y" /* yacc.c:1646  */
    { //cout << "zxvc";
							if(find_var((yyvsp[-1]), variables) == -1 && find_tab((yyvsp[-1]), tables) == -1){
								var v;
								v.name = (yyvsp[-1]);
								v.value = 0;
								variables.push_back(v);
							}else{
								printf("Blad: powtorna deklaracja zmiennej: %s \n", (yyvsp[-1]).c_str());
								return 0;
							}
						}
#line 1441 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 138 "bison.y" /* yacc.c:1646  */
    {		//printf("%s,%s,%s,%s,%s,%s,%s", $1.c_str(),$2.c_str(),$3.c_str(),$4.c_str(),$5.c_str(),$6.c_str(),$7.c_str());
							if(get_num((yyvsp[-4])) > get_num((yyvsp[-2]))){
								printf("Blad: niepoprawne wymiary tablicy: %s \n", (yyvsp[-6]).c_str());
								return 0;
							}else if(find_tab((yyvsp[-6]), tables) == -1 && find_var((yyvsp[-6]), variables) == -1){
								tab t =tab_cons((yyvsp[-2]).c_str(),(yyvsp[-4]).c_str(), (yyvsp[-6]));
								tables.push_back(t);
							}
							else{
								printf("Blad: powtorna deklaracja zmiennej: %s \n", (yyvsp[-6]).c_str());
								return 0;
							}
						}
#line 1459 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 159 "bison.y" /* yacc.c:1646  */
    {//cout << "juz nie wiem";
				//printf("%s, %s, %s", $1.c_str(), $2.c_str(), $3.c_str());
				if(find_var((yyvsp[-3]), variables) == -1){
					//cout << get_tab_name($1);
					//cout << $1;
					if(find_tab(get_tab_name((yyvsp[-3])), tables) == -1){
						printf("Blad: zmienna %s niezadeklarowana\n", (yyvsp[-3]).c_str());
						return 0;
					}else{//cout << "AAAAAAAAAAAAAAAAA";
						//put(last_reg);
						if(count_check != 0){
							//put(last_count_reg);
							//cout << "tab count assign";
							tab_write((yyvsp[-3]), last_count_reg);
							free_last_count_reg();
						}else
							if(read_var_check != 0){
								load_var_to_reg((yyvsp[-1]), "F");
								//put("F");
								tab_write((yyvsp[-3]), "F");
								read_var_check = 0;
								//cout << $3 << endl;
								//cout << num << "   " << $3;
								//cout << to_string(num);
								//setup_val("H", get_num($3));
								//put("H");
						}else if(get_num((yyvsp[-1])) != -1){
							//setup_val("H", get_num($3));
							//put("H");
							tab_write((yyvsp[-3]), (yyvsp[-1]));
						}
							else{
								printf("Blad: niepoprawna zmienna do przypisania: %s\n", (yyvsp[-1]).c_str());
								return 0;
							}
					}
				}else{
					//cout << count_check << "    " << $3 << "    " << read_var_check << "    ";
					if(count_check != 0){
						//cout << last_count_reg;
						//put(last_count_reg);
						var_write((yyvsp[-3]), last_count_reg);
						free_last_count_reg();
					}else{
						//cout << "num";
						if(read_var_check != 0){
							load_var_to_reg((yyvsp[-1]), last_reg);
							
							var_write((yyvsp[-3]), last_reg);
							read_var_check = 0;
							//cout << endl << endl << $3;
							//cout << to_string(num);
							//setup_val("H", get_num($3));
							//put(last_reg);
						}else if(get_num((yyvsp[-1])) != -1){
							//cout << $3 << "    " << get_num($3) << endl;
							//setup_val("H", get_num($3));
							//put("H");
							var_write((yyvsp[-3]), (yyvsp[-1]));
							
						}
						else{
							printf("Blad: niepoprawna zmienna do przypisania: %s\n", (yyvsp[-1]).c_str());
							return 0;
						}
					}
				}
			//put("A");
}
#line 1533 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 228 "bison.y" /* yacc.c:1646  */
    {
	if_beginers.push_back(k);
	k++;
	if_counter++;
	//cout << k;
	//put("B");
	//put("B");
}
#line 1546 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 236 "bison.y" /* yacc.c:1646  */
    {
	//put("A");
	//put("A");
	//put("A");
}
#line 1556 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 241 "bison.y" /* yacc.c:1646  */
    {while_beginers.push_back(k);
						//put("B");
					}
#line 1564 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 243 "bison.y" /* yacc.c:1646  */
    { while_middlers.push_back(k); k++; for_counter++;}
#line 1570 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 243 "bison.y" /* yacc.c:1646  */
    {
	jump(while_beginers[while_beginers.size() - 1]);
	vector<string>::iterator pos = commands.begin();
	stringstream ss;
	ss << "JZERO B " << k;		//chyba +1
	string ss_to_s = ss.str();
	commands.insert(pos + while_middlers[while_middlers.size() - 1] + 1 - for_counter, ss_to_s); 
	while_beginers.pop_back();
	while_middlers.pop_back();
	for_counter--;
}
#line 1586 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 254 "bison.y" /* yacc.c:1646  */
    {while_beginers.push_back(k);
						//put("B");
					}
#line 1594 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 256 "bison.y" /* yacc.c:1646  */
    {
	jzero("B", k + 2);
	jump(while_beginers[while_beginers.size() - 1]);
	while_beginers.pop_back();
}
#line 1604 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 261 "bison.y" /* yacc.c:1646  */
    {
	//cout << get_num($4);
	//put("A");
	//put("A");
	//put("A");
	//cout << find_tab($2, tables) << endl << find_var($2, variables);
	if(find_tab((yyvsp[-2]), tables) == -1 && find_var((yyvsp[-2]), variables) == -1){
		var v;
		v.name = (yyvsp[-2]);

///////XXX////////////sprawdzanie czy jest już taka zmienna XXX XXX XXX

		v.value = 0;
		//cout << variables.size();
		variables.push_back(v);
		//cout << variables.size();

		if(get_num((yyvsp[0])) != -1){
			var_write((yyvsp[-2]), (yyvsp[0]));
		}else if(read_var_check != 0){
			load_var_to_reg((yyvsp[0]), last_reg);
			//cout << $4;
			//put(last_reg);
			var_write((yyvsp[-2]), last_reg);
			read_var_check = 0;
		}
		else{
			printf("Blad: niepoprawna zmienna do przypisania: %s\n", (yyvsp[0]).c_str());
		}

	}else{
		cout << "Blad: powtorna deklaracja zmiennej " << (yyvsp[-2]);
	}				//koniec tworzenia zmiennej	

	//get_val_mem($2, "F");
	//put("F");

	

}
#line 1649 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 300 "bison.y" /* yacc.c:1646  */
    {
	var v;
	stringstream ss;
	for_counter++;
	ss << "for_var" << for_counter;
	v.name = ss.str();
	v.value = 0;
	variables.push_back(v);

	if(read_var_check != 0){
		load_var_to_reg((yyvsp[0]), last_reg);
		var_write(v.name, last_reg);
		read_var_check = 0;
	}else if(get_num((yyvsp[0])) != -1){
		var_write(v.name, (yyvsp[0]));
	}
	else{
		printf("Blad: niepoprawna zmienna do ograniczenia petli: %s\n", (yyvsp[0]).c_str());
	}	
}
#line 1674 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 320 "bison.y" /* yacc.c:1646  */
    {for_markers.push_back(k); k++;}
#line 1680 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 320 "bison.y" /* yacc.c:1646  */
    {

	//cout << $2;

	get_val_mem((yyvsp[-10]), "G");
	//put("G");
	//put("G");
	//put("G");
	inc("G");
	//put("G");
	var_write((yyvsp[-10]), "G");//i++
	//get_val_mem($2, "G");
	//put("G");

	vector<string>::iterator pos = commands.begin();
	stringstream ss;
	ss << "JUMP " << k;		//mozliwe ze bez +1
	string ss_to_s = ss.str();
	commands.insert(pos + for_markers[for_markers.size() - 1] + 1 - for_counter, ss_to_s);
	

	next_load_reg();						//condition
	get_val_mem((yyvsp[-10]), "G");
	//put("G");
	stringstream sss;
	sss << "for_var" << for_counter;
	get_val_mem(sss.str(), "H");
	//put("H");
	
	//cout << $7 << "    " << get_num($7) << endl;
	//if(get_num($7) == -1)   
	is_lesseq("G", "H");
	//else{
	//	is_lesseq("G", sss.str());	//condition
		//cout << sss.str();
	//}
	//put("B");
	//get("B");
	jzero("B", k + 2);		
	jump(for_markers[for_markers.size() - 1] + 1);
	for_markers.pop_back();
	for_counter--;
	
	variables.pop_back();
	variables.pop_back();
	//put("A");
	
	//zamienic kolejnosc w pamieci tablicowych ze zwyklymi bo zapisanie forowej zmiennej moze nadpisac zmienna tablicowa(przekroczenie poprzedniego rozmiaru wektora) [fixed]

}
#line 1735 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 370 "bison.y" /* yacc.c:1646  */
    {
	//cout << get_num($4);
	//put("A");
	//put("A");
	//put("A");
	//cout << find_tab($2, tables) << endl << find_var($2, variables);
	if(find_tab((yyvsp[-2]), tables) == -1 && find_var((yyvsp[-2]), variables) == -1){
		var v;
		v.name = (yyvsp[-2]);
		v.value = 0;
		//cout << variables.size();
		variables.push_back(v);
		//cout << variables.size();

		if(read_var_check != 0){
			load_var_to_reg((yyvsp[0]), last_reg);
			//put(last_reg);
			var_write((yyvsp[-2]), last_reg);
			read_var_check = 0;
		}else if(get_num((yyvsp[0])) != -1){
			var_write((yyvsp[-2]), (yyvsp[0]));
		}
		else{
			printf("Blad: niepoprawna zmienna do przypisania: %s\n", (yyvsp[0]).c_str());
		}

	}else{
		cout << "Blad: powtorna deklaracja zmiennej " << (yyvsp[-2]);
	}				//koniec tworzenia zmiennej	

	//get_val_mem($2, "F");
	//put("F");

	

}
#line 1776 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 405 "bison.y" /* yacc.c:1646  */
    {
	var v;
	stringstream ss;
	for_counter++;
	ss << "for_var" << for_counter;
	v.name = ss.str();
	v.value = 0;
	variables.push_back(v);
	//cout << read_var_check;
	if(read_var_check != 0){
		load_var_to_reg(v.name, last_reg);
		//put("A");
		//put(last_reg);
		//put(last_reg);
		var_write(v.name, last_reg);
		read_var_check = 0;
	}else if(get_num((yyvsp[0])) != -1){
		var_write(v.name, (yyvsp[0]));
	}
	else{
		printf("Blad: niepoprawna zmienna do ograniczenia petli: %s\n", (yyvsp[0]).c_str());
	}	
	//put(last_reg);
}
#line 1805 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 429 "bison.y" /* yacc.c:1646  */
    {for_markers.push_back(k); k++;}
#line 1811 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 429 "bison.y" /* yacc.c:1646  */
    {

	//get_val_mem($7, "E");
	//put("E");

	get_val_mem((yyvsp[-10]), "G");	
	for_enders.push_back(k);
	k++;

	dec("G");
	var_write((yyvsp[-10]), "G");
	

	vector<string>::iterator pos = commands.begin();
	stringstream ss;
	ss << "JUMP " << k;		//mozliwe ze bez +1
	string ss_to_s = ss.str();
	commands.insert(pos + for_markers[for_markers.size() - 1] + 1 - for_counter, ss_to_s);
	

	//put("B");
	//put("B"); 288 + 16 + 2
	//put("B");
	next_load_reg();						//condition
	get_val_mem((yyvsp[-10]), "G");
	//cout << $2;
	//put("A");
	//put("G");
	//put("F");
	stringstream sss;
	sss << "for_var" << for_counter;
	get_val_mem(sss.str(), "H");
	//put("A");
	//load("E");
	//put("E");
	//put("E");
	//put("H");
	//next_load_reg();
	//cout << $7;
	//if(get_num($7) == -1)   
		is_biggeq("G", "H");
	//else
	//	is_biggeq("G", sss.str());	//condition
	
	//put("B");
	//get("B");
	//cout << k;
	jzero("B", k + 2);		//+5 bo dostosowane do śmieciowych putów
	jump(for_markers[for_markers.size() - 1] + 1);

	vector<string>::iterator posx = commands.begin();
	stringstream ssx;
	ssx << "JZERO G " << k;		//mozliwe ze bez +1
	string ssx_to_s = ssx.str();
	//cout << for_counter;

	commands.insert(pos + for_enders[for_enders.size() - 1], ssx_to_s);

	for_enders.pop_back();
	for_markers.pop_back();
	for_counter--;
	
	variables.pop_back();
	variables.pop_back();
	//put("A");
	
	//zamienic kolejnosc w pamieci tablicowych ze zwyklymi bo zapisanie forowej zmiennej moze nadpisac zmienna tablicowa(przekroczenie poprzedniego rozmiaru wektora) [fixed]

}
#line 1885 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 498 "bison.y" /* yacc.c:1646  */
    {
	if(read_in((yyvsp[-1]), tables, variables) != 0)
		cout << "Niepoprawna zmienna" << (yyvsp[-1]);
}
#line 1894 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 502 "bison.y" /* yacc.c:1646  */
    {
	//cout << $2 << "    ";
	//cout << calc_addr($2);
	if(find_var((yyvsp[-1]), variables) != -1 || find_tab(get_tab_name((yyvsp[-1])), tables) != -1){
		load_var_to_reg((yyvsp[-1]),"F");
		put("F");
		//put("F");
		//put("F");
		//cout << "inside";
	}else if(get_num((yyvsp[-1])) != -1){
		//write_out($2);
		setup_val("F",get_num((yyvsp[-1])));
		put("F");
		//put("F");
		//put("F");
	}else{
		printf("Blad: niepoprawna zmienna do wydrukowania: %s\n", (yyvsp[-1]).c_str());
		return 0;
	}
	//halt();
	read_var_check = 0;
}
#line 1921 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 526 "bison.y" /* yacc.c:1646  */
    {if_enders.push_back(k); k++;}
#line 1927 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 526 "bison.y" /* yacc.c:1646  */
    {
	vector<string>::iterator pos = commands.begin();
	long long int jump = if_enders[if_beginers.size() - 1] + 1;
	stringstream ss;
	ss << "JZERO B " << to_string(if_enders[if_enders.size() - 1] + 1);
	string ss_to_s = ss.str();
	commands.insert(pos + if_beginers[if_beginers.size() - 1] + 1 - for_counter, ss_to_s); // + if_counter przy zagnieżdżonych
	stringstream ss2;
	ss2 << "JUMP " << k;
	string ss_to_s2 = ss2.str();
	commands.insert(pos + if_enders[if_enders.size() - 1] - for_counter, ss_to_s2);
	if_counter--;
	if_beginers.pop_back();
	if_enders.pop_back();
}
#line 1947 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 541 "bison.y" /* yacc.c:1646  */
    {if_enders.push_back(k);}
#line 1953 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 541 "bison.y" /* yacc.c:1646  */
    {
	//cout << k;
	vector<string>::iterator pos = commands.begin();
	long long int jump = if_enders[if_beginers.size() - 1] + 1;
	stringstream ss;
	//cout << if_counter;
	ss << "JZERO B " << k;
	string ss_to_s = ss.str();
	commands.insert(pos + if_beginers[if_beginers.size() - 1], ss_to_s); // + if_counter przy zagnieżdżonych
	if_counter--;
	if_beginers.pop_back();
	if_enders.pop_back();
}
#line 1971 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 557 "bison.y" /* yacc.c:1646  */
    {
	if(get_num((yyvsp[-2])) == -1){
		if(get_num((yyvsp[0])) == -1){
			adder(next_load_reg(), last_reg);
		}
		else
			adder(last_reg, (yyvsp[0]));
	}
	else{
		if(get_num((yyvsp[0])) == -1){ 
			adder((yyvsp[-2]), last_reg);
		}
		else
			adder((yyvsp[-2]), (yyvsp[0]));
	}
	set_last_count_reg();
}
#line 1993 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 574 "bison.y" /* yacc.c:1646  */
    {
	if(get_num((yyvsp[-2])) == -1){
		if(get_num((yyvsp[0])) == -1)   
			subber(next_load_reg(), last_reg);
		else
			subber(last_reg, (yyvsp[0]));
	}
	else{
		if(get_num((yyvsp[0])) == -1){ 
			subber((yyvsp[-2]), last_reg);
		}
		else
			subber((yyvsp[-2]), (yyvsp[0]));
	}
	set_last_count_reg();
}
#line 2014 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 590 "bison.y" /* yacc.c:1646  */
    {
	if(get_num((yyvsp[-2])) == -1){
		if(get_num((yyvsp[0])) == -1){
			//put(next_load_reg());
			//put(next_load_reg());
			multiplier(next_load_reg(), last_reg);			
		}
		else
			multiplier(last_reg, (yyvsp[0]));
	}
	else{
		if(get_num((yyvsp[0])) == -1){ 
			multiplier((yyvsp[-2]), last_reg);
		}
		else
			multiplier((yyvsp[-2]), (yyvsp[0]));
	}
	set_last_count_reg();
}
#line 2038 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 609 "bison.y" /* yacc.c:1646  */
    {
	//put(next_load_reg());
	//put("A");
	//put("B");
	//put("C");
	//put("D");
	//put("E");
	//put("F");
	//put("G");
	//put("H");
	//cout << last_reg;
	//put(next_load_reg());
	//cout << $1 << "    " << $3;
	if(get_num((yyvsp[-2])) == -1){
		if(get_num((yyvsp[0])) == -1)   
			divider(next_load_reg(), last_reg);
		else
			divider(last_reg, (yyvsp[0]));
	}
	else{
		if(get_num((yyvsp[0])) == -1){ 
			divider((yyvsp[-2]), last_reg);
		}
		else
			divider((yyvsp[-2]), (yyvsp[0]));
	}
	set_last_count_reg();
}
#line 2071 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 637 "bison.y" /* yacc.c:1646  */
    {
	//put(last_reg);
	//put(next_load_reg());
	//next_load_reg();
	if(get_num((yyvsp[-2])) == -1){
		if(get_num((yyvsp[0])) == -1)   
			modder(next_load_reg(), last_reg);
		else
			modder(last_reg, (yyvsp[0]));
	}
	else{
		if(get_num((yyvsp[0])) == -1){ 
			modder((yyvsp[-2]), last_reg);
		}
		else
			modder((yyvsp[-2]), (yyvsp[0]));
	}
	set_last_count_reg();
}
#line 2095 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 658 "bison.y" /* yacc.c:1646  */
    {
	if(get_num((yyvsp[-2])) == -1){
		if(get_num((yyvsp[0])) == -1)   
			is_equal(next_load_reg(), last_reg);
		else
			is_equal(last_reg, (yyvsp[0]));
	}
	else{
		if(get_num((yyvsp[0])) == -1){ 
			is_equal((yyvsp[-2]), last_reg);
		}
		else
			is_equal((yyvsp[-2]), (yyvsp[0]));
	}
}
#line 2115 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 673 "bison.y" /* yacc.c:1646  */
    {
	if(get_num((yyvsp[-2])) == -1){
		if(get_num((yyvsp[0])) == -1)   
			is_nequal(next_load_reg(), last_reg);
		else
			is_nequal(last_reg, (yyvsp[0]));
	}
	else{
		if(get_num((yyvsp[0])) == -1){ 
			is_nequal((yyvsp[-2]), last_reg);
		}
		else
			is_nequal((yyvsp[-2]), (yyvsp[0]));
	}
}
#line 2135 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 688 "bison.y" /* yacc.c:1646  */
    {
	if(get_num((yyvsp[-2])) == -1){
		if(get_num((yyvsp[0])) == -1)   
			is_less(next_load_reg(), last_reg);
		else
			is_less(last_reg, (yyvsp[0]));
	}
	else{
		if(get_num((yyvsp[0])) == -1){ 
			is_less((yyvsp[-2]), last_reg);
		}
		else
			is_less((yyvsp[-2]), (yyvsp[0]));
	}
}
#line 2155 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 703 "bison.y" /* yacc.c:1646  */
    {
	if(get_num((yyvsp[-2])) == -1){
		if(get_num((yyvsp[0])) == -1)   
			is_bigg(next_load_reg(), last_reg);
		else
			is_bigg(last_reg, (yyvsp[0]));
	}
	else{
		if(get_num((yyvsp[0])) == -1){ 
			is_bigg((yyvsp[-2]), last_reg);
		}
		else
			is_bigg((yyvsp[-2]), (yyvsp[0]));
	}
}
#line 2175 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 718 "bison.y" /* yacc.c:1646  */
    {
	if(get_num((yyvsp[-2])) == -1){
		if(get_num((yyvsp[0])) == -1)   
			is_lesseq(next_load_reg(), last_reg);
		else
			is_lesseq(last_reg, (yyvsp[0]));
	}
	else{
		if(get_num((yyvsp[0])) == -1){ 
			is_lesseq((yyvsp[-2]), last_reg);
		}
		else
			is_lesseq((yyvsp[-2]), (yyvsp[0]));
	}
}
#line 2195 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 733 "bison.y" /* yacc.c:1646  */
    {
	if(get_num((yyvsp[-2])) == -1){
		if(get_num((yyvsp[0])) == -1)   
			is_biggeq(next_load_reg(), last_reg);
		else
			is_biggeq(last_reg, (yyvsp[0]));
	}
	else{
		if(get_num((yyvsp[0])) == -1){ 
			is_biggeq((yyvsp[-2]), last_reg);
		}
		else
			is_biggeq((yyvsp[-2]), (yyvsp[0]));
	}
}
#line 2215 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 751 "bison.y" /* yacc.c:1646  */
    {
	//$$ = last_reg;
	read_var_check = 1;
	//put("G");
	//put("H");
	//put(last_reg);
	//setup_val("H", 12345);
	//put("H");
}
#line 2229 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 762 "bison.y" /* yacc.c:1646  */
    {//printf("empty");
	next_load_reg();	
	get_val_mem((yyvsp[0]), last_reg);
	//cout << $1 << "\n\n\n\n" << last_reg;
	//put(last_reg);
	//put("A");
	last_loaded = 1;
}
#line 2242 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 770 "bison.y" /* yacc.c:1646  */
    {//printf("pid");
	(yyval) = (yyvsp[-3]) + "(" + (yyvsp[-1]) + ")";
	if(find_var((yyvsp[-1]), variables) == -1){
		cout << "Blad: niezadeklarowana zmienna:" << (yyvsp[-1]);
		return 0;
	}
	tab_mode = 1;
	//printf("%s", $$.c_str());
	stringstream ss;
	ss << (yyvsp[-3]) << "(" << (yyvsp[-1]) << ")";
	string ss_to_s = ss.str(); 
	get_val_mem(ss_to_s, next_load_reg());
	last_loaded = 1;
}
#line 2261 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 784 "bison.y" /* yacc.c:1646  */
    {//printf("num");
	(yyval) = (yyvsp[-3]) + "(" + (yyvsp[-1]) + ")";	
	tab_mode = 1;
	//printf("%s", $$.c_str());
	stringstream ss;
	ss << (yyvsp[-3]) << "(" << (yyvsp[-1]) << ")";
	string ss_to_s = ss.str(); 
	//cout << ss_to_s << "    " << last_reg << "\n";
	//put("A");
	//put("A");
	//put("A");
	//put("G");
	//put("H");
	next_load_reg();
	get_val_mem(ss_to_s, last_reg);
	//put("G");
	//put("H");
	//put("A");
	//put("A");
	//put("A");	
	//put(last_reg);
	last_loaded = 1;
}
#line 2289 "bison.tab.c" /* yacc.c:1646  */
    break;


#line 2293 "bison.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 808 "bison.y" /* yacc.c:1906  */


void load_var_to_reg(string var, string reg){
	int addr = calc_addr(var);
	//cout << var << find_var(var, variables) << " " << addr;
	//cout << "laod " << var << "->" << reg << "addr" << addr;
	//setup_val("A", addr); XXX bo calc ustawia a
	//put("A");
	load(reg);
	//put(reg);
}

string get_tab_name(string s){
	int size = s.length();
	string name = "";
	for(int i = 0; i < size; i++)
		if(s.substr(i, 1) == "(")
			name = s.substr(0, i);
	return name;
}

void finish(){
	//cout << "ebebebebeb";
	for(int i = 0; i < commands.size(); i++){
		cout << commands[i] << endl;
	}
}

long long int sanitize_val(string s, vector<var> var_set, vector<tab> tab_set, string reg){
	//cout << s;
	if(get_num(s) != -1){
		//cout << "getvarval: " << get_num(s) << "\n";
		return get_num(s);
	}
	else{
		//put("A");
		if(calc_addr(s) != -1){
			//setup_val("A", calc_addr(s)); XXX bo calc ustawia a
			load(reg);
			//put("A");
			//put(reg);
			return -2;
		}
	}
	return -1;
}

int find_var(string name, vector<var> var_set){
	int s = var_set.size();
	//cout << s;
	for(int i = 0; i < s; i++){
		if(var_set[i].name == name)
			return i;
	}
	return -1;
}

int find_tab(string name, vector<tab> tab_set){
	//printf("%s, %d\n", name.c_str(), tab_set.size());
	int s = tab_set.size();
	//printf("%s, %d\n", name.c_str(), s);
	for(int b = 0; b < s; b++){
		//printf("petla %d", b);
		if(tab_set[b].name == name){
			//printf("index %d",b);
			return b;
		}
	}
	//printf("saddnes");
	return -1;
}

tab tab_cons(const char* max, const char* min, string n){
	//cout << std::numeric_limits<std::size_t>::max;
	tab t;
	t.name = n;
	long long int size = atoll(max) - atoll(min) + 1;
	t.table = vector<long long int>();//(size, 0);
	t.min = atoi(min);
	t.max = atoi(max);
	//cout << t.name << "  XXX  " << t.min << "  XXX  " << t.max << endl;
	return t;
}

void cng_var(string name, long long int val, vector<var> *var_set){
	long long int i = find_var(name, *var_set);
	var_set->at(i).value = val;
}

long long int *get_var_tab(string pid, string ind, vector<tab> tab_set, vector<var> var_set){
	int size = pid.length();
	int num;
	string name;
	//printf("%s,%s,%d\n", pid.c_str(), ind.c_str(), tab_mode);
	if(tab_mode){
		//printf("%d\n", find_tab(pid, tab_set));
		
		if(find_tab(pid, tab_set) != -1){
			//printf("%lld", get_var_val(ind, var_set));
			if(int i=get_var_val(ind, var_set) != -1){
				return &tab_set[num].table[i - tab_set[num].min];
			}
		}
	}
	if(num=find_var(pid, var_set) != -1)
		return &var_set[find_var(pid, var_set)].value;
	return NULL;
}

long long int *get_var_tab_old(string pid, vector<tab> tab_set, vector<var> var_set){
	int size = pid.length();
	int num;
	string name;
	//printf("%s, LENGTH: %d", pid.c_str(), size);
	for(int i = 0; i < size; i++){
		//printf("%s\n", pid.substr(i, 1).c_str());
		if(pid.substr(i, 1) == "("){
			name = pid.substr(0, i);
			//printf("%sasdfasdf%s", name.c_str(), pid.c_str());
			int j = find_tab(name, tab_set);
			//printf("%d",j);
			if(j != -1){
				string ss = pid.substr(i + 1, size - i - 2);
				//printf("j = %d, indexs = %s,index =  %lld, min = %d, max = %d", j, ss.c_str(), get_var_val(ss, var_set), tab_set[j].min, tab_set[j].max);
				if(get_var_val(pid.substr(i + 1, size - i - 2), var_set) >= tab_set[j].min && get_var_val(pid.substr(i + 1, size - i - 2), var_set) <= tab_set[j].max)
					return &tab_set[j].table[get_var_val(pid.substr(i + 1, size - i - 2), var_set) - tab_set[j].min];
			}
		}		
	}
	if(num=find_var(pid, var_set) != -1)
		return &var_set[find_var(pid, var_set)].value;
	return NULL;
}

long long int get_var_val(string s, vector<var> var_set){
	long long int num;	
	//printf("vvv%svvv", s.c_str());
	if(num=get_num(s) != -1){
		//printf("numcheck: %lld", get_num(s));
		return get_num(s);
}
	else
		if(num=find_var(s, var_set) != -1)
			return var_set[num].value;
		else
			return -1;
}

long long int get_num(string s){
	int size = s.length();
	//s = s.substr(0, size - 1);
	//cout << "\ns : " << s; 
	for(int i = 0; i < size; i++){
		//cout << "\ndigit : " << i << s.at(i) << "\n";
		if(!isdigit(s.at(i)))
			return -1;
	}
	//printf("after numcheck");
	long long int num = atoll(s.c_str());
	//printf("\nreturn :%lld", num);
	return num;
}

int is_reg(string s){
	if(s == "A"||
	s == "B"||
	s == "C"||
	s == "D"||
	s == "E"||
	s == "F"||
	s == "G"||
	s == "H")
		return 1;
	else 
		return 0;
}

void fix_jumps_if(long long int pos){
	//for(long long int i = pos; 
}

void is_equal(string a, string b){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	copy("C","A");
	sub("A","B");
	jump(k + 4);
	sub("B","C");
	jzero("B",k + 4);
	jump(k + 6);
	jzero("A",k - 3);
	jump(k + 4);
	sub("B","B");
	inc("B");
	jump(k + 2);
	sub("B","B");
}

void is_nequal(string a, string b){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	copy("C","A");
	sub("A","B");
	jump(k + 4);
	sub("B","C");
	jzero("B",k + 4);
	jump(k + 5);
	jzero("A",k - 3);
	jump(k + 3);
	sub("B","B");
	jump(k + 3);
	sub("B","B");
	inc("B");
}

void is_less(string a, string b){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	sub("B","A");
	jzero("B",k + 4);
	sub("B","B");
	inc("B");
	jump(k + 2);
	sub("B","B");
}

void is_bigg(string a, string b){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	sub("A","B");
	jzero("A",k + 4);
	sub("B","B");
	inc("B");
	jump(k + 2);
	sub("B","B");
	//put("B");
}

void is_lesseq(string a, string b){
	reset("A");
	reset("B");
	//put(a);
	//put(b);
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	sub("A","B");
	jzero("A",k + 3);
	sub("B","B");
	jump(k + 3);
	sub("B","B");
	inc("B");
	//put("B");
}

void is_biggeq(string a, string b){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	sub("B","A");
	jzero("B",k + 3);
	sub("B","B");
	jump(k + 3);
	sub("B","B");
	inc("B");
	//put("B");
}

long long int adder(string a, string b){
	//put(a);
	//put(b);
	reset("A");
	reset("B");
	//cout << a;
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	//cout << a << " " << ai;
	//put("H");
	//put("G");
	copy("A","C");
	//put("G");
	//put("B");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{ 
		if(ai != -0)
			setup_val("A", ai);
	}
	//put("A");
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do dodania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put(a);
	//put("A");
	//put("B");
	add("A","B");
	regs[0] = ai + bi;
	//put("A");
	return regs[0];
}

long long int subber(string a, string b){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(a, variables, tables, "C");
	long long int bi = sanitize_val(b, variables, tables, "B");
	int aa = 0, bb = 0;
	//put("A");
	//put("B");
	copy("A","C");
	if(ai == -1){
		if(is_reg(a))	
			copy("A", a);
		else
			printf("Blad: Niepoprawna wartość do odejmowania");
	}else{ 
		if(ai != 0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(b))	
			copy("B", b);
		else
			printf("Blad: Niepoprawna wartość do odejmowania");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	//put("A");
	//put("B");
	sub("A","B");
	//put("A");
	regs[0] = ai + bi;
	return regs[0];
}

void multiplier(string as, string bs){
	reset("A");
	reset("B");
	long long int ai = sanitize_val(as, variables, tables, "C");
	long long int bi = sanitize_val(bs, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	if(ai == -1){
		if(is_reg(as))	
			copy("A", as);
		else
			printf("Blad: Niepoprawna wartość do mnozenia");
	}else{ 
		if(ai != 0)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(bs))	
			copy("B", bs);
		else
			printf("Blad: Niepoprawna wartość do mnozenia");
	}else{
		if(bi != 0)
			setup_val("B", bi);
	}
	
	//put("A");
	//put("B");

	jump(k + 3);
	sub("A", "A");
	jump(k + 44);
	jzero("A", k - 1);
	jzero("B", k - 3);

	copy("C", "A");
	sub("C","B");				//ustawienie wiekszej liczby na A
	jump(k + 4);
	copy("C", "A");
	copy("A", "B");
	copy("B", "C");
	jzero("C", k - 3);	//ustawienie wiekszej liczby na A
	//put("A");
	//put("B");
	reset("C");
	inc("C");
	copy("D","B");			//dodawańsko
	sub("D","C");
	//put("D");
	jzero("D", k + 5);
	add("A","A");
	add("C","C");
	jump(k - 5);				//dodawańsko

	jump(k + 4);				//jeśli B to potega 2
	copy("D","C");
	sub("D","B");
	//put("D");
	jzero("D", k + 21);

	copy("D","B");			// buduje D - pozostałe A do dodania		[new]	
	half("C");
	sub("D","C");				// D skonczone	[new]
	
	add("C","C");
	copy("B","A");
	half("A");
	half("B");
	half("C");
	copy("E","D");
	sub("E","C");
	jzero("E", k + 2);

	jump(k + 5);
	copy("E","C");
	sub("E","D");
	jzero("E", k + 7);
	jump(k - 9);

	sub("D","C");
	add("A","B");
	//copy("E","D");
	//dec("E");						//xxx
	//jzero("E", k + 4);	//xxx
	jzero("D", k + 4);	// wyjscie [new]
	//jump(k - 9);				// xxx
	jump(k - 13);	//xxx/////////////////////////////////
	jump(k + 2);
	add("A","B");
	//put("A");
	
			//wynik A
	
}

void divider(string as, string bs){
	reset("A");
	reset("B");
	//cout << bs;
	//put(as);
	//put(bs);
	long long int ai = sanitize_val(as, variables, tables, "C");
	long long int bi = sanitize_val(bs, variables, tables, "B");
	int aa = 0, bb = 0;
	//cout << ai << bi;
	copy("A","C");
	if(ai == -1){
		if(is_reg(as))	
			copy("A", as);
		else
			printf("Blad: Niepoprawna wartość do dzielenia");
	}else{ 
		if(ai != -2)
		setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(bs))	
			copy("B", bs);
		else
			printf("Blad: Niepoprawna wartość do dzielenia");
	}else{
		if(bi != -2){
			setup_val("B", bi);
			//cout << bi;
		}
	}
	reset("C");
	reset("D");
	//put("A");
	//put("B");			///////
	jzero("A", k + 10);
	jzero("B", k + 9);
	jump(k + 10);		///////
	copy("C","B");
	sub("C","A");
	jump(k + 4);
	reset("A");
	inc("A");
	jump(k + 47);
	jzero("C", k - 3);
	reset("A");				///////
	jump(k + 44);		///////
	copy("C","A");
	sub("C","B");
	jzero("C", k - 11);	///////
	copy("C","A");				///////
	sub("C","B");
	reset("D");
	jzero("C", k + 36);
	copy("C","B");
	inc("D");
	reset("E");
	inc("E");
	jzero("E",k + 6);
	add("C","C");
	add("D","D");
	copy("E","A");
	sub("E","C");
	jump(k - 5);
	
	copy("E","C");
	sub("E","A");
	jzero("E", k + 23);

	half("C");
	half("D");			///////
	copy("B","C");
	copy("E","D");
	reset("F");
	inc("F");
	jzero("F", k + 12);	///////
	jump(k + 3);	
	sub("C","B");
	sub("D","E");		///////
	half("B");
	jzero("B", k + 11);
	half("E");
	add("C","B");
	add("D","E");
	copy("F","A");
	sub("F", "C");
	jump(k - 11);
	copy("F","C");
	sub("F","A");
	jzero("F",k + 2);
	jump(k - 13);
	copy("A","D");
	//put("B");
	//put("C");
	//put("D");
	//put("E");
	//put("F");
			//wynik A z D 
}

void modder(string as, string bs){
	reset("A");
	reset("B");
	//cout << as << "    " << bs;
	long long int ai = sanitize_val(as, variables, tables, "C");
	long long int bi = sanitize_val(bs, variables, tables, "B");
	int aa = 0, bb = 0;
	copy("A","C");
	//put("A");
	//put("B");
	if(ai == -1){
		if(is_reg(as))	
			copy("A", as);
		else
			printf("Blad: Niepoprawna wartość do dzielenia");
	}else{ 
		if(ai != -2)
			setup_val("A", ai);
	}
	if(bi == -1){
		if(is_reg(bs))	
			copy("B", bs);
		else
			printf("Blad: Niepoprawna wartość do dzielenia");
	}else{
		if(bi != -2)
			setup_val("B", bi);
	}
	reset("C");
	reset("D");
	//put("A");
	//put("B");			
	jzero("A", k + 11);
	jzero("B", k + 9);
	jump(k + 10);		
	copy("C","B");
	sub("C","A");
	jump(k + 3);
	reset("A");
	jump(k + 30);			//out
	jzero("C", k - 2);
	jump(k + 2);
	reset("A");			
	jump(k + 26);			//out
	copy("C","A");
	sub("C","B");
	jzero("C", k - 11);
	reset("E");
	inc("E");	
	copy("C","B");
	add("C","C");
	add("E","E");
	copy("D","A");
	sub("D","C");
	jzero("D", k + 10);
	jump(k - 5);
	sub("A","C");
	half("C");
	half("E");
	jzero("E", k + 10);		//out
	copy("D", "A");
	sub("D", "C");
	jzero("D", k + 2);		//c >= a
	jump(k - 7);
	copy("D", "C");
	sub("D", "A");
	jzero("D", k + 2);		//c == a
	jump(k - 10);
	reset("A");
	//put("A");

/*
	copy("C","A");				///////
	sub("C","B");
	reset("D");
	jzero("C", k + 33);
	copy("C","B");
	inc("D");
	reset("E");
	inc("E");
	jzero("E",k + 6);
	add("C","C");
	add("D","D");
	copy("E","A");
	sub("E","C");
	jump(k - 5);
	half("C");
	half("D");			///////
	copy("B","C");
	copy("E","D");
	reset("F");
	inc("F");
	jzero("F", k + 12);	///////
	jump(k + 3);	
	sub("C","B");		// c = a - b
	sub("D","E");		///////
	half("E");
	jzero("E", k + 11);
	half("B");
	//put("C");
	add("C","B");
	add("D","E");
	copy("F","A");
	sub("F", "C");
	jump(k - 11);
	copy("F","C");
	sub("F","A");
	jzero("F",k + 2);
	jump(k - 13);
	sub("A","C");
	//put("C");
	//put("A");
*/
			//wynik A
}

void set_last_count_reg(){
	//put("A");
	if(last_count_reg == "F"){
		last_count_reg = "E";
		copy("E","A");
	}
	else{
		last_count_reg = "F"; 
		copy("F","A");
	}
	count_check = 1;
}

void free_last_count_reg(){
	last_count_reg = "E";
	count_check = 0;
	read_var_check = 0;
}

int decrypt_reg(string s){
	if(s=="A")
		return 0;
	if(s=="B")
		return 1;
	if(s=="C")
		return 2;
	if(s=="D")
		return 3;
	if(s=="E")
		return 4;
	if(s=="F")
		return 5;
	if(s=="G")
		return 6;
	
		return 7;
}

int setup_val(string reg, long long int val){
	//put("A");
	reset(reg);
	if(val < 0)
		return -1;
	if(val == 0){
		reset(reg);
		return 0;
	}	
	inc(reg);
	if(val == 1)
		return 1;
	//cout << val;
	long long int a = 1;
	while(a * 2 < val){
		add(reg, reg);
		a *= 2;
	}
	if(a == val){
		last_calculated = a;
		return a;
	}
	string reg2 = "D";
	//cout << reg2;
	reset(reg2);
	copy(reg2, reg);
	long long int b = a;
	//half(reg2);
	while(b > 0){
		if(b + a <= val){
			a += b;
			add(reg,reg2);
			//put(reg);
		}
		if(a == val){
			last_calculated = a;
			//put(reg);
			return a;
		}else{
			b /= 2;
			half(reg2);
		}	
	}
	//put("E");
	//put("E");
	//put("E");
	return -1;	
}

string encrypt_reg(int reg){
	if(reg == 0)
		return "A";
	if(reg == 1)
		return "B";
	if(reg == 2)
		return "C";
	if(reg == 3)
		return "D";
	if(reg == 4)
		return "E";
	if(reg == 5)
		return "F";
	if(reg == 6)
		return "G";
	if(reg == 7)
		return "H";
	return "ABCDEFGH";
}

int calc_addr(string var){
	int size = var.size();
	int num;
	
	string name;
	for(int i = 0; i < size; i++){
		if(var.substr(i, 1) == "("){
			name = var.substr(0, i);
			int j = find_tab(name, tables);
			if(j != -1){
				string ss = var.substr(i + 1, size - i - 2);
				//cout << var << "    " << ss << "    " << get_var_val(ss, variables) << "    " << tables[j].min << "    " << tables[j].max;
				//if(get_var_val(ss, variables) >= tables[j].min && get_var_val(ss, variables) <= tables[j].max){
					int addr = 0;
					for(int l = 0; l < j; l++){
						addr += tables[l].max - tables[l].min + 1;
						//cout << tables[l].max << "   " << tables[l].min << endl;
					}
					setup_val("A", j);
					//put("A");
					//put("A");
					//put("A");
					//addr -= tables[j].min;
					//put("A");
					//cout << addr << "    " << var << "    " << j << endl;
					if(get_num(ss) != -1){
						addr += get_num(ss);
						setup_val("A", addr);
						setup_val("B", tables[j].min);
						sub("A", "B");
						//put("A");
					}
					else{
						//cout << ss <<endl;
						get_val_mem(ss, "B");
						setup_val("A", addr);
						//put("A");
						//put("B");
						add("A", "B");
						//put("A");
						setup_val("B", tables[j].min);
						sub("A", "B");
					}
					
					//put("A");
					//cout << var << "   " << get_var_val(ss, variables) - tables[j].min << endl;
					return addr;
				
			}
		}		
	}
	if(find_var(var, variables) != -1){
		int addr = find_var(var, variables);
		//cout << var << "    " << addr << endl;
		for(int i = 0; i < tables.size(); i++){
			addr += tables[i].max - tables[i].min + 1;
			//cout << tables[i].max << "   " << tables[i].min << endl;
		}
		//cout << var << "    " << addr << endl;
		setup_val("A", addr);
		return addr;
	}
	return -1;
}

int get_val_from_mem(string var){
	int addr = calc_addr(var);
	if(addr != -1){
		//setup_val("A", addr); XXX bo calc ustawia a
		load("B");
		return 0;
	}
	return -1;
}

void write_out(string id){
	long long int val = atoll(id.c_str());
	if(is_reg(id)){
		get_val_from_mem(id);
		//put("B");
		return;
	}
	if(val != -1){
		//printf("%lld",val);
		setup_val("A", val);
		//put("A");
		return;
	}	
}

int read_in(string s, vector<tab> tab_set, vector<var> var_set){
	int addr = calc_addr(s);
	if(addr == -1)
		return -1;
	//setup_val("A", addr);
	get(next_load_reg());
	store(last_reg);
	return 0;
}

void tab_write_old(string tab, string val){
	put(val);
	int size = tab.length();
	string name = "";
	long long int ind = -1;
	for(int i = 0; i < size; i++)
		if(tab.substr(i, 1) == "("){
			name = tab.substr(0, i);
			ind = atoll(tab.substr(i + 1, size - i - 2).c_str());
			int addr = variables.size();
			for(int k = 0; k < find_tab(name, tables); k++)
				addr += tables[k].table.size();
			addr += ind - tables[find_tab(name, tables)].min;
			setup_val("A", addr);
			if(is_reg(val)){
				store(val);
			}else{
			long long int value = sanitize_val(val, variables, tables, "B");
			if(value > 0)
				setup_val("B", value);
			store("B");
			}
			return;
		}
}

void tab_write(string tab, string val){
	//put(val);
	int addr = calc_addr(tab);
	//setup_val("A", addr); XXX bo calc ustawia a
	
	if(is_reg(val))
		store(val);
	else{
		setup_val("B", get_num(val));
		store("B");
	}
}

void var_write(string var, string val){
	int v = calc_addr(var);
	//setup_val("A", v); XXX bo calc ustawia a
	
	//put("A");
	//cout << "var_write: " << v << "  " << val;
	if(is_reg(val))
		store(val);
	else{
	//cout << val;
	//cout << get_num(val);	
	setup_val("B", get_num(val));
	//put("B");
	store("B");
	}
}

void for_var_write(string var, string val){
	int v = find_var(var, for_variables);
	v += variables.size();
	for(int i = 0; i < tables.size(); i++){
		v += tables[i].table.size();
	}
	setup_val("A", v);
	
	//put("A");
	//cout << "var_write: " << v << "  " << val;
	if(is_reg(val))
		store(val);
	else{
	//cout << val;
	//cout << get_num(val);	
	setup_val("B", get_num(val));
	//put("B");
	store("B");
	}
}

string next_load_reg(){
	if(last_reg == "G"){
		last_reg = "H";
	}else{
		last_reg = "G";
	}
	return last_reg;
}

void get_val_mem(string s, string reg){
	int v = calc_addr(s);
	//setup_val("A", v); XXX bo calc ustawia a
	load(reg);
}

void reset(string ind){
	regs[decrypt_reg(ind)] = 0;
	sub(ind, ind);
}

void get(string i){
	stringstream s;
	s << "GET " << i;
	k++;
	commands.push_back(s.str());
}

void put(string i){
	stringstream s;
	s << "PUT " << i;
	k++;
	commands.push_back(s.str());
}

void load(string i){
	stringstream s;
	s << "LOAD " << i;
	k++;
	commands.push_back(s.str());
}

void store(string i){
	stringstream s;
	s << "STORE " << i;
	k++;
	commands.push_back(s.str());
}

void copy(string i, string j){
	stringstream s;
	s << "COPY " << i << " " << j;
	k++;
	commands.push_back(s.str());
}

void add(string i, string j){
	stringstream s;
	s << "ADD " << i << " " << j;
	k++;
	commands.push_back(s.str());
}

void sub(string i, string j){
	stringstream s;
	s << "SUB " << i << " " << j;
	k++;
	commands.push_back(s.str());
}

void half(string i){
	stringstream s;
	s << "HALF " << i;
	k++;
	commands.push_back(s.str());
}

void inc(string i){
	stringstream s;
	s << "INC " << i;
	k++;
	commands.push_back(s.str());
}

void dec(string i){
	stringstream s;
	s << "DEC " << i;
	k++;
	commands.push_back(s.str());
}

void jump(int i){
	stringstream s;
	s << "JUMP " << i;
	k++;
	commands.push_back(s.str());
}

void jzero(string i, int j){
	stringstream s;
	s << "JZERO " << i << " " << j;
	k++;
	commands.push_back(s.str());
}

void jodd(string i, int j){
	stringstream s;
	s << "HALF " << i << " " << j;
	k++;
	commands.push_back(s.str());
}

void halt(){
	stringstream s;
	s << "HALT ";
	commands.push_back(s.str());
}

void yyerror(char const *s){
	printf("%s", s);
}

int main()
{
	//printf("ASDF");
	yyparse();
	//printf("fdsa");
	//printf("Przetworzono linii: %d\n",yylineno-1);
	//printf("%lld %lld", variables[0].value, tables[0].table[0]);
	return 0;
}
