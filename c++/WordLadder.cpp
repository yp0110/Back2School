
#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;

struct wordnode {
    string str;
    vector<wordnode *> child;
    wordnode(string s1) {
        str = s1;

        child.clear();

    }

};

bool adjacentnode(string s1, string s2) {
    int tab1[70], tab2 [70];
    int ct = 0;

        for (int i1 = 0; i1 < 70; i1++) {
            tab1[i1] = 0;
            tab2[i1] = 0;

        }

        for (int i1 = 0; i1 < s1.length(); i1++) {

            tab1[((int)s1[i1])- 65] += 1;

            tab2[((int)s2[i1])- 65] += 1;

        }

        for (int i1 = 0; i1 < 70; i1++) {

            if (tab1[i1] != tab2[i1])

                  ct++;

            if (ct > 2)

        return false;

        }

            if (ct == 2)

        return true;

            else

        return false;

        }

void constr_tree(wordnode *rootnode, vector<string> data) {

    deque<wordnode *> q;

    q.push_back(rootnode);

    while (!q.empty()) {

        wordnode *curr = q.front();

        q.pop_front();

        if (data.size() == 0)

            return;

        for (int i = 0; i < data.size(); i++) {

            if (adjacentnode(data[i], curr->str)) {

                string n = data[i];

                data.erase(data.begin()+i);

                i--;

                wordnode *nwordnode = new wordnode(n);

                q.push_back(nwordnode);

                curr->child.push_back(nwordnode);

            }

        }

    }

}

void construct_ladd(stack<wordnode *> st, string e, vector<vector <string> > &ladd) {

    wordnode *top = st.top();

    if (adjacentnode(top->str,e)) {

        stack<wordnode *> t = st;

        vector<string> n;

        while (!t.empty()) {

            n.push_back(t.top()->str);

            t.pop();

        }

        ladd.push_back(n);

    }

    for (int i = 0; i < top->child.size(); i++) {

        st.push(top->child[i]);

        construct_ladd(st,e,ladd);

        st.pop();

    }

}

void print(string s, string e, vector<vector<string> > ladd) {

    for (int i = 0; i < ladd.size(); i++) {

        for (int j = ladd[i].size()-1; j >= 0; j--) {

            cout<<ladd[i][j]<<" ";

        }

        cout<<e<<endl;

    }

}

int main() {

    vector<string> data;

    string s1 = "hit";

    string e1 = "cog";

    data.push_back("hot");

    data.push_back("dot");

    data.push_back("dog");

    data.push_back("lot");

    data.push_back("log");

    wordnode *rootnode = new wordnode(s1);

    stack<wordnode *> st1;

    st1.push(rootnode);

    constr_tree(rootnode, data);

//string

    vector<vector<string> > ladd;

    construct_ladd(st1, e1, ladd);

    print(s1,e1,ladd);

    return 0;

}