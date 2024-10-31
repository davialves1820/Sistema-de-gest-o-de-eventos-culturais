/*
Menu Interativo
O menu deve permitir ao usuário:
Adicionar e remover eventos e artistas.
Listar (de forma ordenada) eventos e artistas.
*/

#include "EventManager.h"

using std::cin;
using std::getline;


// Função exibir menu
void display_menu() {
    cout << "1-Adicionar evento" << endl;
    cout << "2-Remover evento" << endl;
    cout << "3-adicionar artista a evento" << endl;
    cout << "4-remover artista do evento" << endl;
    cout << "5-Listar eventos" << endl;
    cout << "6-Listar artista de um evento" << endl;
    cout << "0-Exit" << endl;
    cout << "Option: ";
}

int main(void) {

    Event_manager event_manager; // Gerenciamento de eventos
    int opcao;

    do {
        cout << endl;
        display_menu(); // Menu de opções
        cin >> opcao;
        cin.ignore();
        cout << endl;

        switch (opcao) {
            case 1: { // Adicionar evento
                try { // Bloco try para verificar se teve lançamento de exceção
                    string nome_evento, tipo;
                    int idade_evento, tipo_evento;
                    cout << "Digite o nome do evento: ";
                    getline(cin, nome_evento);
                    cout << "Digite a idade do evento: ";
                    cin >> idade_evento;
                    cout << "Digite o tipo de evento (1-Show, 2-Exposicao): ";
                    cin >> tipo_evento;
                    cin.ignore();

                    if (tipo_evento == 1) { // Caso o evento for show
                        cout << "Digite o genero musical: ";
                        getline(cin, tipo);
                        Show* show = new Show(nome_evento, idade_evento, tipo); // Cria um novo show
                        event_manager.add_event(show); // Adiciona o show no gerenciamento de eventos
                        cout << "Evento adicionado com sucesso" << endl; // Informa que a adição do evento foi bem sucedida
                    } else if (tipo_evento == 2) { // Caso o evento for Exposição
                        cout << "Digite o tipo de arte: ";
                        getline(cin, tipo);
                        Exposure* exposure = new Exposure(nome_evento, idade_evento, tipo); // Cria uma nova exposição
                        event_manager.add_event(exposure); // Adiciona a exposição ao gerenciamento de eventos
                        cout << "Evento adicionado com sucesso" << endl; // Informa que a adição do evento foi bem sucedida
                    }
                } catch(const Negative_age_exception& e) { // Captura exceção de idade negativa
                    cout << "Excecao encontrada: " << e.what() << endl;
                }
                break;
            }
            case 2: { // Remover evento
                string nome_evento;
                cout << "Digite o nome do evento a ser removido: ";
                getline(cin, nome_evento);
                event_manager.remove_event(nome_evento);
                cout << "Evento removido com sucesso" << endl; // Informa que a remoção foi bem sucedida
                break;
            }
            case 3: { // Adicionar artista no evento
                try { // Bloco try para verificar se teve lançamento de exceção
                    string nome_evento, nome_artista;
                    int idade_artista;
                    cout << "Digite o nome do evento: ";
                    getline(cin, nome_evento);
                    cout << "Digite o nome do artista: ";
                    getline(cin, nome_artista);
                    cout << "Digite a idade do artista: ";
                    cin >> idade_artista;

                    Event* event = event_manager.get_event(nome_evento); // Variavel que recebe o evento selecionado
                    if (event == nullptr) { // Verifica se o evento foi encontrado, se for nullptr informa que não
                        cout << "Evento nao encontrado" << endl;
                        break;
                    }
                    Artist artist(nome_artista, idade_artista); // Cria um novo artista
                    (*event) + artist; // Adiciona artista ao evento
                    cout << "Artista adicionado com sucesso" << endl; // Informa que a adição foi bem sucedida
                }catch(const Negative_age_exception& e) { // Captura a exceção de idade negativa
                    cout << "Excecao encontrada: " << e.what() << endl;
                }
                break;
            }
            case 4: { // Remover artista de um evento
                string nome_evento, nome_artista;
                cout << "Digite o nome do evento: ";
                getline(cin, nome_evento);
                cout << "Digite o nome do artista a ser removido: ";
                getline(cin, nome_artista);

                Event* event = event_manager.get_event(nome_evento); // Encontra o evento selecionado
                if (event == nullptr) { // Verifica se o evento foi encontrado, se for nullptr informa que não
                    cout << "Evento nao encontrado" << endl;
                    break;
                }
                (*event) - nome_artista; // Caso encontrado remove o artista do evento
                cout << "Artista removido com sucesso" << endl; // Informa que a remoção foi bem sucedida
                break;
            }
            case 5: { // Exibe todos os eventos
                event_manager.display_events();
                break;
            }
            case 6: { // Exibir artistas de um evento
                string nome_evento, nome_artista;
                cout << "Digite o nome do evento: ";
                getline(cin, nome_evento);
                Event* event = event_manager.get_event(nome_evento); // Encontra o evento selecionado
                if (event == nullptr) { // Verifica se o evento foi encontrado, se for nullptr informa que não
                    cout << "Evento nao encontrado" << endl;
                    break;
                }
                event->display_artists(); // Exibe todos os artistas do evento ordenado pela idade
                break;
            }
            case 0: { // Encerra o looping
                cout << "Saindo...\n";
                break;
            }
            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}