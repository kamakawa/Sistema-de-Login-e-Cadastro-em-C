#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int dia;
    int mes;
    int ano;
    char senha[10];
    char confirmasenha[10];
} Dados;

void dadosSalvos(Dados* dados, int quantidade) {
    FILE *salvar = fopen("cadastro.dat", "rb");

    if (salvar == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for(int i = 0; i < quantidade; i++) {
        fread(dados[i].nome, sizeof(dados[i].nome), 1, salvar);
        fread(dados[i].senha, sizeof(dados[i].senha), 1, salvar);
        fread(&dados[i].dia, sizeof(int), 1, salvar);
        fread(&dados[i].mes, sizeof(int), 1, salvar);
        fread(&dados[i].ano, sizeof(int), 1, salvar);
    }
    fclose(salvar);
}

int contarUsuarios() {
    FILE *arquivo = fopen("cadastro.dat", "rb");
    if (arquivo == NULL) {
        return 0;
    }
    fseek(arquivo, 0, SEEK_END);
    int quantidade = ftell(arquivo) / sizeof(Dados);
    fclose(arquivo);
    return quantidade;
}

void salvarUsuarios(Dados* dados, int quantidade) {
    FILE *arquivo = fopen("cadastro.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    fwrite(dados, sizeof(Dados), quantidade, arquivo);
    fclose(arquivo);
}


void login(Dados* dados, int numeroUsuarios) {
    dadosSalvos(dados, numeroUsuarios);
    char nomeUsuario[50];
    char senhaUsuario[10]; 
    char alterar;
    int opcao;
    int usuarioAutenticado = 0;

    printf("\n---- Login ----\n");
    printf("Digite o seu nome (nome cadastrado): \n");
    fgets(nomeUsuario, 50, stdin);
    nomeUsuario[strcspn(nomeUsuario, "\n")] = '\0';
    setbuf(stdin, NULL);

    printf("Digite a sua senha: \n");
    fgets(senhaUsuario, 10, stdin); 
    senhaUsuario[strcspn(senhaUsuario, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < numeroUsuarios; i++) {
        if (strcmp(nomeUsuario, dados[i].nome) == 0 && strcmp(senhaUsuario, dados[i].senha) == 0) {
            usuarioAutenticado = 1;
            printf("\nOlá, %s\n", dados[i].nome);
            printf("\nPerfil:\n");
            printf("Data de nascimento: %02d/%02d/%d \n", dados[i].dia, dados[i].mes, dados[i].ano);
            printf("Senha: %s \n", dados[i].senha);

            // Pergunta sobre alterações no cadastro
            printf("\n%s, deseja fazer alguma alteração no seu cadastro?\n", dados[i].nome);
            printf("Se sim, digite a tecla 's'\n");
            scanf(" %c", &alterar);
            setbuf(stdin, NULL);

            if (alterar == 's' || alterar == 'S') {
                printf("O que você deseja alterar?\n");
                printf(" 1 - Nome\n");
                printf(" 2 - Data de nascimento\n");
                printf(" 3 - Senha\n");
                scanf("%d", &opcao);
                setbuf(stdin, NULL);

                switch (opcao) {
                    case 1:
                        printf("Digite o novo nome de usuário: \n");
                        fgets(dados[i].nome, 50, stdin);
                        dados[i].nome[strcspn(dados[i].nome, "\n")] = '\0';
                        break;

                    case 2:
                        printf("Digite a sua data de nascimento: \n");
                        printf("Dia:");
                        scanf("%d", &dados[i].dia);
                        printf("Mês:");
                        scanf("%d", &dados[i].mes);
                        printf("Ano:");
                        scanf("%d", &dados[i].ano);
                        break;

                    case 3:
                        printf("Digite a sua nova senha:\n");
                        fgets(dados[i].senha, 10, stdin); 
                        dados[i].senha[strcspn(dados[i].senha, "\n")] = '\0';

                        printf("Digite novamente a sua nova senha:\n");
                        fgets(dados[i].confirmasenha, 10, stdin); 
                        dados[i].confirmasenha[strcspn(dados[i].confirmasenha, "\n")] = '\0';

                        while (strcmp(dados[i].senha, dados[i].confirmasenha) != 0) {
                            printf("Erro! Senhas diferentes\n");
                            printf("Digite a sua nova senha:\n");
                            fgets(dados[i].senha, 10, stdin); 
                            dados[i].senha[strcspn(dados[i].senha, "\n")] = '\0';

                            printf("Digite novamente a sua nova senha:\n");
                            fgets(dados[i].confirmasenha, 10, stdin); 
                            dados[i].confirmasenha[strcspn(dados[i].confirmasenha, "\n")] = '\0';
                        }
                        break;

                    default:
                        printf("Opção inválida!\n");
                        break;
                }
                salvarUsuarios(dados, numeroUsuarios);
                printf("Cadastro atualizado com sucesso!\n");
            }
            break;
        }
    }

    if (!usuarioAutenticado) {
        printf("Login falhou! Nome ou senha incorretos.\n");
    }
}

void salvarCadastro(Dados* dados, int* quantidade) {
    FILE *salvar = fopen("cadastro.dat", "ab");

    if (salvar == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (int i = 0; i < *quantidade; i++) {
        fwrite(dados[i].nome, sizeof(char), 50, salvar);
        fwrite(dados[i].senha, sizeof(char), 10, salvar);
        fwrite(&dados[i].dia, sizeof(int), 1, salvar);
        fwrite(&dados[i].mes, sizeof(int), 1, salvar);
        fwrite(&dados[i].ano, sizeof(int), 1, salvar);
    }

    fclose(salvar);
}

void cadastro(Dados** dados, int* quantidade) {
    char escolha;

    printf("\n--- Cadastro de Usuário ---\n");

    for (int i = 0; i < *quantidade; i++) {
        printf("Digite o seu nome:\n");
        fgets((*dados)[i].nome, 50, stdin);
        (*dados)[i].nome[strcspn((*dados)[i].nome, "\n")] = '\0';
        setbuf(stdin, NULL);

        printf("%s, digite o dia do seu nascimento: ", (*dados)[i].nome);
        scanf("%d", &(*dados)[i].dia);
        setbuf(stdin, NULL);

        while ((*dados)[i].dia > 31 || (*dados)[i].dia < 1) {
            printf("Erro! Dia inválido. Digite novamente: ");
            scanf("%d", &(*dados)[i].dia);
            setbuf(stdin, NULL);
        }

        printf("%s, digite o mês do seu nascimento: ", (*dados)[i].nome);
        scanf("%d", &(*dados)[i].mes);
        setbuf(stdin, NULL);

        while ((*dados)[i].mes > 12 || (*dados)[i].mes < 1) {
            printf("Erro! Mês inválido. Digite novamente: ");
            scanf("%d", &(*dados)[i].mes);
            setbuf(stdin, NULL);
        }

        printf("%s, digite o ano do seu nascimento: ", (*dados)[i].nome);
        scanf("%d", &(*dados)[i].ano);
        setbuf(stdin, NULL);

        while ((*dados)[i].ano > 2025 || (*dados)[i].ano < 1900) {
            printf("Erro! Ano inválido. Digite novamente: ");
            scanf("%d", &(*dados)[i].ano);
            setbuf(stdin, NULL);
        }

        printf("%s, crie uma senha:\n", (*dados)[i].nome);
        fgets((*dados)[i].senha, 10, stdin);
        (*dados)[i].senha[strcspn((*dados)[i].senha, "\n")] = '\0';
        setbuf(stdin, NULL);

        printf("Repita a mesma senha:\n");
        fgets((*dados)[i].confirmasenha, 10, stdin);
        (*dados)[i].confirmasenha[strcspn((*dados)[i].confirmasenha, "\n")] = '\0';
        setbuf(stdin, NULL);

        while (strcmp((*dados)[i].senha, (*dados)[i].confirmasenha) != 0) {
            printf("Erro! Senhas diferentes\n");
            printf("%s, crie uma senha:\n", (*dados)[i].nome);
            fgets((*dados)[i].senha, 10, stdin);
            (*dados)[i].senha[strcspn((*dados)[i].senha, "\n")] = '\0';
            setbuf(stdin, NULL);

            printf("Repita a mesma senha:\n");
            fgets((*dados)[i].confirmasenha, 10, stdin);
            (*dados)[i].confirmasenha[strcspn((*dados)[i].confirmasenha, "\n")] = '\0';
            setbuf(stdin, NULL);
        }

        printf("Cadastro realizado com sucesso!\n");
        printf("%s, você deseja realizar mais algum cadastro? (S/N): ", (*dados)[i].nome);
        scanf(" %c", &escolha);
        setbuf(stdin, NULL);

        if (escolha == 'N' || escolha == 'n') {
            *quantidade = i + 1;
            break;
        }

        // Realocação dinâmica caso o limite seja atingido
        if (i == *quantidade - 1) {
            int novaQuantidade = *quantidade + 2;
            Dados* temp = (Dados*) realloc(*dados, novaQuantidade * sizeof(Dados));
            if (temp == NULL) {
                printf("Erro na alocação de memória!\n");
                exit(1);
            }
            *dados = temp;
            *quantidade = novaQuantidade;
        }
    }
}

int main() {
    int quantidade = 2;
    int opcao;
    int numeroUsuarios = 0;
    
    Dados* dados = (Dados*) malloc(quantidade * sizeof(Dados));

    if (dados == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Cadastrar novo usuário\n");
        printf("2 - Login\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);

        switch (opcao) {
            case 1:
                cadastro(&dados, &quantidade);
                salvarCadastro(dados, &quantidade);
                break;

            case 2:
                numeroUsuarios = contarUsuarios();
                login(dados, numeroUsuarios);
                break;

            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);

    free(dados);
    return 0;
}
