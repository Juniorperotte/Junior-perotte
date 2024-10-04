#include <iostream>

int main(int argc, char **argv)
{
    char reserva[10][6] = {
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '}};

    int fileira = -1, acento = -1, tipoDePassagem = -1;
    char poltrona, proximaReserva;
    bool reservado;

    while (true)
    {
        printf("\nQual tipo de passagem ?(1- EXECUTIVA 2-ECONÔMICA): ");
        scanf("%d", &tipoDePassagem);

        if (tipoDePassagem <= 0 || tipoDePassagem >= 3)
        {
            std::cout << "Passagem inválida!";
            continue;
        }

        printf("\nQual fileira você quer reservar ?(1 - 10): ");
        scanf("%d", &fileira);

        if (fileira <= 0 || fileira >= 11)
        {
            std::cout << "fileira inválida!";
            continue;
        }

        printf("\nQual poltrona você quer reservar ?[A][B][C][D][E][F]: ");
        scanf(" %c", &poltrona);

        if (tipoDePassagem == 2)
        {
            switch (poltrona)
            {
            case 'A':
                acento = 0;
                std::cout << "\nPoltronas A e F apenas Executivo!";
                continue;
            case 'B':
                acento = 1;
                break;
            case 'C':
                acento = 2;
                break;
            case 'D':
                acento = 3;
                break;
            case 'E':
                acento = 4;
                break;
            case 'F':
                acento = 5;
                std::cout << "\nPoltronas A e F apenas Executivo!";
                continue;
            default:
                std::cout << "\nAcento inválido!";
                continue;
            }
        }

        reservado = reserva[fileira - 1][acento] == 'x';
        if (reservado)
        {
            std::cout << "Selecione outra poltrona, essa já está ocupada!";
            continue;
        }

        switch (poltrona)
        {
        case 'A':
            acento = 0;
            break;
        case 'B':
            acento = 1;
            break;
        case 'C':
            acento = 2;
            break;
        case 'D':
            acento = 3;
            break;
        case 'E':
            acento = 4;
            break;
        case 'F':
            acento = 5;
            break;
        default:
            std::cout << "\nAcento inválido!";
            continue;
        }

        reserva[fileira - 1][acento] = 'x';
        printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");

        for (int x = 0; x < 10; x++)
        {
            if (x != 9)
            {
                printf("\n\t0%d\t", x + 1);
            }
            else
            {
                printf("\n\t%d\t", x + 1);
            }
            for (int y = 0; y < 6; y++)
            {
                std::cout << "[" << reserva[x][y] << "] ";
                if (y == 2)
                {
                    printf("\t");
                }
            }
        }

        printf("\nFazer outra reserva ?:(y/n) ");
        scanf(" %c", &proximaReserva);

        if (proximaReserva == 'n')
        {
            break;
        }
        else if (proximaReserva == 'y')
        {
            continue;
        }
        else
            std::cout << "Resposta inválida!";

        break;
        printf("\n");
    }
    return 0;
}