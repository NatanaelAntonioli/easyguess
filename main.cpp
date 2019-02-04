#include <iostream>
#include <fstream>

#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif

using namespace std;

int main()
{

    // Declaração das variáveis utilizadas

    string palavra;
    int total_letras;
    string obtlista;
    int valido = 1;
    int continuar = 1;
    int menu;
    string FILENAME;//
    int contagem;

    while (continuar == 1){ // Loop que garante a execução do programaa

    cout << " ___   _   _____   __   ___ _   _ ___ ___ ___ " << endl;
    cout << "| __| /_\\ / __\\ \\ / /  / __| | | | __/ __/ __|" << endl;
    cout << "| _| / _ \\\\__ \\\\ V /  | (_ | |_| | _|\\__ \\__ \\" << endl;
    cout << "|___/_/ \\_\\___/ |_|    \\___|\\___/|___|___/___/" << endl;
    cout << endl;
    cout << "Desenvolvido por: Natanael Antonioli/Fabrica de Noobs" << endl;
    cout << "Versao 1.0" << endl;
    cout << endl;

    cout << "Insira a palavra a ser descoberta, colocando ? no lugar das letras que voce nao conhece: ";
    cin >> palavra;

    total_letras = palavra.size();

    cout << endl;

    cout << "A palavra a ser procurada e: ";

    for (int i = 0; i < total_letras; i++){

        cout << palavra[i] << " ";
    }
    cout << endl;
    cout << endl;

    // Seleção da wordlist a ser utilizada

    cout << "1 - Portugues completo" << endl;
    cout << "2 - Portugues reduzido (melhor para palavras de 2 a 4 caracteres)" << endl;
    cout << "3 - Ingles" << endl;
    cout << "4 - Wordlist personalizada" << endl;;
    cout << endl;
    cout << "Qual wordlist deseja usar para a busca? ";
    cin >> menu;
    cout << endl;

    // A variável "contagem" é uma gambiarra necessária para rodar a wordlist principal

    if (menu == 1){

        FILENAME = "ptbrcompleto.txt";
        contagem = total_letras+1;

    }

    if (menu == 2){

        FILENAME = "ptbrreduzido.txt";
        contagem = total_letras;

    }

    if (menu == 3){

        FILENAME = "ingles.txt";
        contagem = total_letras;

    }

    if (menu == 4){

        cout << "Coloque a wordlist no diretorio do programa e insira seu nome, incluindo o .txt: ";
        cin >> FILENAME;
        contagem = total_letras;

    }

    ifstream file(FILENAME.c_str()); // abre a wordlist

    // Começa as buscas

    cout << "------------------------------ Iniciando buscas -------------------------------" << endl;


    if (file.is_open()) {

        std::string line;

        while (getline(file, line)) {

            obtlista = line.c_str();

            if (obtlista.size() == contagem){ /// VERIFICA SE TEM O TAMANHO ESPERADO

                for (int j = 0; j < total_letras; j++){

                    if (palavra[j] == '?'){ /// NÃO FAZ NADA SE FOR IGUAL A ?

                    }

                    else {

                        if (palavra[j] != obtlista[j] && palavra[j] != toupper(obtlista[j]) && toupper(palavra[j]) != obtlista[j]){

                            valido = 0;
                            j = total_letras + 1;
                        }

                    }

                }

                if (valido == 1){

                    cout << obtlista << endl;

                }

                valido = 1;

            }


        }
        file.close();

    cout << "------------------------------ Buscas terminadas ------------------------------" << endl;
    
    cout << endl;

    system("pause");
    if (system("CLS")) system("clear");

    }
    }



}
