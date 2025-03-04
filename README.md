# Sistema de Login e Cadastro em C

Este projeto é uma implementação simples de um sistema de login e cadastro desenvolvido em linguagem C. O sistema permite o cadastro de usuários e posterior autenticação, possibilitando também a atualização dos dados cadastrais.

## Funcionalidades

- **Cadastro de Usuários:**
  - Coleta de dados: nome, data de nascimento (dia, mês e ano) e senha (com confirmação);
  - Validações básicas para garantir a integridade dos dados (ex.: dia, mês e ano válidos, verificação de senhas iguais);
  - Armazenamento dos dados em um arquivo binário (`cadastro.dat`);
  - Uso de alocação dinâmica para suportar um número variável de usuários.

- **Login e Autenticação:**
  - Solicita nome e senha do usuário;
  - Validação das credenciais comparando com os dados armazenados;
  - Exibição do perfil do usuário autenticado e opção de atualizar dados cadastrais.

- **Atualização do Cadastro:**
  - Permite que o usuário altere seu nome, data de nascimento ou senha;
  - Realiza validação para garantir que a nova senha seja confirmada corretamente.

## Pré-Requisitos

- Compilador C (ex.: GCC);
- Ambiente de execução com suporte a terminal (Linux, macOS ou Windows).

## Como Compilar e Executar

1. **Clone o repositório:**

   ```bash
   git clone https://github.com/seu-usuario/sistema-login-c.git
