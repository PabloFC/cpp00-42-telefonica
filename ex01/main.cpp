/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:30:55 by pafuente          #+#    #+#             */
/*   Updated: 2025/08/27 10:36:18 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phonebook;
    std::string command;
    
    std::cout << "=== MY AWESOME PHONEBOOK ===" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        
        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContacts();
        } else if (command == "EXIT") {
            std::cout << "Goodbye! Contacts will be lost forever!" << std::endl;
            break;
        } else if (!command.empty()) {
            std::cout << "Invalid command! Use: ADD, SEARCH, EXIT" << std::endl;
        }
        
        if (std::cin.eof()) {
            std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
            break;
        }
    }
    
    return 0;
}