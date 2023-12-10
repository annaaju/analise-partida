#include <stdio.h>
#include <string.h>

// analisando uma partida de lol

typedef struct{

    char nome[100];
    char lado[20];
    int jogadores[5];

} Time;

typedef struct{

    char nick[100];
    char lane[100];
    char campeao[100];
    int kills;
    int assists;
    int deaths;
    float kda;

}Jogador;

typedef struct{

    char vencedor[100];
    char perdedor[100];
    char mvp [100];
    int duracao;   // em minutos


}Partida;

typedef struct {
   
    struct {
        int ouroAcumulado;
        int torresDestruidas;
        int dragoesConquistados;
        int baroesConquistados;
    } time1, time2;

} EstatisticasPartida;

// preenchendo os dados time

void dadosTime(Time *time, int numeroTime) {
    printf("Digite o nome do Time %d: ", numeroTime);
    scanf(" %[^\n]", time->nome);

    printf("Digite o lado do Time %d (vermelho ou azul): ", numeroTime);
    scanf(" %[^\n]", time->lado);

    printf("Digite os jogadores do Time %d (IDs de 1 a 5): ", numeroTime);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &time->jogadores[i]);
    }
}

int calcularMVP(Jogador jogadoresTime[], int numJogadores) {
    int melhorJogador = 0;
    float melhorKDA = jogadoresTime[0].kda;

    for (int i = 1; i < numJogadores; i++) {
        if (jogadoresTime[i].kda > melhorKDA) {
            melhorKDA = jogadoresTime[i].kda;
            melhorJogador = i;
        }
    }

    return melhorJogador;
}

//preencher dados dos jogadores

void dadosJogador(Jogador *jogador){

    printf("Digite o nick do jogador: ");
    scanf(" %[^\n]", jogador->nick);

    printf("Digite a lane do jogador: ");
    scanf(" %[^\n]", jogador->lane);

    printf("Digite o campeão do jogador: ");
    scanf(" %[^\n]", jogador->campeao);

    printf("Digite o número de kills do jogador: ");
    scanf("%d", &jogador->kills);

    printf("Digite o número de assists do jogador: ");
    scanf("%d", &jogador->assists);

    printf("Digite o número de deaths do jogador: ");
    scanf("%d", &jogador->deaths);

    jogador->kda = (float)(jogador->kills + 0.5 * jogador->assists) / jogador->deaths;

}

// preencher dados da partida 

void dadosPartida(Partida *partida, EstatisticasPartida *estatisticas, Jogador jogadoresTime1[], Jogador jogadoresTime2[]) {
    printf("Digite o vencedor da partida: ");
    scanf(" %[^\n]", partida->vencedor);

    printf("Digite o perdedor da partida: ");
    scanf(" %[^\n]", partida->perdedor);

    int mvpTime1 = calcularMVP(jogadoresTime1, 5);
    int mvpTime2 = calcularMVP(jogadoresTime2, 5);

    if (jogadoresTime1[mvpTime1].kda > jogadoresTime2[mvpTime2].kda) {
        strcpy(partida->mvp, jogadoresTime1[mvpTime1].nick);
    } else {
        strcpy(partida->mvp, jogadoresTime2[mvpTime2].nick);
    }

    printf("Digite a duração da partida (em minutos): ");
    scanf("%d", &partida->duracao);

    // estatísticas da partida para o Time 1
    printf("Digite o ouro acumulado pelo Time 1: ");
    scanf("%d", &estatisticas->time1.ouroAcumulado);

    printf("Digite o número de torres destruídas pelo Time 1: ");
    scanf("%d", &estatisticas->time1.torresDestruidas);

    printf("Digite o número de dragões conquistados pelo Time 1: ");
    scanf("%d", &estatisticas->time1.dragoesConquistados);

    printf("Digite o número de barões conquistados pelo Time 1: ");
    scanf("%d", &estatisticas->time1.baroesConquistados);

    // estatísticas da partida para o Time 2
    printf("Digite o ouro acumulado pelo Time 2: ");
    scanf("%d", &estatisticas->time2.ouroAcumulado);

    printf("Digite o número de torres destruídas pelo Time 2: ");
    scanf("%d", &estatisticas->time2.torresDestruidas);

    printf("Digite o número de dragões conquistados pelo Time 2: ");
    scanf("%d", &estatisticas->time2.dragoesConquistados);

    printf("Digite o número de barões conquistados pelo Time 2: ");
    scanf("%d", &estatisticas->time2.baroesConquistados);

}

//exibindo

void exibirPartida(Time time1, Time time2, Jogador jogadoresTime1[], Jogador jogadoresTime2[], Partida partida, EstatisticasPartida estatisticas) {
    printf("\n --- DETALHES DA PARTIDA ---\n");

    printf("Time %s (Lado: %s)\n", time1.nome, time1.lado);
    for (int i = 0; i < 5; i++) {
        printf("Jogador %s - Campeão: %s, K/D/A: %d/%d/%d, KDA: %.2f\n",
               jogadoresTime1[i].nick, jogadoresTime1[i].campeao,
               jogadoresTime1[i].kills, jogadoresTime1[i].assists, jogadoresTime1[i].deaths, jogadoresTime1[i].kda);
    }

    printf("\nTime %s (Lado: %s)\n", time2.nome, time2.lado);
    for (int i = 0; i < 5; i++) {
        printf("Jogador %s - Campeão: %s, K/D/A: %d/%d/%d, KDA: %.2f\n",
               jogadoresTime2[i].nick, jogadoresTime2[i].campeao,
               jogadoresTime2[i].kills, jogadoresTime2[i].assists, jogadoresTime2[i].deaths, jogadoresTime2[i].kda);
    }

    printf("\nResultado da Partida:\n");
    printf("Vencedor: %s\n", partida.vencedor);
    printf("Perdedor: %s\n", partida.perdedor);
    printf("MVP: %s\n", partida.mvp);

    printf("\nEstatísticas da Partida:\n");
    printf("Duração: %d minutos\n", partida.duracao);

    printf("\nEstatísticas para o Time %s:\n", time1.nome);
    printf("Ouro Acumulado: %d\n", estatisticas.time1.ouroAcumulado);
    printf("Torres Destruidas: %d\n", estatisticas.time1.torresDestruidas);
    printf("Dragões Conquistados: %d\n", estatisticas.time1.dragoesConquistados);
    printf("Barões Conquistados: %d\n", estatisticas.time1.baroesConquistados);

    printf("\nEstatísticas para o Time %s:\n", time2.nome);
    printf("Ouro Acumulado: %d\n", estatisticas.time2.ouroAcumulado);
    printf("Torres Destruidas: %d\n", estatisticas.time2.torresDestruidas);
    printf("Dragões Conquistados: %d\n", estatisticas.time2.dragoesConquistados);
    printf("Barões Conquistados: %d\n", estatisticas.time2.baroesConquistados);
}

int main() {
    Time time1, time2;
    Jogador jogadoresTime1[5], jogadoresTime2[5];
    Partida partida;
    EstatisticasPartida estatisticas;

    dadosTime(&time1, 1);

    for (int i = 0; i < 5; i++) {
        printf("\n** Preenchendo dados do Jogador %d do Time 1 **\n", i + 1);
        dadosJogador(&jogadoresTime1[i]);
    }

    prinff("\n");
    dadosTime(&time2, 2);

    for (int i = 0; i < 5; i++) {
        printf("\n** Preenchendo dados do Jogador %d do Time 2 **\n", i + 1);
        dadosJogador(&jogadoresTime2[i]);
    }

    printf("\n-- PREENCHENDO DADOS DA PARTIDA --\n");
    dadosPartida(&partida, &estatisticas, jogadoresTime1, jogadoresTime2);

    exibirPartida(time1, time2, jogadoresTime1, jogadoresTime2, partida, estatisticas);

    return 0;
}
