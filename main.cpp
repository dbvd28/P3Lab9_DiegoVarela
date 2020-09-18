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
            atributos.push_back(i-1);
            tokens[i]=tokens[i];
        }
        else
        {
            int j = tokens[i].find(':');
            tokens[i] = tokens[i].substr(j+1, tokens[i].size());
        }
    }
    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i]<<endl;
    }
    string contenido="";
contenido="#pragma once"+"\n"+"#include <string>"+"\n"+"using namespace std;"+"\n"+"class"+tokens[i]+;
}