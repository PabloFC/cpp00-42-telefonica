/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:07:33 by pafuente          #+#    #+#             */
/*   Updated: 2025/08/27 10:07:40 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact() : firstName(""), lastName(""), nickname(""), 
                    phoneNumber(""), darkestSecret("") {}

void Contact::setDetails() {
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
}

void Contact::displaySummary(int index) const {
    if (isEmpty()) return;
    
    std::cout << std::setw(10) << index << "|";
    
    // First name
    if (firstName.length() > 10)
        std::cout << std::setw(10) << firstName.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << firstName;
    std::cout << "|";
    
    // Last name
    if (lastName.length() > 10)
        std::cout << std::setw(10) << lastName.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << lastName;
    std::cout << "|";
    
    // Nickname
    if (nickname.length() > 10)
        std::cout << std::setw(10) << nickname.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << nickname;
    
    std::cout << std::endl;
}

void Contact::displayFull() const {
    if (isEmpty()) {
        std::cout << "Contact is empty!" << std::endl;
        return;
    }
    
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

bool Contact::isEmpty() const {
    return firstName.empty() && lastName.empty() && nickname.empty() &&
           phoneNumber.empty() && darkestSecret.empty();
}