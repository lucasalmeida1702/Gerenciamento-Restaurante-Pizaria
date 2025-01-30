#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <string>
#include <vector>
#include "Cardapio.hpp"
#include "utils.hpp"

class Pedido {
private:
    struct ItemPedido {
        std::string nome;
        double preco;
        int quantidade;
    };

    std::string cliente;
    std::string endereco;
    std::vector<ItemPedido> itens;
    std::string status;

public:
	//!<Pedido::Pedido(const std::string& cli, const std::string& end) : cliente(cli), endereco(end), status("Pedido feito") {}
    Pedido(const std::string& cli, const std::string& end);
    /*!void Pedido::addItem(const Cardapio::Item& item, int quantidade) {
    itens.push_back({ item.nome, item.preco, quantidade });
    }*/
    void addItem(const Cardapio::Item& item, int quantidade);
    /*!void Pedido::setEndereco(const std::string& end) {
    std::string ende=end;
    while(1){
        if(validarSenha(ende)){
        std::cout<<FG_VERMELHO <<"Endereco Invalido!"; 
        std::cout<< FG_CIANO <<" Digite o endreco novamente:"<< RESET;
        std::getline(std::cin,ende);
        }
        else{
            endereco = ende;
            break;
        }
    }
    }*/
    void setEndereco(const std::string& end);
    /*!void Pedido::cancelaPedido() {
    status = "Cancelado";
    }*/
    void cancelaPedido();
    /*!void Pedido::atualizarStatus(const std::string& novoStatus) {
    status = novoStatus;
    }*/
    void atualizarStatus(const std::string& novoStatus);
    const std::string& getStatus() const;
    const std::string& getCliente() const;
    const std::string& getEndereco() const;
    const std::vector<ItemPedido>& getItens() const;
    /*!void Pedido::exibirResumo() const {
    double total = 0;
    printLine();
    std::cout << FG_CIANO << "Confirmacao do pedido:" << RESET << std::endl;
    std::cout << FG_CIANO << "Cliente: " << FG_BRANCO << cliente << RESET << std::endl;
    std::cout << FG_CIANO << "Pedido:" << RESET << std::endl;
    for (const auto& item : itens) {
        std::cout << FG_BRANCO << item.quantidade << "x " << item.nome
            << " - " << FG_VERDE << "R$" << item.preco * item.quantidade << RESET << std::endl;
        total += item.preco * item.quantidade;
    }
    std::cout << FG_CIANO << "Endereco: " << FG_BRANCO << endereco << RESET << std::endl;
    std::cout << FG_CIANO << "Total a pagar: " << FG_VERDE << "R$" << total << RESET << std::endl;
    printLine();
    }*/
    void exibirResumo() const;
    /*!void Pedido::exibirDetalhes() const {
    std::cout << FG_CIANO << "Cliente: " << FG_BRANCO << cliente << RESET << std::endl;
    for (const auto& item : itens) {
        std::cout << FG_BRANCO << item.quantidade << "x " << item.nome << RESET << std::endl;
    }
    std::cout << FG_CIANO << "Status: " << FG_BRANCO << status << RESET << std::endl;
    }*/
    void exibirDetalhes() const;
};

#endif // PEDIDO_HPP
