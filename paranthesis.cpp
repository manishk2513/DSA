#include <iostream>
#include <string>
using namespace std;

// ─────────────────────────────────────────────
//  Node — for the internal linked-list stack
// ─────────────────────────────────────────────
struct Node {
    char  data;
    Node* next;
    Node(char c) : data(c), next(nullptr) {}
};

// ─────────────────────────────────────────────
//  Stack (char) — dynamic linked list
// ─────────────────────────────────────────────
class Stack {
    Node* head;
public:
    Stack() : head(nullptr) {}
    ~Stack() { while (!isEmpty()) pop(); }

    bool isEmpty() const { return head == nullptr; }

    void push(char c) {
        Node* n = new Node(c);
        n->next = head;
        head    = n;
    }

    char pop() {
        if (isEmpty()) return '\0';
        char val = head->data;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return val;
    }

    char peek() const {
        return isEmpty() ? '\0' : head->data;
    }
};

// ─────────────────────────────────────────────
//  Helpers
// ─────────────────────────────────────────────
bool isOpening(char c) { return c == '(' || c == '{' || c == '['; }
bool isClosing(char c) { return c == ')' || c == '}' || c == ']'; }

bool isMatch(char open, char close) {
    return (open == '(' && close == ')')
        || (open == '{' && close == '}')
        || (open == '[' && close == ']');
}

// ─────────────────────────────────────────────
//  Result struct — carries verdict + detail
// ─────────────────────────────────────────────
struct Result {
    bool   balanced;
    string message;
    int    errorPos;   // 1-based; -1 if no positional error
};

// ─────────────────────────────────────────────
//  check() — core algorithm
//
//  Algorithm:
//    For each character in expression:
//      • Opening bracket  →  push onto stack
//      • Closing bracket  →
//          – stack empty          → unmatched closing bracket (error)
//          – top doesn't match    → wrong closing bracket    (error)
//          – top matches          → pop (pair resolved)
//    After full scan:
//      • Stack not empty → unclosed opening bracket(s) left
//      • Stack empty     → perfectly balanced
// ─────────────────────────────────────────────
Result check(const string& expr) {
    Stack s;

    for (int i = 0; i < (int)expr.size(); i++) {
        char c = expr[i];

        if (isOpening(c)) {
            s.push(c);
        }
        else if (isClosing(c)) {
            if (s.isEmpty()) {
                return { false,
                         string("Unmatched closing '") + c + "' with no opening pair.",
                         i + 1 };
            }
            char top = s.peek();
            if (!isMatch(top, c)) {
                return { false,
                         string("Mismatched: opened with '") + top +
                         "' but closed with '" + c + "'.",
                         i + 1 };
            }
            s.pop();   // matched pair — resolved
        }
        // non-bracket characters are simply ignored
    }

    if (!s.isEmpty()) {
        return { false,
                 string("Unclosed opening bracket '") + s.peek() + "' has no closing pair.",
                 -1 };
    }

    return { true, "All brackets are balanced and correctly nested.", -1 };
}

// ─────────────────────────────────────────────
//  Pretty printer
// ─────────────────────────────────────────────
void printResult(const string& expr, const Result& r) {
    cout << "  Expression : \"" << expr << "\"\n";

    if (r.errorPos != -1) {
        // draw a caret pointing to the error character
        string spaces(r.errorPos + 14, ' '); // offset for "  Expression : \""
        cout << spaces << "^\n";
        cout << "  Position   : " << r.errorPos << "\n";
    }

    cout << "  Status     : " << (r.balanced ? "✔  BALANCED" : "✘  NOT BALANCED") << "\n";
    cout << "  Detail     : " << r.message << "\n";
    cout << "  " << string(50, '-') << "\n";
}

// ─────────────────────────────────────────────
//  Main — test suite
// ─────────────────────────────────────────────
int main() {
    cout << "==========================================\n";
    cout << "        PARENTHESIS CHECKER              \n";
    cout << "     Brackets: ( )  { }  [ ]             \n";
    cout << "==========================================\n\n";

    // { expression, expected }
    const string tests[] = {
        // ── Balanced ──────────────────────────────
        "()",
        "{}",
        "[]",
        "(){}[]",
        "{[()]}",
        "(({{[[]]}}))",
        "a + (b * c) - {d / [e + f]}",
        "int main() { return 0; }",

        // ── Not balanced ──────────────────────────
        "(",              // unclosed opening
        "{[}]",           // wrong closing type
        "){",             // unmatched closing at start
        "((())",          // extra opening
        "{[}",            // mismatched inner
        "[{()}])",        // extra closing at end
        "(((",            // all unclosed
    };

    int total   = sizeof(tests) / sizeof(tests[0]);
    int passed  = 0;

    for (const string& expr : tests) {
        Result r = check(expr);
        printResult(expr, r);
        if (r.balanced) passed++;
    }

    cout << "\n  Summary: " << passed << " balanced / "
         << (total - passed) << " unbalanced  (out of " << total << " tests)\n\n";

    // ── Interactive mode ──────────────────────────
    cout << "==========================================\n";
    cout << "  INTERACTIVE MODE  (type 'quit' to exit)\n";
    cout << "==========================================\n";

    string input;
    while (true) {
        cout << "\n  Enter expression: ";
        getline(cin, input);
        if (input == "quit" || input == "exit") break;
        printResult(input, check(input));
    }

    cout << "\n  Goodbye!\n";
    return 0;
}