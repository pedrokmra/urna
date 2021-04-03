#include <iostream>
using namespace std;

typedef struct 
{
string nome;
int numero;
int voto;
} candidato;


int limitandoCandidatos (int quantidade)
{
    while (quantidade > 5) 
    {
        cout << "Erro: numero de candidatos excedido!" << endl;
        cout << "Cadastrar quantos candidatos |MAX 5|? ";
        cin >> quantidade;
    }

    return quantidade;
}


void quantidadeCandidatos (int *quantidade)
{
    cout << "Cadastrar quantos candidatos |MAX 5|? ";
    cin >> *quantidade;

    *quantidade = limitandoCandidatos (*quantidade);
}


void cadastro (int quantidade, candidato *Candidato[quantidade])
{ 
    int contador, contador2;
    int numeroAuxiliar;

    cout << "====== CADASTRO ======" << endl;
    for (contador = 0; contador < quantidade; contador++) //CADASTRO
    {
        cout << contador + 1 << ". Nome e Numero: ";
        cin >> Candidato[contador] -> nome >> Candidato[contador] -> numero;
        numeroAuxiliar = Candidato[contador] -> numero;

        for (contador2 = 0; contador2 < contador; contador2++) //REPETIÇÃO
        {
            if (numeroAuxiliar == Candidato[contador2] -> numero)
            {
                contador--;
                cout << "Erro: Numero repetido!" << endl;
            }
        }
    }

    for (contador = 0; contador < quantidade; contador++) //ZERAR votoCandidato
    {
        Candidato[contador] -> voto = 0;
    }

    for (contador = 0; contador < quantidade; contador++) //IMPRIMIR CANIDATOS
    {
        cout << Candidato[contador] -> nome << " - " << Candidato[contador] -> numero << endl; 
    }
}

int continuarVotacao ()
{
    string querVotar;
    cout << "Quer Votar S/N? ";
    cin >> querVotar;
    
    if (querVotar == "S")
    {
        return true;
    }
    else 
    {
        return false;
    }
}


void votacao (int quantidade,  candidato *Candidato[quantidade], int *votoBranco, int *votoNulo)
{
    int contador;
    int numeroAuxiliar;

    bool querVotar = continuarVotacao ();
    bool invalidar;
    
    int candidatoOuBranco;
    int candidatoOuArrumar;
    int continuarOuArrumar;

    while (querVotar == true)
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
                if (numeroAuxiliar == Candidato[contador] -> numero)
                {
                    cout << "Votar no " << Candidato[contador] -> nome << " |1| ou ARRUMAR |2|? ";
                    cin >> candidatoOuArrumar;

                    invalidar = false;

                    if (candidatoOuArrumar == 1) 
                    {
                        Candidato[contador] -> voto++;
                        cout << "Voto computado!" << endl; 
                    } 
                
                }
            }

            if (invalidar == true) 
            {
                cout << "Voto Invalido!" << endl;
                cout << "CONTINUAR |1| ou ARRUMAR |2|? ";
                cin >> continuarOuArrumar;
            
                if (continuarOuArrumar == 1)
                {
                    *votoNulo = *votoNulo + 1;
                } 
            }

        }
        else
        {
            *votoBranco = *votoBranco + 1;
            cout << "Voto em Branco computado!" << endl;
        }

        querVotar = continuarVotacao ();
    }
}

void resultado (int quantidade, candidato *Candidato[quantidade], int *votoBranco, int *votoNulo)
{
    int contador; 

    cout << "====== RESULTADO ======" << endl;
    cout << "Votos em Branco: " << *votoBranco << endl;
    cout << "Votos em Invalido: " << *votoNulo << endl;

    for (contador = 0; contador < quantidade; contador++)
    {
        cout << Candidato[contador] -> nome << ": " << Candidato[contador] -> voto << " Votos" << endl;
    }
}

int main () 
{
    int quantidade;
    int *PonteiroQuantidade;
    PonteiroQuantidade = &quantidade;


    int contador;

    int votoBranco = 0;
    int *PonteiroVotoBranco;
    PonteiroVotoBranco = &votoBranco;

    int votoNulo = 0;
    int *PonteiroVotoNulo;
    PonteiroVotoNulo = &votoNulo;


    quantidadeCandidatos (PonteiroQuantidade);

    candidato prefeito[quantidade];
    candidato *PonteiroPrefeito[quantidade];

    for (contador = 0; contador < quantidade; contador++) //Endereço -> Ponteiro
    {
        PonteiroPrefeito[contador] = &prefeito[contador]; 
    }

    cadastro (quantidade, PonteiroPrefeito);

    votacao (quantidade, PonteiroPrefeito, PonteiroVotoBranco, PonteiroVotoNulo);

    resultado (quantidade, PonteiroPrefeito, PonteiroVotoBranco, PonteiroVotoNulo);
}