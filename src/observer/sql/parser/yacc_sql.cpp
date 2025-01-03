/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

UnboundAggregateExpr *create_aggregate_expression(AggregateType type,
                                           Expression *child,
                                           const char *sql_string,
                                           YYLTYPE *llocp)
{
  UnboundAggregateExpr *expr = new UnboundAggregateExpr(type, child);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}


#line 125 "yacc_sql.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_BY = 4,                         /* BY  */
  YYSYMBOL_CREATE = 5,                     /* CREATE  */
  YYSYMBOL_DROP = 6,                       /* DROP  */
  YYSYMBOL_GROUP = 7,                      /* GROUP  */
  YYSYMBOL_TABLE = 8,                      /* TABLE  */
  YYSYMBOL_TABLES = 9,                     /* TABLES  */
  YYSYMBOL_INDEX = 10,                     /* INDEX  */
  YYSYMBOL_CALC = 11,                      /* CALC  */
  YYSYMBOL_SELECT = 12,                    /* SELECT  */
  YYSYMBOL_DESC = 13,                      /* DESC  */
  YYSYMBOL_SHOW = 14,                      /* SHOW  */
  YYSYMBOL_SYNC = 15,                      /* SYNC  */
  YYSYMBOL_INSERT = 16,                    /* INSERT  */
  YYSYMBOL_DELETE = 17,                    /* DELETE  */
  YYSYMBOL_UPDATE = 18,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 19,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 20,                    /* RBRACE  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 22,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 23,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 24,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 25,                     /* INT_T  */
  YYSYMBOL_STRING_T = 26,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 27,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 28,                    /* DATE_T  */
  YYSYMBOL_VECTOR_T = 29,                  /* VECTOR_T  */
  YYSYMBOL_HELP = 30,                      /* HELP  */
  YYSYMBOL_EXIT = 31,                      /* EXIT  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_INTO = 33,                      /* INTO  */
  YYSYMBOL_VALUES = 34,                    /* VALUES  */
  YYSYMBOL_FROM = 35,                      /* FROM  */
  YYSYMBOL_INNER_JOIN = 36,                /* INNER_JOIN  */
  YYSYMBOL_WHERE = 37,                     /* WHERE  */
  YYSYMBOL_AND = 38,                       /* AND  */
  YYSYMBOL_SET = 39,                       /* SET  */
  YYSYMBOL_ON = 40,                        /* ON  */
  YYSYMBOL_IN = 41,                        /* IN  */
  YYSYMBOL_NOT_IN = 42,                    /* NOT_IN  */
  YYSYMBOL_EXISTS = 43,                    /* EXISTS  */
  YYSYMBOL_NOT_EXISTS = 44,                /* NOT_EXISTS  */
  YYSYMBOL_LOAD = 45,                      /* LOAD  */
  YYSYMBOL_DATA = 46,                      /* DATA  */
  YYSYMBOL_ORDER = 47,                     /* ORDER  */
  YYSYMBOL_ASC = 48,                       /* ASC  */
  YYSYMBOL_INFILE = 49,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 50,                   /* EXPLAIN  */
  YYSYMBOL_STORAGE = 51,                   /* STORAGE  */
  YYSYMBOL_FORMAT = 52,                    /* FORMAT  */
  YYSYMBOL_AS = 53,                        /* AS  */
  YYSYMBOL_EQ = 54,                        /* EQ  */
  YYSYMBOL_LT = 55,                        /* LT  */
  YYSYMBOL_GT = 56,                        /* GT  */
  YYSYMBOL_LE = 57,                        /* LE  */
  YYSYMBOL_GE = 58,                        /* GE  */
  YYSYMBOL_NE = 59,                        /* NE  */
  YYSYMBOL_NOT = 60,                       /* NOT  */
  YYSYMBOL_NULL_T = 61,                    /* NULL_T  */
  YYSYMBOL_LIKE = 62,                      /* LIKE  */
  YYSYMBOL_L2_DISTANCE = 63,               /* L2_DISTANCE  */
  YYSYMBOL_COSINE_DISTANCE = 64,           /* COSINE_DISTANCE  */
  YYSYMBOL_INNER_PRODUCT = 65,             /* INNER_PRODUCT  */
  YYSYMBOL_IS = 66,                        /* IS  */
  YYSYMBOL_COUNT = 67,                     /* COUNT  */
  YYSYMBOL_MAX = 68,                       /* MAX  */
  YYSYMBOL_MIN = 69,                       /* MIN  */
  YYSYMBOL_AVG = 70,                       /* AVG  */
  YYSYMBOL_SUM = 71,                       /* SUM  */
  YYSYMBOL_TEXT_T = 72,                    /* TEXT_T  */
  YYSYMBOL_NUMBER = 73,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 74,                     /* FLOAT  */
  YYSYMBOL_ID = 75,                        /* ID  */
  YYSYMBOL_SSS = 76,                       /* SSS  */
  YYSYMBOL_DATE = 77,                      /* DATE  */
  YYSYMBOL_VECTOR = 78,                    /* VECTOR  */
  YYSYMBOL_79_ = 79,                       /* '+'  */
  YYSYMBOL_80_ = 80,                       /* '-'  */
  YYSYMBOL_81_ = 81,                       /* '*'  */
  YYSYMBOL_82_ = 82,                       /* '/'  */
  YYSYMBOL_UMINUS = 83,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_commands = 85,                  /* commands  */
  YYSYMBOL_command_wrapper = 86,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 87,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 88,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 89,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 90,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 91,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 92,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 93,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 94,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 95,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 96,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 97,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 98,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 99,             /* attr_def_list  */
  YYSYMBOL_attr_def = 100,                 /* attr_def  */
  YYSYMBOL_number = 101,                   /* number  */
  YYSYMBOL_type = 102,                     /* type  */
  YYSYMBOL_insert_stmt = 103,              /* insert_stmt  */
  YYSYMBOL_value_list = 104,               /* value_list  */
  YYSYMBOL_value = 105,                    /* value  */
  YYSYMBOL_storage_format = 106,           /* storage_format  */
  YYSYMBOL_delete_stmt = 107,              /* delete_stmt  */
  YYSYMBOL_update_list = 108,              /* update_list  */
  YYSYMBOL_update_stmt = 109,              /* update_stmt  */
  YYSYMBOL_select_stmt = 110,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 111,                /* calc_stmt  */
  YYSYMBOL_expression_list = 112,          /* expression_list  */
  YYSYMBOL_expression = 113,               /* expression  */
  YYSYMBOL_rel_attr = 114,                 /* rel_attr  */
  YYSYMBOL_relation = 115,                 /* relation  */
  YYSYMBOL_rel_list = 116,                 /* rel_list  */
  YYSYMBOL_join_list = 117,                /* join_list  */
  YYSYMBOL_where = 118,                    /* where  */
  YYSYMBOL_condition_list = 119,           /* condition_list  */
  YYSYMBOL_condition = 120,                /* condition  */
  YYSYMBOL_comp_op = 121,                  /* comp_op  */
  YYSYMBOL_group_by = 122,                 /* group_by  */
  YYSYMBOL_order_by = 123,                 /* order_by  */
  YYSYMBOL_order_by_list = 124,            /* order_by_list  */
  YYSYMBOL_order_by_item = 125,            /* order_by_item  */
  YYSYMBOL_load_data_stmt = 126,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 127,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 128,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 129             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  258

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   334


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    81,    79,     2,    80,     2,    82,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    83
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   227,   227,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   258,   264,   269,   275,   281,   287,   293,
     300,   306,   314,   328,   338,   362,   365,   378,   387,   396,
     405,   414,   423,   434,   437,   438,   439,   440,   441,   442,
     445,   462,   465,   476,   481,   486,   491,   496,   503,   513,
     525,   533,   536,   543,   555,   561,   569,   583,   636,   645,
     650,   661,   665,   669,   673,   677,   681,   684,   687,   690,
     693,   697,   701,   704,   709,   715,   721,   724,   728,   732,
     739,   744,   754,   759,   766,   776,   785,   799,   802,   823,
     826,   832,   835,   840,   847,   855,   863,   873,   874,   875,
     876,   877,   878,   879,   880,   881,   882,   883,   884,   885,
     886,   891,   894,   904,   907,   916,   922,   931,   937,   943,
     952,   965,   973,   983,   984
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "BY",
  "CREATE", "DROP", "GROUP", "TABLE", "TABLES", "INDEX", "CALC", "SELECT",
  "DESC", "SHOW", "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE",
  "COMMA", "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "VECTOR_T", "HELP", "EXIT", "DOT", "INTO", "VALUES",
  "FROM", "INNER_JOIN", "WHERE", "AND", "SET", "ON", "IN", "NOT_IN",
  "EXISTS", "NOT_EXISTS", "LOAD", "DATA", "ORDER", "ASC", "INFILE",
  "EXPLAIN", "STORAGE", "FORMAT", "AS", "EQ", "LT", "GT", "LE", "GE", "NE",
  "NOT", "NULL_T", "LIKE", "L2_DISTANCE", "COSINE_DISTANCE",
  "INNER_PRODUCT", "IS", "COUNT", "MAX", "MIN", "AVG", "SUM", "TEXT_T",
  "NUMBER", "FLOAT", "ID", "SSS", "DATE", "VECTOR", "'+'", "'-'", "'*'",
  "'/'", "UMINUS", "$accept", "commands", "command_wrapper", "exit_stmt",
  "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "desc_table_stmt",
  "create_index_stmt", "drop_index_stmt", "create_table_stmt",
  "attr_def_list", "attr_def", "number", "type", "insert_stmt",
  "value_list", "value", "storage_format", "delete_stmt", "update_list",
  "update_stmt", "select_stmt", "calc_stmt", "expression_list",
  "expression", "rel_attr", "relation", "rel_list", "join_list", "where",
  "condition_list", "condition", "comp_op", "group_by", "order_by",
  "order_by_list", "order_by_item", "load_data_stmt", "explain_stmt",
  "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-201)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     259,    12,    18,   102,   102,   -54,    15,  -201,     0,     2,
     -36,  -201,  -201,  -201,  -201,  -201,   -34,    19,   259,    77,
      70,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,
    -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,
    -201,    31,    45,    55,    61,    11,  -201,   124,   132,   138,
     139,   149,   165,   172,   192,  -201,  -201,   127,  -201,  -201,
    -201,   129,  -201,  -201,  -201,   -19,  -201,   178,  -201,  -201,
     156,   158,   175,   180,   186,  -201,  -201,  -201,  -201,   217,
     197,  -201,   198,   -11,   223,   -12,   102,   102,   102,   102,
     102,   102,   102,   102,   169,  -201,  -201,  -201,   102,   102,
     102,   102,   102,   170,   212,   214,   177,   -42,   181,   183,
     184,   185,   -42,   241,  -201,  -201,   160,   168,   174,    20,
      30,    34,    73,   106,  -201,  -201,    42,    42,  -201,  -201,
     -50,   242,   226,   260,    64,  -201,   224,   214,    76,  -201,
     247,   -13,   263,   266,  -201,   265,  -201,   102,   102,   102,
    -201,  -201,  -201,  -201,  -201,   213,  -201,   170,   170,   214,
     -42,   102,   102,   258,  -201,   249,   102,  -201,  -201,  -201,
     283,  -201,  -201,  -201,  -201,  -201,  -201,    -8,   183,   272,
     218,  -201,   136,   140,   144,  -201,  -201,   254,   288,   265,
     148,   148,  -201,  -201,  -201,  -201,  -201,  -201,  -201,  -201,
    -201,  -201,   234,  -201,   237,   102,    64,   187,   228,   232,
     245,  -201,   263,   256,   290,  -201,  -201,  -201,    64,   304,
     264,   299,  -201,  -201,   148,  -201,   177,  -201,  -201,   301,
    -201,  -201,   270,  -201,  -201,   226,   102,   319,  -201,  -201,
    -201,    86,   271,  -201,  -201,   102,   267,  -201,   251,    16,
    -201,   306,  -201,  -201,  -201,  -201,   102,  -201
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    24,    23,     0,     0,     0,     0,
     133,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    55,    90,    57,    58,
      59,     0,    86,    83,    68,    69,    85,     0,    31,    30,
       0,     0,     0,     0,     0,   131,     1,   134,     2,     0,
       0,    29,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    55,    82,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    70,    76,    77,    78,    79,
      92,    95,    97,     0,   101,    63,     0,    99,     0,   132,
       0,     0,    35,     0,    33,    51,    84,     0,     0,     0,
      71,    72,    73,    74,    75,     0,    94,     0,     0,    99,
       0,     0,     0,     0,   100,   102,     0,    66,    54,    56,
       0,    44,    45,    46,    47,    48,    49,    42,     0,     0,
       0,    52,     0,     0,     0,    93,    96,     0,   121,    51,
     105,   106,   117,   118,   119,   120,   107,   108,   109,   110,
     111,   112,     0,   113,   115,     0,   101,    65,     0,     0,
       0,    41,    35,    61,     0,    87,    88,    89,   101,     0,
     123,     0,   114,   116,   104,   103,     0,   130,    43,     0,
      40,    36,     0,    34,    32,    97,     0,     0,    67,    50,
      64,    39,     0,    98,   122,     0,     0,    38,     0,   127,
     124,   125,    37,    62,   129,   128,     0,   126
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -201,  -201,   311,  -201,  -201,  -201,  -201,  -201,  -201,  -201,
    -201,  -201,  -201,  -201,  -201,   118,   153,  -201,  -201,  -201,
    -138,   -41,  -201,  -201,   107,  -201,   287,  -201,    -4,   -44,
    -201,   176,   179,   100,  -132,  -200,  -201,  -201,  -201,  -201,
      85,  -201,  -201,  -201,  -201,  -201
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   179,   142,   229,   177,    33,
     113,    63,   233,    34,   137,    35,    36,    37,    64,    65,
      66,   131,   132,   159,   135,   164,   165,   205,   220,   238,
     250,   251,    38,    39,    40,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    85,    98,   155,    83,   167,   225,   181,   115,   -51,
     112,   209,   171,   172,   173,   174,   175,    97,   235,    46,
      41,    68,    42,     4,    69,   156,    43,   188,    44,   254,
      45,    55,    56,    70,    58,    59,    60,    71,   138,    72,
     150,    73,   116,   117,   118,   119,   120,   121,   122,   123,
     151,   221,   210,   211,   152,   126,   127,   128,   129,   176,
      99,   100,   101,   102,   255,    74,   139,    99,   100,   101,
     102,   145,    46,    77,    47,    48,    49,    76,    50,    51,
      52,    53,    54,    45,    55,    56,    57,    58,    59,    60,
     163,    61,    62,   153,   125,    99,   100,   101,   102,    99,
     100,   101,   102,   182,   183,   184,    79,   161,   162,    99,
     100,   101,   102,    99,   100,   101,   102,   190,   191,   189,
      80,    45,   207,   101,   102,    46,   154,    47,    48,    49,
      81,    50,    51,    52,    53,    54,    82,    55,    56,    57,
      58,    59,    60,    86,    61,    62,   246,   247,    45,   168,
     169,    87,    99,   100,   101,   102,   215,    88,    89,    94,
     216,   224,   163,    46,   217,    47,    48,    49,    90,    50,
      51,    52,    53,    54,   163,    55,    56,    57,    58,    59,
      60,   147,    61,    62,    91,    99,   100,   101,   102,   148,
      46,    92,    47,    48,    49,   149,    50,    51,    52,    53,
      54,   249,    95,    96,    57,    58,    59,    60,   226,    61,
      62,    93,   249,   103,   106,    99,   100,   101,   102,    99,
     100,   101,   102,    99,   100,   101,   102,    99,   100,   101,
     102,   104,   244,   105,   107,   108,   109,   110,   111,    99,
     100,   101,   102,   114,   124,   130,   133,    99,   100,   101,
     102,   134,   136,    99,   100,   101,   102,   140,   141,   143,
     144,   146,   158,   157,     1,     2,    99,   100,   101,   102,
       3,     4,     5,     6,     7,     8,     9,    10,   166,   160,
     170,    11,    12,    13,   178,   180,   112,   206,   185,    14,
      15,   208,   213,   214,   218,   219,   222,   223,    16,   192,
     193,   194,   195,   227,    17,   228,   230,   232,   236,    18,
     234,   237,   196,   197,   198,   199,   200,   201,   202,   239,
     203,   241,   242,   245,   204,   248,   253,   256,   252,    75,
     231,   212,    84,   240,   187,   243,   186,    99,   100,   101,
     102,   257
};

static const yytype_int16 yycheck[] =
{
       4,    45,    21,    53,    45,   137,   206,   145,    20,    20,
      21,    19,    25,    26,    27,    28,    29,    61,   218,    61,
       8,    75,    10,    12,     9,    75,     8,   159,    10,    13,
      19,    73,    74,    33,    76,    77,    78,    35,    80,    75,
      20,    75,    86,    87,    88,    89,    90,    91,    92,    93,
      20,   189,    60,    61,    20,    99,   100,   101,   102,    72,
      79,    80,    81,    82,    48,    46,   107,    79,    80,    81,
      82,   112,    61,     3,    63,    64,    65,     0,    67,    68,
      69,    70,    71,    19,    73,    74,    75,    76,    77,    78,
     134,    80,    81,    20,    98,    79,    80,    81,    82,    79,
      80,    81,    82,   147,   148,   149,    75,    43,    44,    79,
      80,    81,    82,    79,    80,    81,    82,   161,   162,   160,
      75,    19,   166,    81,    82,    61,    20,    63,    64,    65,
      75,    67,    68,    69,    70,    71,    75,    73,    74,    75,
      76,    77,    78,    19,    80,    81,    60,    61,    19,    73,
      74,    19,    79,    80,    81,    82,    20,    19,    19,    32,
      20,   205,   206,    61,    20,    63,    64,    65,    19,    67,
      68,    69,    70,    71,   218,    73,    74,    75,    76,    77,
      78,    21,    80,    81,    19,    79,    80,    81,    82,    21,
      61,    19,    63,    64,    65,    21,    67,    68,    69,    70,
      71,   245,    73,    74,    75,    76,    77,    78,    21,    80,
      81,    19,   256,    35,    39,    79,    80,    81,    82,    79,
      80,    81,    82,    79,    80,    81,    82,    79,    80,    81,
      82,    75,   236,    75,    54,    49,    19,    40,    40,    79,
      80,    81,    82,    20,    75,    75,    34,    79,    80,    81,
      82,    37,    75,    79,    80,    81,    82,    76,    75,    75,
      75,    20,    36,    21,     5,     6,    79,    80,    81,    82,
      11,    12,    13,    14,    15,    16,    17,    18,    54,    19,
      33,    22,    23,    24,    21,    19,    21,    38,    75,    30,
      31,     8,    20,    75,    40,     7,    62,    60,    39,    41,
      42,    43,    44,    75,    45,    73,    61,    51,     4,    50,
      20,    47,    54,    55,    56,    57,    58,    59,    60,    20,
      62,    20,    52,     4,    66,    54,    75,    21,    61,    18,
     212,   178,    45,   226,   158,   235,   157,    79,    80,    81,
      82,   256
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    11,    12,    13,    14,    15,    16,    17,
      18,    22,    23,    24,    30,    31,    39,    45,    50,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   103,   107,   109,   110,   111,   126,   127,
     128,     8,    10,     8,    10,    19,    61,    63,    64,    65,
      67,    68,    69,    70,    71,    73,    74,    75,    76,    77,
      78,    80,    81,   105,   112,   113,   114,   112,    75,     9,
      33,    35,    75,    75,    46,    86,     0,     3,   129,    75,
      75,    75,    75,   105,   110,   113,    19,    19,    19,    19,
      19,    19,    19,    19,    32,    73,    74,   113,    21,    79,
      80,    81,    82,    35,    75,    75,    39,    54,    49,    19,
      40,    40,    21,   104,    20,    20,   113,   113,   113,   113,
     113,   113,   113,   113,    75,   112,   113,   113,   113,   113,
      75,   115,   116,    34,    37,   118,    75,   108,    80,   105,
      76,    75,   100,    75,    75,   105,    20,    21,    21,    21,
      20,    20,    20,    20,    20,    53,    75,    21,    36,   117,
      19,    43,    44,   113,   119,   120,    54,   118,    73,    74,
      33,    25,    26,    27,    28,    29,    72,   102,    21,    99,
      19,   104,   113,   113,   113,    75,   116,   115,   118,   105,
     113,   113,    41,    42,    43,    44,    54,    55,    56,    57,
      58,    59,    60,    62,    66,   121,    38,   113,     8,    19,
      60,    61,   100,    20,    75,    20,    20,    20,    40,     7,
     122,   104,    62,    60,   113,   119,    21,    75,    73,   101,
      61,    99,    51,   106,    20,   119,     4,    47,   123,    20,
     108,    20,    52,   117,   112,     4,    60,    61,    54,   113,
     124,   125,    61,    75,    13,    48,    21,   124
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,    99,   100,   100,   100,
     100,   100,   100,   101,   102,   102,   102,   102,   102,   102,
     103,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   107,   108,   108,   109,   110,   111,   112,
     112,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     114,   114,   115,   115,   115,   116,   116,   117,   117,   118,
     118,   119,   119,   119,   120,   120,   120,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     126,   127,   128,   129,   129
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     8,     5,     8,     0,     3,     7,     6,     5,
       4,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       8,     0,     3,     1,     2,     1,     2,     1,     1,     1,
       1,     0,     4,     4,     5,     3,     5,     8,     2,     1,
       3,     4,     4,     4,     4,     4,     3,     3,     3,     3,
       3,     3,     2,     1,     4,     1,     1,     6,     6,     6,
       1,     3,     1,     3,     2,     1,     3,     0,     5,     0,
       2,     0,     1,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     1,     1,
       1,     0,     3,     0,     3,     1,     3,     1,     2,     2,
       7,     2,     4,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 228 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1849 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 258 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1858 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 264 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1866 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 269 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1874 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 275 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1882 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 281 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1890 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 287 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1898 "yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 293 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1908 "yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 300 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1916 "yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC ID  */
#line 306 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1926 "yacc_sql.cpp"
    break;

  case 32: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID RBRACE  */
#line 315 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_name = (yyvsp[-1].string);
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 1941 "yacc_sql.cpp"
    break;

  case 33: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 329 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 1953 "yacc_sql.cpp"
    break;

  case 34: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format  */
#line 339 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-5].string);
      free((yyvsp[-5].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-2].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
        delete src_attrs;
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-3].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-3].attr_info);
      if ((yyvsp[0].string) != nullptr) {
        create_table.storage_format = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
    }
#line 1978 "yacc_sql.cpp"
    break;

  case 35: /* attr_def_list: %empty  */
#line 362 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 1986 "yacc_sql.cpp"
    break;

  case 36: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 366 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2000 "yacc_sql.cpp"
    break;

  case 37: /* attr_def: ID type LBRACE number RBRACE NOT NULL_T  */
#line 379 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-5].number);
      (yyval.attr_info)->name = (yyvsp[-6].string);
      (yyval.attr_info)->arr_len = (yyvsp[-3].number);
      (yyval.attr_info)->nullable = false;
      free((yyvsp[-6].string));
    }
#line 2013 "yacc_sql.cpp"
    break;

  case 38: /* attr_def: ID type LBRACE number RBRACE NULL_T  */
#line 388 "yacc_sql.y"
    {
          (yyval.attr_info) = new AttrInfoSqlNode;
          (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
          (yyval.attr_info)->name = (yyvsp[-5].string);
          (yyval.attr_info)->arr_len = (yyvsp[-2].number);
          (yyval.attr_info)->nullable = true;
          free((yyvsp[-5].string));
    }
#line 2026 "yacc_sql.cpp"
    break;

  case 39: /* attr_def: ID type LBRACE number RBRACE  */
#line 397 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-3].number);
      (yyval.attr_info)->name = (yyvsp[-4].string);
      (yyval.attr_info)->arr_len = (yyvsp[-1].number);
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-4].string));
    }
#line 2039 "yacc_sql.cpp"
    break;

  case 40: /* attr_def: ID type NOT NULL_T  */
#line 406 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-2].number);
      (yyval.attr_info)->name = (yyvsp[-3].string);
      (yyval.attr_info)->arr_len = 1;
      (yyval.attr_info)->nullable = false;
      free((yyvsp[-3].string));
    }
#line 2052 "yacc_sql.cpp"
    break;

  case 41: /* attr_def: ID type NULL_T  */
#line 415 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->arr_len = 1;
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-2].string));
    }
#line 2065 "yacc_sql.cpp"
    break;

  case 42: /* attr_def: ID type  */
#line 424 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[0].number);
      (yyval.attr_info)->name = (yyvsp[-1].string);
      (yyval.attr_info)->arr_len = 1;
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-1].string));
    }
#line 2078 "yacc_sql.cpp"
    break;

  case 43: /* number: NUMBER  */
#line 434 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2084 "yacc_sql.cpp"
    break;

  case 44: /* type: INT_T  */
#line 437 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::INTS); }
#line 2090 "yacc_sql.cpp"
    break;

  case 45: /* type: STRING_T  */
#line 438 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::CHARS); }
#line 2096 "yacc_sql.cpp"
    break;

  case 46: /* type: FLOAT_T  */
#line 439 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::FLOATS); }
#line 2102 "yacc_sql.cpp"
    break;

  case 47: /* type: DATE_T  */
#line 440 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::DATES); }
#line 2108 "yacc_sql.cpp"
    break;

  case 48: /* type: VECTOR_T  */
#line 441 "yacc_sql.y"
                 { (yyval.number) = static_cast<int>(AttrType::VECTORS); }
#line 2114 "yacc_sql.cpp"
    break;

  case 49: /* type: TEXT_T  */
#line 442 "yacc_sql.y"
                 { (yyval.number) = static_cast<int>(AttrType::TEXTS); }
#line 2120 "yacc_sql.cpp"
    break;

  case 50: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 446 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-5].string);
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.sql_node)->insertion.values.swap(*(yyvsp[-1].value_list));
        delete (yyvsp[-1].value_list);
      }
      (yyval.sql_node)->insertion.values.emplace_back(*(yyvsp[-2].value));
      std::reverse((yyval.sql_node)->insertion.values.begin(), (yyval.sql_node)->insertion.values.end());
      delete (yyvsp[-2].value);
      free((yyvsp[-5].string));
    }
#line 2137 "yacc_sql.cpp"
    break;

  case 51: /* value_list: %empty  */
#line 462 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2145 "yacc_sql.cpp"
    break;

  case 52: /* value_list: COMMA value value_list  */
#line 465 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2159 "yacc_sql.cpp"
    break;

  case 53: /* value: NUMBER  */
#line 476 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2168 "yacc_sql.cpp"
    break;

  case 54: /* value: '-' NUMBER  */
#line 481 "yacc_sql.y"
               {
      (yyval.value) = new Value(-(int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2177 "yacc_sql.cpp"
    break;

  case 55: /* value: FLOAT  */
#line 486 "yacc_sql.y"
          {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2186 "yacc_sql.cpp"
    break;

  case 56: /* value: '-' FLOAT  */
#line 491 "yacc_sql.y"
              {
      (yyval.value) = new Value(-(float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2195 "yacc_sql.cpp"
    break;

  case 57: /* value: SSS  */
#line 496 "yacc_sql.y"
        {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2206 "yacc_sql.cpp"
    break;

  case 58: /* value: DATE  */
#line 503 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = Value::from_date(tmp);
      if (!(yyval.value)->is_date_valid()) {
        (yyval.value)->reset();
      }
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2220 "yacc_sql.cpp"
    break;

  case 59: /* value: VECTOR  */
#line 513 "yacc_sql.y"
           {
      // 如果以双引号或单引号开头，去掉头尾的引号
      if ((yyvsp[0].string)[0] == '\"' || (yyvsp[0].string)[0] == '\'') {
        char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
        (yyval.value) = Value::from_vector(tmp);
        free(tmp);
      } else {
        (yyval.value) = Value::from_vector((yyvsp[0].string));
      }
      free((yyvsp[0].string));
    }
#line 2236 "yacc_sql.cpp"
    break;

  case 60: /* value: NULL_T  */
#line 525 "yacc_sql.y"
           {
      (yyval.value) = new Value();
      (yyval.value)->set_null();
      (yyloc) = (yylsp[0]);
    }
#line 2246 "yacc_sql.cpp"
    break;

  case 61: /* storage_format: %empty  */
#line 533 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2254 "yacc_sql.cpp"
    break;

  case 62: /* storage_format: STORAGE FORMAT EQ ID  */
#line 537 "yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2262 "yacc_sql.cpp"
    break;

  case 63: /* delete_stmt: DELETE FROM ID where  */
#line 544 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2276 "yacc_sql.cpp"
    break;

  case 64: /* update_list: ID EQ expression COMMA update_list  */
#line 556 "yacc_sql.y"
    {
        (yyval.update_info_list) = (yyvsp[0].update_info_list);
        (yyval.update_info_list)->emplace_back(std::string((yyvsp[-4].string)), (yyvsp[-2].expression));
        free((yyvsp[-4].string));
    }
#line 2286 "yacc_sql.cpp"
    break;

  case 65: /* update_list: ID EQ expression  */
#line 562 "yacc_sql.y"
    {
        (yyval.update_info_list) = new std::vector<UpdateInfoNode>();
        (yyval.update_info_list)->emplace_back(std::string((yyvsp[-2].string)), (yyvsp[0].expression));
        free((yyvsp[-2].string));
    }
#line 2296 "yacc_sql.cpp"
    break;

  case 66: /* update_stmt: UPDATE ID SET update_list where  */
#line 570 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-3].string);
      (yyval.sql_node)->update.update_infos = *(yyvsp[-1].update_info_list);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-3].string));
      delete (yyvsp[-1].update_info_list);
    }
#line 2312 "yacc_sql.cpp"
    break;

  case 67: /* select_stmt: SELECT expression_list FROM rel_list join_list where group_by order_by  */
#line 584 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-6].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[-6].expression_list));
        delete (yyvsp[-6].expression_list);
      }

      // from
      if ((yyvsp[-4].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-4].relation_list));
        std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());
        delete (yyvsp[-4].relation_list);
      }

      // join
      if ((yyvsp[-3].join_list) != nullptr) {
        /* 由于是递归顺序解析的join，需要 reverse */
        std::reverse((yyvsp[-3].join_list)->begin(), (yyvsp[-3].join_list)->end());
        for (auto &join : *(yyvsp[-3].join_list)) {
          (yyval.sql_node)->selection.relations.push_back(join.relation);
          for (auto &condition : join.conditions) {
            (yyval.sql_node)->selection.conditions.emplace_back(std::move(condition));
          }
        }
        // delete $5; // TODO(Soulter): free test
      }

      // where
      if ((yyvsp[-2].condition_list) != nullptr) {
        // $$->selection.conditions.swap(*$6);
        for (auto &condition : *(yyvsp[-2].condition_list)) {
          (yyval.sql_node)->selection.conditions.emplace_back(std::move(condition));
        }
        std::reverse((yyval.sql_node)->selection.conditions.begin(), (yyval.sql_node)->selection.conditions.end());
        delete (yyvsp[-2].condition_list);
      }

      // group by
      if ((yyvsp[-1].expression_list) != nullptr) {
        (yyval.sql_node)->selection.group_by.swap(*(yyvsp[-1].expression_list));
        delete (yyvsp[-1].expression_list);
      }

      // order by
      if ((yyvsp[0].order_by_list) != nullptr) {
        (yyval.sql_node)->selection.order_by.swap(*(yyvsp[0].order_by_list));
        std::reverse((yyval.sql_node)->selection.order_by.begin(), (yyval.sql_node)->selection.order_by.end());
        delete (yyvsp[0].order_by_list);
      }
    }
#line 2367 "yacc_sql.cpp"
    break;

  case 68: /* calc_stmt: CALC expression_list  */
#line 637 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2377 "yacc_sql.cpp"
    break;

  case 69: /* expression_list: expression  */
#line 646 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2386 "yacc_sql.cpp"
    break;

  case 70: /* expression_list: expression COMMA expression_list  */
#line 651 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-2].expression));
    }
#line 2399 "yacc_sql.cpp"
    break;

  case 71: /* expression: COUNT LBRACE expression RBRACE  */
#line 662 "yacc_sql.y"
    {
      (yyval.expression) = create_aggregate_expression(AggregateType::COUNT, (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2407 "yacc_sql.cpp"
    break;

  case 72: /* expression: MAX LBRACE expression RBRACE  */
#line 666 "yacc_sql.y"
    {
      (yyval.expression) = create_aggregate_expression(AggregateType::MAX, (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2415 "yacc_sql.cpp"
    break;

  case 73: /* expression: MIN LBRACE expression RBRACE  */
#line 670 "yacc_sql.y"
    {
      (yyval.expression) = create_aggregate_expression(AggregateType::MIN, (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2423 "yacc_sql.cpp"
    break;

  case 74: /* expression: AVG LBRACE expression RBRACE  */
#line 674 "yacc_sql.y"
    {
      (yyval.expression) = create_aggregate_expression(AggregateType::AVG, (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2431 "yacc_sql.cpp"
    break;

  case 75: /* expression: SUM LBRACE expression RBRACE  */
#line 678 "yacc_sql.y"
    {
      (yyval.expression) = create_aggregate_expression(AggregateType::SUM, (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2439 "yacc_sql.cpp"
    break;

  case 76: /* expression: expression '+' expression  */
#line 681 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2447 "yacc_sql.cpp"
    break;

  case 77: /* expression: expression '-' expression  */
#line 684 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2455 "yacc_sql.cpp"
    break;

  case 78: /* expression: expression '*' expression  */
#line 687 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2463 "yacc_sql.cpp"
    break;

  case 79: /* expression: expression '/' expression  */
#line 690 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2471 "yacc_sql.cpp"
    break;

  case 80: /* expression: LBRACE select_stmt RBRACE  */
#line 693 "yacc_sql.y"
                                {
      (yyval.expression) = new SubqueryExpr((yyvsp[-1].sql_node));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2480 "yacc_sql.cpp"
    break;

  case 81: /* expression: LBRACE expression RBRACE  */
#line 697 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2489 "yacc_sql.cpp"
    break;

  case 82: /* expression: '-' expression  */
#line 701 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, nullptr, (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2497 "yacc_sql.cpp"
    break;

  case 83: /* expression: value  */
#line 704 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2507 "yacc_sql.cpp"
    break;

  case 84: /* expression: LBRACE value value_list RBRACE  */
#line 709 "yacc_sql.y"
                                      {
      std::vector<Value> *values = (yyvsp[-1].value_list);
      values->emplace_back(*(yyvsp[-2].value));
      (yyval.expression) = new ValueListExpr(*values);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2518 "yacc_sql.cpp"
    break;

  case 85: /* expression: rel_attr  */
#line 715 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2529 "yacc_sql.cpp"
    break;

  case 86: /* expression: '*'  */
#line 721 "yacc_sql.y"
          {
      (yyval.expression) = new StarExpr();
    }
#line 2537 "yacc_sql.cpp"
    break;

  case 87: /* expression: L2_DISTANCE LBRACE expression COMMA expression RBRACE  */
#line 724 "yacc_sql.y"
                                                            {
      (yyval.expression) = new VectorDistanceExpr(VectorDistanceExpr::Type::L2_DISTANCE, (yyvsp[-3].expression), (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2546 "yacc_sql.cpp"
    break;

  case 88: /* expression: COSINE_DISTANCE LBRACE expression COMMA expression RBRACE  */
#line 728 "yacc_sql.y"
                                                                {
      (yyval.expression) = new VectorDistanceExpr(VectorDistanceExpr::Type::COSINE_DISTANCE, (yyvsp[-3].expression), (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2555 "yacc_sql.cpp"
    break;

  case 89: /* expression: INNER_PRODUCT LBRACE expression COMMA expression RBRACE  */
#line 732 "yacc_sql.y"
                                                              {
      (yyval.expression) = new VectorDistanceExpr(VectorDistanceExpr::Type::INNER_PRODUCT, (yyvsp[-3].expression), (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2564 "yacc_sql.cpp"
    break;

  case 90: /* rel_attr: ID  */
#line 739 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2574 "yacc_sql.cpp"
    break;

  case 91: /* rel_attr: ID DOT ID  */
#line 744 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2586 "yacc_sql.cpp"
    break;

  case 92: /* relation: ID  */
#line 754 "yacc_sql.y"
       {
      (yyval.relation) = new RelationSqlNode;
      (yyval.relation)->name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2596 "yacc_sql.cpp"
    break;

  case 93: /* relation: ID AS ID  */
#line 759 "yacc_sql.y"
               {
      (yyval.relation) = new RelationSqlNode;
      (yyval.relation)->name = (yyvsp[-2].string);
      (yyval.relation)->alias = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2608 "yacc_sql.cpp"
    break;

  case 94: /* relation: ID ID  */
#line 766 "yacc_sql.y"
            {
      (yyval.relation) = new RelationSqlNode;
      (yyval.relation)->name = (yyvsp[-1].string);
      (yyval.relation)->alias = (yyvsp[0].string);
      free((yyvsp[-1].string));
      free((yyvsp[0].string));
    }
#line 2620 "yacc_sql.cpp"
    break;

  case 95: /* rel_list: relation  */
#line 776 "yacc_sql.y"
             {
      // $$ = new std::vector<std::string>();
      // $$->push_back($1);
      // free($1);
      (yyval.relation_list) = new std::vector<RelationSqlNode>;
      (yyval.relation_list)->emplace_back(*(yyvsp[0].relation));
      // free($1);
      delete (yyvsp[0].relation);
    }
#line 2634 "yacc_sql.cpp"
    break;

  case 96: /* rel_list: relation COMMA rel_list  */
#line 785 "yacc_sql.y"
                              {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<RelationSqlNode>;
      }
      (yyval.relation_list)->emplace_back(*(yyvsp[-2].relation));
      // free($1);
      delete (yyvsp[-2].relation);
    }
#line 2649 "yacc_sql.cpp"
    break;

  case 97: /* join_list: %empty  */
#line 799 "yacc_sql.y"
    {
      (yyval.join_list) = nullptr;
    }
#line 2657 "yacc_sql.cpp"
    break;

  case 98: /* join_list: INNER_JOIN relation ON condition_list join_list  */
#line 802 "yacc_sql.y"
                                                      {
      if ((yyvsp[0].join_list) != nullptr) {
        (yyval.join_list) = (yyvsp[0].join_list);
      } else {
        (yyval.join_list) = new std::vector<JoinSqlNode>;
      }

      JoinSqlNode join1;
      join1.relation = *(yyvsp[-3].relation);
      delete (yyvsp[-3].relation);
      // reverse
      std::reverse((yyvsp[-1].condition_list)->begin(), (yyvsp[-1].condition_list)->end());
      for (auto &condition : *(yyvsp[-1].condition_list)) {
        join1.conditions.emplace_back(std::move(condition));
      }
      (yyval.join_list)->emplace_back(std::move(join1));
    }
#line 2679 "yacc_sql.cpp"
    break;

  case 99: /* where: %empty  */
#line 823 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2687 "yacc_sql.cpp"
    break;

  case 100: /* where: WHERE condition_list  */
#line 826 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2695 "yacc_sql.cpp"
    break;

  case 101: /* condition_list: %empty  */
#line 832 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2703 "yacc_sql.cpp"
    break;

  case 102: /* condition_list: condition  */
#line 835 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->push_back(std::move(*(yyvsp[0].condition)));
      delete (yyvsp[0].condition);
    }
#line 2713 "yacc_sql.cpp"
    break;

  case 103: /* condition_list: condition AND condition_list  */
#line 840 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->push_back(std::move(*(yyvsp[-2].condition)));
      delete (yyvsp[-2].condition);
    }
#line 2723 "yacc_sql.cpp"
    break;

  case 104: /* condition: expression comp_op expression  */
#line 848 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_expr = std::unique_ptr<Expression>((yyvsp[-2].expression));
      (yyval.condition)->right_expr = std::unique_ptr<Expression>((yyvsp[0].expression));
      (yyval.condition)->comp_op = (yyvsp[-1].comp);
    }
#line 2734 "yacc_sql.cpp"
    break;

  case 105: /* condition: EXISTS expression  */
#line 856 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->comp_op = CompOp::EXISTS;
      // left_expr: SpecialPlaceholderExpr
      (yyval.condition)->left_expr = std::make_unique<SpecialPlaceholderExpr>();
      (yyval.condition)->right_expr = std::unique_ptr<Expression>((yyvsp[0].expression));
    }
#line 2746 "yacc_sql.cpp"
    break;

  case 106: /* condition: NOT_EXISTS expression  */
#line 864 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->comp_op = CompOp::NOT_EXISTS;
      (yyval.condition)->left_expr = std::make_unique<SpecialPlaceholderExpr>();
      (yyval.condition)->right_expr = std::unique_ptr<Expression>((yyvsp[0].expression));
    }
#line 2757 "yacc_sql.cpp"
    break;

  case 107: /* comp_op: EQ  */
#line 873 "yacc_sql.y"
         { (yyval.comp) = CompOp::EQUAL_TO; }
#line 2763 "yacc_sql.cpp"
    break;

  case 108: /* comp_op: LT  */
#line 874 "yacc_sql.y"
         { (yyval.comp) = CompOp::LESS_THAN; }
#line 2769 "yacc_sql.cpp"
    break;

  case 109: /* comp_op: GT  */
#line 875 "yacc_sql.y"
         { (yyval.comp) = CompOp::GREAT_THAN; }
#line 2775 "yacc_sql.cpp"
    break;

  case 110: /* comp_op: LE  */
#line 876 "yacc_sql.y"
         { (yyval.comp) = CompOp::LESS_EQUAL; }
#line 2781 "yacc_sql.cpp"
    break;

  case 111: /* comp_op: GE  */
#line 877 "yacc_sql.y"
         { (yyval.comp) = CompOp::GREAT_EQUAL; }
#line 2787 "yacc_sql.cpp"
    break;

  case 112: /* comp_op: NE  */
#line 878 "yacc_sql.y"
         { (yyval.comp) = CompOp::NOT_EQUAL; }
#line 2793 "yacc_sql.cpp"
    break;

  case 113: /* comp_op: LIKE  */
#line 879 "yacc_sql.y"
           { (yyval.comp) = CompOp::LIKE; }
#line 2799 "yacc_sql.cpp"
    break;

  case 114: /* comp_op: NOT LIKE  */
#line 880 "yacc_sql.y"
               { (yyval.comp) = CompOp::NOT_LIKE; }
#line 2805 "yacc_sql.cpp"
    break;

  case 115: /* comp_op: IS  */
#line 881 "yacc_sql.y"
         { (yyval.comp) = CompOp::IS; }
#line 2811 "yacc_sql.cpp"
    break;

  case 116: /* comp_op: IS NOT  */
#line 882 "yacc_sql.y"
             { (yyval.comp) = CompOp::NOT_IS; }
#line 2817 "yacc_sql.cpp"
    break;

  case 117: /* comp_op: IN  */
#line 883 "yacc_sql.y"
         { (yyval.comp) = CompOp::IN; }
#line 2823 "yacc_sql.cpp"
    break;

  case 118: /* comp_op: NOT_IN  */
#line 884 "yacc_sql.y"
             { (yyval.comp) = CompOp::NOT_IN; }
#line 2829 "yacc_sql.cpp"
    break;

  case 119: /* comp_op: EXISTS  */
#line 885 "yacc_sql.y"
             { (yyval.comp) = CompOp::EXISTS; }
#line 2835 "yacc_sql.cpp"
    break;

  case 120: /* comp_op: NOT_EXISTS  */
#line 886 "yacc_sql.y"
                 { (yyval.comp) = CompOp::NOT_EXISTS; }
#line 2841 "yacc_sql.cpp"
    break;

  case 121: /* group_by: %empty  */
#line 891 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 2849 "yacc_sql.cpp"
    break;

  case 122: /* group_by: GROUP BY expression_list  */
#line 895 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2859 "yacc_sql.cpp"
    break;

  case 123: /* order_by: %empty  */
#line 904 "yacc_sql.y"
    {
      (yyval.order_by_list) = nullptr;
    }
#line 2867 "yacc_sql.cpp"
    break;

  case 124: /* order_by: ORDER BY order_by_list  */
#line 908 "yacc_sql.y"
    {
      (yyval.order_by_list) = new std::vector<OrderBySqlNode>;
      (yyval.order_by_list)->swap(*(yyvsp[0].order_by_list));
      delete (yyvsp[0].order_by_list);
    }
#line 2877 "yacc_sql.cpp"
    break;

  case 125: /* order_by_list: order_by_item  */
#line 917 "yacc_sql.y"
    {
      (yyval.order_by_list) = new std::vector<OrderBySqlNode>;
      (yyval.order_by_list)->push_back(std::move(*(yyvsp[0].order_by_node)));
      delete (yyvsp[0].order_by_node);
    }
#line 2887 "yacc_sql.cpp"
    break;

  case 126: /* order_by_list: order_by_item COMMA order_by_list  */
#line 923 "yacc_sql.y"
    {
      (yyval.order_by_list) = (yyvsp[0].order_by_list);
      (yyval.order_by_list)->push_back(std::move(*(yyvsp[-2].order_by_node)));
      delete (yyvsp[-2].order_by_node);
    }
#line 2897 "yacc_sql.cpp"
    break;

  case 127: /* order_by_item: expression  */
#line 932 "yacc_sql.y"
    {
      (yyval.order_by_node) = new OrderBySqlNode;
      (yyval.order_by_node)->expression = std::unique_ptr<Expression>((yyvsp[0].expression));
      (yyval.order_by_node)->is_desc = false;
    }
#line 2907 "yacc_sql.cpp"
    break;

  case 128: /* order_by_item: expression ASC  */
#line 938 "yacc_sql.y"
    {
      (yyval.order_by_node) = new OrderBySqlNode;
      (yyval.order_by_node)->expression = std::unique_ptr<Expression>((yyvsp[-1].expression));
      (yyval.order_by_node)->is_desc = false;
    }
#line 2917 "yacc_sql.cpp"
    break;

  case 129: /* order_by_item: expression DESC  */
#line 944 "yacc_sql.y"
    {
      (yyval.order_by_node) = new OrderBySqlNode;
      (yyval.order_by_node)->expression = std::unique_ptr<Expression>((yyvsp[-1].expression));
      (yyval.order_by_node)->is_desc = true;
    }
#line 2927 "yacc_sql.cpp"
    break;

  case 130: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 953 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 2941 "yacc_sql.cpp"
    break;

  case 131: /* explain_stmt: EXPLAIN command_wrapper  */
#line 966 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 2950 "yacc_sql.cpp"
    break;

  case 132: /* set_variable_stmt: SET ID EQ value  */
#line 974 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 2962 "yacc_sql.cpp"
    break;


#line 2966 "yacc_sql.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 986 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
