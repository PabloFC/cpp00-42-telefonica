/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <pafuente@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:09:19 by pafuente          #+#    #+#             */
/*   Updated: 2025/09/02 21:28:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), index(0) {}

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
        std::cout << "Error: no se permiten campos vacíos." << std::endl;
        return;
    }

    contacts[index].setContact(f, l, n, p, d);
    index = (index + 1) % 8;
    if (count < 8)
        count++;
}

static std::string truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::searchContacts() const
{
    if (count == 0)
    {
        std::cout << "Agenda vacía." << std::endl;
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

    std::cout << "Ingrese el índice del contacto a mostrar: ";
    int idx;
    std::cin >> idx;
    std::cin.ignore();

    if (idx < 0 || idx >= count)
    {
        std::cout << "Índice inválido." << std::endl;
        return;
    }

    std::cout << "First name: " << contacts[idx].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[idx].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[idx].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[idx].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[idx].getDarkestSecret() << std::endl;
}
