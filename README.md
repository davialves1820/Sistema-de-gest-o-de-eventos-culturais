# Sistema de Gerenciamento de Eventos Culturais

# 📄 Descrição
Este projeto é um sistema de gerenciamento de eventos desenvolvido em C++. O sistema permite adicionar, remover e listar eventos, além de gerenciar artistas associados a esses eventos. Os eventos podem ser de diferentes tipos, como shows e exposições.

---

## 🔧 Funcionalidades

- **Adicionar Evento**: Cria um novo evento, especificando o nome, idade e tipo (Show ou Exposição).
- **Remover Evento**: Remove um evento existente pelo nome.
- **Adicionar Artista a Evento**: Adiciona um artista a um evento específico, informando o nome e a idade do artista.
- **Remover Artista de Evento**: Remove um artista de um evento específico.
- **Listar Eventos**: Exibe todos os eventos cadastrados.

---

## 🗂️ Estrutura do Projeto

- **`src/: Contém os arquivos de implementação (.cpp).
- **`include/: Contém os arquivos de cabeçalho (.h).
- **`obj/: Diretório gerado pelo Makefile para armazenar arquivos objeto (.o).
- **`build/: Diretório gerado pelo Makefile para o executável final.
- **`Makefile: Script para automatizar o processo de compilação.

---

## 📦 Classes Principais

- **`Artist`**: Classe que implementa a funcionalidade do objeto artista
- **`Event`**: Classe base abstrata para todos os tipos de eventos.
- **`Show`**, **`Exposure`**: Classes derivadas que implementam a funcionalidade específica de cada tipo de evento.
- **`EventManager`**: Classe responsável por gerenciar os eventos.

---

## ⚙️ Compilação e Execução

Para compilar o projeto no terminal execute: 

```bash
make
```
Para executar o programa no terminal execute:
```bash
./build/my_program
```

---

## 🖥️ Exemplo de Uso

- **Adicionar Evento:** Selecione adicionar evento e preencha as informações solicitadas.
- **Remover Evento:** Selecione remover evento e insira o nome do evento a ser removido.
- **Adicionar Artista ao Evento:** Selecione adicionar artista e selecione o evento e insira os dados do artista.
- **Remover Artista de um Evento:** Selecione remover artista de um evento insira o nome do evento e do artista.
- **Exibir Todos os Eventos:** Selecione exibir eventos para ver uma lista de eventos.
- **Exibir Artistas de um Evento:** Selecione exibir artistas e selecione o evento para ver os artistas associados.
