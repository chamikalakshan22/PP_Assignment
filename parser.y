%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int line_num;
void yyerror(const char *s);

FILE *output_file;

// Data structures for form representation
typedef struct {
    char *key;
    char *value;
} MetaData;

typedef struct {
    char *name;
    char *value;
} Attribute;

typedef struct {
    char *name;
    char *type;
    Attribute attributes[20];
    int attr_count;
} Field;

typedef struct {
    char *name;
    Field fields[50];
    int field_count;
} Section;

typedef struct {
    char *field_name;
    char *operator;
    double value;
    char *error_msg;
} ValidationRule;

typedef struct {
    char *name;
    MetaData metadata[10];
    int meta_count;
    Section sections[20];
    int section_count;
    ValidationRule validations[10];
    int validation_count;
} Form;

Form current_form;
Section current_section;
Field current_field;
ValidationRule current_validation;

// Function prototypes
void add_metadata(char *key, char *value);
void add_section(char *name);
void add_field(char *name, char *type);
void add_attribute(char *name, char *value);
void add_validation(char *field, char *op, double val, char *error);
void generate_html();
char* strip_quotes(char *str);
%}

%union {
    char *str;
    double num;
    int boolean;
}

/* Tokens */
%token FORM META SECTION FIELD VALIDATE IF ERROR
%token TEXT TEXTAREA NUMBER_TYPE EMAIL DATE CHECKBOX DROPDOWN RADIO PASSWORD FILE_FIELD
%token REQUIRED PATTERN DEFAULT MIN MAX ROWS COLS OPTIONS ACCEPT
%token LBRACE RBRACE LBRACKET RBRACKET LPAREN RPAREN
%token SEMICOLON COMMA COLON EQUALS
%token LT GT LE GE EQ NE
%token <str> IDENTIFIER STRING
%token <num> NUMBER
%token <boolean> BOOLEAN

/* Non-terminals */
%type <str> field_type string_list

/* Precedence and associativity */
%left LT GT LE GE EQ NE

%%

program:
    form {
        generate_html();
        
    }
;

form:
    FORM IDENTIFIER LBRACE form_body RBRACE {
        current_form.name = strdup($2);
        free($2);
    }
;

form_body:
    meta_list section_list
    | meta_list section_list validate_block
    | section_list
    | section_list validate_block
;

meta_list:
    /* empty */
    | meta_list meta_stmt
;

meta_stmt:
    META IDENTIFIER EQUALS STRING SEMICOLON {
        add_metadata($2, $4);
        free($2);
        free($4);
    }
;

section_list:
    section_stmt
    | section_list section_stmt
;

section_stmt:
    SECTION IDENTIFIER LBRACE {
        add_section($2);
        free($2);
    } field_list RBRACE
;

field_list:
    field_stmt
    | field_list field_stmt
;

field_stmt:
    FIELD IDENTIFIER COLON field_type attribute_list SEMICOLON {
        add_field($2, $4);
        free($2);
        free($4);
    }
    | FIELD IDENTIFIER COLON field_type SEMICOLON {
        add_field($2, $4);
        free($2);
        free($4);
    }
;

field_type:
    TEXT { $$ = strdup("text"); }
    | TEXTAREA { $$ = strdup("textarea"); }
    | NUMBER_TYPE { $$ = strdup("number"); }
    | EMAIL { $$ = strdup("email"); }
    | DATE { $$ = strdup("date"); }
    | CHECKBOX { $$ = strdup("checkbox"); }
    | DROPDOWN { $$ = strdup("select"); }
    | RADIO { $$ = strdup("radio"); }
    | PASSWORD { $$ = strdup("password"); }
    | FILE_FIELD { $$ = strdup("file"); }
;

attribute_list:
    attribute
    | attribute_list attribute
;

attribute:
    REQUIRED {
        add_attribute("required", "required");
    }
    | PATTERN EQUALS STRING {
        add_attribute("pattern", $3);
        free($3);
    }
    | DEFAULT EQUALS STRING {
        add_attribute("value", $3);
        free($3);
    }
    | DEFAULT EQUALS NUMBER {
        char buf[50];
        sprintf(buf, "%.0f", $3);
        add_attribute("value", buf);
    }
    | DEFAULT EQUALS BOOLEAN {
        add_attribute("checked", $3 ? "checked" : "");
    }
    | MIN EQUALS NUMBER {
        char buf[50];
        sprintf(buf, "%.0f", $3);
        add_attribute("min", buf);
    }
    | MAX EQUALS NUMBER {
        char buf[50];
        sprintf(buf, "%.0f", $3);
        add_attribute("max", buf);
    }
    | ROWS EQUALS NUMBER {
        char buf[50];
        sprintf(buf, "%.0f", $3);
        add_attribute("rows", buf);
    }
    | COLS EQUALS NUMBER {
        char buf[50];
        sprintf(buf, "%.0f", $3);
        add_attribute("cols", buf);
    }
    | OPTIONS EQUALS LBRACKET string_list RBRACKET {
        add_attribute("options", $4);
        free($4);
    }
    | ACCEPT EQUALS STRING {
        add_attribute("accept", $3);
        free($3);
    }
;

string_list:
    STRING {
        $$ = strdup($1);
        free($1);
    }
    | string_list COMMA STRING {
        char *result = malloc(strlen($1) + strlen($3) + 2);
        sprintf(result, "%s,%s", $1, $3);
        free($1);
        free($3);
        $$ = result;
    }
;

validate_block:
    VALIDATE LBRACE validation_rules RBRACE
;

validation_rules:
    validation_rule
    | validation_rules validation_rule
;

validation_rule:
    IF IDENTIFIER LT NUMBER LBRACE ERROR STRING SEMICOLON RBRACE {
        add_validation($2, "<", $4, $7);
        free($2);
        free($7);
    }
    | IF IDENTIFIER GT NUMBER LBRACE ERROR STRING SEMICOLON RBRACE {
        add_validation($2, ">", $4, $7);
        free($2);
        free($7);
    }
    | IF IDENTIFIER LE NUMBER LBRACE ERROR STRING SEMICOLON RBRACE {
        add_validation($2, "<=", $4, $7);
        free($2);
        free($7);
    }
    | IF IDENTIFIER GE NUMBER LBRACE ERROR STRING SEMICOLON RBRACE {
        add_validation($2, ">=", $4, $7);
        free($2);
        free($7);
    }
    | IF IDENTIFIER EQ NUMBER LBRACE ERROR STRING SEMICOLON RBRACE {
        add_validation($2, "==", $4, $7);
        free($2);
        free($7);
    }
    | IF IDENTIFIER NE NUMBER LBRACE ERROR STRING SEMICOLON RBRACE {
        add_validation($2, "!=", $4, $7);
        free($2);
        free($7);
    }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parse error at line %d: %s\n", line_num, s);
}

void add_metadata(char *key, char *value) {
    if (current_form.meta_count < 10) {
        current_form.metadata[current_form.meta_count].key = strdup(key);
        current_form.metadata[current_form.meta_count].value = strdup(strip_quotes(value));
        current_form.meta_count++;
    }
}

void add_section(char *name) {
    if (current_form.section_count < 20) {
        current_section.name = strdup(name);
        current_section.field_count = 0;
    }
}

void add_field(char *name, char *type) {
    if (current_section.field_count < 50) {
        current_field.name = strdup(name);
        current_field.type = strdup(type);
        current_field.attr_count = 0;
        
        // Add the field to current section
        current_section.fields[current_section.field_count] = current_field;
        current_section.field_count++;
        
        // Add section to form if this is the first field
        if (current_section.field_count == 1 || 
            current_form.section_count == 0 || 
            strcmp(current_form.sections[current_form.section_count-1].name, current_section.name) != 0) {
            current_form.sections[current_form.section_count] = current_section;
            current_form.section_count++;
        } else {
            // Update existing section
            current_form.sections[current_form.section_count-1] = current_section;
        }
    }
}

void add_attribute(char *name, char *value) {
    if (current_field.attr_count < 20) {
        current_field.attributes[current_field.attr_count].name = strdup(name);
        current_field.attributes[current_field.attr_count].value = strdup(value);
        current_field.attr_count++;
    }
}

void add_validation(char *field, char *op, double val, char *error) {
    if (current_form.validation_count < 10) {
        current_validation.field_name = strdup(field);
        current_validation.operator = strdup(op);
        current_validation.value = val;
        current_validation.error_msg = strdup(strip_quotes(error));
        current_form.validations[current_form.validation_count] = current_validation;
        current_form.validation_count++;
    }
}

char* strip_quotes(char *str) {
    if (str[0] == '"' && str[strlen(str)-1] == '"') {
        str[strlen(str)-1] = '\0';
        return str + 1;
    }
    return str;
}

void generate_html() {
    output_file = fopen("output.html", "w");
    if (!output_file) {
        fprintf(stderr, "Error: Cannot create output.html\n");
        return;
    }
    
    // HTML header
    fprintf(output_file, "<!DOCTYPE html>\n");
    fprintf(output_file, "<html lang=\"en\">\n");
    fprintf(output_file, "<head>\n");
    fprintf(output_file, "    <meta charset=\"UTF-8\">\n");
    fprintf(output_file, "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    fprintf(output_file, "    <title>%s</title>\n", current_form.name);
    fprintf(output_file, "    <style>\n");
    fprintf(output_file, "        body { font-family: Arial, sans-serif; max-width: 600px; margin: 0 auto; padding: 20px; }\n");
    fprintf(output_file, "        .section { margin-bottom: 30px; padding: 20px; border: 1px solid #ddd; border-radius: 5px; }\n");
    fprintf(output_file, "        .section h2 { margin-top: 0; color: #333; }\n");
    fprintf(output_file, "        .field { margin-bottom: 15px; }\n");
    fprintf(output_file, "        label { display: block; margin-bottom: 5px; font-weight: bold; }\n");
    fprintf(output_file, "        input, textarea, select { width: 100%%; padding: 8px; border: 1px solid #ccc; border-radius: 4px; box-sizing: border-box; }\n");
    fprintf(output_file, "        input[type=\"checkbox\"], input[type=\"radio\"] { width: auto; margin-right: 5px; }\n");
    fprintf(output_file, "        .radio-group { margin-top: 5px; }\n");
    fprintf(output_file, "        .radio-option { margin-bottom: 5px; }\n");
    fprintf(output_file, "        .error { color: red; font-size: 0.9em; margin-top: 5px; }\n");
    fprintf(output_file, "    </style>\n");
    fprintf(output_file, "</head>\n");
    fprintf(output_file, "<body>\n");
    
    // Form metadata as comments
    for (int i = 0; i < current_form.meta_count; i++) {
        fprintf(output_file, "<!-- %s: %s -->\n", 
                current_form.metadata[i].key, current_form.metadata[i].value);
    }
    
    fprintf(output_file, "    <h1>%s</h1>\n", current_form.name);
    fprintf(output_file, "    <form name=\"%s\" id=\"%s\">\n", current_form.name, current_form.name);
    
// Generate sections and fields
for (int i = 0; i < current_form.section_count; i++) {
    Section sec = current_form.sections[i];
    fprintf(output_file, "        <div class=\"section\">\n");
    fprintf(output_file, "            <h2>%s</h2>\n", sec.name);

    for (int j = 0; j < sec.field_count; j++) {
        Field field = sec.fields[j];
        fprintf(output_file, "            <div class=\"field\">\n");

        if (strcmp(field.type, "radio") == 0) {
            // Handle radio buttons
            fprintf(output_file, "                <label>%s:</label>\n", field.name);
            fprintf(output_file, "                <div class=\"radio-group\">\n");
            // Find options attribute
            char *options = NULL;
            for (int k = 0; k < field.attr_count; k++) {
                if (strcmp(field.attributes[k].name, "options") == 0) {
                    options = field.attributes[k].value;
                    break;
                }
            }
            if (options) {
                char *opt_copy = strdup(options);
                char *token = strtok(opt_copy, ",");
                while (token) {
                    char *clean_token = strip_quotes(token);
                    fprintf(output_file, "                    <div class=\"radio-option\">\n");
                    fprintf(output_file, "                        <input type=\"radio\" name=\"%s\" value=\"%s\" id=\"%s_%s\">\n", 
                            field.name, clean_token, field.name, clean_token);
                    fprintf(output_file, "                        <label for=\"%s_%s\">%s</label>\n", 
                            field.name, clean_token, clean_token);
                    fprintf(output_file, "                    </div>\n");
                    token = strtok(NULL, ",");
                }
                free(opt_copy);
            }
            fprintf(output_file, "                </div>\n");

        } else if (strcmp(field.type, "checkbox") == 0) {
            // Handle checkbox
            fprintf(output_file, "                <label>\n");
            fprintf(output_file, "                    <input type=\"checkbox\" name=\"%s\"", field.name);
            // Add attributes
            for (int k = 0; k < field.attr_count; k++) {
                if (strcmp(field.attributes[k].name, "checked") == 0 && 
                    strlen(field.attributes[k].value) > 0) {
                    fprintf(output_file, " checked");
                }
            }
            fprintf(output_file, ">\n");
            fprintf(output_file, "                    %s\n", field.name);
            fprintf(output_file, "                </label>\n");

        } else if (strcmp(field.type, "textarea") == 0) {
            // Handle textarea
            fprintf(output_file, "                <label for=\"%s\">%s:</label>\n", field.name, field.name);
            fprintf(output_file, "                <textarea name=\"%s\" id=\"%s\"", field.name, field.name);
            // Add attributes
            for (int k = 0; k < field.attr_count; k++) {
                if (strcmp(field.attributes[k].name, "value") != 0) {
                    fprintf(output_file, " %s=\"%s\"", 
                            field.attributes[k].name, field.attributes[k].value);
                }
            }
            fprintf(output_file, ">");
            // Add default value inside textarea
            for (int k = 0; k < field.attr_count; k++) {
                if (strcmp(field.attributes[k].name, "value") == 0) {
                    fprintf(output_file, "%s", field.attributes[k].value);
                    break;
                }
            }
            fprintf(output_file, "</textarea>\n");

        } else if (strcmp(field.type, "select") == 0) {
            // Handle dropdown/select
            fprintf(output_file, "                <label for=\"%s\">%s:</label>\n", field.name, field.name);
            fprintf(output_file, "                <select name=\"%s\" id=\"%s\"", field.name, field.name);
            // Add other attributes except "options"
            for (int k = 0; k < field.attr_count; k++) {
                if (strcmp(field.attributes[k].name, "options") != 0) {
                    fprintf(output_file, " %s=\"%s\"", 
                            field.attributes[k].name, field.attributes[k].value);
                }
            }
            fprintf(output_file, ">\n");
            // Add options
            char *options = NULL;
            for (int k = 0; k < field.attr_count; k++) {
            if (strcmp(field.attributes[k].name, "options") == 0) {
             options = field.attributes[k].value;
              break;
            }
}
            if (options) {
    char *opt_copy = strdup(options);
    char *start = opt_copy;
    while (*start) {
        // Skip whitespace and commas
        while (*start == ' ' || *start == ',') start++;
        if (*start == '\0') break;
        // Find start of quoted string
        if (*start == '"') start++;
        char *end = start;
        while (*end && *end != '"') end++;
        char tmp = *end;
        *end = '\0';
        fprintf(output_file, "    <option value=\"%s\">%s</option>\n", start, start);
        *end = tmp;
        start = end;
        if (*start == '"') start++;
        while (*start == ',' || *start == ' ') start++;
    }
    free(opt_copy);
}
            fprintf(output_file, "                </select>\n");

        } else {
            // Handle regular input fields
            fprintf(output_file, "                <label for=\"%s\">%s:</label>\n", field.name, field.name);
            fprintf(output_file, "                <input type=\"%s\" name=\"%s\" id=\"%s\"", 
                    field.type, field.name, field.name);
            // Add attributes
            for (int k = 0; k < field.attr_count; k++) {
                if (strcmp(field.attributes[k].name, "options") != 0) {
                    fprintf(output_file, " %s=\"%s\"", 
                            field.attributes[k].name, field.attributes[k].value);
                }
            }
            fprintf(output_file, ">\n");
        }

        fprintf(output_file, "            </div>\n");
    }

    fprintf(output_file, "        </div>\n");
}

fprintf(output_file, "        <button type=\"submit\">Submit</button>\n");
fprintf(output_file, "    </form>\n");
    
    // Add JavaScript validation if needed
    if (current_form.validation_count > 0) {
        fprintf(output_file, "    <script>\n");
        fprintf(output_file, "        document.getElementById('%s').addEventListener('submit', function(e) {\n", current_form.name);
        fprintf(output_file, "            let isValid = true;\n");
        fprintf(output_file, "            let errors = [];\n");
        
        for (int i = 0; i < current_form.validation_count; i++) {
            ValidationRule rule = current_form.validations[i];
            fprintf(output_file, "            let %s = parseFloat(document.getElementById('%s').value);\n", 
                    rule.field_name, rule.field_name);
            fprintf(output_file, "            if (%s %s %.0f) {\n", 
                    rule.field_name, rule.operator, rule.value);
            fprintf(output_file, "                errors.push('%s');\n", rule.error_msg);
            fprintf(output_file, "                isValid = false;\n");
            fprintf(output_file, "            }\n");
        }
        
        fprintf(output_file, "            if (!isValid) {\n");
        fprintf(output_file, "                e.preventDefault();\n");
        fprintf(output_file, "                alert('Validation errors:\\n' + errors.join('\\n'));\n");
        fprintf(output_file, "            }\n");
        fprintf(output_file, "        });\n");
        fprintf(output_file, "    </script>\n");
    }
    
    fprintf(output_file, "</body>\n");
    fprintf(output_file, "</html>\n");
    
    fclose(output_file);
}

int main() {
    // Initialize form structure
    current_form.name = NULL;
    current_form.meta_count = 0;
    current_form.section_count = 0;
    current_form.validation_count = 0;
    
    
    int result = yyparse();
    
    if (result == 0) {
        printf("Parsing completed successfully.\n");
    } else {
        printf("Parsing failed with errors.\n");
        return 1;
    }
    
    return 0;
}