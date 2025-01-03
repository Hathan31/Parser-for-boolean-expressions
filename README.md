# Intérprete Booleano en C

## Descripción del Proyecto
Este proyecto implementa un **intérprete booleano** en C que analiza y evalúa expresiones booleanas utilizando un analizador léxico (lexer) y un analizador sintáctico (parser) basado en Bison y Flex. El objetivo principal es construir un **árbol de sintaxis abstracta (AST)** a partir de una expresión boolean y evaluar su valor lógico.

---

## Características

- **Lexer (`lexer.l`)**:
  - Analiza el texto de entrada y tokeniza operadores booleanos (`&&`, `||`, `!`), operadores relacionales (`<`, `>`, `<=`, `>=`, `==`, `!=`) y valores numéricos.
  - Detecta errores léxicos.

- **Parser (`parser.y`)**:
  - Construye el árbol de sintaxis abstracta (AST) de las expresiones booleanas.
  - Valida la sintaxis y genera mensajes de error si es inválida.

- **Evaluación de Expresiones**:
  - Evalúa el AST generado para determinar el resultado booleano de la expresión (verdadero o falso).

- **Soporte de Operadores**:
  - Operadores booleanos: `&&`, `||`, `!`.
  - Operadores relacionales: `<`, `>`, `<=`, `>=`, `==`, `!=`.

- **Visualización del AST**:
  - Imprime el árbol generado con indentación para representar su estructura jerárquica.

---

## Estructura del Proyecto

1. **`lexer.l`**:
   - Define los tokens para los operadores, números y paréntesis.
   - Detecta errores léxicos y genera mensajes correspondientes.

2. **`parser.y`**:
   - Contiene la gramática para analizar expresiones booleanas.
   - Genera el AST y evalúa su valor.

3. **`exp.h`**:
   - Define la estructura de los nodos del AST y funciones para su creación, evaluación e impresión.

4. **`testing.txt`**:
   - Archivo de prueba que contiene expresiones booleanas para validar el funcionamiento del intérprete.

---

## Instalación y Ejecución

1. **Requisitos Previos**:
   - Flex y Bison instalados en el sistema.

2. **Compilación**:
   Ejecuta los siguientes comandos para compilar el proyecto:
   ```bash
   flex lexer.l
   bison -d parser.y
   gcc lex.yy.c parser.tab.c -o interpreter
   ```

3. **Ejecución**:
   Proporciona un archivo de prueba como entrada:
   ```bash
   ./interpreter < testing.txt
   ```

---

## Ejemplo de Uso

### Entrada (`testing.txt`):
```plaintext
(5 > 3) && (2 == 2) || !(1 < 0)
```

### Salida:
```plaintext
Valid syntax
AST:
  OR
    AND
      GT
        NUM(5)
        NUM(3)
      EQ
        NUM(2)
        NUM(2)
    NOT
      LT
        NUM(1)
        NUM(0)
Result: true
```

---

## Funciones Principales

1. **`create_num_node`**:
   - Crea nodos para valores numéricos en el AST.

2. **`create_binary_node`**:
   - Crea nodos para operadores binarios (`&&`, `||`, etc.).

3. **`evaluate_tree`**:
   - Evalúa el AST recursivamente para calcular el resultado booleano.

4. **`print_tree`**:
   - Imprime el AST con indentación para facilitar su interpretación visual.

---

## Mejoras Futuras

- Soporte para variables booleanas y asignaciones.
- Manejo de comentarios en el archivo de entrada.
- Optimizaciones en la evaluación del AST.

---

## Autor
**Jonathan Sampera**


