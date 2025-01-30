#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>

// CÛdigos ANSI para cores e estilos
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"
#define FG_CIANO "\033[36m"
#define FG_VERDE "\033[32m"
#define FG_BRANCO "\033[37m"
#define FG_VERMELHO "\033[31m"
#define FG_AZUL "\033[34m"

//FunÁ„o auxiliar para imprimir linhas decorativas
void printLine();
/*!int validarEntradaNumerica() {
    int valor;
    while (true) {
        std::cin >> valor;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << FG_VERMELHO << "Entrada invalida. Por favor, insira um numero: " << RESET;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
    }
}*/
int validarEntradaNumerica();
/*!bool validarEntradaSimNao(const std::string& entrada) {
    return (entrada == "s" || entrada == "S" || entrada == "n" || entrada == "N");
}*/
bool validarEntradaSimNao(const std::string& entrada);
/*!bool validarSenha(const std::string& SenhaNova) {
    if(SenhaNova=="") return true;
    // Retorna falso se a string n√£o for vazia e contiver apenas espa√ßos
    else return !SenhaNova.empty() && std::all_of(SenhaNova.begin(), SenhaNova.end(), [](char c) { return std::isspace(c); });
}*/
bool validarSenha(const std::string& SenhaNova);
#endif // UTILS_HPP
