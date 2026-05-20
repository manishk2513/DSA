#include <iostream>
#include <string>
using namespace std;

// ─────────────────────────────────────────────
//  Node — char-based linked-list stack node
// ─────────────────────────────────────────────
struct Node {
    char  data;
    Node* next;
    Node(char c) : data(c), next(nullptr) {}
};

// ─────────────────────────────────────────────
//  Stack<char> — dynamic linked list
// ─────────────────────────────────────────────
class Stack {
    Node* head;
public:
    Stack() : head(nullptr) {}
    ~Stack() { while (!isEmpty()) pop(); }

    bool isEmpty()  const { return head == nullptr; }
    char peek()     const { return isEmpty() ? '\0' : head->data; }

    void push(char c) {
        Node* n = new Node(c);
        n->next = head;
        head    = n;
    }

    char pop() {
        if (isEmpty()) return '\0';
        char val  = head->data;
        Node* tmp = head;
        head      = head->next;
        delete tmp;
        return val;
    }
};

// ─────────────────────────────────────────────
//  Helpers
// ─────────────────────────────────────────────

// Operator precedence  (* / higher than + -)  ^ highest
int precedence(char op) {
    if (op == '^')             return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Operand: letter or digit
bool isOperand(char c) {
    return isalnum(c);
}

// Right-associative: only '^' in standard arithmetic
bool isRightAssoc(char op) {
    return op == '^';
}

// Remove all spaces from a string
string stripSpaces(const string& s) {
    string out;
    for (char c : s)
        if (c != ' ') out += c;
    return out;
}

// ════════════════════════════════════════════════════════════
//  1. INFIX → POSTFIX   (Shunting-Yard Algorithm)
//
//  Rules:
//   • Operand            → append to output
//   • '('               → push onto stack
//   • ')'               → pop & append until '(' found, discard '('
//   • Operator op        →
//       while stack not empty
//         AND top is not '('
//         AND (top has higher precedence
//              OR same precedence & op is LEFT-associative)
//         → pop & append
//       then push op
//   • End of input       → pop & append all remaining operators
// ════════════════════════════════════════════════════════════
string infixToPostfix(const string& infix) {
    string   expr = stripSpaces(infix);
    string   output;
    Stack    s;

    for (int i = 0; i < (int)expr.size(); i++) {
        char c = expr[i];

        if (isOperand(c)) {
            output += c;
            output += ' ';
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                output += s.pop(), output += ' ';
            s.pop();   // discard '('
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && s.peek() != '(' &&
                   (precedence(s.peek()) > precedence(c) ||
                   (precedence(s.peek()) == precedence(c) && !isRightAssoc(c))))
            {
                output += s.pop();
                output += ' ';
            }
            s.push(c);
        }
    }

    while (!s.isEmpty())
        output += s.pop(), output += ' ';

    // trim trailing space
    if (!output.empty() && output.back() == ' ')
        output.pop_back();

    return output;
}

// ════════════════════════════════════════════════════════════
//  2. INFIX → PREFIX
//
//  Method (Reverse Infix approach):
//   Step 1 – Reverse the infix expression;
//            swap '(' ↔ ')' in the reversed string.
//   Step 2 – Apply the Postfix algorithm on the modified string.
//   Step 3 – Reverse the resulting postfix string → that is PREFIX.
//
//  Why this works:
//   Prefix is the mirror of Postfix. Reversing the input and
//   output maps one algorithm to the other cleanly.
// ════════════════════════════════════════════════════════════
string infixToPrefix(const string& infix) {
    string expr = stripSpaces(infix);

    // Step 1: reverse and swap parentheses
    string rev(expr.rbegin(), expr.rend());
    for (char& c : rev) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    // Step 2: postfix of reversed expression
    //         (use right-assoc logic flipped for '^')
    string   output;
    Stack    s;

    for (int i = 0; i < (int)rev.size(); i++) {
        char c = rev[i];

        if (isOperand(c)) {
            output += c;
            output += ' ';
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                output += s.pop(), output += ' ';
            s.pop();
        }
        else if (isOperator(c)) {
            // For prefix via reverse: '^' becomes LEFT-assoc in this pass
            while (!s.isEmpty() && s.peek() != '(' &&
                   (precedence(s.peek()) > precedence(c) ||
                   (precedence(s.peek()) == precedence(c) && isRightAssoc(c))))
            {
                output += s.pop();
                output += ' ';
            }
            s.push(c);
        }
    }

    while (!s.isEmpty())
        output += s.pop(), output += ' ';

    // trim trailing space
    if (!output.empty() && output.back() == ' ')
        output.pop_back();

    // Step 3: reverse the postfix result → PREFIX
    // reverse token-by-token to keep multi-char operands intact
    // (single chars here, but done properly)
    string prefix(output.rbegin(), output.rend());

    // spaces are now on the wrong side — normalise
    // simplest: rebuild left-to-right from reversed tokens
    // Split on spaces, reverse token list, rejoin
    // ── split ──
    string tokens[256];
    int    tCount = 0;
    string cur;
    for (char ch : output) {
        if (ch == ' ') {
            if (!cur.empty()) { tokens[tCount++] = cur; cur = ""; }
        } else {
            cur += ch;
        }
    }
    if (!cur.empty()) tokens[tCount++] = cur;

    // ── reverse token order ──
    prefix = "";
    for (int i = tCount - 1; i >= 0; i--) {
        prefix += tokens[i];
        if (i > 0) prefix += ' ';
    }

    return prefix;
}

// ─────────────────────────────────────────────
//  Pretty printer
// ─────────────────────────────────────────────
void convert(const string& infix) {
    cout << "  Infix    : " << infix << "\n";
    cout << "  Postfix  : " << infixToPostfix(infix) << "\n";
    cout << "  Prefix   : " << infixToPrefix(infix)  << "\n";
    cout << "  " << string(50, '-') << "\n";
}

// ─────────────────────────────────────────────
//  Main
// ─────────────────────────────────────────────
int main() {
    cout << "==========================================\n";
    cout << "    ARITHMETIC EXPRESSION CONVERSION     \n";
    cout << "    Infix  →  Postfix  &  Prefix         \n";
    cout << "==========================================\n\n";

    cout << "[ Basic Expressions ]\n";
    convert("A + B");
    convert("A - B * C");
    convert("A + B * C");
    convert("A * B + C * D");

    cout << "\n[ With Parentheses ]\n";
    convert("(A + B) * C");
    convert("A * (B + C)");
    convert("(A + B) * (C - D)");
    convert("((A + B) * C) - D");

    cout << "\n[ Multi-Level Nesting ]\n";
    convert("A + (B * (C - D))");
    convert("((A + B) * (C - D)) / (E + F)");
    convert("A * B + C * D - E / F");

    cout << "\n[ With Exponentiation (right-associative) ]\n";
    convert("A ^ B");
    convert("A ^ B ^ C");          // right-assoc: A^(B^C)
    convert("(A + B) ^ C");
    convert("A ^ (B + C) * D");

    cout << "\n[ Numeric Digits ]\n";
    convert("3 + 4 * 2");
    convert("(3 + 4) * 2");
    convert("5 ^ 2 ^ 3");

    // ── Interactive mode ──────────────────────────
    cout << "\n==========================================\n";
    cout << "  INTERACTIVE MODE  (type 'quit' to exit)\n";
    cout << "==========================================\n";

    string input;
    while (true) {
        cout << "\n  Enter infix expression: ";
        getline(cin, input);
        if (input == "quit" || input == "exit") break;
        if (input.empty()) continue;
        convert(input);
    }

    cout << "\n  Goodbye!\n";
    return 0;
}