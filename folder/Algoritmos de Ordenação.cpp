
// Trabalho 01 - Implementa��o de Algoritmos de Ordena��o
//   ###########   INTEGRANTES DO GRUPO    #############
// - Andr� Igor Costa Linhares - Engenharia de Computa��o, Turma 2021.1.
// - Gustavo Silveira Dias - Engenharia de Computa��o, Turma 2021.1.
// - Mirelle Silva Vieira - Engenharia de Computa��o, Turma 2021.1.
// Apenas introduzindo uma altera��o

#include <iostream>
#include <locale>

using namespace std;

void Merge(double vet[], int inicio, int meio, int fim, int MaxTam); // Procedimento Merge respons�vel pela jun��o da primeira e
                                                                     // segunda parte do vetor. Ele receber� o vetor vet, e as
                                                                     // vari�veis inicio, meio, fim e MaxTam.

void MergeSort(double vet[], int inicio, int fim, int MaxTam); // Procedimento MergeSort, que receber� o vetor vet e as
                                                               // vari�veis inicio, fim e MaxTam

double DividirVetor(double vetor[], int comeco, int fim, int k); // Fun��o respons�vel por dividir o vetor (sendo esquerda menor que o piv� e direita maior que piv�), retornar posi��o do piv� e
                                                                // recebe por par�metro o vetor, come�o do vetor, final do vetor.
void QuickSort(double vetor[], int esq, int dir, int k);// Procedimento para o m�todo QuickSort.

void ChamadaPraQuick(double vetor[], int esq, int dir, int k); // Procedimento respons�vel por mostrar o vetor original do QuickSort e chamar o procedimento "QuickSort".

void InsertionSort(double vetor[], int maxTam); // Procedimento InsertionSort que recebe o vetor vet e a vari�vel maxTam

void BubbleSort(double vetor[], int maxTam);// Procedimento de ordena��o referente ao BubbleSort, recebendo o vetor e seu tamanho como par�metro.

void SelectionSort(double vetor[], int maxTam);// Procedimento de ordena��o referente ao SelectionSort, recebendo o vetor e seu tamanho como par�metro.

void VetorVariavel(double VetDin[], int maxTam, int num); // Procedimento respons�vel por preencher o vetor(por entrada) e chamar a fun��o referente a op��o selecionada no menu.

void Menu(double VetDin[], int maxTam); // Procedimento que cria o menu para a sele��o do m�todo de ordena��o desejado.

int main() // Fun��o principal, onde ser� inicializado o programa.
{
    setlocale(LC_ALL, "Portuguese");
    // Declara��o de vari�veis para serem usadas em todo o programa.
    int maxTam;
    double VetDin[maxTam];

    Menu(VetDin, maxTam); // Chamada de procedimento Menu.

    return 0;
}

void Merge(double vet[], int inicio, int meio, int fim, int MaxTam)
{
    // Vari�veis i, j e k declaradas para n�o ocorer altera��o nas vari�veis inicio, meio e fim,
    // que possibilitam a divis�o
    int i = inicio; // Vari�vel utilizada para perccorrer a primeira parte do vetor
    int j = meio + 1; // Vari�vel utilizada para perccorrer a segunda parte do vetor
    int k = inicio; // Vari�vel utilizada para o vetor auxiliar, declarado logo ap�s
    int b = j; // Vari�vel utilizada para auxiliar a mostrar a primeira parte do vetor na parte das compara��es

    double aux[MaxTam]; // Declara��o de um vetor auxiliar, onde ser�o copiados os elementos ordenados do vetor vet

    cout << "Comparando o primeiro elemento da primeira parte com o primeiro elemento da segunda parte: " << endl;

    // La�o de repeti��o que ocorre apenas se houver elementos na primeira e segunda parte
    while (i <= meio && j <= fim) {
        cout << "Primeira parte: ";
        // La�o de repeti��o que mostra a primeira parte do vetor
        for(int m = i; m < b; m++){
            cout << vet[m] << " ";
        }
        cout << endl;

        cout << "Segunda parte: ";
        // La�o de repeti��o que mostra a segunda parte do vetor
        for(int n = j; n <= fim; n++){
            cout << vet[n] << " ";
        }
        cout << endl << endl;
        cout << vet[i] << " < " << vet[j] << "?" << endl;
        if (vet[i] <= vet[j]) {
            cout << "SIM!" << endl << endl;
            aux[k] = vet[i]; // Vetor aux recebe o primeiro elemento da primeira parte, que � menor do que o primeiro elemento da seguda parte
            i++; // A posi��o i do vetor j� foi comparada, o la�o agora trabalhar� com i + 1
        }
        else {
            cout << "NAO!" << endl << endl;
            aux[k] = vet[j]; // Vetor aux  recebe o primeiro elemento da segunda parte, que � menor do que o primeiro elemento da primeira parte
            j++; // A posi��o i do vetor j� foi comparada, o la�o agora trabalhar� com i + 1
        }
        k++; // A posi��o k do vetor aux j� foi preenchida, o la�o agora trabalhar� com k + 1
    }

    //Caso haja elementos restantes da primeira parte, ele ser�o copiados para o vetor auxiliar
    while (i <= meio) {
        aux[k] = vet[i];
        i++;
        k++;
    }

    //Caso haja elementos restantes da segunda parte, ele ser�o copiados para o vetor auxiliar
    while (j <= fim) {
        aux[k] = vet[j];
        j++;
        k++;
    }

    //Os elementos do vetor auxiliar s�o s�o copiados para o vetor original
    for (int p = inicio; p <= fim; p++) {
        vet[p] = aux[p];
        cout << vet[p] << " ";
    }

    cout << endl << endl;
}

/* inicio refere-se a posi��o da esquerda
e fim, a posi��o da direita das sublistas do
vetor a ser ordenado
*/

void MergeSort(double vet[], int inicio, int fim, int MaxTam)//MergeSort
{
    // Para que a divis�o aconte�a, o vetor precisa no m�nimo de 2 elementos
    if (inicio < fim) {
        // calculando o meio
        int meio = (inicio + fim) / 2;

        cout << "Dividindo... " << endl;

        cout << "Primeira parte do vetor: " << endl;
        // La�o de repeti��o que mostra a primeira parte ap�s a divis�o
        for(int i = inicio; i <= meio; i++) {
            cout << vet[i] << "  ";
        }

        cout << endl;
        cout << "Segunda parte do vetor: " << endl;
        // La�o de repeti��o que mostra a segunda parte ap�s a divis�o
        for(int i = meio + 1; i <= fim; i++) {
            cout << vet[i] << "  ";
        }

        cout << endl << endl;

        MergeSort(vet, inicio, meio, MaxTam); // Chamada recursiva da fun��o MergeSort para a primeira parte
        MergeSort(vet, meio + 1, fim, MaxTam); // Chamada recursiva da fun��o MergeSort para a segunda parte

        Merge(vet, inicio, meio, fim, MaxTam); // Jun��o dos elementos da primeira e segunda parte

        cout << "Vetor com todos os elementos: ";
        // La�o de repeti��o que mostra o vetor com todos os elementos
        for (int i = 0; i < MaxTam; i++) {
            cout << vet[i] << " ";
        }
        cout << endl << endl;
    }
}

double DividirVetor(double vetor[], int comeco, int fim, int k)
{
    double pivo = vetor[fim];// Declarada vari�vel piv� recebendo o item da ultima posi��o do vetor.
    double aux;             // Vari�vel respons�vel por permitir a troca de valores dentro do vetor.
    int Indice = comeco;

    cout << "Para o pivo: " << pivo << endl;
    for(int i=0; i < k; i++)// La�o que imprime o vetor antes da altera��o.
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    for( int i= comeco; i < fim; i++)// La�o de repeti��o que varre todo o vetor.
    {
      if(vetor[i] < pivo)// Caso o valor da posi��o do la�o seja menor que o valor do piv�, entra na condi��o.
      {
          if(vetor[i] != vetor[Indice]){
            cout << "Pega o " << vetor[i] << " e troca pelo " << vetor[Indice] << endl;
          }
          aux = vetor[i];       // Troca dos valores utilizando a vari�vel aux como intermediadora.
          vetor[i] = vetor[Indice];
          vetor[Indice] = aux;
          Indice++;
      }
    }

    aux = vetor[fim];  // Realocando o piv� para sua devida posi��o.
    vetor[fim] = vetor[Indice];
    vetor[Indice] = aux;

    if(vetor[fim] != vetor[Indice])
    {
        cout << "Realocando o pivo [" << vetor[Indice] << "] para seu lugar. " << endl;
    }
    else
    {
        cout << "Pivo j� est� na sua respectiva posi��o!" << endl;
    }

    for(int i=0; i<k; i++)// La�o que imprime o vetor depois da altera��o.
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    return Indice;// retorna posi��o do piv�.
}

void QuickSort(double vetor[], int esq, int dir, int k)//QuickSort
{
    double pivo;// Declara��o da vari�vel que ser� usada para armazenar a posi��o do vetor
                // que estiver o valor do piv�.
    if(esq < dir)// Condi��o para a execu��o apenas se o valor do in�cio for menor que o
    {           // do final do vetor, sendo ele particionado ou n�o.
       pivo = DividirVetor(vetor, esq, dir, k);// A fun��o armazena na vari�vel piv� o valor da posi��o do piv� retornado por ela.

       QuickSort(vetor, esq, pivo-1, k);// Chamada recursiva, por�m alterando os valores dos par�metros e considerando apenas os valores do come�o at� uma posi��o a menos do piv�.
       QuickSort(vetor, pivo+1, dir, k);// Chamada recursiva com valores de par�metros alterados considerando apenas valores
    }                                   // de uma posi��o a mais do piv� at� o final do vetor.

}

void ChamadaPraQuick(double vetor[], int esq, int dir, int k)
{
    cout << "############### QuickSort ###############" << endl;
    cout << "=========== VETOR ORIGINAL ===========" << endl;

    for(int i=0; i < k; i++)// La�o de repeti��o que imprime o vetor em seu estado original, ou seja,
    {                       //   antes das altera��es.
        cout << vetor[i] << " ";
    }
    cout << endl;

    cout << "=========== Opera��es ===========" << endl;
    QuickSort(vetor, 0, (dir - 1), k);//   antes das altera��es.
}

void InsertionSort(double vetor[], int maxTam)//InsertionSort
{
    int aux; //Declara��o da vari�vel aux de "auxiliar", ela armazenar� temporariamente valores
             //durante a execu��o da ordena��o por Insertion Sort.

    cout << "############### InsertionSort ###############" << endl;

    cout << "=========== VETOR ORIGINAL ===========" << endl;
    for(int i=0; i < maxTam; i++) //La�o de repeti��o que mostra os elementos do vetor na sua forma original.
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    cout << "=========== Opera��es ===========" << endl;
    for(int i=0; i < maxTam -1; i++) //La�o de repeti��o exterior que refere-se a parte ordenada do vetor, que
                                     //come�a com o primeiro elemento.
    {
        for(int j= i+1; j>0; j--) //La�o de repeti��o interior que refere-se a parte desordenada do vetor, que
                                  //come�a com o segundo elemento.
        {
            if(vetor[j]< vetor[j-1]) //A troca s� ser� realizada se o vetor da parte desordenada for menor que
                                     //o da parte ordenada.
            {
                aux = vetor[j]; //Vari�vel aux recebe temporariamente o elemento da posi��o j.
                vetor[j] = vetor[j-1];//O maior elemento vai para a posi��o onde estava o elemento da posi��o j.
                vetor[j-1] = aux;//O vetor na posi��o anterior a de j recebe o que est� dentro da vari�vel aux.

                cout << "Troca do [" << vetor[j] << "] pelo [" << vetor[j-1] << "]: " << endl; // Imprime os valores que foram trocados na itera��o.

                for(int i=0; i < maxTam; i++)//La�o de repeti��o que mostra todos os passos do InsertionSort.
                {
                    cout << vetor[i] << " ";
                }
                cout << endl;
                cout << endl;
            }
        }
    }

    cout << "=========== VETOR AP�S OPERA��ES ===========" << endl;

    for(int i=0; i < maxTam; i++)//La�o de repeti��o que mostra o vetor ordenado pelo InsertionSort
    {
        cout << vetor[i] << " ";
    }

    cout << endl;
}

void BubbleSort(double vetor[], int maxTam)//BubbleSort
{
   double aux; // vari�vel respons�vel por possibilitar a troca de dois valores do vetor.

    cout << "############### BubbleSort ###############" << endl;
    cout << "=========== VETOR ORIGINAL ===========" << endl;

    for(int i=0; i < maxTam; i++) // La�o respons�vel por imprimir na tela o vetor original,
    {                              //sendo por atribui��o ou por entrada de dados.
        cout << vetor[i] << " ";
    }

    cout << endl;

    cout << "=========== Opera��es ===========" << endl;

    for(int i= 0; i< maxTam; i++)   // La�o externo respons�vel por percorrer todo o vetor.
    {
        for(int j=0; j< maxTam -1; j++) // La�o interno respons�vel pelas compara��es.
        {
            if(vetor[j] > vetor[j+1])// Compara��o do elemento presente na posi��o "J" para verificar se ele � maior que
                                    // o elemento "J + 1".
                {
                    aux = vetor[j]; // A varialvel aux armazena  temporariamente o elemento presente na posi��o "J".
                    vetor[j] = vetor[j+1]; // Vetor[j] recebe o elemento presente na posi��o "J +1".
                    vetor[j+1] = aux; // Vetor[ j + 1] recebe o elemento que estava presente na posi��o " J " e faz a troca de elementos.

                    cout << "Troca do [" << vetor[j] << "] pelo [" << vetor[j+1] << "]: " << endl; // Informando os elementos que est�o sendo trocados na intera��o.

                    for(int i=0; i < maxTam; i++) // La�o de repeti��o para mostrar todos os passos de troca do algoritmo de ordena��o.
                    {
                        cout << vetor[i] << " ";
                    }

                    cout << endl;
                    cout << endl;
                }
        }
    }

    cout << "=========== VETOR AP�S OPERA��ES ===========" << endl;

    for(int i=0; i < maxTam; i++) // La�o de repeti��o para mostrar os elementos completamente ordenados  pelo BubbleSort.
    {
        cout << vetor[i] << " ";
    }

    cout << endl;
}

void SelectionSort(double vetor[], int maxTam)
{
    double menor;  // Vari�vel responsavel para armazenar o menor elemento do vetor.
    int posicao;  // Vari�vel responsavel para armazenar a posi��o do menor elemento do vetor.
    bool troca;  // Vari�vel de troca (verdadeira ou falsa).
    double aux; // vari�vel respons�vel por possibilitar a troca de dois valores do vetor.

    cout << "############### SelectionSort ###############" << endl;
    cout << "=========== VETOR ORIGINAL ===========" << endl;

    for(int i=0; i < maxTam; i++) // La�o respons�vel por imprimir na tela o vetor original,
                                 //sendo por atribui��o ou por entrada de dados.
    {
        cout << vetor[i] << " ";
    }
    cout << endl; // Quebra de linha.

    cout << "=========== Opera��es ===========" << endl;
    for(int i=0; i< maxTam -1; i++)
    {
        menor = vetor[i];  // Vari�vel "menor" esta recebendo o menor elemento do vetor.
        posicao = i;      // Vari�vel "Posi��o" esta recebendo o menor elemento do vetor.
        troca = false;   //  Troca est� recebendo falso.

        for(int j= i+1; j< maxTam; j++)
        {
            if(vetor[j] < menor)  // Se o elemento da posi��o "j" for menor que o elemento guardado no  "menor"  ent�o faz a troca.
            {
                menor = vetor[j]; // Caso o elemento "j" seja menor, ir� atualizar o indice e passar "j" como menor elemento.
                posicao = j;     // Elemento da posi��o "J" foi armazenado na vari�vel posi��o.
                troca = true;   // Troca foi realizada.
            }
        }

        for (int i=0; i< maxTam; i++) // La�o de repeti��o responsav�l por percorrer o vetor.
        {
            cout << vetor[i] << " ";

        }

        cout <<  endl; // Quebra de linha.

        if (vetor[i] != vetor[posicao]) // Compara��o dos elementos na posi��o "i" para ver se � diferente que o vetor "posi��o".
        {
            cout << "Troca do [" << vetor[i] << "] pelo [" << vetor[posicao] << "]: " << endl; // Informando os elementos que est�o sendo trocados na intera��o.
        }
        else
        {
            cout << "[" << vetor[i] << "] e [" << vetor[posicao] << "] s�o iguais, mant�m!! " << endl; // Informando os elementos que s�o iguais na intera��o.
        }

        if (troca)
        {
            aux = vetor[i]; // Vari�vel aux recebeu temporariamente o elemento da posi��o "I".
            vetor[i] = menor; // Vetor[i] recebe o menor elemento.
            vetor[posicao] = aux; // vetor[posicao] troca de valor com  a vari�vel aux.
        }
    }

    cout << "=========== VETOR AP�S OPERA��ES ===========" << endl;

    for(int i=0; i< maxTam; i++) // La�o de repeti��o para mostrar os elementos completamente ordenados pelo algoritmo SelectionSort.
    {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void VetorVariavel(double VetDin[], int maxTam, int num) // Procedimento para preencher o vetor de tamanho vari�vel de acordo com a entrada do tamanho m�ximo.
{
    for(int i=0; i< maxTam; i++) // La�o para preencher o vetor por entrada.
    {
        cout << "Digite o " << i+1 << "� n�mero: ";
        cin >> VetDin[i];
    }
    cout << endl;

    if(num == 1)// Condicional necess�ria para ordena��o de acordo com o solicitado no menu, passado por par�metro pela vari�vel "num".
    {
      InsertionSort(VetDin, maxTam);
    }
    else if(num == 2)
    {
        SelectionSort(VetDin, maxTam);
    }
    else if(num == 3)
    {
        BubbleSort(VetDin, maxTam);
    }
    else if(num == 4)
    {
        ChamadaPraQuick(VetDin, 0, maxTam, maxTam);
    }
    else if(num == 5)
    {
        cout << "############### MergeSort ###############" << endl;

        cout << "=========== VETOR ORIGINAL ===========" << endl;
        for(int i=0; i < maxTam; i++)
        {
            cout << VetDin[i] << " ";
        }
        cout << endl << endl;
        cout << "=========== Opera��es ===========" << endl;
        MergeSort(VetDin, 0, maxTam -1, maxTam);
    }
}

void Menu(double VetDin[], int maxTam)
{
    char entrar;

    cout << "|-------------------- Seja bem-vindo(a) ao algoritmo de ordena��o --------------------|" << endl;

    cout << "Deseja entrar no menu de op��es? (s/n): ";// Entrada de valor respons�vel pela inicia��o ou n�o no la�o while.
    cin >> entrar;

    while (entrar == 's' || entrar == 'S')
    {
        double numeros[10]= {3.2, 2, 5, 1, 10, 9, 7, 3, 4, 11};// Declara��o do vetor por atribui��o com seus valores j� pr� definidos.
        int botao2;// Declara��o de vari�veis para a entrada no menu.
        char botao1;// Declara��o de vari�veis para a entrada no menu.

        cout << "========== Bem-Vindo(a) ao menu ==========" << endl;//Card�pio de op��es para que o usu�rio possa escolher.
        cout << "[A] - Vetor por atribui��o." << endl;
        cout << "[B] - Vetor por entrada." << endl;
        cout << "Selecione uma letra: ";
        cin >> botao1; // Entrada do valor para sele��o entre (A ou B).
        cout << "[1] - InsertionSort." << endl;
        cout << "[2] - SelectionSort." << endl;
        cout << "[3] - BubbleSort."  << endl;
        cout << "[4] - QuickSort."  << endl;
        cout << "[5] - MergeSort." << endl;
        cout << "Selecione uma op��o: ";
        cin >> botao2;// Entrada do valor para sele��o entre (1, 2, 3, 4 ou 5).

        if(botao2 == 1 && (botao1 == 'a'|| botao1 == 'A') )// Condi��es para executar o tipo de Algoritmo de ordena��o
        {                                                   // de acordo com o valor da entrada mostrada no card�pio de op��es.
            InsertionSort(numeros, 10);// Chama o procedimento InsertionSort para o vetor preenchido por atribui��o.
        }
        else if(botao2 == 1 && (botao1 == 'b'|| botao1 == 'B') )
        {
            cout << "Digite o tamanho do vetor: ";
            cin >> maxTam;
            VetorVariavel(VetDin,maxTam, 1);// Chamada da fun��o que preenche o vetor por entrada.
        }
        else if(botao2 == 2 && (botao1 == 'a'|| botao1 == 'A') )
        {
            SelectionSort(numeros, 10);// Chama o procedimento SelectionSort para o vetor preenchido por atribui��o.
        }
        else if(botao2 == 2 && (botao1 == 'b'|| botao1 == 'B') )
        {
            cout << "Digite o tamanho do vetor: ";
            cin >> maxTam;
            VetorVariavel(VetDin,maxTam, 2);// Chamada da fun��o que preenche o vetor por entrada.
        }
        else if(botao2 == 3 && (botao1 == 'a'|| botao1 == 'A') )
        {
            BubbleSort(numeros, 10);// Chama o procedimento BubbleSort para o vetor preenchido por atribui��o.
        }
        else if(botao2 == 3 && (botao1 == 'b'|| botao1 == 'B') )
        {
            cout << "Digite o tamanho do vetor: ";
            cin >> maxTam;
            VetorVariavel(VetDin,maxTam, 3);// Chamada da fun��o que preenche o vetor por entrada.
        }
        else if(botao2 == 4 && (botao1 == 'a'|| botao1 == 'A') )
        {
            ChamadaPraQuick(numeros, 0, 10, 10);// Chama o procedimento ChamadaPraQuick para o vetor preenchido por atribui��o.

            cout << "=========== VETOR ORDENADO ===========" << endl;
            for(int i=0; i<10; i++)// Imprime o vetor j� ordenado.
            {
                cout << numeros[i] << " ";
            }
            cout << endl;
        }
        else if(botao2 == 4 && (botao1 == 'b'|| botao1 == 'B'))
        {
            cout << "Digite o tamanho do vetor: ";// Entrada do valor referente ao tamanho do vetor.
            cin >> maxTam;
            VetorVariavel(VetDin,maxTam, 4);// Chamada da fun��o que preenche o vetor por entrada.

            cout << "=========== VETOR ORDENADO ===========" << endl;

            for (int i=0; i<maxTam; i++)// Imprime o vetor j� ordenado.
            {
                cout << VetDin[i] << " ";
            }
            cout << endl;
        }
        else if(botao2 == 5 && (botao1 == 'a' || botao1 == 'A'))
        {
            cout << "############### MergeSort ###############" << endl;

            cout << "=========== VETOR ORIGINAL ===========" << endl;
            for(int i=0; i < 10; i++)//Imprime o vetor Original.
            {
                cout << numeros[i] << " ";
            }
            cout << endl;
            cout << "=========== Opera��es ===========" << endl;

            MergeSort(numeros, 0, 9, 10);// Chama o procedimento MergeSort.

            cout << "=========== VETOR ORDENADO ===========" << endl; // Imprime o vetor j� ordenado.
            for(int i=0; i< 10; i++)
            {
                cout << numeros[i] << " ";
            }
            cout << endl;

        }
        else if(botao2 == 5 && (botao1 == 'b' || botao1 == 'B'))
        {
            cout << "Digite o tamanho do vetor: "; // Entrada do valor referente ao tamanho do vetor.
            cin >> maxTam;

            VetorVariavel(VetDin,maxTam, 5); // Chamada da fun��o que preenche o vetor por entrada.

            cout << "=========== VETOR ORDENADO ===========" << endl;
            for(int i=0; i< maxTam; i++)// La�o para mostrar o vetor ap�s ser ordenado pelo MergeSort.
            {
                cout << VetDin[i] << " ";
            }
            cout << endl;

        }

    cout << "Deseja retornar ao menu? (s/n): ";// Entrada do valor que ir� satisfazer ou n�o a condi��o do
    cin >> entrar;                              // while que ela est� inclusa.
    }
}
