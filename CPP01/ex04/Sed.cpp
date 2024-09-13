/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:07:49 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/13 18:43:12 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"


//c_str sert a "convertir" une string dans un format c_string requi par fstream
void	replace(std::string infilename, std::string s1, std::string s2)
{
	std::string		outfilename = std::string(infilename) + ".replace";
	std::ofstream	outf(outfilename.c_str());

	std::ifstream	infile(infilename.c_str());
	
	if (s1 == ""){
		std::cout << "Error" << std::endl;
		std::cout << "S1 shouldn't be empty" << std::endl;
		return ;
	}
	if (!infile.is_open())
		std::cerr << "Failed opening infile -> " << infilename << std::endl;
	if (!outf.is_open())
		std::cerr << "Failed opening outfile" << std::endl;

	std::string	line;
	if (std::getline(infile, line, '\0'))
	{
		size_t	pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1);
		}
		outf << line;
		outf.close();//pas necessaire mais bonne pratique
		infile.close();//pas necessire mais bonne pratique
	}
	else
		std::cout << "Your " << infilename << " file is empty." << std::endl;
}
