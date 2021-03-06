# Query Language Grammar
- Spaces and tabs don't matter
- Program structure is just one statement followed by semicolon.

## Lexical Elements
    keyword: 'select' | 'create' | 'insert' | 'delete' | 
        'from' | 'where' | 'join' | 'into' | 'and' |
        'on' | 'or' | 'show' | 'use' | 'drop' |
        'table' | 'database' | 'tables' | 'databases'
    symbol: '(' | ')' | ' " ' | ';' | ',' | '*'
    integerConstant: number 
    stringConstant: '"' sequence of characters '"'
    doubleConstant: '"' integerConstant ('.' integerConstant)? '"'
    identifier: single word that doesnt start with a number
## Program Structure
    query: statement
    parameterList: parameterPair ((',' parameterPair)*)?
    attributeList: * | attributeName ((',' attributeName)*)?
    stringConstantList: stringConstant ((',' stringConstant)*)?
    parameterPair: identifier type
    type: 'int' | 'double' | 'char' | 'string'
    tableName: identifier
    databaseName: identifier
    attributeName: identifier
## Statements
    selectStatement: 'select' attributeList 'from' tableName 
        ('join' tableName 'on' (attributeName | tableReference) '=' 
        (attributeName | tableReference))? ('where' expression)? ';'
    simpleSelect: 'select' 'attributeList' 'from' tableName 'where' 
        expression ';'
    createTableStatement: 'create' 'table' tableName 
        '(' parameterList ')' ';'
    dropTableStatement: 'drop' 'table' tableName ';'
    showTablesStatement: 'show' 'tables' ';'
    createDatabaseStatement: 'create' 'database' databaseName ';'
    dropDatabaseStatement: 'drop' 'database' databaseName ';'
    useDatabaseStatement: 'use' databaseName ';'
    showDatabasesStatement: 'show' 'databases' ';'
    insertRow: 'insert' 'into' tableName '(' stringConstantList ')' ';'
    deleteStatement: 'delete' 'from' tableName 'where' expression ';'
## Expression 
    expression: term (op term)*
    term: integerConstant | stringConstant |
        tableReference | unaryOp term
    op: '<' | '>' | '=' | 'and' | 'or' 
    unaryOp: 'not'
    keywordConstant: 'null'
    tableReference: tableName '.' attributeName