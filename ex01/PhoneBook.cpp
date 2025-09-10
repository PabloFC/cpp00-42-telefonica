/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:09:19 by pafuente          #+#    #+#             */
/*   Updated: 2025/09/10 12:42:18 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

// Constructor initializes contact count and index to 0
PhoneBook::PhoneBook() : count(0), index(0) {}

// Prompts user for contact information and adds it to phonebook
// Validates that no field is empty before storing the contact
void PhoneBook::addContact()
{
    std::string f, l, n, p, d;

    std::cout << "First name: ";
    std::getline(std::cin, f);
    std::cout << "Last name: ";
    std::getline(std::cin, l);
    std::cout << "Nickname: ";
    std::getline(std::cin, n);
    std::cout << "Phone number: ";
    std::getline(std::cin, p);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, d);

    if (f.empty() || l.empty() || n.empty() || p.empty() || d.empty())
    {
        std::cout << "Error: empty fields are not allowed." << std::endl;
        return;
    }

    contacts[index].setContact(f, l, n, p, d);
    index = (index + 1) % 8;
    if (count < 8)
        count++;
}

// Truncates strings longer than 10 characters and adds a dot
// Returns original string if 10 characters or less
static std::string truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

// Displays contacts in table format and allows user to view details
// Shows all contacts and prompts for index to display full information
void PhoneBook::searchContacts() const
{
    if (count == 0)
    {
        std::cout << "Empty phonebook." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Enter the index of the contact to display: ";
    int idx;
    
    if (!(std::cin >> idx))
    {
        std::cout << "Invalid input: please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore();

    if (idx < 0 || idx >= count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    std::cout << "First name: " << contacts[idx].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[idx].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[idx].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[idx].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[idx].getDarkestSecret() << std::endl;
}