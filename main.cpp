#include <iostream>
using namespace std;

int main ()
{
    //QUANTIDADE de CANDIDATOS
    int quantidade;

    cout << "Cadastrar quantos candidatos |MAX 5|? ";
    cin >> quantidade;

    while (quantidade > 5)
    {
        cout << "Erro: numero de candidatos excedido!" << endl;
        cout << "Cadastrar quantos candidatos |MAX 5|? ";
        cin >> quantidade;
    }


    //CADASTRO
    int contador;

    struct candidato
    {
        string nome;
        int numero;
        int voto;
    };

    struct candidato prefeito[quantidade];


    cout << "====== CADASTRO ======" << endl;
    for (contador = 0; contador < quantidade; contador++)
    {
        cout << contador + 1 << ". Nome e Numero: ";
        cin >> prefeito[contador].nome >> prefeito[contador].numero;
    }

    for (contador = 0; contador < quantidade; contador++)
    {
        cout << prefeito[contador].nome << " - " << prefeito[contador].numero << endl;
    }

    for (contador = 0; contador < quantidade; contador++) //ZERAR votoCandidato
    {
        prefeito[contador].voto = 0;
    }


    //VOTAÇÃO
    string querVotar;
    int candidatoOuBranco;
    int candidatoOuArrumar;
    bool invalidar = true;

    int numeroAuxiliar;

    int votoBranco = 0;
    int votoInvalido = 0;
    cout << "====== VOTACAO ======" << endl;
    cout << "Quer votar S/N? ";
    cin >> querVotar;


    while (querVotar == "S")
    {
        cout << "Quer votar em um CANDIDATO |1| ou em BRANCO |2|? ";
        cin >> candidatoOuBranco;

        if (candidatoOuBranco == 1)
        {
            invalidar = true;
            cout << "Numero do candidato: ";
            cin >> numeroAuxiliar;


            for (contador = 0; contador < quantidade; contador++)
            {
                if (numeroAuxiliar == prefeito[contador].numero)
                {
                    cout << "Votar no " << prefeito[contador].nome << " |1| ou ARRUMAR |2|? ";
                    cin >> candidatoOuArrumar;

                    invalidar = false;

                    if (candidatoOuArrumar == 1)
                    {
                        prefeito[contador].voto++;
                        cout << "Voto computado!" << endl;
                    }
                }
            }

            if (invalidar == true)
            {
                votoInvalido++;
                cout << "Voto Invalido!" << endl;
            }

        }

        else
        {
            votoBranco++;
            cout << "Voto computado!" << endl;
        }

        cout << "Quer votar S/N? ";
        cin >> querVotar;
    }


    //RESULTADO
    cout << "====== RESULTADO ======" << endl;
    cout << "Votos em Branco: " << votoBranco << endl;
    cout << "Votos em Invalido: " << votoInvalido << endl;

    for (contador = 0; contador < quantidade; contador++)
    {
        cout << prefeito[contador].nome << ": " << prefeito[contador].voto << " Votos" << endl;
    }
}

/*
CORRIGIR BUGS
- cadastro de nomes e numeros iguais
- corrigir voto

MELHORAR
- usar funções
- usar ponteiros
*/