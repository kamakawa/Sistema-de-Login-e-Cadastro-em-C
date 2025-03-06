# Sistema de Login e Cadastro em C

Este projeto é uma implementação simples de um sistema de login e cadastro desenvolvido em linguagem C. O sistema permite o cadastro de usuários e posterior autenticação, possibilitando também a atualização dos dados cadastrais.

## Funcionalidades

### Cadastro de Usuários
- Coleta de dados: nome, data de nascimento (dia, mês e ano) e senha (com confirmação);
- Validações básicas para garantir a integridade dos dados (ex.: dia, mês e ano válidos, verificação de senhas iguais);
- Armazenamento dos dados em um arquivo binário (`cadastro.dat`);
- Uso de alocação dinâmica para suportar um número variável de usuários.

### Login e Autenticação
- Solicita nome e senha do usuário;
- Validação das credenciais comparando com os dados armazenados;
- Exibição do perfil do usuário autenticado e opção de atualizar dados cadastrais.

### Atualização do Cadastro
- Permite que o usuário altere seu nome, data de nascimento ou senha;
- Realiza validação para garantir que a nova senha seja confirmada corretamente.

## Como os Dados São Armazenados?
Os dados dos usuários são salvos no arquivo binário `cadastro.dat`, garantindo persistência entre execuções do programa. O formato de armazenamento segue a estrutura:

```
[NOME (50 bytes)][SENHA (10 bytes)][DIA (int)][MÊS (int)][ANO (int)]
```

## Requisitos
- Compilador C (ex.: GCC);
- Ambiente de execução com suporte a terminal (Linux, macOS ou Windows).

## Como Compilar e Executar

1. Clone o repositório:
   ```bash
   git clone https://github.com/kamakawa/Sistema-de-Login-e-Cadastro-em-C.git
   cd Sistema-de-Login-e-Cadastro-em-C
   ```

2. Compile o código:
   ```bash
   gcc main.c -o sistema
   ```
   Se houver múltiplos arquivos `.c`, compile da seguinte forma:
   ```bash
   gcc *.c -o sistema
   ```

3. Execute o programa:
   ```bash
   ./sistema
   ```

## Possíveis Melhorias Futuras
- **Segurança**: Implementar hash de senhas para evitar armazenamento em texto puro.
- **Interface Gráfica**: Utilizar bibliotecas como GTK para melhorar a experiência do usuário.
- **Modularização**: Separar funções em múltiplos arquivos para facilitar a manutenção.
- **Validações Avançadas**: Melhorar as verificações de entrada e tratamento de erros.

## Como Contribuir
Ficamos felizes com contribuições! Para contribuir:
1. Faça um fork do repositório.
2. Crie uma branch para sua contribuição (`git checkout -b minha-melhoria`).
3. Faça suas alterações e commit (`git commit -m "Descrição da melhoria"`).
4. Envie para o repositório remoto (`git push origin minha-melhoria`).
5. Abra um Pull Request.

## Licença
Este projeto está licenciado sob a [MIT License](LICENSE).

---

Caso tenha dúvidas ou sugestões, sinta-se à vontade para abrir uma issue ou entrar em contato!

🚀 Desenvolvido por Eric Kamakawa



