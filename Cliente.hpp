#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <vector>
#include <map>
#include "Pedido.hpp"
#include "Cardapio.hpp"
#include "utils.hpp"

class Cliente {
private:
    static std::map<std::string, std::string> clientes; //!< Banco de dados de clientes (username -> senha)
    std::map<std::string, int> pontosRecompensa; //!< Armazena os pontos por cliente
    std::string username;
    std::string senha;
    std::vector<Pedido*>* listaPedidos;
    Cardapio* cardapio;
    /*!bool Cliente::autenticar(const std::string& user, const std::string& pass) {
    auto it = clientes.find(user);
    return it != clientes.end() && it->second == pass;}
    */
    bool autenticar(const std::string& user, const std::string& pass);

public:
    Cliente(Cardapio* cardapioRef, std::vector<Pedido*>* pedidosRef);
    /*!void Cliente::criarConta() {
    std::string user, pass;
    while (true) {
        std::cout << FG_CIANO << "Escolha um nome de usuario: " << RESET;
        std::getline(std::cin, user);
        if(validarSenha(user)){
            std::cout << FG_VERMELHO << "Nome de usuario nao pode ser nulo!" << RESET << std::endl;
            continue;
        }
        if (clientes.find(user) != clientes.end()) {
            std::cout << FG_VERMELHO << "Nome de usuario indisponivel." << RESET << std::endl;
        }
        else {
            break;
        }
    }
    while(1){
    std::cout << FG_CIANO << "Escolha uma senha: " << RESET;
    std::getline(std::cin, pass);
    if(validarSenha(pass)){
        std::cout << FG_VERMELHO << "A senha nao pode ser nula!" << RESET << std::endl;
        continue;
        }
    se break;
    }
    *entes[user] = pass;
    d::cout << FG_VERDE << "Conta criada com sucesso!" << RESET << std::endl;} 
   */ 
    static void criarConta();
    /*!bool Cliente::entrar() {
    std::string user, pass;
    std::cout << FG_CIANO << "Nome de usuario: " << RESET;
    std::getline(std::cin, user);
    std::cout << FG_CIANO << "Senha: " << RESET;
    std::getline(std::cin, pass);
    if (autenticar(user, pass)) {
        username = user;
        senha = pass;
        std::cout << FG_VERDE << "Login bem-sucedido!" << RESET << std::endl;
        return true;
    }
    else {
        std::cout << FG_VERMELHO << "Credenciais invalidas." << RESET << std::endl;
        return false;
    }
    }*/
    bool entrar();
    /*!void Cliente::alterarSenha() {
    std::string senhaAtual, novaSenha;
    std::cout << FG_CIANO << "Digite a senha atual: " << RESET;
    std::getline(std::cin, senhaAtual);
    if (senhaAtual == senha) {
        while(1){
        std::cout << FG_CIANO << "Digite a nova senha: " << RESET;
        std::getline(std::cin, novaSenha);
        if(validarSenha(novaSenha)){
            std::cout << FG_VERMELHO << "A senha nao pode ser nula!" << RESET << std::endl;
        }
        else{
        senha = novaSenha;
        clientes[username] = novaSenha; // Atualiza o banco de dados estatico
        std::cout << FG_VERDE << "Senha alterada com sucesso!" << RESET << std::endl;
        break;
            }
        }
    }
    else {
        std::cout << FG_VERMELHO << "Senha atual incorreta." << RESET << std::endl;
    }
    }*/
    void alterarSenha();
    /*!void Cliente::realizarPedido() {
    Pedido* novoPedido = new Pedido(username, "");
    double valorTotal = 0.0;
    std::string mais;

    do {
        cardapio->exibirCardapio();
        std::cout << FG_CIANO << "Escolha o número do item para adicionar ao pedido: " << RESET;
        int escolha = validarEntradaNumerica();
        const auto& itens = cardapio->getItens();
        if (escolha > 0 && escolha <= (int)itens.size()) {
            std::cout << FG_BRANCO << "Voce escolheu: " << FG_CIANO << itens[escolha - 1].nome << RESET << std::endl;
            std::cout << FG_CIANO << "Quantas unidades? " << RESET;
            int quantidade = validarEntradaNumerica();
            valorTotal += itens[escolha - 1].preco * quantidade;
            novoPedido->addItem(itens[escolha - 1], quantidade);
        }
        else {
            std::cout << FG_VERMELHO << "Opcao invalida." << RESET << std::endl;
            return;
        }
        do {
            std::cout << FG_CIANO << "Deseja adicionar mais itens? (s/n): " << RESET;
            std::cin >> mais;
            std::cin.ignore();
            if (!validarEntradaSimNao(mais)) {
                std::cout << FG_VERMELHO << "Entrada inválida. Digite 's' para Sim ou 'n' para Não." << RESET << std::endl;
            }
        } while (!validarEntradaSimNao(mais));
    } while (mais == "s" || mais == "S");

    //!< Aplica desconto se disponível
    aplicarDescontoSeDisponivel(valorTotal);

    std::cout << FG_CIANO << "O valor total do pedido é: R$ " << valorTotal << RESET << std::endl;

    std::cout << FG_CIANO << "Digite o endereço de entrega: " << RESET;
    std::string endereco;
    std::getline(std::cin, endereco);
    novoPedido->setEndereco(endereco);

    printLine();
    std::cout << FG_CIANO << "Confirmação do pedido:" << RESET << std::endl;
    novoPedido->exibirResumo();
    printLine();

    std::string confirmar;
    do {
        std::cout << FG_CIANO << "Confirmar pedido? (s/n): " << RESET;
        std::cin >> confirmar;
        std::cin.ignore();
        if (!validarEntradaSimNao(confirmar)) {
            std::cout << FG_VERMELHO << "Entrada inválida. Digite 's' para Sim ou 'n' para Não." << RESET << std::endl;
        }
    } while (!validarEntradaSimNao(confirmar));

    if (confirmar == "s" || confirmar == "S") {
        listaPedidos->push_back(novoPedido);
        std::cout << FG_VERDE << "Pedido realizado com sucesso!" << RESET << std::endl;
        acumularPontos(valorTotal); // Acumula pontos após o pedido ser confirmado
    }
    else {
        delete novoPedido;
        std::cout << FG_VERMELHO << "Pedido cancelado." << RESET << std::endl;
    }
    }*/
    void realizarPedido();
    /*!void Cliente::exibirStatusPedido() {
    for (size_t i = 0; i < listaPedidos->size(); ++i) {
        const auto& pedido = (*listaPedidos)[i];
        if (pedido->getCliente() == username) {
            std::cout << FG_CIANO << "Pedido " << i + 1 << FG_BRANCO << " de " << pedido->getCliente() << RESET << std::endl;
            pedido->exibirDetalhes();
            std::cout << " " << std::endl;
        }
    }
    }*/
    void exibirStatusPedido();
    /*!void Cliente::actions_cliente() {
    int opcao;
    do {
        printLine();
        std::cout << BOLD << FG_CIANO << "USUARIO: " << username << RESET << std::endl;
        std::cout << FG_BRANCO << "1. Ver cardapio" << RESET << std::endl;
        std::cout << FG_BRANCO << "2. Realizar pedido" << RESET << std::endl;
        std::cout << FG_BRANCO << "3. Ver status do pedido" << RESET << std::endl;
        std::cout << FG_BRANCO << "4. Alterar senha" << RESET << std::endl;
        std::cout << FG_BRANCO << "5. Ver pontos acumulados" << RESET << std::endl;
        std::cout << FG_VERMELHO << "6. Sair" << RESET << std::endl;

        printLine();
        opcao = validarEntradaNumerica();
        if (opcao == 1) {
            cardapio->exibirCardapio();
        }
        else if (opcao == 2) {
            realizarPedido();
        }
        else if (opcao == 3) {
            exibirStatusPedido();
        }
        else if (opcao == 4) {
            alterarSenha();
        }
        else if (opcao == 5) {
            exibirPontos();
        }
    } while (opcao != 6);
    }*/
    void actions_cliente();
    /*!void Cliente::menuInicial(Cardapio* cardapio, std::vector<Pedido*>* listaPedidos) {
    int opcao;
    do {
        printLine();
        std::cout << FG_CIANO << "BEM VINDO!" << RESET << std::endl;
        std::cout << FG_CIANO << "Selecione uma opcao:" << RESET << std::endl;
        std::cout << FG_BRANCO << "1. Entrar" << RESET << std::endl;
        std::cout << FG_VERDE << "2. Criar conta" << RESET << std::endl;
        std::cout << FG_BRANCO << "3. Voltar" << RESET << std::endl;
        printLine();
        opcao = validarEntradaNumerica();
        if (opcao == 1) {
            Cliente cliente(cardapio, listaPedidos);
            if (cliente.entrar()) {
                cliente.actions_cliente();
            }
        }
        else if (opcao == 2) {
            criarConta();
        }
    } while (opcao != 3);
    }*/
    static void menuInicial(Cardapio* cardapio, std::vector<Pedido*>* listaPedidos);
    static const std::map<std::string, std::string>& getClientes();
    /*!void Cliente::acumularPontos(double valorPedido) {
    int pontosGanhos = valorPedido / 10;
    pontosRecompensa[username] += pontosGanhos;
    std::cout << FG_VERDE << "Voce ganhou " << pontosGanhos << " pontos de recompensa!" << RESET << std::endl;
    }*/
    void acumularPontos(double valorPedido);
    /*"void Cliente::exibirPontos() {
    int pontos = pontosRecompensa[username];
    std::cout << FG_CIANO << "Voce tem " << pontos << " pontos acumulados." << RESET << std::endl;
    }*/
    void exibirPontos();
    /*!bool Cliente::aplicarDescontoSeDisponivel(double& valorPedido) {
    int pontos = pontosRecompensa[username];
    if (pontos >= 20) {
        double desconto = 10.0; // Desconto fixo de R$ 10
        valorPedido = std::max(0.0, valorPedido - desconto);
        pontosRecompensa[username] -= 20;
        std::cout << FG_VERDE << "Desconto de R$ " << desconto << " aplicado! Voce tem " 
                  << pontosRecompensa[username] << " pontos restantes." << RESET << std::endl;
        return true;
    }
    return false;
    }*/
    bool aplicarDescontoSeDisponivel(double& valorPedido);
};

#endif // CLIENTE_HPP
