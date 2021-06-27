#include <bits/stdc++.h>
#define A_Z 27
#define DEBUG false
using namespace std;

struct node {
    bool word;
    node *x[A_Z];
};

struct trie {
    int cont;
    node *root;
};

int charToIndex(char c) {
    return (int)c - (int)'a';
}

node *initNode(void) {
    node *n = NULL;
    n = (node *)malloc(sizeof(node)); /*Returning a node pointer to the beginning of the block*/
    if (n) {
        n->word = 0;
        for (int i = 0; i < A_Z; ++i) {
            n->x[i] = NULL;
        }
    }
}

void initTrie(trie *t) {
    t->root = initNode();
    t->cont = 0;
}

void insert(trie *t, string s) {
    int l = s.size();
    t->cont++;
    node *aux = t->root;
    for (int i = 0; i < l; i++) {
        int idx = charToIndex(s[i]);
        if (!aux->x[idx]) {
            aux->x[idx] = initNode();
        }
        aux = aux->x[idx];
    }
    aux->word = 1;
}

bool search(trie *t, string s) {
    int l = s.size();
    node *aux = t->root;
    for (int i = 0; i < l; ++i) {
        int idx = charToIndex(s[i]);
        if (!aux->x[idx]) {
            return 0;
        }
        aux = aux->x[idx];
    }
    return (0 != aux && aux->word);
}

void showTrie(trie *t) {
    node *aux = t->root;
    queue<node*> q;
    q.push(aux);
    while (!q.empty()) {
        node *n = q.front();
        q.pop();
        for (int i = 0; i < A_Z; ++i) {
            if (n->x[i]) {
                node *tmp = n->x[i];
                q.push(tmp);
                cout << char(i + (int) 'a') << "   ";
            }
        }
        cout << endl;
    }
    
}

int main() {
    string dictionary [] = {
        "hola", "holaamigos", "holacomoestas", "holaholahola", "holiboli", "holaquetal"
    };
    trie t;
    initTrie(&t);
    for (int i = 0; i < 6; ++i) {
        insert(&t, dictionary[i]);
    }

    if (DEBUG) {
        showTrie(&t);
    }

    string pattern;
    while (cin >> pattern) {
        if (search(&t, pattern)) {
            cout << "String is in the dictionary" << endl;
        } else {
            cout << "String not found" << endl;;
        }
    }

    return 0;
}