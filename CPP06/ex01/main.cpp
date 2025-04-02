/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:28:07 by frite             #+#    #+#             */
/*   Updated: 2025/04/02 17:36:32 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// int main()
// {
// 	Data ptr2;
// 	ptr2.name = "Michaela Mustermann";
// 	ptr2.age = 42;
// 	ptr2.next = NULL;

// 	Data ptr;
// 	ptr.name = "Max Mustermann";
// 	ptr.age = 42;
// 	ptr.next = &ptr2;


// 	std::cout << "Here is the original structs:" <<
// 				"\n\taddress: " << &ptr <<
// 				"\n\tname: " << ptr.name <<
// 				"\n\tage: " << ptr.age <<
// 				"\n\taddress next: " << ptr.next <<
// 	std::endl;
// 	std::cout << "\taddress ptr2: " << &ptr2 <<
// 				"\n\tname: " << ptr2.name <<
// 				"\n\tage: " << ptr2.age <<
// 				"\n\taddress next: " << ptr2.next <<
// 	std::endl << std::endl;


// 	Data *reserialized_struct = Serializer::operator=(Serializer::serialize(&ptr));

// 	std::cout << "Here is the reserialized structs:" <<
// 				"\n\taddress: " << reserialized_struct <<
// 				"\n\tname: " << reserialized_struct->name <<
// 				"\n\tage: " << reserialized_struct->age <<
// 				"\n\taddress next: " << reserialized_struct->next <<
// 	std::endl;
// 	std::cout << "\taddress ptr2: " << &ptr2 <<
// 				"\n\tname: " << ptr2.name <<
// 				"\n\tage: " << ptr2.age <<
// 				"\n\taddress next: " << ptr2.next <<
// 	std::endl << std::endl;

// 	return (0);
// }

int main(void){
    Data* data = new Data;

    data->name = "testname";
    data->age = 42;
    
    std::cout << "data name: " << data->name << std::endl;
    std::cout << "data age: " << data->age << std::endl;

    std::cout << "data serialized: " << Serializer::serialize(data) << std::endl;

    std::cout << "data name: " << data->name << std::endl;
    std::cout << "data age: " << data->age << std::endl;

    std::cout << "data deserialized: " << Serializer::deserialize(Serializer::serialize(data)) << std::endl;

    std::cout << "data name: " << data->name << std::endl;
    std::cout << "data age: " << data->age << std::endl;
}