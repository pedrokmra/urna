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

    string candidato[quantidade];
    int numeroCandidato[quantidade];
    int votoCandidato[quantidade];
    cout << "====== CADASTRO ======" << endl;
    for (contador = 0; contador < quantidade; contador++)
    {
        cout << contador + 1 << ". Nome e Numero: ";
        cin >> candidato[contador] >> numeroCandidato[contador];
    }

    for (contador = 0; contador < quantidade; contador++)
    {
        cout << candidato[contador] << " - " << numeroCandidato[contador] << endl;
    }

    for (contador = 0; contador < quantidade; contador++) //ZERAR votoCandidato
    {
        votoCandidato[contador] = 0;
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
                if (numeroAuxiliar == numeroCandidato[contador])
                {
                    cout << "Votar no " << candidato[contador] << " |1| ou ARRUMAR |2|? ";
                    cin >> candidatoOuArrumar;

                    invalidar = false;

                    if (candidatoOuArrumar == 1)
                    {
                        votoCandidato[contador]++;
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
        cout << candidato[contador] << ": " << votoCandidato[contador] << " Votos" << endl;
    }
}

/*
CORRIGIR BUGS
- cadastro de numeros iguais
- corrigir voto

MELHORAR
- usar struct
- usar funções
- usar ponteiros
*/