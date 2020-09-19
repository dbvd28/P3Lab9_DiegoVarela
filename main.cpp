#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    string linea = "";
    string linea_auxiliar = "";
    vector<string> clases;
    vector<int> atributos;
    vector<string> nombre_clase;
    fstream lector(argv[1]);
    while (!lector.eof())
    {
        lector >> linea_auxiliar;
        if (linea_auxiliar != "[")
        {
            linea += linea_auxiliar + " ";
        }
        else
        {
            linea = linea;
        }
    }
    int j = 0;
    int k = 0;
    lector.close();
    string line = linea;

    // Vector of string to save tokens
    vector<string> tokens;

    // stringstream class check1
    stringstream check1(line);

    string intermediate;

    // Tokenizing w.r.t. space ' '
    while (getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }

    // Printing the token vector
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "]")
        {
            tokens[i] = tokens[i];
        }
        else
        {
            int j = tokens[i].find(':');
            tokens[i] = tokens[i].substr(j + 1, tokens[i].size());
        }
    }
    char comilla = '"';
    string pragma="#pragma once";
    string include = "#include ";
    string contenidoh = "";
    string contenidocp = "";
    int att = tokens[1].find('|');
    contenidoh = pragma+"\n" + include+ "<string>" + "\n" + "using namespace std;" + "\n" + "class " + tokens[0] + "{" + "\n" + "peivate:" + "\n" + tokens[1].substr(0, j) + tokens[1].substr(j + 1, tokens[1].size()) + ";" + "\n" + "public:" + "\n" + tokens[0] + "();" + "\n" + tokens[0] + "(" + tokens[1].substr(0, j) + ")" + ";" + "\n" + "void " + "set" + "_" + tokens[1].substr(j + 1, tokens[1].size()) + "( " + tokens[1].substr(0, j) + ");" + "\n" + tokens[1].substr(0, j) + " get" + "_" + tokens[1].substr(j + 1, tokens[1].size()) + "();" + "\n" + "~" + tokens[0] + "();" + "\n" + "};" + "#endif";
    contenidocp = "#include " + comilla + tokens[0] + ".h" + comilla + "\n" + tokens[0] + "::" + tokens[0] + "{" + "\n" + "}" + "\n" + tokens[0] + "::" + tokens[0] + "(" + tokens[1].substr(0, j) + "_" + tokens[1].substr(j + 1, tokens[1].size()) + ") {" + "\n" + tokens[1].substr(j + 1, tokens[1].size()) + "= _" + tokens[1].substr(j + 1, tokens[1].size()) +";" + "\n" + "}" + "\n" + "void " + tokens[0] + "set_" + tokens[1].substr(j + 1, tokens[1].size()) + "(" + tokens[1].substr(0, j) + "_" + tokens[1].substr(j + 1, tokens[1].size()) + " ){" + "\n" + tokens[1].substr(j + 1, tokens[1].size()) + "=" + " _" + tokens[1].substr(j + 1, tokens[1].size()) + ";" + "\n" + "}" + "\n" + tokens[1].substr(0, j) + tokens[1].substr(j + 1, tokens[1].size()) + "::" + "get" + "_" + tokens[1].substr(j + 1, tokens[1].size()) + "(){" + "\n" +
                  "return " + tokens[1].substr(j + 1, tokens[1].size()) + ";" + "\n" + "}" + "\n" + tokens[1].substr(0, j) + " " + tokens[0] + "::" + "toString(){" + "\n" + "return " + comilla + tokens[0] + "-> " + tokens[1].substr(j + 1, tokens[1].size()) + comilla + "+" + tokens[1].substr(j + 1, tokens[1].size()) + comilla + "\n" + "}" + "\n" + tokens[0] +"::~" + tokens[0] + "(){" + "\n" + "}";
fstream escritor;
escritor.open(tokens[0]+".h",ios::app);
escritor<<contenidoh;
escritor.close();
fstream escritor1;
escritor1.open(tokens[0]+".cpp",ios::app);
escritor1<<contenidocp;
escritor1.close();
}