# 📘 Trabalho Individual – Estruturas de Dados (UCB)

Este repositório contém a implementação de um trabalho individual da disciplina **Estrutura de Dados**, do curso de Ciência da Computação da **Universidade Católica de Brasília (UCB)**. O projeto foi desenvolvido em linguagem **C**, utilizando conceitos de estruturas dinâmicas, como listas encadeadas.

---

## 📚 Descrição

O programa realiza as seguintes operações:

- 📥 **Leitura de dados** de cidades a partir de arquivos `.txt`
- 🧩 **Armazenamento** dos dados em **listas encadeadas simples**
- 🔍 **Análise de vizinhança** entre as cidades com base nas regras definidas na proposta do trabalho
- 📝 **Geração automática de relatórios** com os resultados no arquivo `Resultado.txt`

---

## 🗂️ Estrutura dos Arquivos

- `main.c` — Função principal e controle de execução  
- `cidades.c` / `cidades.h` — Implementação do TAD "Cidade" e suas operações  
- `Teste01.txt`, `Teste02.txt` — Arquivos de entrada com dados de teste  
- `Resultado.txt` — Arquivo de saída gerado pelo programa  
- `programa.exe` — Versão compilada para ambiente Windows  

---
###
## 🛠️ Tecnologias Utilizadas

- Linguagem **C**
- Compilador **GCC** / **MinGW**
- ❌ Nenhuma biblioteca externa foi utilizada

---

## 🚀 Como Executar

### 1. Compilando o programa (opcional, se quiser recompilar)
```bash
gcc main.c cidades.c -o programa
```
### 2. Executando 
```bash
./programa
```
### 3. Resultado
- O arquivo Resultado.txt será criado na mesma pasta, contendo a análise final com base nos dados fornecidos.

---
## 📌 Observações Importantes

- Este projeto foi desenvolvido **exclusivamente para fins acadêmicos**, como parte das atividades avaliativas da disciplina **Estrutura de Dados** do curso de **Ciência da Computação** da **Universidade Católica de Brasília (UCB)**.
  
- A implementação foi realizada de forma **individual**, seguindo os critérios e orientações do professor responsável pela disciplina.

- O código e os arquivos fornecidos têm **propósito didático** e podem ser adaptados livremente para fins de aprendizado e prática.

- **Evite o uso indevido** do código em atividades avaliativas de outras instituições sem a devida autorização ou modificação.
