#include <iostream>
#include <string>
#include <cmath>        // pow()
using namespace std;

// ─────────────────────────────────────────────
//  Node — double-based linked-list stack node
// ─────────────────────────────────────────────
struct Node {
    double data;
    Node*  next;
    Node(double v) : data(v), next(nullptr) {}
};

// ─────────────────────────────────────────────
//  Stack<double> — dynamic linked list
// ─────────────────────────────────────────────
class Stack {
    Node* head;
public:
    Stack() : head(nullptr) {}
    ~Stack() { while (!isEmpty()) pop(); }

    bool   isEmpty() const { return head == nullptr; }
    double peek()    const { return isEmpty() ? 0 : head->data; }
    int    size()    const {
        int n = 0;
        for (Node* c = head; c; c = c->next) n++;
        return n;
    }

    void push(double v) {
        Node* n = new Node(v);
        n->next = head;
        head    = n;
    }

    double pop() {
        if (isEmpty()) return 0;
        double val = head->data;
        Node*  tmp = head;
        head       = head->next;
        delete tmp;
        return val;
    }
};

// ─────────────────────────────────────────────
//  Result struct
// ─────────────────────────────────────────────
struct EvalResult {
    bool   ok;
    double value;
    string error;
};

// ─────────────────────────────────────────────
//  Helpers
// ─────────────────────────────────────────────
bool isOperator(const string& tok) {
    return tok == "+" || tok == "-" || tok == "*"
        || tok == "/" || tok == "%" || tok == "^";
}

// Apply operator to two operands (left op right)
EvalResult applyOp(char op, double left, double right) {
    switch (op) {
        case '+': return { true, left + right, "" };
        case '-': return { true, left - right, "" };
        case '*': return { true, left * right, "" };
        case '/':
            if (right == 0)
                return { false, 0, "Division by zero." };
            return { true, left / right, "" };
        case '%':
            if (right == 0)
                return { false, 0, "Modulo by zero." };
            return { true, fmod(left, right), "" };
        case '^': return { true, pow(left, right), "" };
    }
    return { false, 0, string("Unknown operator: ") + op };
}

// Try to parse a token as a number
bool toDouble(const string& tok, double& out) {
    try {
        size_t idx;
        out = stod(tok, &idx);
        return idx == tok.size();   // whole token consumed
    } catch (...) {
        return false;
    }
}

// ════════════════════════════════════════════════════════════
//  evaluatePostfix()
//
//  Algorithm:
//    Scan tokens left to right:
//      • Number   →  push onto stack
//      • Operator →  pop RIGHT, pop LEFT
//                    apply (left op right)
//                    push result
//    After scan:
//      • Exactly one value on stack  →  that is the answer
//      • More than one               →  too many operands
//      • Zero                        →  empty expression
// ════════════════════════════════════════════════════════════
EvalResult evaluatePostfix(const string& expr) {
    Stack  s;
    string token;

    // tokenise on whitespace
    for (int i = 0; i <= (int)expr.size(); i++) {
        char c = (i < (int)expr.size()) ? expr[i] : ' ';

        if (c == ' ' || c == '\t') {
            if (token.empty()) continue;

            // ── process collected token ───────────────
            double num;
            if (toDouble(token, num)) {
                // it's a number → push
                s.push(num);
            }
            else if (token.size() == 1 && isOperator(token)) {
                // it's an operator → needs two operands
                if (s.size() < 2)
                    return { false, 0,
                             string("Not enough operands for operator '")
                             + token + "'." };

                double right = s.pop();
                double left  = s.pop();
                EvalResult r = applyOp(token[0], left, right);
                if (!r.ok) return r;
                s.push(r.value);
            }
            else {
                return { false, 0, "Invalid token: '" + token + "'." };
            }
            token.clear();
        }
        else {
            token += c;
        }
    }

    if (s.isEmpty())
        return { false, 0, "Empty expression." };
    if (s.size() > 1)
        return { false, 0, "Too many operands — expression is malformed." };

    return { true, s.pop(), "" };
}

// ─────────────────────────────────────────────
//  Pretty printer — shows step-by-step trace
// ─────────────────────────────────────────────
void printEval(const string& expr) {
    cout << "  Postfix  : " << expr << "\n";

    // ── step-by-step trace ────────────────────
    Stack  s;
    string token;
    int    step = 0;

    auto pad = [](double v) -> string {
        string s = to_string(v);
        // remove trailing zeros after decimal
        if (s.find('.') != string::npos) {
            s.erase(s.find_last_not_of('0') + 1, string::npos);
            if (s.back() == '.') s.pop_back();
        }
        return s;
    };

    auto printStack = [&]() {
        cout << "  [";
        // print bottom → top
        // collect into array first
        double arr[64]; int n = 0;
        Stack  tmp;
        Stack  tmp2;
        // pop all to tmp (reverses), then pop tmp to tmp2 (re-reverses)
        Stack  copy;  // re-build for printing only
        // simplest: just print head..tail reversed
        // We can't iterate the private stack, so we rebuild:
        // This only runs for display — use a second pass on expression.
        // Skip deep copy; just label it:
        cout << "bottom → top]";
    };

    cout << "\n  Step-by-Step Trace:\n";
    cout << "  " << string(46, '-') << "\n";
    cout << "  Token  │ Action              │ Stack State\n";
    cout << "  " << string(46, '-') << "\n";

    // clean re-implementation of trace with array-based display
    double stk[64]; int top = -1;   // simple array for trace display

    auto traceStack = [&]() -> string {
        if (top < 0) return "[ ]";
        string out = "[ ";
        for (int i = 0; i <= top; i++) {
            out += pad(stk[i]);
            if (i < top) out += ", ";
        }
        out += " ]  ← top";
        return out;
    };

    string expr2 = expr + " ";   // sentinel space
    token.clear();
    for (char c : expr2) {
        if (c == ' ' || c == '\t') {
            if (token.empty()) continue;
            step++;

            double num;
            string action;

            if (toDouble(token, num)) {
                stk[++top] = num;
                action = "Push " + pad(num);
            }
            else if (token.size() == 1 && isOperator(token)) {
                double right = stk[top--];
                double left  = stk[top--];
                EvalResult r = applyOp(token[0], left, right);
                double res   = r.value;
                stk[++top]   = res;
                action = pad(left) + " " + token + " " + pad(right)
                       + " = " + pad(res);
            }
            else {
                action = "?? " + token;
            }

            // formatted row
            cout << "  " << step << ".  "
                 << token;
            // pad token col
            for (int sp = (int)token.size(); sp < 7; sp++) cout << ' ';
            cout << "│ " << action;
            for (int sp = (int)action.size(); sp < 20; sp++) cout << ' ';
            cout << "│ " << traceStack() << "\n";

            token.clear();
        } else {
            token += c;
        }
    }

    cout << "  " << string(46, '-') << "\n";

    // final result
    EvalResult result = evaluatePostfix(expr);
    if (result.ok) {
        cout << "  Result   : " << pad(result.value) << "\n";
    } else {
        cout << "  Error    : " << result.error << "\n";
    }
    cout << "  " << string(50, '=') << "\n\n";
}

// Helper to clean format double for output
string fmt(double v) {
    string s = to_string(v);
    if (s.find('.') != string::npos) {
        s.erase(s.find_last_not_of('0') + 1, string::npos);
        if (s.back() == '.') s.pop_back();
    }
    return s;
}

// ─────────────────────────────────────────────
//  Main
// ─────────────────────────────────────────────
int main() {
    cout << "==========================================\n";
    cout << "       POSTFIX EXPRESSION EVALUATOR      \n";
    cout << "   Operators: +  -  *  /  %  ^           \n";
    cout << "==========================================\n\n";

    cout << "[ Basic Arithmetic ]\n";
    printEval("3 4 +");           // 7
    printEval("10 3 -");          // 7
    printEval("6 7 *");           // 42
    printEval("15 4 /");          // 3.75

    cout << "[ Multi-Operator Expressions ]\n";
    printEval("2 3 + 4 *");       // (2+3)*4 = 20
    printEval("5 1 2 + 4 * + 3 - ");   // 5+((1+2)*4)-3 = 14
    printEval("4 2 3 5 1 - + * +");    // 4+(2*(3+(5-1))) = 18

    cout << "[ Exponentiation ]\n";
    printEval("2 8 ^");           // 256
    printEval("3 2 ^ 4 +");       // 13

    cout << "[ Modulo ]\n";
    printEval("17 5 %");          // 2
    printEval("10 3 % 2 *");      // (10%3)*2 = 2

    cout << "[ Negative Numbers ]\n";
    printEval("-3 4 +");          // 1
    printEval("-5 -2 *");         // 10

    cout << "[ Error Cases ]\n";
    printEval("5 0 /");           // division by zero
    printEval("3 4 + +");         // not enough operands
    printEval("3 4 5 +");         // too many operands

    // ── Interactive mode ──────────────────────
    cout << "==========================================\n";
    cout << "  INTERACTIVE MODE  (type 'quit' to exit)\n";
    cout << "  Enter a space-separated postfix expr:  \n";
    cout << "  e.g.  3 4 2 * +\n";
    cout << "==========================================\n";

    string input;
    while (true) {
        cout << "\n  >> ";
        getline(cin, input);
        if (input == "quit" || input == "exit") break;
        if (input.empty()) continue;
        printEval(input);
    }

    cout << "\n  Goodbye!\n";
    return 0;
}
