/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:09:19 by pafuente          #+#    #+#             */
/*   Updated: 2025/08/27 10:16:29 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>  

PhoneBook::PhoneBook() : currentIndex(0), contactCount(0) {}

void PhoneBook::addContact() {
    Contact newContact;
    newContact.setDetails();
    
    contacts[currentIndex] = newContact;
    currentIndex = (currentIndex + 1) % 8;
    
    if (contactCount < 8)
        contactCount++;
    
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayContactsList() const {
    if (contactCount == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }
    
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    
    for (int i = 0; i < contactCount; i++) {
        contacts[i].displaySummary(i);
    }
}

bool PhoneBook::isValidIndex(int index) const {
    return index >= 0 && index < contactCount;
}

void PhoneBook::searchContacts() const {
    if (contactCount == 0) {
        std::cout << "Phonebook is empty! Add contacts first." << std::endl;
        return;
    }
    
    displayContactsList();
    
    std::cout << "Enter index to display: ";
    std::string input;
    std::getline(std::cin, input);
    
    if (input.empty()) {
        std::cout << "Invalid input!" << std::endl;
        return;
    }
    
    // Convert string to int
    std::stringstream ss(input);
    int index;
    ss >> index;
    
    if (ss.fail() || !ss.eof() || !isValidIndex(index)) {
        std::cout << "Invalid index! Please enter a number between 0 and " 
                  << contactCount - 1 << std::endl;
        return;
    }
    
    contacts[index].displayFull();
}