# Sistema Básico de Cadastro e Login em C

Um sistema simples de cadastro e autenticação de usuários desenvolvido em linguagem C, com foco na persistência de dados em arquivo binário e no gerenciamento dinâmico de memória. **Este projeto foi desenvolvido de forma autônoma durante meu 2º período da faculdade com o objetivo de solidificar meus conhecimentos em programação C e explorar conceitos fundamentais como manipulação de arquivos e alocação dinâmica de memória.** É uma base sólida para aplicações que exigem armazenamento e recuperação de informações de usuário.

---

## 🚀 Funcionalidades

* **Cadastro de Novos Usuários:** Permite o registro de nome, username, data de nascimento e senha.
* **Login de Usuários:** Autentica usuários existentes com base em username e senha.
* **Persistência de Dados:** Salva e carrega dados de usuários em um arquivo binário (`cadastro.dat`), garantindo que as informações não se percam após o encerramento do programa.
* **Edição de Cadastro:** Usuários autenticados podem atualizar seu nome, username, data de nascimento e senha.
* **Gerenciamento Dinâmico de Memória:** Utiliza `malloc` e `realloc` para alocar e realocar memória conforme a necessidade de usuários, otimizando o uso de recursos.
* **Validação de Entrada:** Inclui validações básicas para datas e confirmação de senha.

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem de Programação:** C
* **Manipulação de Arquivos:** `stdio.h`
* **Gerenciamento de Memória:** `stdlib.h`
* **Manipulação de Strings:** `string.h`

---

## Como Compilar e Executar

Para compilar e executar este projeto, você precisará de um compilador C (como GCC).

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/seu-usuario/nome-do-repositorio.git](https://github.com/seu-usuario/nome-do-repositorio.git)
    cd nome-do-repositorio
    ```
    *(Ajuste `seu-usuario/nome-do-repositorio` para o link real do seu repositório)*

2.  **Compile o código:**
    ```bash
    gcc main.c -o cadastro_login
    ```
    *(Assumindo que o arquivo principal se chama `main.c`. Se for `seu_arquivo.c`, ajuste o comando)*

3.  **Execute o programa:**
    ```bash
    ./cadastro_login
    ```

---

## 🧠 Conceitos Demonstrados

Este projeto é um excelente exemplo prático de:

* **Estruturas (Structs):** Organização de dados relacionados.
* **Ponteiros e Alocação Dinâmica:** Flexibilidade no gerenciamento de memória.
* **Operações de I/O em Arquivos:** Leitura e escrita de dados binários.
* **Manipulação de Strings:** Funções essenciais para trabalhar com texto.
* **Modularização de Código:** Organização em funções para reuso e clareza.
* **Autenticação Básica:** Implementação de um fluxo de login e verificação.

---

## 💡 Próximos Passos (Possíveis Melhorias)

* **Segurança de Senhas:** Implementar hashing (ex: SHA-256) para armazenar senhas de forma segura.
* **Tratamento de Erros Aprimorado:** Mensagens de erro mais detalhadas e recuperação de erros mais robusta.
* **Interface do Usuário (UI):** Melhorar a experiência do usuário com uma interface mais interativa (embora para um console, isso signifique clareza).
* **Remoção de Usuários:** Adicionar funcionalidade para deletar um cadastro existente.
* **Busca de Usuários:** Permitir buscar usuários por critérios específicos.

---

## Contato

* **Eric Kamakawa** - [erickamakawa@hotmail.com](mailto:erickamakawa@hotmail.com)
* **LinkedIn:** [linkedin.com/in/erickamakawa](https://www.linkedin.com/in/erickamakawa)
* **GitHub:** [github.com/kamakawa](https://github.com/kamakawa)

---
