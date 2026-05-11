/*
 * Declarations for semantic action routines
 */
#include "config.h"

extern boolean is_typedef_name(char *name);
void
new_decl_spec(DeclSpec *decl_spec, char *text, int flags);

extern void join_decl_specs(DeclSpec *result, DeclSpec *a, DeclSpec *b);
extern void free_decl_spec(DeclSpec *decl_spec);
void
new_parameter(Parameter *param, /* pointer to structure to be initialized */ DeclSpec *decl_spec, /* declaration specifier structure */ Declarator *declarator, /* declarator structure */ char *comment_before, /* comment before the param */ char *comment_after);

extern void free_parameter(Parameter *param);

/* add a comment to the last declarator in the list */
int
comment_last_decl(DeclaratorList *list, char *comment);

/* add a comment to the last parameter in the list */
int
comment_last_parameter(ParameterList *list, char *comment);

extern void new_param_list(ParameterList *param_list, Parameter *param);

extern void add_param_list(ParameterList *to, ParameterList *from, Parameter *param);
extern void free_param_list(ParameterList *param_list);
extern void new_ident_list(ParameterList *param_list);
extern void add_ident_list(ParameterList *to, ParameterList *from, Identifier *ident);
extern Declarator * new_declarator(char *text, char *name);
extern void free_declarator(Declarator *d);
extern void new_decl_list(DeclaratorList *decl_list, Declarator *declarator);
extern void add_decl_list(DeclaratorList *to, DeclaratorList *from, Declarator *declarator);
extern void free_decl_list(DeclaratorList *decl_list);
extern void set_param_types(ParameterList *params, DeclSpec *decl_spec, DeclaratorList *declarators, char *comment, char *eolcomment);

/* Output a function parameter.*/
void output_parameter(Parameter *p);

int
remember_declarations(char *comment, /* comment associated */ DeclSpec *decl_spec, /* declaration specifier */ DeclaratorList *decl_list, /* list of declared variables */ char *eolcomment);

void
dyn_decl_spec(DeclSpec *decl_spec, char *text, unsigned int flags);

void
new_enum_decl_spec(DeclSpec *decl_spec, char *text, int flags, EnumeratorList *enum_list);

void
output_decl_spec(DeclSpec *decl_spec);

void
output_declarator(Declarator *d, boolean format);

void parameter_error(Parameter *param);
void declarator_error(Declarator *decl);

boolean has_parameters(const Declarator *d);
boolean is_function_declarator(const Declarator *d);

boolean is_numbered(const char *text);
